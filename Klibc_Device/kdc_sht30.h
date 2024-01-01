/**
  ******************************************************************************
  * @date    May 26, 2023
  * @file    kdc_sht30.h
  * @author  Kefan Zheng
  * @brief   Driver for SHT30
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
#ifndef KLIBC_DEVICE_KDC_SHT30_H_
#define KLIBC_DEVICE_KDC_SHT30_H_

#ifdef __cplusplus
  extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "kdc.h"

#ifdef HAL_I2C_MODULE_ENABLED


/* Exported types ------------------------------------------------------------*/
/**
 * @brief  type of SHT30
*/
typedef struct _KDC_SHT30_t {
	I2C_HandleTypeDef *hi2c;
	I2C_TypeDef *i2c;
	uint16_t address;
	uint16_t temp;
	uint16_t hum;
} KDC_SHT30_t;

/* Exported constants --------------------------------------------------------*/
#define KDC_SHT30_Polynomial (UINT16_C(0x131))
#define KDC_SHT30_Default_Addr (0x44U << 1)

/* Exported macros -----------------------------------------------------------*/
/**
 * @brief  get temperature
 * @param  dsht  pointer to SHT30
 *
 * @retval uint16_t raw output about the temperature
*/
#define KDC_SHT30_GetTemp(__HANDLE__) \
	((__HANDLE__)->temp)

/**
 * @brief  get humidity
 * @param  dsht  pointer to SHT30
 *
 * @retval uint16_t raw output about the humidity
*/
#define KDC_SHT30_GetHum(__HANDLE__) \
  ((__HANDLE__)->hum)

/**
 * @brief  get temperature
 * @param  dsht  pointer to SHT30
 *
 * @retval float temperature
*/
#define KDC_SHT30_fGetTemp(__HANDLE__) \
  (((float)(__HANDLE__)->temp*175)/65535-45)


/**
 * @brief  get humidity
 * @param  dsht  pointer to SHT30
 *
 * @retval float humidity
*/
#define KDC_SHT30_fGetHum(__HANDLE__) \
  (((float)(__HANDLE__)->hum*100)/65535)

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

/* Initialization and de-initialization functions *****************************/
 KDC_State_t KDC_SHT30_Init(KDC_SHT30_t* dsht, I2C_HandleTypeDef *hi2c, uint16_t address);

/* Configuration functions ****************************************************/
KDC_State_t KDC_SHT30_Convert(KDC_SHT30_t* dsht);

/* IO operation functions *****************************************************/
/* State and Error functions **************************************************/
KDC_State_t KDC_SHT30_CheckCRC(uint8_t data[], uint8_t length, uint8_t checksum);

/* Private functions ---------------------------------------------------------*/

#endif

#ifdef __cplusplus
}
#endif

#endif  /* KLIBC_DEVICE_KDC_SHT30_H_ */

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdc_sht30.h ***/
