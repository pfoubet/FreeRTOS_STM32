################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/GUIConf.c \
../src/GUI_X_OS.c \
../src/LCDConf_stm32f429i_disco_MB1075.c \
../src/calibration.c \
../src/interfaces.c \
../src/main.c \
../src/rtc.c \
../src/stm32f4xx_it.c \
../src/syscalls.c \
../src/system_stm32f4xx.c 

OBJS += \
./src/GUIConf.o \
./src/GUI_X_OS.o \
./src/LCDConf_stm32f429i_disco_MB1075.o \
./src/calibration.o \
./src/interfaces.o \
./src/main.o \
./src/rtc.o \
./src/stm32f4xx_it.o \
./src/syscalls.o \
./src/system_stm32f4xx.o 

C_DEPS += \
./src/GUIConf.d \
./src/GUI_X_OS.d \
./src/LCDConf_stm32f429i_disco_MB1075.d \
./src/calibration.d \
./src/interfaces.d \
./src/main.d \
./src/rtc.d \
./src/stm32f4xx_it.d \
./src/syscalls.d \
./src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F429ZITx -DSTM32F429I_DISCO -DSTM32F4 -DSTM32 -DUSE_HAL_DRIVER -DSTM32F429xx -DOS_SUPPORT -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib" -I"/home/invite/workspace/New_GraphEx/FreeRTOS_GraphEx/inc" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/CMSIS/core" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/CMSIS/device" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/HAL_Driver/Inc/Legacy" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/HAL_Driver/Inc" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Middlewares/ST/STemWin/Config" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Middlewares/ST/STemWin/inc" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/ampire480272" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/ampire640480" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/Common" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/cs43l22" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/exc7200" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/ili9325" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/ili9341" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/l3gd20" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/lis302dl" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/lis3dsh" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/lsm303dlhc" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/mfxstm32l152" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/n25q256a" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/ov2640" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/s5k5cag" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/st7735" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/stmpe1600" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/stmpe811" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/ts3510" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Components/wm8994" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Fonts" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/Log" -I"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Utilities/STM32F429I-Discovery" -I"/home/invite/workspace/New_GraphEx/FreeRTOS_GraphEx/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/invite/workspace/New_GraphEx/FreeRTOS_GraphEx/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I/STemWin_HelloWorld/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I"/home/invite/workspace/New_GraphEx/FreeRTOS_GraphEx/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -O3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


