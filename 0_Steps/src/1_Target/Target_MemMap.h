/*-------------------------------------------
   BMHs Sections
--------------------------------------------*/
#if defined (TARGET_START_SEC_BMH0)
  #undef TARGET_START_SEC_BMH0
  /* add pragma for memory allocation here */
  #if defined(__GNUC__)
	#pragma section
	#pragma section ".TARGET.BMH0" a
  #endif
  #if defined(__TASKING__)
	#pragma protect on
	#pragma section farrom ".TARGET.BMH0"
  #endif
  #ifdef CHK_TARGET_SEC_STARTED
    #error "TARGET section not closed"
  #endif
  #define CHK_TARGET_SEC_STARTED
  #define CHK_TARGET_SEC_BMH0_STARTED

#elif defined (TARGET_START_SEC_BMH1)
  #undef TARGET_START_SEC_BMH1
  /* add pragma for memory allocation here */
  #if defined(__GNUC__)
	#pragma section
	#pragma section ".TARGET.BMH1" a
  #endif
  #if defined(__TASKING__)
	#pragma protect on
	#pragma section farrom ".TARGET.BMH1"
  #endif
  #ifdef CHK_TARGET_SEC_STARTED
    #error "TARGET section not closed"
  #endif
  #define CHK_TARGET_SEC_STARTED
  #define CHK_TARGET_SEC_BMH1_STARTED

#elif defined (TARGET_START_SEC_BMH2)
  #undef TARGET_START_SEC_BMH2
  /* add pragma for memory allocation here */
  #if defined(__GNUC__)
	#pragma section
	#pragma section ".TARGET.BMH2" a
  #endif
  #if defined(__TASKING__)
	#pragma protect on
	#pragma section farrom ".TARGET.BMH2"
  #endif
  #ifdef CHK_TARGET_SEC_STARTED
    #error "TARGET section not closed"
  #endif
  #define CHK_TARGET_SEC_STARTED
  #define CHK_TARGET_SEC_BMH2_STARTED

#elif defined (TARGET_START_SEC_BMH3)
  #undef TARGET_START_SEC_BMH3
  /* add pragma for memory allocation here */
  #if defined(__GNUC__)
	#pragma section
	#pragma section ".TARGET.BMH3" a
  #endif
  #if defined(__TASKING__)
	#pragma protect on
	#pragma section farrom ".TARGET.BMH3"
  #endif
  #ifdef CHK_TARGET_SEC_STARTED
    #error "TARGET section not closed"
  #endif
  #define CHK_TARGET_SEC_STARTED
  #define CHK_TARGET_SEC_BMH3_STARTED


/*-------------------------------------------
   Trap Table Section
--------------------------------------------*/
#elif defined (TARGET_START_SEC_TRAPTAB0)
  #undef TARGET_START_SEC_TRAPTAB0
  /* add pragma for memory allocation here */
  #if defined(__GNUC__)
	#pragma section
	#pragma section ".TARGET.TrapTab0" awx
    #pragma GCC optimize ("-O2")
  #endif
  #if defined(__TASKING__)
	#pragma protect on
	#pragma section code ".TARGET.TrapTab0"
  #endif
  #ifdef CHK_TARGET_SEC_STARTED
    #error "TARGET section not closed"
  #endif
  #define CHK_TARGET_SEC_STARTED
  #define CHK_TARGET_SEC_TRAPTAB0_STARTED


/*-------------------------------------------
   HW Entry Section
--------------------------------------------*/
#elif defined (TARGET_START_SEC_HwEntry)
  #undef TARGET_START_SEC_HwEntry

    #if defined(__GNUC__)
		#pragma section
		#pragma section ".HwEntry" x
	#endif
	#if defined(__TASKING__)
		#pragma protect on
		#pragma section code "HwEntry"
	#endif
		#if defined(__DCC__)
		#pragma section CODE ".HwEntry" X
	#endif

  #ifdef CHK_TARGET_SEC_STARTED
    #error "TARGET section not closed"
  #endif
  #define CHK_TARGET_SEC_STARTED
  #define CHK_TARGET_SEC_HwEntry_STARTED


/*-------------------------------------------
   Code Section
--------------------------------------------*/
#elif defined (TARGET_START_SEC_CODE)
  #undef TARGET_START_SEC_CODE
  /* add pragma for memory allocation here */
  #if defined(__GNUC__)
	#pragma section
	#pragma section ".startup_code" x
  #endif
  #if defined(__TASKING__)
	#pragma protect on
	#pragma section code ".startup_code"
  #endif
  #ifdef CHK_TARGET_SEC_STARTED
    #error "TARGET section not closed"
  #endif
  #define CHK_TARGET_SEC_STARTED
  #define CHK_TARGET_SEC_CODE_STARTED

//---------------------------------------------------------------------
#elif defined (TARGET_START_SEC_XXXX)
  #undef TARGET_START_SEC_XXXX
  /* add pragma for memory allocation here */
  #if defined(__GNUC__)
	#pragma section
	#pragma section ".TARGET.XXX" x
  #endif
  #if defined(__TASKING__)
	#pragma protect on
	#pragma section code ".TARGET.XXX"
  #endif
  #ifdef CHK_TARGET_SEC_STARTED
    #error "TARGET section not closed"
  #endif
  #define CHK_TARGET_SEC_STARTED
  #define CHK_TARGET_SEC_XXXX_STARTED




/*-------------------------------------------
   STOP Sections
--------------------------------------------*/
#elif defined (TARGET_STOP_SEC_BMH0)
  #undef TARGET_STOP_SEC_BMH0
  /* add pragma for memory allocation to default section here */
  #if defined(__GNUC__)
    #pragma section
  #endif
  #if defined(__TASKING__)
	#pragma protect restore
	#pragma section farrom restore
  #endif
  #ifndef CHK_TARGET_SEC_BMH0_STARTED
    #error "TARGET_SEC_BMH0 not opened"
  #endif
  #undef CHK_TARGET_SEC_STARTED
  #undef CHK_TARGET_SEC_BMH0_STARTED

#elif defined (TARGET_STOP_SEC_BMH1)
  #undef TARGET_STOP_SEC_BMH1
  /* add pragma for memory allocation to default section here */
  #if defined(__GNUC__)
    #pragma section
  #endif
  #if defined(__TASKING__)
	#pragma protect restore
	#pragma section farrom restore
  #endif
  #ifndef CHK_TARGET_SEC_BMH1_STARTED
    #error "TARGET_SEC_BMH1 not opened"
  #endif
  #undef CHK_TARGET_SEC_STARTED
  #undef CHK_TARGET_SEC_BMH1_STARTED

#elif defined (TARGET_STOP_SEC_BMH2)
  #undef TARGET_STOP_SEC_BMH2
  /* add pragma for memory allocation to default section here */
  #if defined(__GNUC__)
    #pragma section
  #endif
  #if defined(__TASKING__)
	#pragma protect restore
	#pragma section farrom restore
  #endif
  #ifndef CHK_TARGET_SEC_BMH2_STARTED
    #error "TARGET_SEC_BMH2 not opened"
  #endif
  #undef CHK_TARGET_SEC_STARTED
  #undef CHK_TARGET_SEC_BMH2_STARTED

#elif defined (TARGET_STOP_SEC_BMH3)
  #undef TARGET_STOP_SEC_BMH3
  /* add pragma for memory allocation to default section here */
  #if defined(__GNUC__)
    #pragma section
  #endif
  #if defined(__TASKING__)
	#pragma protect restore
	#pragma section farrom restore
  #endif
  #ifndef CHK_TARGET_SEC_BMH3_STARTED
    #error "TARGET_SEC_BMH3 not opened"
  #endif
  #undef CHK_TARGET_SEC_STARTED
  #undef CHK_TARGET_SEC_BMH3_STARTED

#elif defined (TARGET_STOP_SEC_TRAPTAB0)
  #undef TARGET_STOP_SEC_TRAPTAB0
  /* add pragma for memory allocation to default section here */
  #if defined(__GNUC__)
    #pragma section
  #endif
  #if defined(__TASKING__)
	#pragma protect restore
	#pragma section farrom restore
  #endif
  #ifndef CHK_TARGET_SEC_TRAPTAB0_STARTED
    #error "TARGET_SEC_TRAPTAB0 not opened"
  #endif
  #undef CHK_TARGET_SEC_STARTED
  #undef CHK_TARGET_SEC_TRAPTAB0_STARTED

#elif defined (TARGET_STOP_SEC_HwEntry)
  #undef TARGET_STOP_SEC_HwEntry

	#if defined(__GNUC__)
		#pragma section
	#endif
	#if defined(__TASKING__)
		#pragma protect restore
		#pragma section farrom restore
	#endif
	#if defined(__DCC__)
		#pragma section CONST
	#endif

  #ifndef CHK_TARGET_SEC_HwEntry_STARTED
    #error "TARGET_SEC_HwEntry not opened"
  #endif
  #undef CHK_TARGET_SEC_STARTED
  #undef CHK_TARGET_SEC_HwEntry_STARTED

#elif defined (TARGET_STOP_SEC_CODE)
  #undef TARGET_STOP_SEC_CODE
  /* add pragma for memory allocation to default section here */
  #if defined(__GNUC__)
    #pragma section
  #endif
  #if defined(__TASKING__)
	#pragma protect restore
	#pragma section farrom restore
  #endif
  #ifndef CHK_TARGET_SEC_CODE_STARTED
    #error "TARGET_SEC_CODE not opened"
  #endif
  #undef CHK_TARGET_SEC_STARTED
  #undef CHK_TARGET_SEC_CODE_STARTED

//---------------------------------------------------------------------
#elif defined (TARGET_STOP_SEC_XXXX)
  #undef TARGET_STOP_SEC_XXXX
  /* add pragma for memory allocation to default section here */
  #if defined(__GNUC__)
    #pragma GCC reset_options
    #pragma section
  #endif
  #if defined(__TASKING__)
	#pragma protect restore
	#pragma section code restore
  #endif
  #ifndef CHK_TARGET_SEC_XXXX_STARTED
    #error "TARGET_SEC_XXXX not opened"
  #endif
  #undef CHK_TARGET_SEC_STARTED
  #undef CHK_TARGET_SEC_XXXX_STARTED


/*-------------------------------------------
   ERROR Sections
--------------------------------------------*/
#else
  #error "Error: section does not exist in TARGET_MemMap.h"
#endif
