################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DCMOTOR_program.c \
../LCD_program.c \
../SRVM_program.c \
../USS_program.c \
../main.c 

OBJS += \
./DCMOTOR_program.o \
./LCD_program.o \
./SRVM_program.o \
./USS_program.o \
./main.o 

C_DEPS += \
./DCMOTOR_program.d \
./LCD_program.d \
./SRVM_program.d \
./USS_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


