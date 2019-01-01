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
#include "semphr.h"

#include "interface.h"

SemaphoreHandle_t xMutex; // mutex de la LED rouge

// la tache 1 fait clignoter la LED Verte pendant l'utilisation de la rouge
void tache1(void* p)
{
int i;
 while(1){
  xSemaphoreTake(xMutex, portMAX_DELAY); // attente de son tour
  BSP_LED_On(LED4);
  for (i=0; i<5; i++) {
	  BSP_LED_On(LED3);
	  vTaskDelay(100/portTICK_RATE_MS);
	  BSP_LED_Off(LED3);
	  vTaskDelay(100/portTICK_RATE_MS);
  }
  BSP_LED_Off(LED4);
  xSemaphoreGive( xMutex );
  vTaskDelay(100/portTICK_RATE_MS);
 }
}

// la tache 2 fait clignoter la led rouge
void tache2(void* p)
{
int i;
 while(1){
  xSemaphoreTake(xMutex, portMAX_DELAY); // attente de son tour
  for (i=0; i<5; i++) {
	  BSP_LED_On(LED4);
	  vTaskDelay(100/portTICK_RATE_MS);
	  BSP_LED_Off(LED4);
	  vTaskDelay(100/portTICK_RATE_MS);
  }
  xSemaphoreGive( xMutex );
  vTaskDelay(100/portTICK_RATE_MS);
 }
}

// la tache 3 allume les deux leds
void tache3(void* p)
{
 while(1){
  xSemaphoreTake(xMutex, portMAX_DELAY); // attente de son tour
  BSP_LED_On(LED4);
  BSP_LED_On(LED3);
  vTaskDelay(800/portTICK_RATE_MS);
  BSP_LED_Off(LED4);
  BSP_LED_Off(LED3);
  vTaskDelay(200/portTICK_RATE_MS);
  xSemaphoreGive( xMutex );
  vTaskDelay(100/portTICK_RATE_MS);
 }
}

int main(void)
{
int prioMax = configMAX_PRIORITIES-1;
  interface_init();

  // creation du mutex
  xMutex = xSemaphoreCreateMutex();

  /* creation des threads */
  if (!(pdPASS == xTaskCreate( tache1, "tache 1", 64, NULL,1,NULL ))) goto err;
  if (!(pdPASS == xTaskCreate( tache2, "tache 2", 64, NULL,1,NULL ))) goto err;
  if (!(pdPASS == xTaskCreate( tache3, "tache 3", 64, NULL,1,NULL ))) goto err;

  /* lancement du systeme */
  vTaskStartScheduler();
err:              // en principe jamais atteint !
  while(1);
  return 0;
}
