#ifndef __TIMER_H__
#define __TIMER_H__

#include "chip.h"


// IR
#define IR_MR0_FLAG    (1<<0)
#define IR_MR1_FLAG    (1<<1)
#define IR_MR2_FLAG    (1<<2)
#define IR_MR3_FLAG    (1<<3)
#define IR_CR0_FLAG    (1<<4)

// TCR

// MCR
#define MCR_MR0I        (1<<0)  // �ж�
#define MCR_MR0R        (1<<1)  // ��λ
#define MCR_MR0S        (1<<2)  // ֹͣ
#define MCR_MR1I        (1<<3)  // �ж�
#define MCR_MR1R        (1<<4)  // ��λ
#define MCR_MR1S        (1<<5)  // ֹͣ
#define MCR_MR2I        (1<<6)  // �ж�
#define MCR_MR2R        (1<<7)  // ��λ
#define MCR_MR2S        (1<<8)  // ֹͣ
#define MCR_MR3I        (1<<9)  // �ж�
#define MCR_MR3R        (1<<10)  // ��λ
#define MCR_MR3S        (1<<11)  // ֹͣ

// CCR
#define CCR_CAP0RE      (1<<0)  // �����ز���ʹ��
#define CCR_CAP0FE      (1<<1)  // �½���
#define CCR_CAP0I       (1<<2)  // �ж�ʹ��

// EMR
#define EMR_EM0         (1<<0)
#define EMR_EM1         (1<<1)
#define EMR_EM2         (1<<2)
#define EMR_EM3         (1<<3)
#define EMR_EMC0_NONE   (0<<4)  // ������
#define EMR_EMC0_LOW    (1<<4)  // ���0
#define EMR_EMC0_HIG    (2<<4)  // ���1
#define EMR_EMC0_REV    (3<<4)  // �����ת
#define EMR_EMC1_NONE   (0<<6)  // ������
#define EMR_EMC1_LOW    (1<<6)  // ���0
#define EMR_EMC1_HIG    (2<<6)  // ���1
#define EMR_EMC1_REV    (3<<6)  // �����ת
#define EMR_EMC2_NONE   (0<<8)  // ������
#define EMR_EMC2_LOW    (1<<8)  // ���0
#define EMR_EMC2_HIG    (2<<8)  // ���1
#define EMR_EMC2_REV    (3<<8)  // �����ת
#define EMR_EMC3_NONE   (0<<10)  // ������
#define EMR_EMC3_LOW    (1<<10)  // ���0
#define EMR_EMC3_HIG    (2<<10)  // ���1
#define EMR_EMC3_REV    (3<<10)  // �����ת

// CTCR
#define CTCR_MODE_TIM     (0<0)   // ��ʱ��ģʽ
#define CTCR_MODE_RC      (1<0)   // �����ؼ���ģʽ
#define CTCR_MODE_FC      (2<0)   // �½��ؼ���ģʽ
#define CTCR_MODE_BC      (3<0)   // ˫���ؼ���ģʽ

// PWMC
#define PWMC_MAT0_EN    (1<<0)  // MAT0 PWMʹ��
#define PWMC_MAT1_EN    (1<<1)  // MAT1 PWMʹ��
#define PWMC_MAT2_EN    (1<<2)  // MAT2 PWMʹ��
#define PWMC_MAT3_EN    (1<<3)  // MAT3 PWMʹ��

void ct16b0_enable(void);
void ct16b0_disable(void);
void ct16b0_timer_init(uint32_t hz);
void ct16b0_pwn_init(void);
void ct16b0_set_match(uint32_t chanel, uint32_t match_val);
void ct16b1_timer_init(uint32_t hz);
void ct16b1_pwn_init(void);
void ct16b1_set_match(uint32_t chanel, uint32_t match_val);
void ct32b0_pwm_init(void);
void ct32b0_set_match(uint32_t chanel, uint32_t match_val);
void ct32b0_timer_init(uint32_t hz);

#endif

/******************************* (C) COPYRIGHT 2015 GAKATO ******************************/
/****************************************END OF FILE*************************************/


