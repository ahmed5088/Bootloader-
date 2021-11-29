#include "Std_Types.h"
#include "TargetAbstr_Cfg.h"

/*******************************************************************************
**                      Boot Mode Headers                                     **
*******************************************************************************/

#if (Target_UseBMH0 == STD_ON)
    #define TARGET_START_SEC_BMH0
    #include "Target_MemMap.h"

	const uint32 BootModeHeader_0[] = {
		0x00000000u,                 /* STADBM first user code at 0x8000 0020h */
    	0xb3590070u,                 /* BMI = 0070h BMHDID = B359h */
    	0x00000000u,                 /* ChkStart */
    	0x00000000u,                 /* ChkEnd */
    	0x00000000u,                 /* CRCrange */
    	0x00000000u,                 /* !CRCrange */
    	0x791eb864u,                 /* CRChead */
    	0x86e1479bu                  /* !CRChead */
	};
	//Reminder to implement BMH0. Comment this line after implementation
	//#error "BMH0 enabled but not implemented"

    #define TARGET_STOP_SEC_BMH0
    #include "Target_MemMap.h"
#endif


#if(Target_UseBMH1 == STD_ON)
    #define TARGET_START_SEC_BMH1
    #include "Target_MemMap.h"

	const uint32 BootModeHeader_1[] = {
		//BMH1 here
	};
	//Reminder to implement BMH1. Comment this line after implementation
	#error "BMH1 enabled but not implemented"

    #define TARGET_STOP_SEC_BMH1
    #include "Target_MemMap.h"
#endif


#if (Target_UseBMH2 == STD_ON)
    #define TARGET_START_SEC_BMH2
    #include "Target_MemMap.h"

	const uint32 BootModeHeader_2[] = {
		//BMH2 here
	};
	//Reminder to implement BMH2. Comment this line after implementation
	#error "BMH2 enabled but not implemented"

    #define TARGET_STOP_SEC_BMH2
    #include "Target_MemMap.h"
#endif


#if (Target_UseBMH3 == STD_ON)
    #define TARGET_START_SEC_BMH3
    #include "Target_MemMap.h"

	const uint32 BootModeHeader_3[] = {
		//BMH3 here
	};
	//Reminder to implement BMH3. Comment this line after implementation
	#error "BMH3 enabled but not implemented"

    #define TARGET_STOP_SEC_BMH3
    #include "Target_MemMap.h"
#endif
