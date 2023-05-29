/**
  ******************************************************************************
  * @date    May 26, 2023
  * @file    kdc_bh1750.c
  * @author  Kefan Zheng
  * @brief   Driver for BH1750
  * @version V0.0.0
  * @email   kirk_z@yeah.net
  */

/* Includes ------------------------------------------------------------------*/
#include "kdc_bh1750.h"

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
 * @param  dbh  pointer to BH1750
 * @param  hi2c  handler of I2C port
 * @param  address  the slave address
 *
 * @retval None
*/
void KDC_BH1750_Init(KDC_BH1750_t* dbh, I2C_HandleTypeDef *hi2c, uint16_t address)
{
  uint8_t t_Data = 0x01;

  /* Invalid pointer */
  if(dbh == NULL)
    return;
  if(hi2c == NULL)
    return;
  if(!IS_I2C_ALL_INSTANCE(hi2c->Instance))
    return;

  /* Record basic parameters */
  dbh->hi2c = hi2c;
  dbh->i2c = hi2c->Instance;
  dbh->address = address;

  /* Configuration */
  HAL_I2C_Master_Transmit(dbh->hi2c, dbh->address, &t_Data, 1, 0x1FFFF);
}

/* Configuration functions ****************************************************/
/**
 * @brief start preparing data
 * @param  dbh  pointer to BH1750
 *
 * @retval None
*/
void KDC_BH1750_Start(KDC_BH1750_t* dbh)
{
  uint8_t t_Data = 0x10;

  /* Configure */
  HAL_I2C_Master_Transmit(dbh->hi2c, dbh->address, &t_Data, 1, 0xff);
}

/**
 * @brief  get and convert data from BH1750
 * @param  dbh  pointer to BH1750
 * @note  It takes about 120ms for preparing the result after starting.
 *
 * @retval None
*/
void KDC_BH1750_Convert(KDC_BH1750_t *dbh)
{
  uint16_t result;
  uint8_t BUF[2];

  /* Start preparation */
  KDC_BH1750_Start(dbh);
  /* Wait 180ms for preparation */
  HAL_Delay(180);
  /* Receive data */
  HAL_I2C_Master_Receive(dbh->hi2c, dbh->address+1, BUF, 2, 0xff);

  /* Convert result */
  result=BUF[0];
  result=(result<<8)+BUF[1];
  dbh->luminance = result;
}

/* IO operation functions *****************************************************/
/* Peripheral State and Error functions ***************************************/

#endif

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdc_bh1750.c ***/
