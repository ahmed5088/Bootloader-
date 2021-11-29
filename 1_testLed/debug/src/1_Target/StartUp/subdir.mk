################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/1_Target/StartUp/Target_CStart0.c 

OBJS += \
./src/1_Target/StartUp/Target_CStart0.o 

C_DEPS += \
./src/1_Target/StartUp/Target_CStart0.d 


# Each subdirectory must supply rules for building sources it contributes
src/1_Target/StartUp/%.o: ../src/1_Target/StartUp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TriCore C Compiler'
	"C:\HighTec\toolchains\tricore\v4.9.3.0-infineon-1.0/bin/tricore-gcc" -c @ccompilerincludelist.optfile -fno-common -fno-short-enums -funsigned-bitfields -O0 -g3 -W -Wall -Wextra -Wdiv-by-zero -Warray-bounds -Wcast-align -Wignored-qualifiers -Wformat -Wformat-security -pipe -fomit-frame-pointer -ffreestanding -fshort-double -mcpu=tc27xx -fdata-sections -ffunction-sections -mversion-info -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


