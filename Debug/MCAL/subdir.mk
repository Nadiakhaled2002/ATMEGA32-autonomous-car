################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DIO_program.c \
../MCAL/GIR_program.c \
../MCAL/TIMER1_program.c 

OBJS += \
./MCAL/DIO_program.o \
./MCAL/GIR_program.o \
./MCAL/TIMER1_program.o 

C_DEPS += \
./MCAL/DIO_program.d \
./MCAL/GIR_program.d \
./MCAL/TIMER1_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


