#include "std_types.h"
#include "intctrl_interface.h"
#include "sysctrl_interface.h"
#include "port_interface.h"
#include "dio_interface.h"
#include "gpt_interface.h"
#include "led.h"

void LED_initPeriphrals(void(*a_CallBackptr)(void))
{
	  /* enable interrupts in NVIC for timer0 */
    IntrCfg_ConfigTypes IntCtrl_Cfg[1] = {
    {TIMER0A_16_32_BIT, GROUP_LEVEL0, SUB_GROUP_LEVEL0, ENABLE}
    };
    INTCTRL_init(IntCtrl_Cfg);

		/* enable internal oscillator to the system to be the system clock 
		 * enable gpio portF and timer0 clock gates 
		 */
    SysCtrl_CfgTypes SysCtrl_Cfg = {
    PIOSC,
    NO_EXTERNAL_CRYSTAL,
    SYS_CLK_FREQ_DIV_1
    };
    SysCtrl_PheriphralCfgTypes SysCtr_PeripheralCfg[2] =
    {
    {GPIO_PERIPH_CLOCK_GATE, GPIO_PORTF_CLOCK_GATE},
    {TIMER_16_32_PERIPH_CLOCK_GATE, TIMER0_16_32_CLOCK_GATE}
    };
    SYSCTRL_init(&SysCtrl_Cfg);
    SYSCTRL_periphralEnableClock(SysCtr_PeripheralCfg);
    
		/* configure pin F1 as DIO output pin and disable its interrrupt */ 
    Port_CfgType Port_Cfg[1] = 
    {
    {PORT_CHANNEL_F1, OUTPUT, NO_ATTACH, PIN_X_MODE_DIO, CURRENT_2mA, INTERRUPT_DISABLE}
    };
    PORT_init(Port_Cfg);

		/* initialize timer0 16/32 bit with periodic, concatenate modes
		 * set the call back function to the app layer timer0 function
		 * enable interrupt for timer0 and start the timer to count 1 sec
     */		
    Gpt_ConfigType Gpt_Config[1] =
    {
        {GPT_16_32_BIT_TIMER0, PERIODIC, CONCATENATE_TIMERS, 0, a_CallBackptr}
    };
    GPT_init(Gpt_Config);
    GPT_enableNotification(GPT_16_32_BIT_TIMER0);
   	GPT_startTimer(GPT_16_32_BIT_TIMER0, 5000000);
}

void LED_setOn(void)
{
    DIO_writeChannel(DIO_CHANNEL_F1, HIGH);
}

void LED_setOff(void)
{
    DIO_writeChannel(DIO_CHANNEL_F1, LOW);
}