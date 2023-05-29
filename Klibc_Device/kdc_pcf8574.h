/**
  ******************************************************************************
  * @date    May 26, 2023
  * @file    kdc_pcf8574.h
  * @author  Kefan Zheng
  * @brief   Driver for PCF8574
  * @version V0.0.0
  * @contact kirk_z@yeah.net
  @verbatim
  ==============================================================================
                        ##### How to use this driver #####
  ==============================================================================


  @endverbatim
  ******************************************************************************
  * @attention
  *     The INT function has not been implemented.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef KLIBC_DEVICE_KDC_PCF8574_H_
#define KLIBC_DEVICE_KDC_PCF8574_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "kdc.h"

#ifdef HAL_I2C_MODULE_ENABLED

/* Exported types ------------------------------------------------------------*/
/**
 * @brief structure for PCF8574
 */
typedef struct _KDC_PCF8574_t {
	I2C_HandleTypeDef *hi2c;
	I2C_TypeDef *i2c;
	uint16_t address;
	uint8_t output;
	volatile uint8_t input;
} KDC_PCF8574_t;

/* Exported constants --------------------------------------------------------*/
#define KDC_PCF8574_Default_Addr (0x20U << 1)

/* Exported macros -----------------------------------------------------------*/
/**
 * @brief  get current value
 * @note   directly from buffer
 */
#define KDC_PCF8574_Get(__HANDLE__) ((__HANDEL__)->input)

/**
 * @brief  set bits
 * @param  dpcf  pointer to PCF8574
 * @param  bits  bits in order
 *
 * @retval uint8_t current IO state
*/
#define KDC_PCF8574_Set(__HANDLE__,__BITS__) \
  KDC_PCF8574_Write((__HANDLE__), (__HANDLE__)->output | ((__BITS__)))

/**
 * @brief  reset bits
 * @param  dpcf  pointer to PCF8574
 * @param  bits  bits in order
 *
 * @retval uint8_t current IO state
*/
#define KDC_PCF8574_Reset(__HANDLE__,__BITS__) \
  KDC_PCF8574_Write((__HANDLE__), (__HANDLE__)->output & (~((__BITS__))))

/**
 * @brief  read IO and toggle bit
 * @param  dpcf  pointer to PCF8574
 * @param  bits  bits in order
 *
 * @retval uint8_t current IO state
*/
#define PCF8574_Toggle(__HANDLE__,__BITS__) \
  KDC_PCF8574_Write((__HANDLE__), (__HANDEL__)->output ^ (__BITS__))


/**
 * @brief  read IO in bit
 * @param  dpcf  pointer to PCF8574
 * @param  bit   bit order
 *
 * @retval uint8_t high or low
*/
#define KDC_PCF8574_ReadBit(__HANDLE__,__BIT__) \
  (KDC_PCF8574_Read((__HANDLE__)) & (1<<(__BIT__)) ? 1:0 )


/**
 * @brief  read IO and set bit
 * @param  dpcf  pointer to PCF8574
 * @param  bit  bit order
 * @param  data  high or low
 *
 * @retval uint8_t current IO state
*/
#define KDC_PCF8574_WriteBit(__HANDLE__,__BIT__,__DATA__) \
  ((__DATA__) ? KDC_PCF8574_Set((__HANDLE__),1<<(__BIT__)) : KDC_PCF8574_Reset((__HANDLE__),1<<(__BIT__)))

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

/* Initialization and de-initialization functions *****************************/
 KDC_State_t KDC_PCF8574_Init(KDC_PCF8574_t* dpcf, I2C_HandleTypeDef *hi2c, uint16_t address);

/* Configuration functions ****************************************************/

/* IO operation functions *****************************************************/
uint8_t KDC_PCF8574_Read(KDC_PCF8574_t* dpcf);
uint8_t KDC_PCF8574_Write(KDC_PCF8574_t* dpcf, uint8_t data);

/* State and Error functions **************************************************/

/* Private functions ---------------------------------------------------------*/

#endif

#ifdef __cplusplus
}
#endif

#endif  /* KLIBC_DEVICE_KDC_PCF8574_H_ */

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdc_pcf8574.h ***/
