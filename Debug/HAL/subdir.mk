################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/DCMOTOR_program.c \
../HAL/LCD_program.c \
../HAL/SRVM_program.c \
../HAL/USS_program.c 

OBJS += \
./HAL/DCMOTOR_program.o \
./HAL/LCD_program.o \
./HAL/SRVM_program.o \
./HAL/USS_program.o 

C_DEPS += \
./HAL/DCMOTOR_program.d \
./HAL/LCD_program.d \
./HAL/SRVM_program.d \
./HAL/USS_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


