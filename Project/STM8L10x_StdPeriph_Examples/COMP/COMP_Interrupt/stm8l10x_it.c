/**
  ******************************************************************************
  * @file    stm8l10x_it.c
  * @author  MCD Application Team
  * @version V1.2.1
  * @date    30-September-2014
  * @brief   This file contains all the interrupt routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm8l10x_it.h"
#include "stm8l101_eval.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

#ifdef _COSMIC_
/**
  * @brief Dummy interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(NonHandledInterrupt,0)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}
#endif

/**
  * @brief TRAP interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER_TRAP(TRAP_IRQHandler)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}

/**
  * @brief FLASH Interrupt routine.
  * @par Parameters:
  * None
  * @retval None
  * None
  */
INTERRUPT_HANDLER(FLASH_IRQHandler,1)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}

/**
  * @brief Auto Wake Up Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(AWU_IRQHandler,4)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}

/**
  * @brief External IT PORTB Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(EXTIB_IRQHandler, 6)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}

/**
  * @brief External IT PORTD Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(EXTID_IRQHandler, 7)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}

/**
  * @brief External IT PIN0 Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(EXTI0_IRQHandler, 8)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}

/**
  * @brief External IT PIN1 Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(EXTI1_IRQHandler, 9)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}

/**
  * @brief External IT PIN2 Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(EXTI2_IRQHandler, 10)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}

/**
  * @brief External IT PIN3 Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(EXTI3_IRQHandler, 11)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}

/**
  * @brief External IT PIN4 Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(EXTI4_IRQHandler, 12)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}

/**
  * @brief External IT PIN5 Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(EXTI5_IRQHandler, 13)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}

/**
  * @brief External IT PIN6 Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(EXTI6_IRQHandler, 14)

{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}

/**
  * @brief External IT PIN7 Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(EXTI7_IRQHandler, 15)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}

/**
  * @brief Comparator Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(COMP_IRQHandler, 18)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
  uint8_t conval = 0;
  
  COMP_ClearITPendingBit(COMP_IT_CEF2);
  
  conval = TIM3_GetCounter();
  
   if (conval == 0x0)
    {
        STM_EVAL_LEDOn(LED2);
        STM_EVAL_LEDOn(LED3);
        STM_EVAL_LEDOn(LED4);
    }
    else if ((conval <= 0xC0) && (conval > 0xA7))
    {
        STM_EVAL_LEDOff(LED2);
        STM_EVAL_LEDOff(LED3);
        STM_EVAL_LEDOff(LED4);
    }
    else if ((conval >= 0xC1) && (conval <= 0xE0))
    {
        STM_EVAL_LEDOff(LED2);
        STM_EVAL_LEDOff(LED4);
        STM_EVAL_LEDOn(LED3);

    }
    else
    {
        STM_EVAL_LEDOff(LED2);
        STM_EVAL_LEDOn(LED4);
        STM_EVAL_LEDOn(LED3);
    }
}

/**
  * @brief Timer2 Update/Overflow/Trigger/Break Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(TIM2_UPD_OVF_TRG_BRK_IRQHandler, 19)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}

/**
  * @brief Timer2 Capture/Compare Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(TIM2_CAP_IRQHandler, 20)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}


/**
  * @brief Timer3 Update/Overflow/Trigger/Break Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(TIM3_UPD_OVF_TRG_BRK_IRQHandler, 21)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
  GPIO_ToggleBits(GPIOC, GPIO_Pin_4);
  
  TIM3_ClearITPendingBit(TIM3_IT_Update);

}
/**
  * @brief Timer3 Capture/Compare Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(TIM3_CAP_IRQHandler, 22)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}
/**
  * @brief Timer4 Update/Overflow Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(TIM4_UPD_OVF_IRQHandler, 25)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}

/**
  * @brief SPI Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(SPI_IRQHandler, 26)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}
/**
  * @brief USART TX Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(USART_TX_IRQHandler, 27)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}

/**
  * @brief USART RX Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(USART_RX_IRQHandler, 28)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}


/**
  * @brief I2C Interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
INTERRUPT_HANDLER(I2C_IRQHandler, 29)
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/