#include <stdio.h>
#include "timer.h"
#include "board_time.h"
#include "board_rs485.h"
#include "board_light.h"
#include "board_key.h"
#include "board_ir.h"
#include "board_led.h"
#include "board_time.h"
#include "ps.h"
#include "scr_key.h"
#include "door.h"

/*
 * func     UART0�ж�
 * param    none
 * retval   none
 */
void UART0_IRQHandler (void)
{
    handler_rs485();
}

/*
 * func     CT16B0��ʱ���ж�
 * param    none
 * retval   none
 */
void CT16B0_IRQHandler(void)
{

}

/*
 * func     CT16B1��ʱ���ж� 25us�ж�
 * param    none
 * retval   none
 */
void CT16B1_IRQHandler(void)
{
    if ( LPC_CT16B1->IR & IR_MR0_FLAG) {
        // ���ⶨʱ
        handler_ir_tick();
        handler_irps_send(); 
        LPC_CT16B1->IR = IR_MR0_FLAG;			// clear interrupt flag
    }
    return;
}

/*
 * func     SysTick �ж�
 * param    none
 * retval   none
 */
void SysTick_Handler(void)
{
    // ϵͳ��ʱ
    handler_systick();
    // ����ɨ��
    handler_key_scan();
    // ����
    handler_flash_led();
    // ת��
    handler_rotate_led();
    PsHandler();
    // RS485���ճ�ʱ
    handler_rs485_idle();
    // ���Ժ���ʱ
    WaitDelayHandler();
    DoorHander();
    
}

/*
 * func     GPIO0�ж�
 * param    none
 * retval   none
 */
void GPIO0_IRQHandler(void)
{
    // �����жϽ���
    handler_ir();
}

/******************************* (C) COPYRIGHT 2015 GAKATO ******************************/
/****************************************END OF FILE*************************************/


