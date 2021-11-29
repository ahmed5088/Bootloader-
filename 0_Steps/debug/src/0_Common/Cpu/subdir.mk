################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/0_Common/Cpu/IfxCpu.c 

OBJS += \
./src/0_Common/Cpu/IfxCpu.o 

C_DEPS += \
./src/0_Common/Cpu/IfxCpu.d 


# Each subdirectory must supply rules for building sources it contributes
src/0_Common/Cpu/%.o: ../src/0_Common/Cpu/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TriCore C Compiler'
	"C:\HighTec\toolchains\tricore\v4.9.3.0-infineon-1.0/bin/tricore-gcc" -c @ccompilerincludelist.optfile -fno-common -fno-short-enums -funsigned-bitfields -O0 -g3 -W -Wall -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -pipe -fomit-frame-pointer -ffreestanding -fshort-double -mcpu=tc21xx -fdata-sections -ffunction-sections -mversion-info -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


