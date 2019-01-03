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
File        : ideas and base code from demo file: GUIDEMO_Graph.c
----------------------------------------------------------------------
Modification P. Foubet 31/12/2018
*/



#include "display.h"


static WM_HWIN _hGraphDialog;
static int enableTrig;
static GRAPH_Handle          hGraph;
static int clearData;

/*********************************************************************
*
*       Configuration defines
*
**********************************************************************
*/
#define MAX_GRAPH_SIZE_X 440
#define MAX_GRAPH_SIZE_Y (MAX_GRAPH_SIZE_X * 11) / 20

#define DIST_TO_BORDER   10
#define DIST_TO_WIN      5

#define BORDER_TOP       0
#define BORDER_BOTTOM    9
#define BORDER_LEFT      19
#define BORDER_RIGHT     0

#define COLOR_BK         GUI_DARKGRAY
#define COLOR_BORDER     BK_COLOR_1
#define COLOR_FRAME      GUI_BLACK
#define COLOR_GRID       GUI_GRAY

#define SCALE_H_HEIGHT   4

#define TICK_DIST_H      25
#define TICK_DIST_V      20

#define TIME_RUN         7000
#define TIME_STEP        15

#define HEARTBEAT_TIME   1000

#define MAX_NUM_DATA_OBJ 5

#define GRAPH_DIV        9   // (2^9 = 512) If this value is changed _aWaves[] need to be changed too!
#define GRID_DIST_X      25
#define GRID_DIST_Y      10
#define GRID_OFF_Y       25

/*********************************************************************
*
*       Typedef / Data
*
**********************************************************************
*/

static GUI_COLOR _aColorData[MAX_NUM_DATA_OBJ] = {
  0x50C0FF,
  0xFFC050,
  0x50FFC0,
  0x80C0C0,
  0x00FF80
};

GRAPH_SCALE_Handle _hScaleH, _hScaleV;
static int         _DataAdjust;


/*********************************************************************
*
*       _ShowGraph
*/
static void _ShowGraph(GRAPH_Handle hGraph, GRAPH_DATA_Handle hData[], int DataCountIni) {

  int TimeStart, TimeDiff, TimeStep;
  int i;
  int Flag;
  int value, lim=50, memot;
  int DataCount=DataCountIni;

  //
  // Attach data objects
  //
  for (i = 0; i < DataCount; i++) {
    GRAPH_AttachData(hGraph, hData[i]);
  }


  TimeStart = GUI_GetTime();
  Flag = 1;
  do {
    TimeDiff = GUI_GetTime() - TimeStart;

    if (clearData)
    {
    	GRAPH_AttachScale(hGraph, _hScaleH);
    	GRAPH_AttachScale(hGraph, _hScaleV);
        for (i = 0; i < DataCount; i++)
        {
          GRAPH_DATA_YT_Clear(hData[i]);
        }
        clearData=0;
        DataCount--;
        if (DataCount == 0) DataCount=4;
        Flag=1;
    }

    if (1==1)  {
      for (i = 0; i < DataCount; i++)
      {
    	  if (enableTrig>0) memot=((GUI_GetTime()>>1)%100);
          value=((i-1)*lim)+ memot;
          GRAPH_DATA_YT_AddValue(hData[i], value  + _DataAdjust);
      }
      if (Flag) {
        Flag = 0;
        GUI_Exec();
        GRAPH_DetachScale(hGraph, _hScaleH);
        GRAPH_DetachScale(hGraph, _hScaleV);
        WM_ValidateWindow(hGraph);
      }
    }
    TimeStep  = GUI_GetTime() - TimeStart;
    if ((TimeStep - TimeDiff) < TIME_STEP) {
      GUI_Delay(TIME_STEP - (TimeStep - TimeDiff));
    }

//} while (TimeDiff < TIME_RUN);
  } while(1);

  for (i = 0; i < DataCount; i++) {
    GRAPH_DetachData(hGraph, hData[i]);
  }

}



/*********************************************************************
*
*       drawBkS
*/
void drawBk(void)
{
  GUI_SetBkColor(BK_COLOR_1);
  GUI_Clear();
  GUI_DrawBitmap(&bmESIEA_logo, 10, 10);
}

void drawBk2(void)
{
  GUI_SetBkColor(BK_COLOR_2);
  GUI_Clear();
  GUI_DrawBitmap(&bmESIEA_logo, 155, 3);
}


/*********************************************************************
*
*       clearGraph
*/
void clearGraph(void)
{
	clearData=1;
}

/*********************************************************************
*
*       setTrig
*/
void setTrig(int enable)
{
  enableTrig=enable;
}


/*********************************************************************
*
*       _cbBk
*/
static void _cbBk(WM_MESSAGE * pMsg) {
  switch (pMsg->MsgId) {
  case WM_PAINT:
    drawBk();
    break;
  default:
    WM_DefaultProc(pMsg);
  }
}

/*********************************************************************
*
*       _DisplayGraph
*/
static void _DisplayGraph(void) {
  const WIDGET_EFFECT * pEffectOld;
  GRAPH_DATA_Handle     hData[MAX_NUM_DATA_OBJ];
  int                   xSize, ySize, i;
  int                   Graph_xSize, Graph_ySize, Data_ySize;
  int                   Graph_xPos, Graph_yPos;
  int     ScaleVOff; // Vertical scale offset in relation to GRAPH_DIV
  int     DataVOff; // Vertical data  offset in relation to GRAPH_DIV
  int     GridVOff; // Vertical grid  offset in relation to GRAPH_DIV
  int     NumWaves; // Number of waves

  xSize      = LCD_GetXSize();
  ySize      = LCD_GetYSize();
  pEffectOld = WIDGET_SetDefaultEffect(&WIDGET_Effect_Simple);
  //
  // Set Callback function for background window
  //
  WM_SetCallback(WM_HBKWIN, _cbBk);
  //
  // Determine size of GRAPH
  //
  Graph_xSize = xSize - (DIST_TO_BORDER << 1);            // xsize = Screen size subtracting twice the distance to the border of the screen
  Graph_ySize = ySize - INFO_SIZE_Y - (DIST_TO_WIN << 1); // ysize = Screen size subtracting the window sizes and twice the distance to the windows
  if (Graph_ySize > MAX_GRAPH_SIZE_Y) {
    Graph_ySize = MAX_GRAPH_SIZE_Y;
    if (Graph_xSize > (Graph_ySize * 20) / 11) {
      Graph_xSize = (Graph_ySize * 20) / 11;
    }
  }
  //
  // Create and configure GRAPH_WIDGET
  //
  Graph_xPos = (xSize - Graph_xSize) >> 1;
  Graph_yPos = (ySize - Graph_ySize) >> 1;
  if (Graph_yPos < INFO_SIZE_Y + DIST_TO_WIN) {
    Graph_yPos = INFO_SIZE_Y + DIST_TO_WIN;
  }
  hGraph = GRAPH_CreateEx(Graph_xPos, Graph_yPos, Graph_xSize, Graph_ySize, WM_HBKWIN, WM_CF_SHOW | WM_CF_CONST_OUTLINE, 0, 0);
  GRAPH_SetBorder(hGraph, BORDER_LEFT, BORDER_TOP, BORDER_RIGHT, BORDER_BOTTOM);
  WM_SetHasTrans (hGraph);
  GRAPH_SetColor (hGraph, COLOR_BK,     GRAPH_CI_BK);
  GRAPH_SetColor (hGraph, COLOR_BORDER, GRAPH_CI_BORDER);
  GRAPH_SetColor (hGraph, COLOR_FRAME,  GRAPH_CI_FRAME);
  GRAPH_SetColor (hGraph, COLOR_GRID,   GRAPH_CI_GRID);
  //
  // Adjust grid
  //
  GRAPH_SetGridVis  (hGraph, 1);
  GRAPH_SetGridDistX(hGraph, GRID_DIST_X);
  GRAPH_SetGridDistY(hGraph, GRID_DIST_Y);
  WM_BringToBottom  (hGraph);

  //
  // Create and configure GRAPH_DATA_YT object
  //
  for (i = 0; i < MAX_NUM_DATA_OBJ; i++) {
    hData[i] = GRAPH_DATA_YT_Create(_aColorData[i], xSize - (DIST_TO_BORDER << 1) - BORDER_LEFT, 0, 0);
  }
  Data_ySize = Graph_ySize - BORDER_BOTTOM;
  //
  // Create and configure GRAPH_SCALE objects
  //
  _hScaleH = GRAPH_SCALE_Create(BORDER_BOTTOM >> 1, GUI_TA_VCENTER, GRAPH_SCALE_CF_HORIZONTAL, TICK_DIST_H);
  _hScaleV = GRAPH_SCALE_Create(BORDER_LEFT   >> 1, GUI_TA_HCENTER, GRAPH_SCALE_CF_VERTICAL,   TICK_DIST_V);
  GRAPH_SCALE_SetPos(_hScaleH, Graph_ySize - SCALE_H_HEIGHT);
  GRAPH_SCALE_SetOff(_hScaleH, -5);
  //
  // Show graph
  //
  ScaleVOff=157; // Vertical scale offset in relation to GRAPH_DIV
  DataVOff=152; // Vertical data  offset in relation to GRAPH_DIV
  GridVOff=21;  // Vertical grid  offset in relation to GRAPH_DIV
  NumWaves=4; // Number of waves

  GRAPH_AttachScale(hGraph, _hScaleH);
  GRAPH_AttachScale(hGraph, _hScaleV);
  _DataAdjust = (Data_ySize * DataVOff) >> GRAPH_DIV;
  GRAPH_SetGridOffY (hGraph, (Data_ySize * GridVOff) >> GRAPH_DIV);
  GRAPH_SCALE_SetOff(_hScaleV, (((Data_ySize - BORDER_BOTTOM) * ScaleVOff) >> GRAPH_DIV));
  _ShowGraph(hGraph, hData, NumWaves);

  //
  // Clean up
  //
  GRAPH_DetachScale(hGraph, _hScaleH);
  GRAPH_DetachScale(hGraph, _hScaleV);
  GRAPH_SCALE_Delete(_hScaleH);
  GRAPH_SCALE_Delete(_hScaleV);
  for (i = 0; i < MAX_NUM_DATA_OBJ; i++) {
    GRAPH_DATA_YT_Delete(hData[i]);
  }
  WM_DeleteWindow(hGraph);
  WIDGET_SetDefaultEffect(pEffectOld);
}


/*********************************************************************
*
*       Public functions
*
**********************************************************************
*/
void display(void)
{
   enableTrig=1;
   clearData=0;
   _hGraphDialog=CreateGraphDlg();
   _DisplayGraph();
}

void display2(void)
{
	enableTrig=1;
	clearData=0;
    drawBk2();
}






/*************************** End of file ****************************/
