#ifndef __BSP_BASE_TIM_H__
#define __BSP_BASE_TIM_H__

/* 包含头文件 ----------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
 
/* 宏定义 --------------------------------------------------------------------*/
/********************基本定时器TIM参数定义，只限TIM6 & TIM7************/

#define BASIC_TIMx                     TIM6
#define BASIC_TIM_RCC_CLK_ENABLE()     __HAL_RCC_TIM6_CLK_ENABLE()
#define BASIC_TIM_RCC_CLK_DISABLE()    __HAL_RCC_TIM6_CLK_DISABLE()
#define BASIC_TIM_IRQ                  TIM6_DAC_IRQn
#define BASEC_TIM_IRQHandler              TIM6_DAC_IRQHandler


// 定义定时器预分频，定时器实际时钟频率为：84MHz/（BASIC_TIMx_PRESCALER+1）
#define BASIC_TIMx_PRESCALER           83  // 实际时钟频率为：1MHz
// 定义定时器周期，当定时器开始计数到BASIC_TIMx_PERIOD值是更新定时器并生成对应事件和中断
#define BASIC_TIMx_PERIOD              (1000-1)  // 定时器产生中断频率为：1MHz/1000=1KHz，即1ms定时周期
                                                 // BASIC_TIMx_PERIOD设置为100-1那么 1MHz/100=10KHz 即为 0.1ms = 100us ,

// 最终定时器频率计算为： 84MHz/（BASIC_TIMx_PRESCALER+1）/(BASIC_TIMx_PERIOD+1)
// 比如需要产生0.1ms周期定时，可以设置为： 84MHz/（83+1）/100=10kHz，即0.1ms周期 即100us
// 比如需要产生1ms周期定时，可以设置为： 84MHz/（83+1）/1000=1kHz，即1ms周期
// 比如需要产生10ms周期定时，可以设置为： 84MHz/（83+1）/10000=100Hz，即10ms周期
// 比如需要产生20ms周期定时，可以设置为： 84MHz/（83+1）/20000=50Hz，即20ms周期
// 这里设置 BASIC_TIMx_PRESCALER=83；BASIC_TIMx_PERIOD=1000-1； 
                                             

// 1ms = 1000us 那么现在计算100微秒，即0.1ms = 100us

// 1000Hz 为1ms周期，那么100us的周期对应 1000Hz / 0.1 = 10000Hz 即 10KHz对应100us ;
// 最终要得到10KHz的中断频率，反推回去 
// 10000Hz * 1000 = 10000000Hz = 10MHz
// 10MHz/1000 = 10KHz 即100us;


/* 扩展变量 ------------------------------------------------------------------*/
extern TIM_HandleTypeDef htimx;
/* 函数声明 ------------------------------------------------------------------*/

void BASIC_TIMx_Init(void);

#endif	