################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/subdir.mk
-include HAL/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
autonomous_car.lss \

FLASH_IMAGE += \
autonomous_car.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: autonomous_car.elf secondary-outputs

# Tool invocations
autonomous_car.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,autonomous_car.map -mmcu=atmega32 -o "autonomous_car.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

autonomous_car.lss: autonomous_car.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S autonomous_car.elf  >"autonomous_car.lss"
	@echo 'Finished building: $@'
	@echo ' '

autonomous_car.hex: autonomous_car.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex autonomous_car.elf  "autonomous_car.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: autonomous_car.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 autonomous_car.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) autonomous_car.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
