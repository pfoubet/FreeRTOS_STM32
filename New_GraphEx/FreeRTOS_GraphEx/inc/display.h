/*********************************************************************
*          Portions COPYRIGHT 2014 STMicroelectronics                *
*          Portions SEGGER Microcontroller GmbH & Co. KG             *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2013  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.22 - Graphical user interface for embedded applications **
All  Intellectual Property rights  in the Software belongs to  SEGGER.
emWin is protected by  international copyright laws.  Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with the following terms:

The  software has  been licensed  to STMicroelectronics International
N.V. a Dutch company with a Swiss branch and its headquarters in Plan-
les-Ouates, Geneva, 39 Chemin du Champ des Filles, Switzerland for the
purposes of creating libraries for ARM Cortex-M-based 32-bit microcon_
troller products commercialized by Licensee only, sublicensed and dis_
tributed under the terms and conditions of the End User License Agree_
ment supplied by STMicroelectronics International N.V.
Full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : GUIDEMO.h
Purpose     : Configuration file of GUIDemo
----------------------------------------------------------------------
*/

/**
  ******************************************************************************
  * @file    GUIDEMO.c
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    26-February-2014
  * @brief   Configuration file of GUIDemo
  ******************************************************************************
  * @attention
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


#ifndef DISPLAY_H
#define DISPLAY_H

#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

#include "GUI.h"

#if GUI_WINSUPPORT
  #include "WM.h"

  #include "CHECKBOX.h"
  #include "FRAMEWIN.h"
  #include "PROGBAR.h"
  #include "TEXT.h"
  #include "BUTTON.h"
  #include "SLIDER.h"
  #include "HEADER.h"
  #include "GRAPH.h"
  #include "ICONVIEW.h"
  #include "LISTVIEW.h"
  #include "TREEVIEW.h"
  #include "DIALOG.h"
#endif

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define CONTROL_SIZE_X    80
#define CONTROL_SIZE_Y    61
#define INFO_SIZE_Y       65
#define BUTTON_SIZE_X     32
#define BUTTON_SIZE_Y     20
#define PROGBAR_SIZE_X    66
#define PROGBAR_SIZE_Y    12
#define TEXT_SIZE_X       69
#define TEXT_SIZE_Y       7
#define SHOW_PROGBAR_AT   100
#define GUI_ID_HALT       (GUI_ID_USER + 0)
#define GUI_ID_NEXT       (GUI_ID_USER + 1)

#define BK_COLOR_0        0xFF5555
#define BK_COLOR_1        0xC80088
#define BK_COLOR_2        0x789078

#define NUMBYTES_NEEDED   0x200000

#define CIRCLE_RADIUS     100

#define LOGO_DIST_BORDER  5

#define CHAR_READING_TIME 80


/*********************************************************************
*
*       Internal functions
*
**********************************************************************
*/
void showInfo(const char * acInfo);
void drawBk(void);
void clearGraph(void);
void setTrig(int enable);
void graph(void);
void display(void);
void display2(void);

/*********************************************************************
*
*       Externs
*
**********************************************************************
*/
extern GUI_CONST_STORAGE GUI_BITMAP bmESIEA_logo;
extern WM_HWIN CreateGraphDlg(void);


#if defined(__cplusplus)
  }
#endif

#endif // avoid multiple inclusion

/*************************** End of file ****************************/
