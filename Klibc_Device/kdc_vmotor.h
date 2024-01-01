/**
  ******************************************************************************
  * @date    Aug 7, 2023
  * @file    kdc_vmotor.h
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
#ifndef KDC_VMOTOR_H_
#define KDC_VMOTOR_H_

#ifdef __cplusplus
  extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "kdc.h"

/* Exported types ------------------------------------------------------------*/
typedef struct _KDC_vMotor_Encoder_t {
  /* Common Read */
  float vRps;
  /* Common Config */
  TIM_HandleTypeDef* Port;
  int8_t Dir;
  uint32_t Tpr; // Tick per revolution
} KDC_vMotor_Encoder_t;

typedef struct _KDC_vMotor_Driver_t {
  /* Common Read */
  float Speed;
  /* Common Config */

} KDC_vMotor_Driver_t;

typedef struct _KDC_vMotor_t {
  KDC_vMotor_Encoder_t *Encoder;
  KDC_vMotor_Driver_t *Driver;
  float Target;
} KDC_vMotor_t;
/* Exported constants --------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

/* Initialization and de-initialization functions *****************************/

/* Configuration functions ****************************************************/

/* IO operation functions *****************************************************/
/* State and Error functions **************************************************/

/* Private functions ---------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  /* KDC_VMOTOR_H_ */

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdc_vmotor.h ***/
