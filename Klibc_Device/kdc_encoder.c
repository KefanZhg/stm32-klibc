/**
  ******************************************************************************
  * @date    Aug 7, 2023
  * @file    kdc_encoder.c
  * @author  Kefan Zheng
  * @brief   
  * @version V0.0.0
  * @email   kirk_z@yeah.net
  */

/* Includes ------------------------------------------------------------------*/
#include "kdc_encoder.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/* Initialization and de-initialization functions *****************************/
void KDC_Encoder_Start(KDC_Encoder_t* kecd)
{
#ifdef HAL_TIM_MODULE_ENABLED
  if(!kecd->Tpr) kecd->Tpr = 1;
  kecd->Tim = kecd->Port->Instance;
  HAL_TIM_Encoder_Start(kecd->Port, TIM_CHANNEL_1|TIM_CHANNEL_2);

  kecd->Last = HAL_GetTick();
#endif /* HAL_TIM_MODULE_ENABLED */
}

void KDC_Encoder_Stop(KDC_Encoder_t* kecd)
{
#ifdef HAL_TIM_MODULE_ENABLED
   HAL_TIM_Encoder_Stop(kecd->Port, TIM_CHANNEL_1|TIM_CHANNEL_2);

   KDC_Encoder_Convert(kecd);
#endif /* HAL_TIM_MODULE_ENABLED */
}


/* Configuration functions ****************************************************/
void KDC_Encoder_Clear(KDC_Encoder_t* kecd)
{
   kecd->pTick = 0;
   kecd->Tim->CNT = 0;
   kecd->vTps = 0;
}


void KDC_Encoder_Convert(KDC_Encoder_t* kecd)
{
   uint32_t time;
   int16_t itmp;
   double dtmp;

   itmp = kecd->Tim->CNT;
   if(kecd->Dir < 0)
     itmp = -itmp;
   else if (kecd->Dir == 0)
     itmp = 0;
   kecd->Tim->CNT = 0;

   time = HAL_GetTick();

   kecd->pTick += itmp;
   dtmp = itmp;
   itmp = (int16_t)(time - kecd->Last);
   dtmp *= 1000;
   dtmp /= itmp;
   if(kecd->Tpr) dtmp /= kecd->Tpr;
   kecd->vRps = (float)(dtmp);

   kecd->Last = time;
}

/* IO operation functions *****************************************************/


/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdc_encoder.c ***/
