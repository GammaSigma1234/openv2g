################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/test/main.c \
../src/test/main_databinder.c \
../src/test/main_example.c

OBJS += \
./src/test/main.o \
./src/test/main_databinder.o \
./src/test/main_example.o

C_DEPS += \
./src/test/main.d \
./src/test/main_databinder.d \
./src/test/main_example.d


# Each subdirectory must supply rules for building sources it contributes
src/test/%.o: ../src/test/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"../src/codec" -I"../src/din" -I"../src/iso1" -I"../src/iso2" -I"../src/xmldsig" -I"../src/appHandshake" -I"../src/transport" -I"../src/test" -O0 -g3 -Wall -c -fmessage-length=0 -std=c11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


