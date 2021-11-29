/*
 * A[0], A[1],A[8], A[9]: System Global Address Registers
 * D[15] Implicit data register for many 16-bit instructions.
 * A[10] Stack Pointer (SP).
 * A[11] Return address register (RA) for CALL, JL, JLA, and JLI. Return PC value on interrupts(or traps) .
 * A[15] Implicit base address register for many 16-bit load/store instructions.
*/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "TargetAbstr_Cfg.h"
#include "Target_CStart0.h"
#include "IfxScuWdt.h"
#include "IfxCpu.h"
#include "IfxScuCcu.h"

/******************************************************************************/
/*                           Macros                                           */
/******************************************************************************/


/*******************************************************************************
**                      Imported Function Declarations                        **
*******************************************************************************/
IFXCOMPILER_COMMON_LINKER_SYMBOLS()
IFXCOMPILER_CORE_LINKER_SYMBOLS(0)

IFX_EXTERN void main(void);

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
#define IFXCSTART0_PSW_DEFAULT     (0x00000B80u)//TODO: Check 0x00000B80u?? 0x00000980u
#define IFXCSTART0_PCX_O_S_DEFAULT (0xfff00000u)

/*!
 * \brief Data s C variables.
 */
extern uint32 __clear_table[];  /**< clear table entry */
extern uint32 __copy_table[];   /**< copy table entry */

void Ifx_C_Init(void);

typedef volatile union
{
    uint8              *ucPtr;
    uint16             *usPtr;
    uint32             *uiPtr;
    unsigned long long *ullPtr;
} IfxStart_CTablePtr;


#define TARGET_START_SEC_CODE
#include "Target_MemMap.h"

#if defined(__GNUC__)
#pragma GCC optimize ("-O2")
#endif

void _Core0_start(void)
{
    uint32 pcxi;
    uint16 cpuWdtPassword = IfxScuWdt_getCpuWatchdogPasswordInline(&MODULE_SCU.WDTCPU[0]);
    /* sAnwar:commented pre-init tests
       This initial RAM test is only a recommendation and is not seen as mandatory from Safety perspective
    */
    IFX_CFG_CPU_CSTART_PRE_C_INIT_HOOK(0);  /*Test Stack, CSA and Cache */

    /* Load user stack pointer on A[10] register */
    __setareg(sp, __USTACK(0));
    __dsync();

    /* Set the PSW to its reset value in case of a warm start,clear PSW.IS */
    /* sAnwar: Processor(Program) Status Word, Resetting call depth counter and user status bits
     * sAnwar: PSW.IS interrupt stack control
    */
    __mtcr(CPU_PSW, IFXCSTART0_PSW_DEFAULT);

    /* Set the PCXS and PCXO to its reset value in case of a warm start */
    /*
     * PCXI: Previous Context Information Register
     * PCXS: Previous Context Pointer Segment Address. Contains the segment address portion of the PCX.
     * PCXO: Previous Context Pointer Offset Field.
     * The PCXO and PCXS fields form the pointer PCX
     */
    pcxi  = __mfcr(CPU_PCXI);
    pcxi &= IFXCSTART0_PCX_O_S_DEFAULT; /*0xfff00000; */
    __mtcr(CPU_PCXI, pcxi);

    /*enable/disable program cache depending on the configuration */
    IfxCpu_setProgramCache(IFX_CFG_CPU_CSTART_ENABLE_TRICORE0_PCACHE);

    /*enable/disable data cache depending on the configuration */
    IfxCpu_setDataCache(IFX_CFG_CPU_CSTART_ENABLE_TRICORE0_DCACHE);

    /* Clear the ENDINIT bit in the WDT_CON0 register, inline funtion */
    //sAnwar: all Core Special Function Registers can be modified, using the MTCR instruction only when in the endinit is cleared.
    IfxScuWdt_clearCpuEndinitInline(&MODULE_SCU.WDTCPU[0], cpuWdtPassword);

    /* Load Base Address of Trap Vector Table. */
    __mtcr(CPU_BTV, (uint32)__TRAPTAB(0));

    /* Load Base Address of Interrupt Vector Table. we will do this later in the program */
    /* Empty label will be created in in linker but will not be populated with codeInterrupts not used in BootLoader
       TODO: sAnwar populate it with invalid code to cause a trap in case of interrupt
       This is vector table with single entry for Software Managed Interrupts.
       This need to be located at boundary 0xXFE0 where (X=1,3,5 and so on) == 8160*X. The BIV must be set to this address.*/
    __mtcr(CPU_BIV, (uint32)__INTTAB(0));

    /* Load interrupt stack pointer. */
    //TODO: sAnwar, make sure it's working correctly
    __mtcr(CPU_ISP, (uint32)__ISTACK(0));

    IfxScuWdt_setCpuEndinitInline(&MODULE_SCU.WDTCPU[0], cpuWdtPassword);

    /* initialize SDA base pointers */
    //TODO: sAnwar, make sure it's working correctly
    __setareg(a0, __SDATA1(0));
    __setareg(a1, __SDATA2(0));

    /* These to be un commented if A8 and A9 are required to be initialized */
    //__setareg(a8, __SDATA3(0));
    //__setareg(a9, __SDATA4(0));
    /* Setup the context save area linked list. */
    //TODO: sAnwar, make sure it's working correctly
    IfxCpu_initCSA((uint32 *)__CSA(0), (uint32 *)__CSA_END(0));     /*Initialize the context save area for CPU0 */

    {
        /*CPU and safety watchdogs are enabled by default, C initialization functions are not servicing the watchdogs */
        uint16 safetyWdtPassword = IfxScuWdt_getSafetyWatchdogPassword();
        IfxScuWdt_disableCpuWatchdog(cpuWdtPassword);
        IfxScuWdt_disableSafetyWatchdog(safetyWdtPassword);

        Ifx_C_Init();           /*Initialization of C runtime variables */
        //TODO: check why if not commented, a reset will occur.
        //IfxScuWdt_enableCpuWatchdog(cpuWdtPassword);
        //IfxScuWdt_enableSafetyWatchdog(safetyWdtPassword);
    }

    /*Initialize the clock system */
    IFXCPU_CSTART_CCU_INIT_HOOK();

    /*Start remaining cores */
#if (IFX_CFG_CPU_CSTART_ENABLE_TRICORE1 != 0)
    (void)IfxCpu_startCore(&MODULE_CPU1, (uint32)&_Core1_start);       /*The status returned by function call is ignored */
#endif
#if (IFX_CFG_CPU_CSTART_ENABLE_TRICORE2 != 0)
    (void)IfxCpu_startCore(&MODULE_CPU2, (uint32)&_Core2_start);       /*The status returned by function call is ignored */
#endif
    //sAnwar: Additional steps taken from "Cpu0_Main.c"
	/*!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!*/
    IfxScuWdt_disableCpuWatchdog(cpuWdtPassword);
#if (IFX_CFG_CPU_CSTART_ENABLE_TRICORE0 == 0)
    /*halt the CPU 0 if it is not needed to be enabled */
    IfxCpu_setCoreMode(&MODULE_CPU0, IfxCpu_CoreMode_idle);
#endif

    /*Call main function of Cpu0 */
    __non_return_call(main);

}

#if defined(__GNUC__)
#pragma GCC reset_options
#endif



/*!
 * \brief Initializes C variables.
 *
 * This function is called in the startup. This function initialize the all variables in .data section
 * and clears the .bss section
 *
 * Parameters: Nil
 * Return: Nil
 */

void Ifx_C_Init(void)
{
    IfxStart_CTablePtr pBlockDest, pBlockSrc;
    uint32             uiLength, uiCnt;
    uint32            *pTable;
    /* clear table */
    pTable = (uint32 *)&__clear_table;

    while (pTable)
    {
        pBlockDest.uiPtr = (uint32 *)*pTable++;
        uiLength         = *pTable++;

        /* we are finished when length == -1 */
        if (uiLength == 0xFFFFFFFF)
        {
            break;
        }

        uiCnt = uiLength / 8;

        while (uiCnt--)
        {
            *pBlockDest.ullPtr++ = 0;
        }

        if (uiLength & 0x4)
        {
            *pBlockDest.uiPtr++ = 0;
        }

        if (uiLength & 0x2)
        {
            *pBlockDest.usPtr++ = 0;
        }

        if (uiLength & 0x1)
        {
            *pBlockDest.ucPtr = 0;
        }
    }

    /* copy table */
    pTable = (uint32 *)&__copy_table;

    while (pTable)
    {
        pBlockSrc.uiPtr  = (uint32 *)*pTable++;
        pBlockDest.uiPtr = (uint32 *)*pTable++;
        uiLength         = *pTable++;

        /* we are finished when length == -1 */
        if (uiLength == 0xFFFFFFFF)
        {
            break;
        }

        uiCnt = uiLength / 8;
        while (uiCnt--)
        {
            *pBlockDest.ullPtr++ = *pBlockSrc.ullPtr++;
        }

        if (uiLength & 0x4)
        {
            *pBlockDest.uiPtr++ = *pBlockSrc.uiPtr++;
        }

        if (uiLength & 0x2)
        {
            *pBlockDest.usPtr++ = *pBlockSrc.usPtr++;
        }

        if (uiLength & 0x1)
        {
            *pBlockDest.ucPtr = *pBlockSrc.ucPtr;
        }
    }
}

#define TARGET_STOP_SEC_CODE
#include "Target_MemMap.h"

/*******************************************************************************
* _START() - App entry point after reset                                     *
*******************************************************************************/
/* sAnwar: Is the first code to be executed by Hw in case no BL is present.
 * Otherwise, this is the address where BL will jump to start the application.
 * This is a basic jump instruction to jump to startup sequence.
 */
#define TARGET_START_SEC_HwEntry
#include "Target_MemMap.h"

void _START(void)
{
	//TODO: reset reason RSTSTAT
    __non_return_call(_Core0_start);
}


#define TARGET_STOP_SEC_HwEntry
#include "Target_MemMap.h"
