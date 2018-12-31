/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "FreeRTOS.h"
#include "task.h"
#include "interface.h"

void vLedsVerte(void* p)
{
 while(1){
  BSP_LED_On(LED3);
  vTaskDelay(120/portTICK_RATE_MS);
  BSP_LED_Off(LED3);
  vTaskDelay(120/portTICK_RATE_MS);
 }
}

void vLedsRouge(void* p)
{
 while(1){
  BSP_LED_On(LED4);
  vTaskDelay(301/portTICK_RATE_MS);
  BSP_LED_Off(LED4);
  vTaskDelay(301/portTICK_RATE_MS);
 }
}

int main(void)
{
int i;
  interface_init();



  /* test des leds */
  /*
  for (i=0; i<10000; i++) {
      BSP_LED_Toggle(LED3);
      osDelay(200);
  }
  for (i=0; i<10000; i++) {
      BSP_LED_Toggle(LED4);
      osDelay(200);
  }
  */

  if (!(pdPASS == xTaskCreate( vLedsVerte, (signed char*) "LedVerte",64,NULL,1,NULL ))) goto hell;
  if (!(pdPASS == xTaskCreate( vLedsRouge, (signed char*) "LedRouge",64,NULL,2,NULL ))) goto hell;
  /*
   *
  if (!(pdPASS == xTaskCreate( vPrintUart, (signed char*) "Uart",    64,NULL,3,NULL ))) goto hell;
   */
  vTaskStartScheduler();
hell:              // should never be reached
  while(1);
  return 0;
}
