/**
  ******************************************************************************
  * @date    Mar 19, 2023
  * @file    kdc_pin.h
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
#ifndef KDC_PIN_H_
#define KDC_PIN_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "kdc.h"

#ifdef HAL_GPIO_MODULE_ENABLED

/* Exported types ------------------------------------------------------------*/
/**
 * @brief  structure of pin collector
*/
typedef struct _KDC_Pin_t {
	GPIO_TypeDef* Port;
	uint16_t Pin;
} KDC_Pin_t;

/* Exported constants --------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

/* Initialization and de-initialization functions *****************************/
/**
 * @brief  Initialize the pin
*/
#define KDC_Pin_Init(dpin,port,pin) \
		{(dpin)->Port=(port);(dpin)->Pin=(pin);}

/**
 * @brief  Set the pin to 1
*/
#define KDC_Pin_Set(dpin) \
    (dpin)->Port->BSRR = (uint32_t)(dpin)->Pin
		// HAL_GPIO_WritePin((dpin)->port,(dpin)->pin,GPIO_PIN_SET)

/**
 * @brief  Reset the pin to 0
*/
#define KDC_Pin_Reset(dpin) \
    (dpin)->Port->BRR = (uint32_t)(dpin)->Pin
	//	HAL_GPIO_WritePin((dpin)->port,(dpin)->pin,GPIO_PIN_RESET)

/**
 * @brief  Toggle the pin output
*/
#define KDC_Pin_Toggle(dpin) \
		(dpin)->Port->ODR ^= (dpin)->Pin

/**
 * @brief  Write the pin to a designated level
*/
#define KDC_Pin_Write(dpin,level) \
		HAL_GPIO_WritePin((dpin)->Port,(dpin)->Pin,(level)?GPIO_PIN_SET:GPIO_PIN_RESET)

/**
 * @brief  Read the current pin level
*/
#define KDC_Pin_Read(dpin) \
		((dpin)->Port->IDR & (dpin)->Pin) ? GPIO_PIN_SET:GPIO_PIN_RESET

/* Configuration functions ****************************************************/

/* IO operation functions *****************************************************/
/* State and Error functions **************************************************/

/* Private functions ---------------------------------------------------------*/

#endif

#ifdef __cplusplus
}
#endif

#endif  /* KDC_PIN_H_ */

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdc_pin.h ***/
