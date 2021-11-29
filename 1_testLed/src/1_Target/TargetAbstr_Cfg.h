#ifndef TARGET_CFG_H
#define TARGET_CFG_H

#include "Std_Types.h"
/**************************************************************************************************************/
/* Micro Versions */
//sAnwar: don't change the following macros
#define TC29X   		(1U)
#define TC27X   		(2U)
#define TC26X   		(3U)
#define TC23X   		(4U)

#define	IFX_CFG_TC29X   		(TC29X)
#define IFX_CFG_TC27X   		(TC27X)
#define IFX_CFG_TC26X   		(TC26X)
#define IFX_CFG_TC23X   		(TC23X)



/**************************************************************************************************************/
//configuration starts here

/*______________________________________________________________________________
** Configuration for compiler
**____________________________________________________________________________*/
//sAnwar
//Modern compiler has a built in compiler type, but I added it manually in case of
//using an old compiler and to make it easer to navigate with IDEs
#if (!defined __GNUC__)
	#define __GNUC__
#endif


/*______________________________________________________________________________
** Configuration for target
**____________________________________________________________________________*/
//Allowed values IFX_CFG_TC29X, IFX_CFG_TC27X, IFX_CFG_TC26X or IFX_CFG_TC23X
#define IFX_CFG_DEVICE                   (IFX_CFG_TC27X)



/*______________________________________________________________________________
** Configuration for BMHs
**____________________________________________________________________________*/
//TODO: are all the 4 BMHs available for all targets? if not, then the unavailable shall be disabled
#define	Target_UseBMH0					STD_ON
#define	Target_UseBMH1					STD_OFF
#define	Target_UseBMH2					STD_OFF
#define	Target_UseBMH3					STD_OFF


/** \brief Configuration for CpuX enable.
 *
 */
#ifndef IFX_CFG_CPU_CSTART_ENABLE_TRICORE0
#   define IFX_CFG_CPU_CSTART_ENABLE_TRICORE0        (1) /**< Cpu0 enabled by default*/
#endif
#ifndef IFX_CFG_CPU_CSTART_ENABLE_TRICORE1
#   define IFX_CFG_CPU_CSTART_ENABLE_TRICORE1        (0) /**< Cpu1 disabled by default*/
#endif
#ifndef IFX_CFG_CPU_CSTART_ENABLE_TRICORE2
#   define IFX_CFG_CPU_CSTART_ENABLE_TRICORE2        (0) /**< Cpu2 disabled by default*/
#endif

/** \brief Configuration for cache enable.
 *
 */
#ifndef IFX_CFG_CPU_CSTART_ENABLE_TRICORE0_PCACHE
#   define IFX_CFG_CPU_CSTART_ENABLE_TRICORE0_PCACHE (0)  /**< Program Cache Disabled by default*/
#endif
#ifndef IFX_CFG_CPU_CSTART_ENABLE_TRICORE0_DCACHE
#   define IFX_CFG_CPU_CSTART_ENABLE_TRICORE0_DCACHE (0)  /**< Data Cache Disabled by default*/
#endif

#ifndef IFXCPU_CSTART_CCU_INIT_HOOK
#define IFXCPU_CSTART_CCU_INIT_HOOK() (void)IfxScuCcu_init(&IfxScuCcu_defaultClockConfig);   /*The status returned by Ccu init is ignored */
#endif


//TODO
//#define 	IntTable_Location				0x80000600
//#define 	TrapTable_Location				0x80000300
//#define	InterruptStack_Size				1024
//#define	ContextSaveArea_Size			4096
//#define	StartupCfg_UserStackSize		20480
//noinit


#endif
