/**
******************************************************************************
* @file     main.c
* @author   AE team
* @version  V1.0.8
* @date     10/04/2019
* @brief
******************************************************************************
*/
#include "HAL_device.h"
#include "HAL_conf.h"


/********************************************************************************************************
**函数信息 ：main(void)
**功能描述 ：
**输入参数 ：无
**输出参数 ：无
********************************************************************************************************/

int main(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1;   //MCO  PB1
    GPIO_InitStructure.GPIO_Speed =  GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; // 推免复用输出
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_PinAFConfig( GPIOB, GPIO_PinSource1, GPIO_AF_5);

    RCC_MCOConfig(RCC_MCO_SYSCLK);  //通过PB1 pin 观察频率

    //PB1输出系统时钟输出
    while(1);
}

/**
* @}
*/

/**
* @}
*/

/**
* @}
*/

/*-------------------------(C) COPYRIGHT 2019 MindMotion ----------------------*/

