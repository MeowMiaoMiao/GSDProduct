#include "chip.h"
#include "wdt.h"

// ���Ź���ʼ��
void board_wdt_init(void)
{
    wdt_init();
}

// ι��
void board_wdt_feed(void)
{
    wdt_feed();
}
/******************************* (C) COPYRIGHT 2015 GAKATO ******************************/
/****************************************END OF FILE*************************************/


