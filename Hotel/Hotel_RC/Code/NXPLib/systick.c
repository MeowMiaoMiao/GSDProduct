#include "chip.h"

// ���õ��ⲿ����
extern uint32_t SystemCoreClock;

void systick_init(uint32_t hz)
{
    SysTick_Config(SystemCoreClock/hz);   //  HZ
}

/******************************* (C) COPYRIGHT 2015 GAKATO ******************************/
/****************************************END OF FILE*************************************/


