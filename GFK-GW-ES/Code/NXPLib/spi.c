#include "chip.h"
/*
typedef struct {                                    // (@ 0x40040000) SSP0 Structure
  __IO uint32_t  CR0;                               // (@ 0x40040000) Control register 0. Selects the serial clock
                                                    //   rate, bus type, and data size.
  __IO uint32_t  CR1;                               // (@ 0x40040004) Control register 1. Selects master/slave and
                                                    //   other modes.
  __IO uint32_t  DR;                                // (@ 0x40040008) Data register. Writes fill the transmit FIFO,
                                                    //   and reads empty the receive FIFO.
  __I  uint32_t  SR;                                // (@ 0x4004000C) Status register
  __IO uint32_t  CPSR;                              // (@ 0x40040010) Clock Prescale register
  __IO uint32_t  IMSC;                              // (@ 0x40040014) Interrupt Mask Set and Clear register
  __I  uint32_t  RIS;                               // (@ 0x40040018) Raw Interrupt Status register
  __I  uint32_t  MIS;                               // (@ 0x4004001C) Masked Interrupt Status register
  __O  uint32_t  ICR;                               // (@ 0x40040020) SSPICR Interrupt Clear register
} LPC_SSP0_Type;
*/

#include "spi.h"

void spi0_master_init(void)
{

    // ��������

    // ��������
    syscon_ahb_enable(SYSCON_CLK_SSP0);                                 // ��SPI0���� 
    syscon_spi0_div(1);                                                 // SSP_PCLKʱ�ӷ�Ƶ
    syscon_ppp_reset_dis(SYSCON_PPP_SSP0_RST_N);                        // ��ֹSPI0��λ   

    LPC_SSP0->CR0 = (0x01 << 8) |                                       // SCR  ����BIT_CLKʱ�ӷ�Ƶ
                    (0x01 << 7) |                                       //  CPHA ʱ�������λ,
                                                                        //  ��SPIģʽ��Ч
                    (0x01 << 6) |                                       //  CPOL ʱ���������,
                                                                        //  ��SPIģʽ��Ч
                    (0x00 << 4) |                                       //  FRF  ֡��ʽ 00=SPI,01=SSI,
                                                                        //  10=Microwire,11=����
                    (0x07 << 0);                                        //  DSS  ���ݳ���,0000-0010=����,
                                                                        //  0011=4λ,0111=8λ,1111=16λ

    LPC_SSP0->CR1 = (0x00 << 3) |                                       //  SOD  �ӻ��������,1=��ֹ
                    (0x00 << 2) |                                       //  MS   ����ѡ��,0=����,1=�ӻ�
                    (0x01 << 1) |                                       //  SSE  SSPʹ��
                    (0x00 << 0);                                        //  LBM  ��дģʽ

    LPC_SSP0->CPSR = 2;                                                 //  SSPCLK��Ƶֵ
    LPC_SSP0->ICR  = SSP_ICR_RORIC|SSP_ICR_RTIC;                        //  �ж�����Ĵ���

    NVIC_EnableIRQ(SSP0_IRQn);
    NVIC_SetPriority(SSP0_IRQn, 2);                                     //   �ж�ʹ�ܲ��������ȼ�
    LPC_SSP0->IMSC |= SSP_IMSC_RXIM;                                    //   �ж�ʹ�ܼĴ���
} 

uint8_t spi0_send_byte(uint8_t data)
{  
    LPC_SSP0->DR = data;
    while( (LPC_SSP0->SR & (SSP_SR_BSY)) == 0 );                            
    return(LPC_SSP0->DR);
}

void spi0_slave_init(void)
{

}

void spi1_master_init(void)
{

}

void spi1_slave_init(void)
{

}

/******************************* (C) COPYRIGHT 2015 GAKATO ******************************/
/****************************************END OF FILE*************************************/


