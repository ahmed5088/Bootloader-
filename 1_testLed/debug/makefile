################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := "$(TRICORE_TOOLS)/bin/rm" -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/1_Target/Traps/subdir.mk
-include src/1_Target/StartUp/subdir.mk
-include src/1_Target/Mcal/Port/subdir.mk
-include src/1_Target/BMH/subdir.mk
-include src/0_Common/Scu/subdir.mk
-include src/0_Common/Libs/Bsp/subdir.mk
-include src/0_Common/Cpu/subdir.mk
-include src/0_Common/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(I_DEPS)),)
-include $(I_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPCP_DEPS)),)
-include $(CPCP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# Rebuild target
rebuild: clean all

# All Target
all: 1_testLed.elf

# Tool invocations
1_testLed.elf: $(OBJS) $(USER_OBJS) $(ASM)
	@echo 'Building target: $@'
	@echo 'Invoking: TriCore C Linker'
	"C:\HighTec\toolchains\tricore\v4.9.3.0-infineon-1.0/bin/tricore-gcc" -o  "1_testLed.elf" -nocrt0 -nostartfiles -T"C:/BootLoader/1_testLed\src\0_Common\LinkerScript_HighTec_TC275.ld" -Wl,--gc-sections -mcpu=tc27xx -Wl,--mem-holes -Wl,--no-warn-flags -Wl,--warn-orphan -Wl,@objectlist.optfile -Wl,@libpathlist.optfile -Wl,-Map="$(basename $(notdir $@)).map" -Wl,--cref -fshort-double -Wl,-n -Wl,--extmap=a
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	$(foreach __cleandir__,${SUBDIRS},$(call do-clean-dir,$(__cleandir__)))
	@echo 'Cleaning: 1_testLed.elf'
	@$(RM) 1_testLed.elf
	@echo ' '

define do-clean-dir
	@echo 'Cleaning: $1/*.o *.d'
	@$(RM) $1/*.o $1/*.d

endef

legacy-clean:
	-$(RM) $(I_DEPS)$(EXECUTABLES)$(OBJS)$(C_DEPS)$(CPCP_DEPS) 1_testLed.elf
	-@echo ' '

post-build:
	-$(TRICORE_TOOLS)/bin/tricore-objcopy.exe  -O ihex  "1_testLed.elf"  "1_testLed.hex"
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
