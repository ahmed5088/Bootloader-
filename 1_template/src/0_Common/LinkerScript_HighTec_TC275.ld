/*
 * Name: iROM.ld
 *
 * Generated Linker Description File
 * Copyright (C) 2010 HighTec EDV-Systeme GmbH.
 * (!Do not edit outsite of the protection areas!)
 *
 * Description:
 * internal flash configuration
 */

/*
 * Define Entrypoint of Executable
 */
ENTRY(_START)

/*
 * Global
 */
/*Program Flash Memory (PFLASH0)*/
__PMU_PFLASH0_BEGIN = 0x80000000;
__PMU_PFLASH0_SIZE = 2M;
/*Program Flash Memory (PFLASH1)*/
__PMU_PFLASH1_BEGIN = 0x80200000;
__PMU_PFLASH1_SIZE = 2M;
/*Data Flash Memory (DFLASH0)*/
__PMU_DFLASH0_BEGIN = 0xAF000000;
__PMU_DFLASH0_SIZE = 1M;
/*Data Flash Memory (DFLASH0_1)*/
__PMU_DFLASH0_1_BEGIN = 0xAF100000;
__PMU_DFLASH0_1_SIZE = 16K;
/*Data Flash Memory (DFLASH1)*/
__PMU_DFLASH1_BEGIN = 0xAF110000;
__PMU_DFLASH1_SIZE = 64K;
/*Boot ROM (BROM)*/
__BROM_BEGIN = 0x8FFF8000;
__BROM_SIZE = 32K;
/*Scratch-Pad RAM (PSPR)*/
__PMI_PSPR_BEGIN = 0xC0000000;
__PMI_PSPR_SIZE = 24K;
/*Local Data RAM (DSPR)*/
__DMI_DSPR_BEGIN = 0xD0000000;
__DMI_DSPR_SIZE = 112K;


__USTACK0_SIZE = DEFINED (__USTACK0_SIZE) ? __USTACK0_SIZE : 1K;  /* Section for ustack*/
__ISTACK0_SIZE = DEFINED (__ISTACK0_SIZE) ? __ISTACK0_SIZE : 256;  /* Section for istack*/
__HEAP_SIZE = DEFINED (__HEAP_SIZE) ? __HEAP_SIZE : 4K;  /* Section for heap*/
__CSA0_SIZE = DEFINED (__CSA0_SIZE) ? __CSA0_SIZE : 16K;  /* Section for CSA*/

/**
 *	User defined global region
 */
/*PROTECTED REGION ID(Protection:iROM-Global) ENABLED START*/
/*Protection-Area for your own LDF-Code*/
/*PROTECTED REGION END*/

/*
 * internal flash configuration
 */
MEMORY
{
	PMU_PFLASH0 (rx!p):	org = 0xA0000000, len = 2M  /*Program Flash Memory (PFLASH0)*/
	PMU_PFLASH1 (rx!p):	org = 0xA0200000, len = 2M  /*Program Flash Memory (PFLASH1)*/
	PMU_DFLASH0 (r!xp):	org = 0xAF000000, len = 1M  /*Data Flash Memory (DFLASH0)*/
	PMU_DFLASH0_1 (r!xp):	org = 0xAF100000, len = 16K  /*Data Flash Memory (DFLASH0_1)*/
	PMU_DFLASH1 (r!xp):	org = 0xAF110000, len = 64K  /*Data Flash Memory (DFLASH1)*/
	BROM (rx!p):		org = 0x8FFF8000, len = 32K  /*Boot ROM (BROM)*/
	PMI_PSPR (wx!p):	org = 0xC0000000, len = 24K  /*Scratch-Pad RAM (PSPR)*/
	DMI_DSPR (w!xp):	org = 0xD0000000, len = 112K  /*Local Data RAM (DSPR)*/

}

SECTIONS
{
	.bmhd_0 (0xA0000000) :
	{
		KEEP(*(.TARGET.BMH0))
		. = 0x20; 
	} > PMU_PFLASH0 
}

SECTIONS
{ 
	.HWEntry (0xA0000020):
	{
		KEEP (*(.HwEntry))
		. = ALIGN(8);
	} > PMU_PFLASH0 
	
	
}
SECTIONS
{
	/*Code-Sections*/

	/*
	 * Startup code for TriCore
	 */
	.startup_code  :
	{
		PROVIDE(__startup_code_start = .);

		*(.startup_code) /*Startup code for TriCore*/
		*(.startup_code*)

		/*PROTECTED REGION ID(Protection: iROM .startup_code) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__startup_code_end = .);
		. = ALIGN(8);

	} > PMU_PFLASH0 /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */

	/*
	 * Code section
	 */
	.text  :
	{
		PROVIDE(__text_start = .);

		/*PROTECTED REGION ID(Protection: iROM .text.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		*(.text) /*Code section*/
		*(.text*)
		*(.gnu.linkonce.t.*)

		/*PROTECTED REGION ID(Protection: iROM .text) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__text_end = .);
		. = ALIGN(8);

	} > PMU_PFLASH0 /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */

	/*
	 * Code executed before calling main
	 */
	.init  :
	{
		PROVIDE(__init_start = .);

		/*PROTECTED REGION ID(Protection: iROM .init.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		KEEP(*(.init)) /*Code executed before calling main*/
		KEEP(*(.init*))

		/*PROTECTED REGION ID(Protection: iROM .init) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__init_end = .);
		. = ALIGN(8);

	} > PMU_PFLASH0 /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */

	/*
	 * Code executed before exiting program
	 */
	.fini  :
	{
		PROVIDE(__fini_start = .);

		/*PROTECTED REGION ID(Protection: iROM .fini.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		KEEP(*(.fini)) /*Code executed before exiting program*/
		KEEP(*(.fini*))

		/*PROTECTED REGION ID(Protection: iROM .fini) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__fini_end = .);
		. = ALIGN(8);

	} > PMU_PFLASH0 /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */




/*	*********************TRAP AND INTERRUPT VECTOR TABLES SECTIONS********************* */
	/*
	 * Section for trap table
	 */
	.traptab    : ALIGN(8)
	{
		PROVIDE(__TRAPTAB_CPU0 = .);
        KEEP(*(.TARGET.TrapTab0));		
		PROVIDE(__TRAPTAB_CPU0_END = .);
		. = ALIGN(8);

	} > PMU_PFLASH0 /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */

	/*
	 * Section for interrupt table
	 */
	/*TODO: sAnwar populate it with invalid code to cause a trap in case of interrupt*/
	/*This is vector table with single entry for Software Managed Interrupts. 
	  This need to be located at boundary 0xXFE0 where (X=1,3,5 and so on) == 8160*X. 
      the BIV must be set to this address.*/
	.inttab   : ALIGN(8)
	{
		PROVIDE(__INTTAB_CPU0 = .);

		/*PROTECTED REGION ID(Protection: iROM .inttab.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		*(.inttab) /*Section for interrupt table*/
		*(.inttab*)

		/*PROTECTED REGION ID(Protection: iROM .inttab) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__INTTAB_CPU0_END = .);
		. = ALIGN(8);

	} > PMU_PFLASH0 /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */

	/*
	 * Exception handling frame for C++ exceptions
	 */
	.eh_frame  :
	{
		PROVIDE(__eh_frame_start = .);

		/*PROTECTED REGION ID(Protection: iROM .eh_frame.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		*(.eh_frame) /*Exception handling frame for C++ exceptions*/
		*(.eh_frame*)

		/*PROTECTED REGION ID(Protection: iROM .eh_frame) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__eh_frame_end = .);
		. = ALIGN(8);

	} > PMU_PFLASH0 /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */




	/*Absolute Data-Sections*/

	/*
	 * Initialised data addressed as absolute
	 */
	.zdata  :
	{
		PROVIDE(__zdata_start = .);

		/*PROTECTED REGION ID(Protection: iROM .zdata.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		*(.zdata) /*Initialised data addressed as absolute*/
		*(.zdata*)
		*(.gnu.linkonce.z.*)
		*(.gnu.linkonce.zr.*)

		/*PROTECTED REGION ID(Protection: iROM .zdata) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__zdata_end = .);
		. = ALIGN(8);

	} > DMI_DSPR AT > PMU_PFLASH0 /* DMI_DSPR: Local Data RAM (DSPR) */ /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */

	/*
	 * Not initialised data addressed as absolute
	 */
	.zbss (NOLOAD) :
	{
		PROVIDE(__zbss_start = .);

		/*PROTECTED REGION ID(Protection: iROM .zbss.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		*(.zbss) /*Not Initialised data addressed as absolute*/
		*(.zbss*)
		*(.gnu.linkonce.zb.*)

		/*PROTECTED REGION ID(Protection: iROM .zbss) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__zbss_end = .);
		. = ALIGN(8);

	} > DMI_DSPR /* DMI_DSPR: Local Data RAM (DSPR) */

	/*
	 * Not initialised bit data
	 */
	.bbss (NOLOAD) :
	{
		PROVIDE(__bbss_start = .);

		/*PROTECTED REGION ID(Protection: iROM .bbss.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		*(.bbss) /*Not initialised bit data*/
		*(.bbss*)

		/*PROTECTED REGION ID(Protection: iROM .bbss) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__bbss_end = .);
		. = ALIGN(8);

	} > DMI_DSPR /* DMI_DSPR: Local Data RAM (DSPR) */

	/*
	 * Bit variables
	 */
	.bdata  :
	{
		PROVIDE(__bdata_start = .);

		/*PROTECTED REGION ID(Protection: iROM .bdata.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		*(.bdata) /*Bit variables*/
		*(.bdata*)

		/*PROTECTED REGION ID(Protection: iROM .bdata) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__bdata_end = .);
		. = ALIGN(8);

	} > DMI_DSPR AT > PMU_PFLASH0 /* DMI_DSPR: Local Data RAM (DSPR) */ /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */



	/*Small Data-Sections*/

	/*
	 * Storage of write-protected data addressed as small
	 */
	.sdata2  : FLAGS(arsl)
	{
		PROVIDE(__sdata2_start = .);

		/*PROTECTED REGION ID(Protection: iROM .sdata2.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		*(.srodata*)
		*(.sdata.rodata) /*Storage of write-protected data addressed as small*/
		*(.sdata.rodata*)
		*(.sdata2) /*Input section*/
		*(.sdata2*)
		*(.gnu.linkonce.sr.*)

		/*PROTECTED REGION ID(Protection: iROM .sdata2) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__sdata2_end = .);
		. = ALIGN(8);

	} > PMU_PFLASH0 /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */

	/*
	 * Section stores initialised data which is addressable by small data area pointer (%a0)
	 */
	.sdata  : FLAGS(awsl)
	{
		PROVIDE(__sdata_start = .);

		/*PROTECTED REGION ID(Protection: iROM .sdata.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		*(.sdata) /*Section stores initialised data which is addressable by small data area pointer (%a0)*/
		*(.sdata*)
		*(.gnu.linkonce.s.*)

		/*PROTECTED REGION ID(Protection: iROM .sdata) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__sdata_end = .);
		. = ALIGN(8);

	} > DMI_DSPR AT > PMU_PFLASH0 /* DMI_DSPR: Local Data RAM (DSPR) */ /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */

	/*
	 * Not initialised data in section ’.sbss’, addressable by small data area pointer (%a0)
	 */
	.sbss (NOLOAD) : FLAGS(aws)
	{
		PROVIDE(__sbss_start = .);

		/*PROTECTED REGION ID(Protection: iROM .sbss.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		*(.sbss) /*Not initialised data in section ’.sbss’, addressable by small data area pointer (%a0)*/
		*(.sbss*)
		*(.gnu.linkonce.sb.*)

		/*PROTECTED REGION ID(Protection: iROM .sbss) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__sbss_end = .);
		. = ALIGN(8);

	} > DMI_DSPR /* DMI_DSPR: Local Data RAM (DSPR) */



	/*Normal Data-Sections*/

	/*
	 * Storage of write-protected data
	 */
	.rodata  : FLAGS(arl)
	{
		PROVIDE(__rodata_start = .);

		/*PROTECTED REGION ID(Protection: iROM .rodata.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		*(.rodata) /*Storage of write-protected data*/
		*(.rodata*)
		*(.zrodata) /*Input section*/
		*(.zrodata*)
		*(.zdata.rodata) /*Input section*/
		*(.zdata.rodata*)
		*(.gnu.linkonce.r.*)
		*(.jcr.*)

		/*PROTECTED REGION ID(Protection: iROM .rodata) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__rodata_end = .);
		. = ALIGN(8);

	} > PMU_PFLASH0 /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */

	/*
	 * Initialised data
	 */
	.data  :
	{
		PROVIDE(__data_start = .);

		/*PROTECTED REGION ID(Protection: iROM .data.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		*(.data) /*Initialised data*/
		*(.data*)
		*(.gnu.linkonce.d.*)

		/*PROTECTED REGION ID(Protection: iROM .data) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__data_end = .);
		. = ALIGN(8);

	} > DMI_DSPR AT > PMU_PFLASH0 /* DMI_DSPR: Local Data RAM (DSPR) */ /* PMU_PFLASH0: Program Flash Memory (PFLASH0) */

	/*
	 * Not Initialised data
	 */
	.bss (NOLOAD) :
	{
		PROVIDE(__bss_start = .);

		/*PROTECTED REGION ID(Protection: iROM .bss.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		*(.bss) /*Not Initialised data*/
		*(.bss*)
		*(.gnu.linkonce.b.*)

		/*PROTECTED REGION ID(Protection: iROM .bss) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/

		PROVIDE(__bss_end = .);
		. = ALIGN(8);

	} > DMI_DSPR /* DMI_DSPR: Local Data RAM (DSPR) */





	/*
	 * Section for constructors
	 */
	.ctors          : FLAGS(al)
	{
		__CTOR_LIST__ = . ;

		/*PROTECTED REGION ID(Protection: iROMconstructor.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		LONG((__CTOR_END__ - __CTOR_LIST__) / 4 - 2);
		KEEP (*crtbegin.o(.ctors))
		KEEP (*(EXCLUDE_FILE (*crtend.o ) .ctors))
		KEEP (*(SORT(.ctors.*)))
		KEEP (*(.ctors))
		LONG(0) ;
		/*PROTECTED REGION ID(Protection: iROMconstructor) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		__CTOR_END__ = . ;
		 . = ALIGN(8);
	} > PMU_PFLASH0


	/*
	 * Section for destructors
	 */
	.dtors          : FLAGS(al)
	{
		__DTOR_LIST__ = . ;
		/*PROTECTED REGION ID(Protection: iROM destructor.begin) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		LONG((__DTOR_END__ - __DTOR_LIST__) / 4 - 2);
		KEEP (*crtbegin.o(.dtors))
		KEEP (*(EXCLUDE_FILE (*crtend.o ) .dtors))
		KEEP (*(SORT(.dtors.*)))
		KEEP (*(.dtors))
		LONG(0) ;
		/*PROTECTED REGION ID(Protection: iROM destructor) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		__DTOR_END__ = . ;
		. = ALIGN(8);
	} > PMU_PFLASH0


	/*
	 * Section for clear table
	 */
	.clear_sec : FLAGS(arl)
	{
		. = ALIGN(8);
		PROVIDE(__clear_table = .) ;
		LONG(0 + ADDR(.bss));	LONG(SIZEOF(.bss));
		LONG(0 + ADDR(.sbss));	LONG(SIZEOF(.sbss));
		LONG(0 + ADDR(.zbss));	LONG(SIZEOF(.zbss));
		LONG(0 + ADDR(.bbss));	LONG(SIZEOF(.bbss));
		/*PROTECTED REGION ID(Protection: iROM clear section) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		LONG(-1);                 LONG(-1);
	} > PMU_PFLASH0

	/*
	* Section for copy table
	*/
	.copy_sec : FLAGS(arl)
	{
		. = ALIGN(8);
		PROVIDE(__copy_table = .) ;
		LONG(LOADADDR(.data));	LONG(0 + ADDR(.data));	LONG(SIZEOF(.data));
		LONG(LOADADDR(.sdata));	LONG(0 + ADDR(.sdata));	LONG(SIZEOF(.sdata));
		LONG(LOADADDR(.zdata));	LONG(0 + ADDR(.zdata));	LONG(SIZEOF(.zdata));
		LONG(LOADADDR(.bdata));	LONG(0 + ADDR(.bdata));	LONG(SIZEOF(.bdata));
		/*PROTECTED REGION ID(Protection: iROM copy section) ENABLED START*/
			/*Protection-Area for your own LDF-Code*/
		/*PROTECTED REGION END*/
		LONG(-1);                 LONG(-1);                  LONG(-1);
	} > PMU_PFLASH0


	/*
	 * Section for ustack
	 */
	.ustack :
	{
		. = ALIGN(8);
		 __USTACK0_BEGIN = . ;
		. += __USTACK0_SIZE ;
		. = ALIGN(8);
		 __USTACK0 = . ;
		 __USTACK0_END = . ;
	} > DMI_DSPR

	/*
	 * Section for istack
	 */
	.istack :
	{
		. = ALIGN(8);
		 __ISTACK0_BEGIN = . ;
		. += __ISTACK0_SIZE ;
		. = ALIGN(8);
		 __ISTACK0 = . ;
		 __ISTACK0_END = . ;
	} > DMI_DSPR

	/*
	 * Section for heap
	 */
	.heap :
	{
		. = ALIGN(8);
		 __HEAP_BEGIN = . ;
		 __HEAP = . ;
		. += __HEAP_SIZE ;
		. = ALIGN(8);
		 __HEAP_END = . ;
	} > DMI_DSPR

	/*
	 * Section for CSA
	 */
	.csa :
	{
		. = ALIGN(64);
		 __CSA0_BEGIN = . ;
		 __CSA0 = . ;
		. += __CSA0_SIZE ;
		. = ALIGN(64);
		 __CSA0_END = . ;
	} > DMI_DSPR




	/*PROTECTED REGION ID(Protection:iROM-User-Sections) ENABLED START*/
		/*Protection-Area for your own LDF-Code*/
	/*PROTECTED REGION END*/

}

/* the following will be used by startup*/
__CSA0_SIZE = __CSA0_END - __CSA0_BEGIN;
	/* Make sure CSA, stack and heap addresses are properly aligned.  */
	_. = ASSERT ((__CSA0_BEGIN & 0x3f) == 0 , "illegal CSA start address");
	_. = ASSERT ((__CSA0_SIZE & 0x3f) == 0 , "illegal CSA size");
	_. = ASSERT ((__ISTACK0 & 7) == 0 , "ISTACK not doubleword aligned");
	_. = ASSERT ((__USTACK0 & 7) == 0 , "USTACK not doubleword aligned");

	/* Define a default symbol for address 0.  */
	NULL = DEFINED (NULL) ? NULL : 0;
_SMALL_DATA_ = SIZEOF(CORE_SEC(.sdata)) ? ADDR(CORE_SEC(.sdata)) + 32k : (ADDR(CORE_SEC(.sdata)) & 0xF0000000) + 32k ;
__A0_MEM = _SMALL_DATA_;


_SMALL_DATA2_ = SIZEOF(CORE_SEC(.sdata2)) ? ADDR(CORE_SEC(.sdata2)) + 32k : (ADDR(CORE_SEC(.sdata2)) & 0xF0000000) + 32k ;
__A1_MEM = _SMALL_DATA2_;
