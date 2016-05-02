################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

EMPTY := 
SPACE := $(EMPTY) $(EMPTY)

ORDERED_OBJS += \
$(GEN_CMDS_QUOTED) \
"./mainUp8.obj" \
"./mainUp64.obj" \
"./mainUp4.obj" \
"./mainUp32.obj" \
"./mainUp2.obj" \
"./mainUp16.obj" \
"./mainUp128.obj" \
"./mainUp1.obj" \
"./mainDown8.obj" \
"./mainDown64.obj" \
"./mainDown4.obj" \
"./mainDown32.obj" \
"./mainDown2.obj" \
"./mainDown16.obj" \
"./mainDown128.obj" \
"./mainDown1.obj" \
"./main.obj" \
"./ezdsp_setup.obj" \
"./delay8.obj" \
"./delay64.obj" \
"./delay4.obj" \
"./delay32.obj" \
"./delay2.obj" \
"./delay16.obj" \
"./delay128.obj" \
"./delay1.obj" \
"./RMS64band.obj" \
"./RMS32up.obj" \
"./RMS32band.obj" \
"./RMS128band.obj" \
"./RMS128.obj" \
-l"rts55x.lib" \
"../lnkx.cmd" \

-include ../makefile.init

RM := DEL /F

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: system48k.out

# Tool invocations
system48k.out: $(GEN_CMDS) $(CMD_SRCS) $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --diag_warning=225 --ptrdiff_size=16 --memory_model=large -z -m"system48k.map" --warn_sections -i"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/lib" -i"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --reread_libs --rom_model -o "system48k.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C5500_EXECUTABLE_OUTPUTS__QTD) "system48k.out"
	-$(RM) ".\RMS128.obj" ".\RMS128band.obj" ".\RMS32band.obj" ".\RMS32up.obj" ".\RMS64band.obj" ".\delay1.obj" ".\delay128.obj" ".\delay16.obj" ".\delay2.obj" ".\delay32.obj" ".\delay4.obj" ".\delay64.obj" ".\delay8.obj" ".\ezdsp_setup.obj" ".\main.obj" ".\mainDown1.obj" ".\mainDown128.obj" ".\mainDown16.obj" ".\mainDown2.obj" ".\mainDown32.obj" ".\mainDown4.obj" ".\mainDown64.obj" ".\mainDown8.obj" ".\mainUp1.obj" ".\mainUp128.obj" ".\mainUp16.obj" ".\mainUp2.obj" ".\mainUp32.obj" ".\mainUp4.obj" ".\mainUp64.obj" ".\mainUp8.obj" 
	-$(RM) ".\RMS128.pp" ".\RMS128band.pp" ".\RMS32band.pp" ".\RMS32up.pp" ".\RMS64band.pp" ".\delay1.pp" ".\delay128.pp" ".\delay16.pp" ".\delay2.pp" ".\delay32.pp" ".\delay4.pp" ".\delay64.pp" ".\delay8.pp" ".\mainDown1.pp" ".\mainDown128.pp" ".\mainDown16.pp" ".\mainDown2.pp" ".\mainDown32.pp" ".\mainDown4.pp" ".\mainDown64.pp" ".\mainDown8.pp" ".\mainUp1.pp" ".\mainUp128.pp" ".\mainUp16.pp" ".\mainUp2.pp" ".\mainUp32.pp" ".\mainUp4.pp" ".\mainUp64.pp" ".\mainUp8.pp" 
	-$(RM) ".\ezdsp_setup.pp" ".\main.pp" 
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
