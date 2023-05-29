/**
  ******************************************************************************
  * @date    May 26, 2023
  * @file    kdc_bh1750.h
  * @author  Kefan Zheng
  * @brief   Driver for BH1750
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
#ifndef KLIBC_DEVICE_KDC_BH1750_H_
#define KLIBC_DEVICE_KDC_BH1750_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "kdc.h"

#ifdef HAL_I2C_MODULE_ENABLED

/* Exported types ------------------------------------------------------------*/
/**
 * @brief  type of BH1750
*/
typedef struct _KDC_BH1750_t {
  I2C_HandleTypeDef *hi2c;
  I2C_TypeDef *i2c;
  uint16_t address;
  uint16_t luminance;
} KDC_BH1750_t;

/* Exported constants --------------------------------------------------------*/
#define KDC_BH1750_Default_Addr (0x23U << 1)

/* Exported macros -----------------------------------------------------------*/
/**
 * @brief get raw luminance data
 * @param  dbh  pointer to BH1750
 *
 * @retval  uint16_t raw data
*/
#define KDC_BH1750_GetLum(__HANDLE__) \
  ((__HANDLE__)->luminance)

/**
 * @brief get luminance in float
 * @param  dbh  pointer to BH1750
 *
 * @retval float the result
*/
#define KDC_BH1750_fGetLum(__HANDLE__) \
  ((float)((__HANDLE__)->luminance)/1.2)

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

/* Initialization and de-initialization functions *****************************/
void KDC_BH1750_Init(KDC_BH1750_t* dbh, I2C_HandleTypeDef *hi2c, uint16_t address);

/* Configuration functions ****************************************************/
void KDC_BH1750_Start(KDC_BH1750_t* dbh);
void KDC_BH1750_Convert(KDC_BH1750_t* dbh);

/* IO operation functions *****************************************************/
/* State and Error functions **************************************************/

/* Private functions ---------------------------------------------------------*/

#endif

#ifdef __cplusplus
}
#endif

#endif  /* KLIBC_DEVICE_KDC_BH1750_H_ */

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdc_bh1750.h ***/
