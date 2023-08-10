/**
  ******************************************************************************
  * @date    Aug 7, 2023
  * @file    kdc_tb6612.h
  * @author  Kefan Zheng
  * @brief   
  * @version V0.0.0
  * @contact kirk_z@yeah.net
  * @verbatim
  ==============================================================================
                        ##### How to use this driver #####
  ==============================================================================


  @endverbatim
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef KDC_TB6612_H_
#define KDC_TB6612_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "kdc.h"
#include "kdc_pin.h"

#ifdef HAL_GPIO_MODULE_ENABLED
#ifdef HAL_TIM_MODULE_ENABLED

/* Exported types ------------------------------------------------------------*/
typedef struct _KDC_TB6612_t {
    /* Common Read */
    float Speed;
    /* Common Config */

    /* Private */
    int8_t Dir;
    TIM_HandleTypeDef *Port;
    uint32_t Channel;
    uint8_t Complement;
    KDC_Pin_t Pin1, Pin2;
} KDC_TB6612_t;
/* Exported constants --------------------------------------------------------*/
#define KDC_TB6612_Default_Config  \
{                                  \
  .Speed = 0,                      \
  .Dir = 0,                        \
}

/* Exported macros -----------------------------------------------------------*/
#define KDC_TB6612_SetPort(ktb,port,chn,com) \
    {(ktb)->Port=(port);(ktb)->Channel=(chn);(ktb)->Complement=(com);}

#define KDC_TB6612_SetPin1(ktb,port,pin) \
    KDC_Pin_Init(&((ktb)->Pin1),(port),(pin))

#define KDC_TB6612_SetPin2(ktb,port,pin) \
    KDC_Pin_Init(&((ktb)->Pin2),(port),(pin))

#define KDC_TB6612_SetSpeed(ktb,speed) \
    {(ktb)->Speed=(speed);KDC_TB6612_Refresh((ktb));}

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

/* Initialization and de-initialization functions *****************************/
void KDC_TB6612_Start(KDC_TB6612_t* ktb);
void KDC_TB6612_Stop(KDC_TB6612_t* ktb);

/* Configuration functions ****************************************************/

/* IO operation functions *****************************************************/
void KDC_TB6612_Refresh(KDC_TB6612_t *ktb);

/* State and Error functions **************************************************/

/* Private functions ---------------------------------------------------------*/

#endif /* HAL_TIM_MODULE_ENABLED */
#endif /* HAL_GPIO_MODULE_ENABLED */

#ifdef __cplusplus
}
#endif

#endif  /* KDC_TB6612_H_ */

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdc_tb6612.h ***/
