################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GUI_Demo/GUIDEMO.c \
../src/GUI_Demo/GUIDEMO_AntialiasedText.c \
../src/GUI_Demo/GUIDEMO_Automotive.c \
../src/GUI_Demo/GUIDEMO_BarGraph.c \
../src/GUI_Demo/GUIDEMO_Bitmap.c \
../src/GUI_Demo/GUIDEMO_ColorBar.c \
../src/GUI_Demo/GUIDEMO_Conf.c \
../src/GUI_Demo/GUIDEMO_Cursor.c \
../src/GUI_Demo/GUIDEMO_Fading.c \
../src/GUI_Demo/GUIDEMO_Graph.c \
../src/GUI_Demo/GUIDEMO_IconView.c \
../src/GUI_Demo/GUIDEMO_ImageFlow.c \
../src/GUI_Demo/GUIDEMO_Intro.c \
../src/GUI_Demo/GUIDEMO_Listview.c \
../src/GUI_Demo/GUIDEMO_RadialMenu.c \
../src/GUI_Demo/GUIDEMO_Resource.c \
../src/GUI_Demo/GUIDEMO_Skinning.c \
../src/GUI_Demo/GUIDEMO_Speed.c \
../src/GUI_Demo/GUIDEMO_Speedometer.c \
../src/GUI_Demo/GUIDEMO_Start.c \
../src/GUI_Demo/GUIDEMO_TransparentDialog.c \
../src/GUI_Demo/GUIDEMO_Treeview.c \
../src/GUI_Demo/GUIDEMO_VScreen.c \
../src/GUI_Demo/GUIDEMO_WashingMachine.c \
../src/GUI_Demo/GUIDEMO_ZoomAndRotate.c 

OBJS += \
./src/GUI_Demo/GUIDEMO.o \
./src/GUI_Demo/GUIDEMO_AntialiasedText.o \
./src/GUI_Demo/GUIDEMO_Automotive.o \
./src/GUI_Demo/GUIDEMO_BarGraph.o \
./src/GUI_Demo/GUIDEMO_Bitmap.o \
./src/GUI_Demo/GUIDEMO_ColorBar.o \
./src/GUI_Demo/GUIDEMO_Conf.o \
./src/GUI_Demo/GUIDEMO_Cursor.o \
./src/GUI_Demo/GUIDEMO_Fading.o \
./src/GUI_Demo/GUIDEMO_Graph.o \
./src/GUI_Demo/GUIDEMO_IconView.o \
./src/GUI_Demo/GUIDEMO_ImageFlow.o \
./src/GUI_Demo/GUIDEMO_Intro.o \
./src/GUI_Demo/GUIDEMO_Listview.o \
./src/GUI_Demo/GUIDEMO_RadialMenu.o \
./src/GUI_Demo/GUIDEMO_Resource.o \
./src/GUI_Demo/GUIDEMO_Skinning.o \
./src/GUI_Demo/GUIDEMO_Speed.o \
./src/GUI_Demo/GUIDEMO_Speedometer.o \
./src/GUI_Demo/GUIDEMO_Start.o \
./src/GUI_Demo/GUIDEMO_TransparentDialog.o \
./src/GUI_Demo/GUIDEMO_Treeview.o \
./src/GUI_Demo/GUIDEMO_VScreen.o \
./src/GUI_Demo/GUIDEMO_WashingMachine.o \
./src/GUI_Demo/GUIDEMO_ZoomAndRotate.o 

C_DEPS += \
./src/GUI_Demo/GUIDEMO.d \
./src/GUI_Demo/GUIDEMO_AntialiasedText.d \
./src/GUI_Demo/GUIDEMO_Automotive.d \
./src/GUI_Demo/GUIDEMO_BarGraph.d \
./src/GUI_Demo/GUIDEMO_Bitmap.d \
./src/GUI_Demo/GUIDEMO_ColorBar.d \
./src/GUI_Demo/GUIDEMO_Conf.d \
./src/GUI_Demo/GUIDEMO_Cursor.d \
./src/GUI_Demo/GUIDEMO_Fading.d \
./src/GUI_Demo/GUIDEMO_Graph.d \
./src/GUI_Demo/GUIDEMO_IconView.d \
./src/GUI_Demo/GUIDEMO_ImageFlow.d \
./src/GUI_Demo/GUIDEMO_Intro.d \
./src/GUI_Demo/GUIDEMO_Listview.d \
./src/GUI_Demo/GUIDEMO_RadialMenu.d \
./src/GUI_Demo/GUIDEMO_Resource.d \
./src/GUI_Demo/GUIDEMO_Skinning.d \
./src/GUI_Demo/GUIDEMO_Speed.d \
./src/GUI_Demo/GUIDEMO_Speedometer.d \
./src/GUI_Demo/GUIDEMO_Start.d \
./src/GUI_Demo/GUIDEMO_TransparentDialog.d \
./src/GUI_Demo/GUIDEMO_Treeview.d \
./src/GUI_Demo/GUIDEMO_VScreen.d \
./src/GUI_Demo/GUIDEMO_WashingMachine.d \
./src/GUI_Demo/GUIDEMO_ZoomAndRotate.d 


# Each subdirectory must supply rules for building sources it contributes
src/GUI_Demo/%.o: ../src/GUI_Demo/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F429ZITx -DSTM32F429I_DISCO -DSTM32F4 -DSTM32 -DUSE_HAL_DRIVER -DSTM32F429xx -DOS_SUPPORT -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib" -I"/home/invite/workspace/STemWin_HelloWorld_projects/STemWin_HelloWorld/inc" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/CMSIS/core" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/CMSIS/device" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/HAL_Driver/Inc/Legacy" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/HAL_Driver/Inc" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Middlewares/ST/STemWin/Config" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Middlewares/ST/STemWin/inc" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/ampire480272" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/ampire640480" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/Common" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/cs43l22" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/exc7200" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/ili9325" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/ili9341" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/l3gd20" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/lis302dl" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/lis3dsh" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/lsm303dlhc" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/mfxstm32l152" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/n25q256a" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/ov2640" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/s5k5cag" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/st7735" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/stmpe1600" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/stmpe811" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/ts3510" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Components/wm8994" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Fonts" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/Log" -I"/home/invite/workspace/STemWin_HelloWorld_projects/stm32f429i-disco_hal_lib/Utilities/STM32F429I-Discovery" -I"/home/invite/workspace/STemWin_HelloWorld_projects/STemWin_HelloWorld/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/invite/workspace/STemWin_HelloWorld_projects/STemWin_HelloWorld/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I/STemWin_HelloWorld/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I"/home/invite/workspace/STemWin_HelloWorld_projects/STemWin_HelloWorld/src/GUI_Demo" -I"/home/invite/workspace/STemWin_HelloWorld_projects/STemWin_HelloWorld/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


