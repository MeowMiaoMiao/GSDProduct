#include "backlight.h"

sys_bl_t backlight_mode;                // ����ģʽ����

/*
 * func     �����ʼ��
 * param    none
 * retval   none
 */
void backlight_init(kg_cfg_t cfg)
{
    backlight_mode = cfg.bl_level;
}

/******************************* (C) COPYRIGHT 2015 GAKATO ******************************/
/****************************************END OF FILE*************************************/


