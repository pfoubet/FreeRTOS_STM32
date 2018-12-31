/*
 * interfaces.h
 *
 *  Created on: 31 déc. 2018
 *      Author: invite
 */

#ifndef INTERFACES_H_
#define INTERFACES_H_

#include "main.h"
#include "rtc.h"
#include "GRAPH.h"
#include "WM.h"
#include "cmsis_os.h"

extern uint8_t GUI_Initialized;
extern void interfaces_init(void);


extern void BSP_Pointer_Update(void);
extern void BSP_Background(void);

#endif /* INTERFACES_H_ */
