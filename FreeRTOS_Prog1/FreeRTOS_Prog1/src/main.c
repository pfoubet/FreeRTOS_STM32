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
  vTaskDelay(300/portTICK_RATE_MS);
  BSP_LED_Off(LED3);
  vTaskDelay(300/portTICK_RATE_MS);
 }
}

void vLedsRouge(void* p)
{
 while(1){
  BSP_LED_On(LED4);
  vTaskDelay(100/portTICK_RATE_MS);
  BSP_LED_Off(LED4);
  vTaskDelay(100/portTICK_RATE_MS);
 }
}

int main(void)
{
char *Nom1="LedVerte", *Nom2="LedRouge";
  interface_init();

  /* creation des threads */
  if (!(pdPASS == xTaskCreate( vLedsVerte, Nom1, 64, NULL,1,NULL ))) goto err;
  if (!(pdPASS == xTaskCreate( vLedsRouge, Nom2, 64, NULL,configMAX_PRIORITIES-1,NULL ))) goto err;

  /* lancement du systeme */
  vTaskStartScheduler();
err:              // en principe jamais atteint !
  while(1);
  return 0;
}
