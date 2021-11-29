#include "Std_Types.h"
#include "IfxCpu.h"
#include "IfxCpu_Intrinsics.h"
#include "IfxCpu_reg.h"


/*******************************************************************************
**         Global Exported macros/inlines/function ptototypes                 **
*******************************************************************************/
#if defined(__GNUC__)
#define __ALIGN_TRAP_TAB__ __asm(" .align 5");
#define IfxCpu_Tsr_CallTSR(serviceRoutine)         \
    {                                              \
        __ALIGN_TRAP_TAB__;                        \
        __asm("svlcx\n");                          \
        __asm("mov\t %d4, %d15");                  \
        __asm("ji\t %0" : : "a" (serviceRoutine)); \
        __asm("rfe");                              \
    }
#elif defined(__TASKING__)
#define IfxCpu_Tsr_CallTSR(serviceRoutine)                                              \
    {                                                                                   \
        __ALIGN_TRAP_TAB__;                                                             \
        __asm("svlcx\n\tmov\td4,d15\n\tji\t%0\n" : : "a" (serviceRoutine) : "d4", "d15"); \
    }
#define __ALIGN_TRAP_TAB__ __asm(" .align 32");
#endif



uint32 TrapAddress=0;
uint8 TrapCoreId=0;
uint8 TrapIdNum=0;



#define TARGET_START_SEC_CODE
#include "Target_MemMap.h"

void IfxCpu_Trap_memoryManagementError(uint32 tin)
{
    uint32 *res;
    Ifx_CPU_CORE_ID reg;

    // address of the instruction caused the trap.
    __asm__ volatile ("mov.aa %0, %%a11": "=a" (res) : :"a11");
    TrapAddress  = (unsigned int)res;

    //the core which caused the trap
    reg.U = __mfcr(CPU_CORE_ID);
    TrapCoreId = (IfxCpu_Id)reg.B.CORE_ID;

    /*
    IdNum=0--> Virtual Address Fill trap: generated when the MMU is enabled and the virtual address
               referenced by an instruction does not have a page entry in the MMU Translation
               Lookaside Buffer
    IdNum=1--> Virtual Address Protection trap:  generated (when the MMU is enabled) by a memory
               access undergoing PTE translation that is not permitted by the PTE protection settings,
               or by a User-0 mode access to an upper segment that does not have the privileged peripheral property.
    */
    TrapIdNum = tin;

    __asm__ volatile ("debug" : : : "memory");
    __asm("rslcx"); /* Restore lower context before returning. lower context was stored in the trap vector */
    __asm("rfe");
}


void IfxCpu_Trap_internalProtectionError(uint32 tin)
{
    uint32 *res;
    Ifx_CPU_CORE_ID reg;

    // address of the instruction caused the trap.
    __asm__ volatile ("mov.aa %0, %%a11": "=a" (res) : :"a11");
    TrapAddress  = (unsigned int)res;

    //the core which caused the trap
    reg.U = __mfcr(CPU_CORE_ID);
    TrapCoreId = (IfxCpu_Id)reg.B.CORE_ID;

    /*
    IdNum=1--> Privilege Violation trap: A program executing in one of the User modes
               (User-0 or User-1 mode) attempted to execute an instruction not allowed by that mode
    IdNum=2--> Memory Protection Read trap: generated when the memory protection system is enabled
               and the effective address of a load, LDMST, SWAP or ST.T instruction does not lie within
               any range with read permissions enabled
    IdNum=3--> Memory Protection Write trap: generated when the memory protection system is enabled
               and the effective address of a store, LDMST, SWAP or ST.T instruction does not lie
               within any range with write permissions enabled.
    IdNum=4--> Memory Protection Execute trap: generated when the memory protection system is enabled
               and the PC does not lie within any range with execute permissions enabled.
    IdNum=5--> Memory Protection Peripheral Access trap: A program executing in User-0 mode attempted
               a load or store access to a segment is configured to be a peripheral segment
    IdNum=6--> Memory Protection Null address trap: generated whenever any program attempts a
               load / store operation to effective address zero.
    IdNum=7--> Global Register Write Protection trap: A program attempted to modify one of the global
               address registers (A[0], A[1], A[8] or A[9]) when it did not have permission to do so.
     */
    TrapIdNum = tin;

    __asm__ volatile ("debug" : : : "memory");
    __asm("rslcx"); /* Restore lower context before returning. lower context was stored in the trap vector */
    __asm("rfe");
}


void IfxCpu_Trap_instructionError(uint32 tin)
{
    uint32 *res;
    Ifx_CPU_CORE_ID reg;

    // address of the instruction caused the trap.
    __asm__ volatile ("mov.aa %0, %%a11": "=a" (res) : :"a11");
    TrapAddress  = (unsigned int)res;

    //the core which caused the trap
    reg.U = __mfcr(CPU_CORE_ID);
    TrapCoreId = (IfxCpu_Id)reg.B.CORE_ID;

    /*
    IdNum=1--> Illegal Opcode trap: An invalid instruction opcode was encountered. An invalid
               opcode is one that does not correspond to any instruction known to the implementation.
    IdNum=2--> Unimplemented Opcode trap: An unimplemented opcode was encountered. An
               unimplemented opcode corresponds to a known instruction that is not implemented
               in a given hardware implementation.
    IdNum=3--> Invalid Operand trap: raised for instructions that take an even-odd register pair as
               an operand, if the operand specifier is odd. The OPD trap may also be raised for other
               cases where operands are invalid.
    IdNum=4--> Data Address Alignment trap: raised when the address for a data memory operation does
               not conform to the required alignment rules.
    IdNum=5-->  Invalid Memory Address trap: raised when the address of an access can be determined
                to either violate an architectural constraint or an implementation constraint.
     */
    TrapIdNum = tin;

    __asm__ volatile ("debug" : : : "memory");
    __asm("rslcx"); /* Restore lower context before returning. lower context was stored in the trap vector */
    __asm("rfe");
}


void IfxCpu_Trap_contextManagementError(uint32 tin)
{
    uint32 *res;
    Ifx_CPU_CORE_ID reg;

    // address of the instruction caused the trap.
    __asm__ volatile ("mov.aa %0, %%a11": "=a" (res) : :"a11");
    TrapAddress  = (unsigned int)res;

    //the core which caused the trap
    reg.U = __mfcr(CPU_CORE_ID);
    TrapCoreId = (IfxCpu_Id)reg.B.CORE_ID;

    /*
    IdNum=1--> Free Context list Depletion trap:  generated after a context save operation, when the
               operation causes the free context list to become ‘almost empty’. The ‘almost empty’
               condition is signaled when the CSA used for the save operation is the one pointed to by
               the context list limit register LCX.
    IdNum=2--> Call Depth Overflow trap: A program attempted to execute a CALL instruction with the
               Call Depth counter enabled and the call depth count value (PSW.CDC.COUNT) at its maximum value.
    IdNum=3--> Call Depth Underflow trap: A program attempted to execute a RET (return) instruction
               with the Call Depth counter enabled and the call depth count value (PSW.CDC.COUNT) at zero.
    IdNum=4--> Free Context List Underflow trap: a context save operation is attempted but the free
               context list is found to be empty (i.e. the FCX register contents are null).
    IdNum=5--> Call Stack Underflow trap: Raised when a context restore operation is attempted and
               when the contents of the PCX register were null.
    IdNum=6--> Context Type trap: a context restore operation is attempted but the context type, as
               indicated by the PCXI.UL bit, is incorrect for the type of restore attempted.
    IdNum=7--> Nesting Error trap: A program attempted to execute an RFE (return from exception)
               instruction with the Call Depth counter enabled and the call depth count value
               (PSW.CDC.COUNT) non-zero.
     */
    TrapIdNum = tin;

    __asm__ volatile ("debug" : : : "memory");
    __asm("rslcx"); /* Restore lower context before returning. lower context was stored in the trap vector */
    __asm("rfe");
}


void IfxCpu_Trap_busError(uint32 tin)
{
    uint32 *res;
    Ifx_CPU_CORE_ID reg;

    // address of the instruction caused the trap.
    __asm__ volatile ("mov.aa %0, %%a11": "=a" (res) : :"a11");
    TrapAddress  = (unsigned int)res;

    //the core which caused the trap
    reg.U = __mfcr(CPU_CORE_ID);
    TrapCoreId = (IfxCpu_Id)reg.B.CORE_ID;

    /*

        IdNum=1--> Program Fetch Synchronous Error trap: raised when:
                   • A bus error1) occurred because of an instruction fetch.
                   • An instruction fetch targets a segment that does not have the code fetch property.
        IdNum=2--> Data Access Synchronous Error trap: raised when:
                   • Whenever a bus error occurs because of a data load operation.
                   • In the case of a data load or store operation from Data scratchpad RAM (DSPR) where
                     the access is beyond the end of the memory range.
                   • In the case of an error during the data load phase of a data cache refill.
        IdNum=3--> Data Access Asynchronous Error trap: raised when the memory system reports back an error
                   which cannot immediately be linked to a currently executing instruction. Generally this
                   means an error returned on the system bus from a peripheral or external memory.
        IdNum=4--> Coprocessor Trap Asynchronous Error trap: generated by a coprocessor to report an error.
        IdNum=5--> Program Memory Integrity Error trap: raised whenever an uncorrectable memory integrity
                   error is detected in an instruction fetch.
        IdNum=6--> Data Memory Integrity Error trap: raised whenever an uncorrectable memory integrity error
                   is detected in a data access.
        IdNum=7--> Temporal Asynchronous Error trap: raised by the temporal protection system whenever an
                   active timer decrements to zero.
         */
    TrapIdNum = tin;

    __asm__ volatile ("debug" : : : "memory");
    __asm("rslcx"); /* Restore lower context before returning. lower context was stored in the trap vector */
    __asm("rfe");
}


void IfxCpu_Trap_assertion(uint32 tin)
{
    uint32 *res;
    Ifx_CPU_CORE_ID reg;

    // address of the instruction caused the trap.
    __asm__ volatile ("mov.aa %0, %%a11": "=a" (res) : :"a11");
    TrapAddress  = (unsigned int)res;

    //the core which caused the trap
    reg.U = __mfcr(CPU_CORE_ID);
    TrapCoreId = (IfxCpu_Id)reg.B.CORE_ID;

    /*
     IdNum=1--> Arithmetic Overflow trap: Raised by the TRAPV instruction, if the overflow
                bit in the PSW is set (PSW.V == 1).
     IdNum=2--> Sticky Arithmetic Overflow trap: Raised by the TRAPSV instruction, if the
                sticky overflow bit in the PSW is set (PSW.SV == 1).
    */
    TrapIdNum = tin;

    __asm__ volatile ("debug" : : : "memory");
    __asm("rslcx"); /* Restore lower context before returning. lower context was stored in the trap vector */
    __asm("rfe");
}


void IfxCpu_Trap_systemCall_Cpu0(uint32 tin)
{
    uint32 *res;
    Ifx_CPU_CORE_ID reg;

    // address of the instruction caused the trap.
    __asm__ volatile ("mov.aa %0, %%a11": "=a" (res) : :"a11");
    TrapAddress  = (unsigned int)res;

    //the core which caused the trap
    reg.U = __mfcr(CPU_CORE_ID);
    TrapCoreId = (IfxCpu_Id)reg.B.CORE_ID;

    /*
     System Call (TIN = 8-bit unsigned immediate constant in SYSCALL): The SYS trap
     is raised immediately after the execution of the SYSCALL instruction, to initiate
     a system call. The TIN that is loaded into D[15] when the trap is taken is not fixed,
     but is specified as an 8-bit unsigned immediate constant in the SYSCALL instruction.
     The return address points to the instruction immediately following the SYSCALL.
    */
    TrapIdNum = tin;

    //TODO: why not used?
    //__asm__ volatile ("debug" : : : "memory");
    __asm("rslcx"); /* Restore lower context before returning. lower context was stored in the trap vector */
    __asm("rfe");
}


void IfxCpu_Trap_nonMaskableInterrupt(uint32 tin)
{
    uint32 *res;
    Ifx_CPU_CORE_ID reg;

    // address of the instruction caused the trap.
    __asm__ volatile ("mov.aa %0, %%a11": "=a" (res) : :"a11");
    TrapAddress  = (unsigned int)res;

    //the core which caused the trap
    reg.U = __mfcr(CPU_CORE_ID);
    TrapCoreId = (IfxCpu_Id)reg.B.CORE_ID;

    /*
     IdNum=1--> Non-Maskable Interrupt trap: implementation dependent. Typically there is an
                external pin that can be used to signal the NMI, but it may also be raised in
                response to such things as a watchdog timer interrupt, or an impending power failure.
    */
    TrapIdNum = tin;

    //TODO: why not used?
    //__asm__ volatile ("debug" : : : "memory");
    __asm("rslcx"); /* Restore lower context before returning. lower context was stored in the trap vector */
    __asm("rfe");
}

#define TARGET_STOP_SEC_CODE
#include "Target_MemMap.h"




#define TARGET_START_SEC_TRAPTAB0
#include "Target_MemMap.h"

void IfxCpu_Trap_vectorTable0(void)
{
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_memoryManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_internalProtectionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_instructionError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_contextManagementError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_busError);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_assertion);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_systemCall_Cpu0);
    IfxCpu_Tsr_CallTSR(IfxCpu_Trap_nonMaskableInterrupt);
}

#define TARGET_STOP_SEC_TRAPTAB0
#include "Target_MemMap.h"
