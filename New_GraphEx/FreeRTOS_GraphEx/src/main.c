/**
  ******************************************************************************
  * @file    main.c
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    26-February-2014
  * @brief   This file provides main program functions
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
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
/* Mise a jour du 31/12/2018 : P. Foubet
 *
 */
/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "interfaces.h"
#include "display.h"

#define STACK_SIZE 128 // A ajuster !!

/* Threads functions ---------------------------------------------------------*/

void Graphe_Thread(void *p)
{
	 /* Init the STemWin GUI Library */
	 GUI_Init();
	 GUI_Initialized = 1;

	 /* Initialize RTC and Backup */
	 RTC_Init();

	 /* Activate the use of memory device feature */
	 WM_SetCreateFlags(WM_CF_MEMDEV);

	 /* Do the calibration if needed */
	 CALIBRATION_Check();

	 /* Start graph */
	 while(1) display();

}


void Cursor_Thread(void *p)
{
	while(1) {
	  osDelay(50); //wait 50 ms
      /* Capture input event and update cursor */
      if (GUI_Initialized == 1)  BSP_Pointer_Update();
	}
}

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  interfaces_init();

  /* Creation des threads */
  if (!(pdPASS == xTaskCreate( Graphe_Thread, (signed char*) "Graphe",STACK_SIZE*4,NULL,1,NULL ))) goto err;
  if (!(pdPASS == xTaskCreate( Cursor_Thread, (signed char*) "Curseur",STACK_SIZE*4,NULL,2,NULL ))) goto err;

  /* on lance le systeme ! */
  vTaskStartScheduler();

  err:              // En principe jamais atteint !
  while(1);
  return 0;
}



