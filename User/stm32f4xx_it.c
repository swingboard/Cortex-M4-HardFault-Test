/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.4.0
  * @date    04-August-2014
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
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
#include "stm32f4xx_it.h"
#include "stdio.h"

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/
void printfErrMsg(const char *msg)
{
	while (*msg != '\0') {
		ITM_SendChar(*msg);
		msg++;
	}
}

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

// HardFault handler in C, with stack frame location and LR value extracted
// from the assembly wrapper as input parameters
void HardFault_Handler_C(unsigned long * hardfault_args, unsigned int lr_value)
{
  unsigned long stacked_r0;
  unsigned long stacked_r1;
  unsigned long stacked_r2;
  unsigned long stacked_r3;
  unsigned long stacked_r12;
  unsigned long stacked_lr;
  unsigned long stacked_pc;
  unsigned long stacked_psr;
  unsigned long cfsr;
	char buf[100];
  
  cfsr                    = SCB->CFSR;
 
  stacked_r0  = ((unsigned long) hardfault_args[0]);
  stacked_r1  = ((unsigned long) hardfault_args[1]);
  stacked_r2  = ((unsigned long) hardfault_args[2]);
  stacked_r3  = ((unsigned long) hardfault_args[3]);
  stacked_r12 = ((unsigned long) hardfault_args[4]);
  stacked_lr  = ((unsigned long) hardfault_args[5]);
  stacked_pc  = ((unsigned long) hardfault_args[6]);
  stacked_psr = ((unsigned long) hardfault_args[7]);
 
  printfErrMsg ("[HardFault]\n");
  printfErrMsg ("- Stack frame:\n");
  sprintf (buf, " R0  = 0x%x\n", stacked_r0);
	printfErrMsg(buf);
  sprintf (buf, " R1  = 0x%x\n", stacked_r1);
	printfErrMsg(buf);
  sprintf (buf, " R2  = 0x%x\n", stacked_r2);
	printfErrMsg(buf);
  sprintf (buf, " R3  = 0x%x\n", stacked_r3);
	printfErrMsg(buf);
  sprintf (buf, " R12 = 0x%x\n", stacked_r12);
	printfErrMsg(buf);
  sprintf (buf, " LR  = 0x%x\n", stacked_lr);
	printfErrMsg(buf);
  sprintf (buf, " PC  = 0x%x\n", stacked_pc);
	printfErrMsg(buf);
  sprintf (buf, " MSR = 0x%x\n", stacked_psr);
	printfErrMsg(buf);
  printfErrMsg ("- FSR/FAR:\n");
  sprintf (buf, " CFSR = 0x%x\n", cfsr);
	printfErrMsg(buf);
  sprintf (buf, " HFSR = 0x%x\n", SCB->HFSR);
	printfErrMsg(buf);
  sprintf (buf, " DFSR = 0x%x\n", SCB->DFSR);
	printfErrMsg(buf);
  sprintf (buf, " AFSR = 0x%x\n", SCB->AFSR);
	printfErrMsg(buf);
	if (cfsr & 0x0080) {sprintf (buf, " MMFAR = 0x%x\n", SCB->MMFAR);printfErrMsg(buf);}
	if (cfsr & 0x8000) {sprintf (buf, " BFAR = 0x%x\n", SCB->BFAR);printfErrMsg(buf);}
  printfErrMsg ("- Misc\n"); 
  sprintf (buf, " LR/EXC_RETURN= 0x%x\n", lr_value);
	printfErrMsg(buf);
 	
  while(1); // endless loop
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
__asm void HardFault_Handler(void)
{
	tst lr,#4
	ite eq
	mrseq r0,msp
	mrsne r0,psp
	mov r1,lr
	import HardFault_Handler_C
	ldr r2,=HardFault_Handler_C
	bx r2
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
 
}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
