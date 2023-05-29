/**
  ******************************************************************************
  * @date    Mar 18, 2023
  * @file    kdc_led.c
  * @author  Kefan Zheng
  * @brief   
  * @version V0.0.0
  * @email   kirk_z@yeah.net
  */

/* Includes ------------------------------------------------------------------*/
#include "kdc_led.h"

#ifdef HAL_GPIO_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/* Initialization and de-initialization functions *****************************/
/**
 * @brief  Initialize the handler for LED
*/
void KDC_LED_Init(KDC_LED_t *dled, GPIO_TypeDef* port, uint16_t pin, KDC_LED_State onstate)
{
  dled->Type    = KDC_LED_DRtype_GPIO;
  dled->Port    = port;
  dled->Pin     = pin;
  dled->Onstate = onstate;
}

#ifdef HAL_TIM_MODULE_ENABLED

#include "kdr_math.h"

/**
 * @brief  Initialize the handler for LED powered by PWM
*/
void KDC_LED_PWMInit(KDC_LED_t* dled, TIM_HandleTypeDef* port, uint32_t channel, KDC_LED_OnState onstat, uint8_t complement)
{
  if(complement)
    dled->Type = KDC_LED_DRtype_CompPWM;
  else
    dled->Type = KDC_LED_DRtype_PWM;

  dled->tPort = port;
  dled->Channel[0] = channel;
  dled->Onstate = complement?!onstat:onstat;
  dled->Gamma = KDC_LED_DEFAULT_GAMMA;
  dled->Brightness = 0;
  dled->Brightness_Range = KDC_LED_DEFAULT_BRIGHTNESSRANGE;
  dled->Bound = KDC_LED_DEFAULT_BOUNDRANGE;
  dled->Bound_Range = KDC_LED_DEFAULT_BOUNDRANGE;

  dled->AutoReloadValue = dled->tPort->Instance->ARR;
  if(dled->AutoReloadValue == 0xFFFFFFFF)
    dled->AutoReloadValue--;

  KDC_LED_Refresh(dled);
  KDC_LED_TurnOn(dled);
}

/**
 * @brief  Initialize the handler for paired LED powered by PWM
*/
void KDC_LED_PairInit(KDC_LED_t* dled, TIM_HandleTypeDef* port, uint32_t channel_low, uint32_t channel_high)
{
  dled->Type = KDC_LED_DRtype_PairedPWM;

  dled->tPort = port;
  dled->Channel[0] = channel_low;
  dled->Channel[1] = channel_high;

  dled->Gamma = KDC_LED_DEFAULT_GAMMA;
  dled->Brightness = 0;
  dled->Brightness_Range = KDC_LED_DEFAULT_BRIGHTNESSRANGE;
  dled->Bound = KDC_LED_DEFAULT_BOUNDRANGE;
  dled->Bound_Range = KDC_LED_DEFAULT_BOUNDRANGE;

  dled->AutoReloadValue = dled->tPort->Instance->ARR;
  if(dled->AutoReloadValue == 0xFFFFFFFF)
    dled->AutoReloadValue--;
  dled->Onstate = KDC_LED_ONSTATE_LOW;
  dled->Proportion_Range = KDC_LED_DEFAULT_PROPORTIONRANGE;

  KDC_LED_Refresh(dled);
  KDC_LED_TurnOn(dled);
}

#endif

/* Configuration functions ****************************************************/
/* IO operation functions *****************************************************/
/**
 * @brief  Turn on LED or start PWM
*/
void KDC_LED_TurnOn(KDC_LED_t *dled)
{
  switch (dled->Type)
  {
  case KDC_LED_DRtype_GPIO:
    HAL_GPIO_WritePin((dled)->Port,(dled)->Pin,(GPIO_PinState)((dled)->Onstate));
    break;
#ifdef HAL_TIM_MODULE_ENABLED
  case KDC_LED_DRtype_PWM:
    HAL_TIM_PWM_Start((dled)->tPort,(dled)->Channel[0]);
    break;
  case KDC_LED_DRtype_PairedPWM:
    HAL_TIM_PWM_Start((dled)->tPort,(dled)->Channel[0]);
    HAL_TIM_PWM_Start((dled)->tPort,(dled)->Channel[1]);
    break;
  case KDC_LED_DRtype_CompPWM:
    HAL_TIM_PWM_Start((dled)->tPort,(dled)->Channel[0]);
    HAL_TIMEx_PWMN_Start((dled)->tPort,(dled)->Channel[0]);
    break;
#endif
  default:

    break;
  }
}

/**
 * @brief  Turn off LED or stop PWM
*/
void KDC_LED_TurnOff(KDC_LED_t *dled)
{
  switch (dled->Type)
  {
  case KDC_LED_DRtype_GPIO:
    HAL_GPIO_WritePin((dled)->Port,(dled)->Pin,!(GPIO_PinState)((dled)->Onstate));
    break;
#ifdef HAL_TIM_MODULE_ENABLED
  case KDC_LED_DRtype_PWM:
    HAL_TIM_PWM_Stop((dled)->tPort,(dled)->Channel[0]);
    break;
  case KDC_LED_DRtype_PairedPWM:
    HAL_TIM_PWM_Stop((dled)->tPort,(dled)->Channel[0]);
    HAL_TIM_PWM_Stop((dled)->tPort,(dled)->Channel[1]);
    break;
  case KDC_LED_DRtype_CompPWM:
    HAL_TIM_PWM_Stop((dled)->tPort,(dled)->Channel[0]);
    HAL_TIMEx_PWMN_Stop((dled)->tPort,(dled)->Channel[0]);
    break;
#endif
  default:

    break;
  }
}

/**
 * @brief  Toggle LED status if powered by GPIO
*/
void KDC_LED_Toggle(KDC_LED_t *dled)
{
  switch (dled->Type)
  {
  case KDC_LED_DRtype_GPIO:
    HAL_GPIO_TogglePin((dled)->Port,(dled)->Pin);
    break;
#ifdef HAL_TIM_MODULE_ENABLED
  case KDC_LED_DRtype_PWM:

    break;
  case KDC_LED_DRtype_PairedPWM:

    break;
  case KDC_LED_DRtype_CompPWM:

    break;
#endif
  default:

    break;
  }
}

/**
 * @brief  Set the LED status if powered by GPIO
*/
void KDC_LED_Turn(KDC_LED_t *dled, KDC_LED_State state)
{
  switch (dled->Type)
  {
  case KDC_LED_DRtype_GPIO:
    HAL_GPIO_WritePin((dled)->Port,(dled)->Pin,(GPIO_PinState)(!((state)^(dled)->Onstate)));
    break;
#ifdef HAL_TIM_MODULE_ENABLED
  case KDC_LED_DRtype_PWM:

    break;
  case KDC_LED_DRtype_PairedPWM:

    break;
  case KDC_LED_DRtype_CompPWM:

    break;
#endif
  default:

    break;
  }
}

#ifdef HAL_TIM_MODULE_ENABLED

/**
 * @brief  Set the brightness of LED
*/
void KDC_LED_SetBrightness(KDC_LED_t* dled, uint16_t brightness)
{
  switch (dled->Type)
  {
  case KDC_LED_DRtype_PWM:
  case KDC_LED_DRtype_PairedPWM:
  case KDC_LED_DRtype_CompPWM:
    dled->Brightness = brightness<dled->Brightness_Range?brightness:dled->Brightness_Range;

    KDC_LED_Refresh(dled);
    break;
  default:

    break;
  }
}

/**
 * @brief  Set the range brightness of LED
*/
void KDC_LED_SetBrightnessRange(KDC_LED_t* dled, uint16_t range)
{
  double ratio;
  (void) ratio;

  switch (dled->Type)
  {
  case KDC_LED_DRtype_PWM:
  case KDC_LED_DRtype_PairedPWM:
  case KDC_LED_DRtype_CompPWM:
    ratio = dled->Brightness;
    ratio /= dled->Brightness_Range;

    dled->Brightness_Range = range;
    dled->Brightness = (uint16_t)(ratio * range + 0.5);

    KDC_LED_Refresh(dled);
    break;
  default:

    break;
  }
}

/**
 * @brief  Set the bound of LED
 */
void KDC_LED_SetBound(KDC_LED_t* dled, uint16_t bound)
{
  switch (dled->Type)
  {
  case KDC_LED_DRtype_PWM:
  case KDC_LED_DRtype_PairedPWM:
  case KDC_LED_DRtype_CompPWM:
    dled->Bound = bound<dled->Bound_Range?bound:dled->Bound_Range;

    KDC_LED_Refresh(dled);
    break;
  default:

    break;
  }
}

/**
 * @brief  Set the range of bound of LED
*/
void KDC_LED_SetBoundRange(KDC_LED_t* dled, uint16_t range)
{
  double ratio;
  (void) ratio;

  switch (dled->Type)
  {
  case KDC_LED_DRtype_PWM:
  case KDC_LED_DRtype_PairedPWM:
  case KDC_LED_DRtype_CompPWM:
    ratio = dled->Bound;
    ratio /= dled->Bound_Range;

    dled->Bound_Range = range;
    dled->Bound = (uint16_t)(ratio * range + 0.5);

    KDC_LED_Refresh(dled);
    break;
  default:

    break;
  }
}

/**
 * @brief  Set the gamma of LED
 */
void KDC_LED_SetGamma(KDC_LED_t* dled, float gamma)
{
  switch (dled->Type)
  {
  case KDC_LED_DRtype_PWM:
  case KDC_LED_DRtype_PairedPWM:
  case KDC_LED_DRtype_CompPWM:
    dled->Gamma = (uint16_t)(gamma * KDC_LED_GAMMA_SCALER + 0.5);

    KDC_LED_Refresh(dled);
    break;
  default:

    break;
  }
}

/**
 * @brief  Update the PWM output
*/
void KDC_LED_Refresh(KDC_LED_t* dled)
{
  double tmp;
  double Pulse[2];
  uint16_t uPulse[2];
  uint8_t i;
  uint32_t* ccr = (uint32_t*)&(dled->tPort->Instance->CCR1);
  uint32_t* ptmp;

  (void)tmp;
  (void)Pulse[0];
  (void)uPulse[0];
  (void)i;

  switch (dled->Type)
  {
  case KDC_LED_DRtype_PWM:
  case KDC_LED_DRtype_CompPWM:
    Pulse[0] = ((float)dled->Brightness / dled->Brightness_Range) * ((float)dled->Bound / dled->Bound_Range);
    Pulse[0] = pow(Pulse[0], ((float)dled->Gamma)/KDC_LED_GAMMA_SCALER);
    Pulse[0] *= dled->AutoReloadValue + 1;
    uPulse[0] = (uint16_t)(Pulse[0] + 0.5);
    break;
  case KDC_LED_DRtype_PairedPWM:
    tmp = ((double)dled->Brightness / dled->Brightness_Range) * ((double)dled->Bound / dled->Bound_Range);
    tmp = pow(tmp, ((double)dled->Gamma)/KDC_LED_GAMMA_SCALER);
    tmp *= dled->AutoReloadValue + 1;

    Pulse[0] = tmp * dled->Proportion;
    Pulse[0] /= dled->Proportion_Range;
    Pulse[1] = tmp - Pulse[0];
    break;
  default:

    break;
  }

  for(i=0;i<((dled->Type==KDC_LED_DRtype_PairedPWM)?2:1);i++)
  {
    uPulse[i] = (uint16_t)(Pulse[i] + 0.5);
#if 0 // Both are valid. Use the simpler case unless it does not work.
    switch (dled->Channel[i])
    {
    case TIM_CHANNEL_1:

      /* Check the parameters */
      assert_param(IS_TIM_CC1_INSTANCE(htim->Instance));

      /* Set the capture 1 value */
      dled->tPort->Instance->CCR1 =  i?uPulse[i]:dled->AutoReloadValue+1-uPulse[i];

      break;

    case TIM_CHANNEL_2:

      /* Set the parameters */
      assert_param(IS_TIM_CC2_INSTANCE(htim->Instance));

      /* Return the capture 2 value */
      dled->tPort->Instance->CCR2 =  i?uPulse[i]:dled->AutoReloadValue+1-uPulse[i];

      break;


    case TIM_CHANNEL_3:

      /* Check the parameters */
      assert_param(IS_TIM_CC3_INSTANCE(htim->Instance));

      /* Set the capture 3 value */
      dled->tPort->Instance->CCR3 =  i?uPulse[i]:dled->AutoReloadValue+1-uPulse[i];

      break;


    case TIM_CHANNEL_4:

      /* Check the parameters */
      assert_param(IS_TIM_CC4_INSTANCE(htim->Instance));

      /* Set the capture 4 value */
      dled->tPort->Instance->CCR4 =  i?uPulse[i]:dled->AutoReloadValue+1-uPulse[i];

      break;


    default:
      break;
    }
#else
    ptmp = ccr + (dled->Channel[i]>>2);
    *ptmp = (dled->Onstate)?uPulse[i]:dled->AutoReloadValue+1-uPulse[i];
#endif
  }
}

/**
 * @brief  Set the proportion of the paired LED
*/
void KDC_LED_SetProportion(KDC_LED_t* dled, uint16_t proportion)
{
  if(dled->Type == KDC_LED_DRtype_PairedPWM)
  {
    dled->Proportion = proportion;

    if(dled->Proportion > dled->Proportion_Range)
      dled->Proportion = dled->Proportion_Range;

    KDC_LED_Refresh(dled);
  }
  else
  {

  }
}

/**
 * @brief  Increase the proportion of the paired LED
*/
void KDC_LED_IncProportion(KDC_LED_t* dled, uint16_t proportion)
{
  if(dled->Type == KDC_LED_DRtype_PairedPWM)
  {
    dled->Proportion += proportion;

    if(dled->Proportion > dled->Proportion_Range)
      dled->Proportion = dled->Proportion_Range;

    KDC_LED_Refresh(dled);
  }
  else
  {

  }
}

/**
 * @brief  Decrease the proportion of the paired LED
*/
void KDC_LED_DecProportion(KDC_LED_t* dled, uint16_t proportion)
{
  if(dled->Type == KDC_LED_DRtype_PairedPWM)
  {
    dled->Proportion = proportion<dled->Proportion?dled->Proportion-proportion:0;
    KDC_LED_Refresh(dled);
  }
  else
  {

  }
}

/**
 * @brief  Set the range of proportion of the paired LED
*/
void KDC_LED_SetProportionRange(KDC_LED_t* dled, uint16_t range)
{
  if(dled->Type == KDC_LED_DRtype_PairedPWM)
  {
    dled->Proportion_Range = range;
    KDC_LED_Refresh(dled);
  }
  else
  {

  }
}

#endif
/* Peripheral State and Error functions ***************************************/

#endif

/******** (C) COPYRIGHT github.com/KefanZhg/ *** END OF FILE kdc_led.c ***/
