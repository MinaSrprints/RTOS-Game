################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_operations.c \
../LCD.c \
../button.c \
../croutine.c \
../event_groups.c \
../heap_1.c \
../keypad.c \
../lcd_4bit.c \
../led.c \
../list.c \
../main.c \
../port.c \
../queue.c \
../stream_buffer.c \
../tasks.c \
../timers.c 

OBJS += \
./DIO_operations.o \
./LCD.o \
./button.o \
./croutine.o \
./event_groups.o \
./heap_1.o \
./keypad.o \
./lcd_4bit.o \
./led.o \
./list.o \
./main.o \
./port.o \
./queue.o \
./stream_buffer.o \
./tasks.o \
./timers.o 

C_DEPS += \
./DIO_operations.d \
./LCD.d \
./button.d \
./croutine.d \
./event_groups.d \
./heap_1.d \
./keypad.d \
./lcd_4bit.d \
./led.d \
./list.d \
./main.d \
./port.d \
./queue.d \
./stream_buffer.d \
./tasks.d \
./timers.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


