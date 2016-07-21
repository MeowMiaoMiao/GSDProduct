#include "sys.h"
#include "board_time.h"
#include "board_wdt.h"

// ȫ�ֱ�������
static volatile tick_t _systick = 0;
static volatile tick_t _delayms_time = 0;
static volatile tick_t _timeout_time = 0;
volatile unsigned int lightsensor_tick;

void handler_delayms(void)
{
    if(_delayms_time != 0){
        _delayms_time--;
    }
}

void handler_timeout(void)
{
    if(_timeout_time != 0){
        _timeout_time--;
    }
}

/* ���붨ʱ��ע�� */
void handler_systick(void)
{
    // ϵͳ��ʱ
    _systick++;
    // ��ʱ
    handler_delayms();
    // ��ʱ
    handler_timeout();
}

void board_time_init(void)
{
    systick_init(1000); // ms��ʱ

    ct16b1_timer_init(40000);    // us��ʱ
}

tick_t board_time_get(void)
{
    return _systick;
}

void board_time_delay1ms(tick_t tim)
{
    _delayms_time = tim;
    while(_delayms_time != 0){
        board_wdt_feed();   // ι��
    }
}


void board_time_out_set(tick_t tim)
{
    _timeout_time = tim;
}

tick_t board_time_out_wait(void)
{
    return _timeout_time;
}

tick_t board_time_calc(tick_t tim_pre, tick_t tim_now)
{
    if(tim_now >= tim_pre){
        return tim_now - tim_pre;
    }else{
        return tim_now + MAX_TIME - tim_pre;
    }
}

/******************************* (C) COPYRIGHT 2015 GAKATO ******************************/
/****************************************END OF FILE*************************************/



