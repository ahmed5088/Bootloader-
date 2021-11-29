#include "Std_Types.h"
#include "IfxPort.h"
#include "Bsp.h"
#define LED         &MODULE_P00,5                                           /* LED: Port, Pin definition            */
#define WAIT_TIME   100

void main(void)
{

	/* Initialization of the LED used in this example */
	IfxPort_setPinModeOutput(LED, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);

	/* Switch OFF the LED (low-level active) */
	IfxPort_setPinHigh(LED);


	while(1)
	{
		IfxPort_togglePin(LED);                                                     /* Toggle the state of the LED      */
		waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, WAIT_TIME));    /* Wait 500 milliseconds            */
	}
}
