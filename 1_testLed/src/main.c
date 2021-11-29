#include "Std_Types.h"
#include "IfxPort.h"
//#include "STM_System_Time.h"
#include "IfxStm.h"

#define LED         &MODULE_P00,5                                           /* LED: Port, Pin definition            */
#define WAIT_TIME   2000


void User_Init(void);
void User_SuperLoop(void);
void User_1MsTask(void);
void User_5MsTask(void);
void User_10MsTask(void);

void main(void)
{

	uint32 CurrentStm0Ticks=0;
	uint32 LastStm0Ticks=0;
	uint32 TicksDifference=0;
	uint32 TicksPerMs=0;
	uint32 MsCounter=0;

	User_Init();

	TicksPerMs=IfxStm_getFrequency(&MODULE_STM0)/1000;
	LastStm0Ticks=IfxStm_getLower(&MODULE_STM0);

	while(1)
	{
		User_SuperLoop();

		CurrentStm0Ticks=IfxStm_getLower(&MODULE_STM0);
		TicksDifference=CurrentStm0Ticks-LastStm0Ticks;

		if(TicksDifference>=TicksPerMs)
		{
			LastStm0Ticks=IfxStm_getLower(&MODULE_STM0);
			MsCounter++;
			User_1MsTask();

			if((MsCounter % 5) ==0)
			{
				void User_5MsTask();
			}
			else if((MsCounter % 10) ==0)
			{
				void User_10MsTask();
			}
		}
	}
}


void User_Init(void)
{
	/* Initialization of the LED used in this example */
	IfxPort_setPinModeOutput(LED, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);

	/* Switch OFF the LED (low-level active) */
	IfxPort_setPinHigh(LED);
}

void User_SuperLoop(void)
{

}

void User_1MsTask(void)
{
	static uint32 Tmp1Mscounter=0;
	Tmp1Mscounter++;
	if((Tmp1Mscounter % 1000) ==0)
	{
		IfxPort_togglePin(LED);
	}
}

void User_5MsTask(void)
{

}

void User_10MsTask(void)
{

}


