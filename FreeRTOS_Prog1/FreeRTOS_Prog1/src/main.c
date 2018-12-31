/**
  ******************************************************************************
  * @file    main.c
  * @author  P. Foubet
  * @version V1.0
  * @date    31-December-2018
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
  interface_init();



  if (!(pdPASS == xTaskCreate( vLedsVerte, (signed char*) "LedVerte",64,NULL,1,NULL ))) goto err;
  if (!(pdPASS == xTaskCreate( vLedsRouge, (signed char*) "LedRouge",64,NULL,2,NULL ))) goto err;

  vTaskStartScheduler();
err:              // should never be reached
  while(1);
  return 0;
}
