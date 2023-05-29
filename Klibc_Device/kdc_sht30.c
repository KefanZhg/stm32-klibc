/**
  ******************************************************************************
  * @date    May 26, 2023
  * @file    kdc_sht30.c
  * @author  Kefan Zheng
  * @brief   Driver for SHT30
  * @version V0.0.0
  * @email   kirk_z@yeah.net
  */

/* Includes ------------------------------------------------------------------*/
#include "kdc_sht30.h"

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
 * @param  dsht  pointer to SHT30
 * @param  hi2c  handler of I2C port
 * @param  address  the slave address
 *
 * @retval KDC_State_t KDC Status
*/
KDC_State_t KDC_SHT30_Init(KDC_SHT30_t* dsht, I2C_HandleTypeDef *hi2c, uint16_t address)
{
  uint8_t SHT3X_Modecommand_Buffer[2]={0x22,0x36}; //periodic mode commands
  /* Invalid pointer */
  if(dsht == NULL)
    return KDC_ERROR;
  if(hi2c == NULL)
    return KDC_ERROR;
  if(!IS_I2C_ALL_INSTANCE(hi2c->Instance))
    return KDC_ERROR;

  /* Note the info */
  dsht->hi2c = hi2c;
  dsht->i2c = hi2c->Instance;
  dsht->address = address;

  if(HAL_OK == HAL_I2C_Master_Transmit(hi2c, address, SHT3X_Modecommand_Buffer, 2, KDC_DEFAULT_TIMEOUT))
  return KDC_OK;
  else
  return KDC_ERROR;
}

/* Configuration functions ****************************************************/
/**
 * @brief  convert data
 * @param  dsht  pointer to SHT30
 *
 * @retval KDC_State_t KDC Status
*/
KDC_State_t KDC_SHT30_Convert(KDC_SHT30_t* dsht)
{
  static uint8_t command[2]={0xE0,0x00};	//read the measurement results
  static uint8_t buffer[6]; 				//byte 0,1 is temperature byte 4,5 is humidity

  HAL_StatusTypeDef stat;

  /* Check pointer valid */
  stat = HAL_I2C_Master_Transmit(dsht->hi2c,dsht->address,command,2,KDC_DEFAULT_TIMEOUT); //Read sht30 sensor data
  if(stat!=HAL_OK)
    return KDC_ERROR;

  stat = HAL_I2C_Master_Receive(dsht->hi2c,dsht->address+1,buffer,6,KDC_DEFAULT_TIMEOUT);
  if(stat!=HAL_OK)
    return KDC_ERROR;

  /* Check and record temperature */
  if( KDC_OK == KDC_SHT30_CheckCRC(&buffer[0], 2, buffer[2]))
  {
    dsht->temp = ((uint16_t)buffer[0] << 8) | buffer[1];
  }

  /* Check and record humidity */
  if( KDC_OK == KDC_SHT30_CheckCRC(&buffer[3], 2, buffer[5]))
  {
    dsht->hum = ((uint16_t)buffer[3] << 8) | buffer[4];
  }

  return KDC_OK;
}

/* IO operation functions *****************************************************/

/* Peripheral State and Error functions ***************************************/
/**
 * @brief  check crc for result
 * @param  data  array of data
 * @param  length  length of array
 * @param  checksum  supposed check sum
 *
 * @retval KDC_State_t  whether check successful
*/
KDC_State_t KDC_SHT30_CheckCRC(uint8_t data[], uint8_t length, uint8_t checksum)
{
  uint8_t crc = 0xFF;
  uint8_t bit = 0;
  uint8_t byteCtr ;

  /* calculates 8-Bit checksum with given polynomial */
  for(byteCtr = 0; byteCtr < length; ++byteCtr)
  {
    crc ^= (data[byteCtr]);
    for ( bit = 8; bit > 0; --bit)
    {
      if (crc & 0x80) crc = (crc << 1) ^ KDC_SHT30_Polynomial;
      else crc = (crc << 1);
    }
  }

  return (crc == checksum)?KDC_OK:KDC_ERROR;
}

#endif

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdc_sht30.c ***/
