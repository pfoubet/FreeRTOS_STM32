################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/GUI/subdir.mk
-include src/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: FreeRTOS_GraphEx.elf

dependents:
	-cd /home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Release && $(MAKE) all

# Tool invocations
FreeRTOS_GraphEx.elf: $(OBJS) $(USER_OBJS) /home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Release/libstm32f429i-disco_hal_lib.a
	@echo 'Building target: $@'
	@echo 'Invoking: MCU G++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -L"/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Release" -L"/home/invite/workspace/New_GraphEx/FreeRTOS_GraphEx/../stm32f429i-disco_hal_lib/Middlewares/ST/STemWin/Lib" -T"/home/invite/workspace/New_GraphEx/FreeRTOS_GraphEx/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -fno-exceptions -fno-rtti -o "FreeRTOS_GraphEx.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "FreeRTOS_GraphEx.elf" "FreeRTOS_GraphEx.bin"
	arm-none-eabi-size -B "FreeRTOS_GraphEx.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build
/home/invite/workspace/New_GraphEx/stm32f429i-disco_hal_lib/Release/libstm32f429i-disco_hal_lib.a:

-include ../makefile.targets
