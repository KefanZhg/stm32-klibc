/**
  ******************************************************************************
  * @date    May 26, 2023
  * @file    kdc_pcf8574.c
  * @author  Kefan Zheng
  * @brief   Driver for PCF8574
  * @version V0.0.0
  * @email   kirk_z@yeah.net
  */

/* Includes ------------------------------------------------------------------*/
#include "kdc_pcf8574.h"

#ifdef HAL_I2C_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/* Initialization and de-initialization functions *****************************/
/**
 * @brief  initialize the module
 * @param  dpcf  pointer to PCF8574
 * @param  hi2c  handler of I2C port
 * @param  address  the slave address
 *
 * @retval uint8_t current IO state
*/
uint8_t KDC_PCF8574_Init(KDC_PCF8574_t* dpcf, I2C_HandleTypeDef *hi2c, uint16_t address)
{
  /* Check valid pointers */
  if(dpcf == NULL)
    return 0;
  if(hi2c == NULL)
    return 0;
  if(!IS_I2C_ALL_INSTANCE(hi2c->Instance))
    return 0;

  /* Record the values */
  dpcf->hi2c = hi2c;
  dpcf->i2c = hi2c->Instance;
  dpcf->address = address;

  /* Init output */
  return KDC_PCF8574_Write(dpcf, 0xFF);
}

/* Configuration functions ****************************************************/
/* IO operation functions *****************************************************/
/**
 * @brief  read IO
 * @param  dpcf  pointer to PCF8574
 *
 * @retval uint8_t current IO state
*/
uint8_t KDC_PCF8574_Read(KDC_PCF8574_t* dpcf)
{
  uint8_t data;

  /* Read and record data */
  HAL_I2C_Master_Receive(dpcf->hi2c, dpcf->address, &data, 1, KDC_DEFAULT_TIMEOUT);
  dpcf->input = data;

  /* Return result */
  return data;
}

/**
 * @brief  write IO
 * @param  dpcf  pointer to PCF8574
 * @param  data  value
 *
 * @retval uint8_t current IO state
*/
uint8_t KDC_PCF8574_Write(KDC_PCF8574_t* dpcf, uint8_t data)
{
  /* Transmit data */
    dpcf->output = data;
  HAL_I2C_Master_Transmit(dpcf->hi2c, dpcf->address, &data, 1, KDC_DEFAULT_TIMEOUT);

  /* Get feedback */
  return KDC_PCF8574_Read(dpcf);
}


/* Peripheral State and Error functions ***************************************/
#endif

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdc_pcf8574.c ***/
