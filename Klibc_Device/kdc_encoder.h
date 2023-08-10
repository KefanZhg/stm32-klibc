/**
  ******************************************************************************
  * @date    Aug 7, 2023
  * @file    kdc_encoder.h
  * @author  Kefan Zheng
  * @brief   
  * @version V0.0.0
  * @contact kirk_z@yeah.net
  * @verbatim
  ==============================================================================
                        ##### How to use this driver #####
  ==============================================================================

  TODO: Pre-processing, LPF

  @endverbatim
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef KDC_ENCODER_H_
#define KDC_ENCODER_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "kdc.h"

/* Exported types ------------------------------------------------------------*/
typedef struct _KDC_Encoder_t {
    /* Common Read */
    float vRps;
    /* Common Config */
    TIM_HandleTypeDef* Port;
    int8_t Dir;
    uint32_t Tpr; // Tick per revolution
    /* Private */
    double vTps; // Tick per second
    int32_t pTick;
    uint32_t Last;
    TIM_TypeDef* Tim;
} KDC_Encoder_t;

/* Exported constants --------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/
#define KDC_Encoder_pRev(kecd) \
  (((float)(kecd)->pTick)/(kecd)->Tpr)

#define KDC_Encoder_vRps(kecd) \
  ((kecd)->vRps)

#define KDC_Encoder_vRpm(kecd) \
  ((kecd)->vRps*60.0)
/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

/* Initialization and de-initialization functions *****************************/
void KDC_Encoder_Clear(KDC_Encoder_t* kecd);
void KDC_Encoder_Start(KDC_Encoder_t* kecd);

/* Configuration functions ****************************************************/
void KDC_Encoder_Stop(KDC_Encoder_t* kecd);
void KDC_Encoder_Convert(KDC_Encoder_t* kecd);

/* IO operation functions *****************************************************/

/* State and Error functions **************************************************/

/* Private functions ---------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  /* KDC_ENCODER_H_ */

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdc_encoder.h ***/
