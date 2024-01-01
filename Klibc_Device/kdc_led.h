/**
  ******************************************************************************
  * @date    Mar 18, 2023
  * @file    kdc_led.h
  * @author  Kefan Zheng
  * @brief   
  * @version V0.0.0
  * @contact kirk_z@yeah.net
  @verbatim
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
#ifndef KDC_LED_H_
#define KDC_LED_H_

#ifdef __cplusplus
  extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "kdc.h"

#ifdef HAL_GPIO_MODULE_ENABLED

/* Exported types ------------------------------------------------------------*/
/**
 * @brief  enumerating LED on status
*/
typedef enum {
  KDC_LED_ONSTATE_LOW = 0,
  KDC_LED_ONSTATE_HIGH
} KDC_LED_OnState;

/**
 * @brief  enumerating LED status
*/
typedef enum {
  KDC_LED_OFF = 0,
  KDC_LED_ON
} KDC_LED_State;

/**
 * @brief  driver type of LED
*/
typedef enum {
  KDC_LED_DRtype_GPIO      = 0,
#ifdef HAL_TIM_MODULE_ENABLED
  KDC_LED_DRtype_PWM       = 1,
  KDC_LED_DRtype_PairedPWM = 2,
  KDC_LED_DRtype_CompPWM   = 3
#endif
} KDC_LED_DRtype;

/**
 * @brief  type of LED
*/
typedef struct _KDC_LED_t {
  KDC_LED_DRtype Type;
  GPIO_TypeDef* Port;
  uint16_t Pin;
  KDC_LED_State Onstate;

#ifdef HAL_TIM_MODULE_ENABLED
  TIM_HandleTypeDef *tPort;
  uint32_t Channel[2];

  uint16_t Brightness;
  uint16_t Brightness_Range;

  uint16_t Bound;
  uint16_t Bound_Range;

  uint16_t Proportion;
  uint16_t Proportion_Range;

  uint32_t AutoReloadValue;

  uint16_t Gamma; /* 20K times of Gamma.  2.2 * 20K = 44K */
#endif
} KDC_LED_t;

/* Exported constants --------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/
#define KDC_LED_GAMMA_SCALER 20000U
#define KDC_LED_DEFAULT_GAMMA 44000U /* 2.2*20K=44K */
#define KDC_LED_DEFAULT_BRIGHTNESSRANGE 255U
#define KDC_LED_DEFAULT_BOUNDRANGE 255U
#define KDC_LED_DEFAULT_PROPORTIONRANGE 100U

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

/* Initialization and de-initialization functions *****************************/
void KDC_LED_Init(KDC_LED_t *dled, GPIO_TypeDef* port, uint16_t pin, KDC_LED_State onstate);

#ifdef HAL_TIM_MODULE_ENABLED

void KDC_LED_PWMInit(KDC_LED_t* dled, TIM_HandleTypeDef* port, uint32_t channel, KDC_LED_OnState onstat, uint8_t complement);
void KDC_LED_PairInit(KDC_LED_t* dled, TIM_HandleTypeDef* port, uint32_t channel_low, uint32_t channel_high);

#endif

/* Configuration functions ****************************************************/

/* IO operation functions *****************************************************/
void KDC_LED_TurnOn(KDC_LED_t *dled);
void KDC_LED_TurnOff(KDC_LED_t *dled);
void KDC_LED_Toggle(KDC_LED_t *dled);
void KDC_LED_Turn(KDC_LED_t *dled, KDC_LED_State state);

#ifdef HAL_TIM_MODULE_ENABLED

void KDC_LED_SetBrightness(KDC_LED_t* dled, uint16_t brightness);
void KDC_LED_SetBrightnessRange(KDC_LED_t* dled, uint16_t range);
void KDC_LED_SetBound(KDC_LED_t* dled, uint16_t bound);
void KDC_LED_SetBoundRange(KDC_LED_t* dled, uint16_t range);
void KDC_LED_SetGamma(KDC_LED_t* dled, float gamma);
void KDC_LED_Refresh(KDC_LED_t* dled);

void KDC_LED_SetProportion(KDC_LED_t* dled, uint16_t proportion);
void KDC_LED_IncProportion(KDC_LED_t* dled, uint16_t proportion);
void KDC_LED_DecProportion(KDC_LED_t* dled, uint16_t proportion);
void KDC_LED_SetProportionRange(KDC_LED_t* dled, uint16_t range);

#endif

/* State and Error functions **************************************************/

/* Private functions ---------------------------------------------------------*/

#endif

#ifdef __cplusplus
}
#endif

#endif  /* KDC_LED_H_ */

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdc_led.h ***/
