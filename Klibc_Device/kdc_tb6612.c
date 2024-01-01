/**
  ******************************************************************************
  * @date    Aug 7, 2023
  * @file    kdc_tb6612.c
  * @author  Kefan Zheng
  * @brief   
  * @version V0.0.0
  * @email   kirk_z@yeah.net
  */

/* Includes ------------------------------------------------------------------*/
#include "kdc_tb6612.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/* Initialization and de-initialization functions *****************************/
void KDC_TB6612_Start(KDC_TB6612_t* ktb)
{
  KDC_Pin_Reset(&ktb->Pin1);
  KDC_Pin_Reset(&ktb->Pin2);

#ifdef HAL_TIM_MODULE_ENABLED
  HAL_TIM_PWM_Start(ktb->Port, ktb->Channel);
  if(ktb->Complement == KDC_PortComplement)
  {
    HAL_TIMEx_PWMN_Start(ktb->Port, ktb->Channel);
  }
#endif /* HAL_TIM_MODULE_ENABLED */
}

void KDC_TB6612_Stop(KDC_TB6612_t* ktb)
{
#ifdef HAL_TIM_MODULE_ENABLED
  HAL_TIM_PWM_Stop(ktb->Port, ktb->Channel);
  if(ktb->Complement == KDC_PortComplement)
  {
    HAL_TIMEx_PWMN_Stop(ktb->Port, ktb->Channel);
  }
#endif /* HAL_TIM_MODULE_ENABLED */
}
/* Configuration functions ****************************************************/

/* IO operation functions *****************************************************/
void KDC_TB6612_Refresh(KDC_TB6612_t *ktb)
{
  float ftmp;
#ifdef HAL_TIM_MODULE_ENABLED
  uint16_t utmp;
  TIM_HandleTypeDef *port;
  uint32_t channel;
#endif /* HAL_TIM_MODULE_ENABLED */

  if(ktb == NULL)
    return;

  if(ktb->Speed>1)
    ktb->Speed = 1;
  if(-ktb->Speed>1)
    ktb->Speed = -1;

  /* Set direction */
  if(ktb->Speed < 0 && ktb->Dir >= 0)
  {
    /* Clear */
    if(ktb->Pin1.Port != NULL)
      KDC_Pin_Reset(&ktb->Pin1);
    if(ktb->Pin2.Port != NULL)
      KDC_Pin_Reset(&ktb->Pin2);
    /* Set */
    if(ktb->Pin1.Port != NULL)
      KDC_Pin_Set(&ktb->Pin1);
    /* State */
    ktb->Dir = -1;
  }
  else if(ktb->Speed > 0 && ktb->Dir <= 0)
  {
    /* Clear */
    if(ktb->Pin1.Port != NULL)
      KDC_Pin_Reset(&ktb->Pin1);
    if(ktb->Pin2.Port != NULL)
      KDC_Pin_Reset(&ktb->Pin2);
    /* Set */
    if(ktb->Pin2.Port != NULL)
      KDC_Pin_Set(&ktb->Pin2);
    /* State */
    ktb->Dir = 1;
  }

  ftmp = ktb->Speed;
  if(ftmp < 0)
    ftmp = -ftmp;

#ifdef HAL_TIM_MODULE_ENABLED
  port = ktb->Port;
  channel = ktb->Channel;
  utmp = port->Instance->ARR;

  ftmp *= utmp;
  ftmp += 0.5;
  utmp = (uint16_t)ftmp;

  __HAL_TIM_SET_COMPARE(port, channel, utmp);
#endif /* HAL_TIM_MODULE_ENABLED */
}
/* Peripheral State and Error functions ***************************************/

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdc_tb6612.c ***/
