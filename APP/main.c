#include "led.h"
#include "std_types.h"

void APP_timer0ACallBack(void);
void APP_LedOnAndOff(uint8 onTime, uint8 offTime);

uint8 g_tick = 0;   /* global variable to count the seconds */

int main (void)
{
    uint8 onTime  = 8;
    uint8 offTime = 4;
    LED_initPeriphrals(APP_timer0ACallBack);  /* LED driver that initialize all the periphrals */

    while (1)
    {
       APP_LedOnAndOff(onTime, offTime);
    }
}

void APP_timer0ACallBack(void)
{
	g_tick++;
}

void APP_LedOnAndOff(uint8 onTime, uint8 offTime)
{
	 LED_setOn();
	 while(g_tick < onTime);
	 g_tick = 0;
   LED_setOff();
   while(g_tick < offTime);
	 g_tick = 0;
}