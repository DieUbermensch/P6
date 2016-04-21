################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ezdsp_setup.c \
../main.c 

ASM_SRCS += \
../FIR.asm 

CMD_SRCS += \
../lnkx.cmd 

ASM_DEPS += \
./FIR.pp 

OBJS += \
./FIR.obj \
./ezdsp_setup.obj \
./main.obj 

C_DEPS += \
./ezdsp_setup.pp \
./main.pp 

OBJS__QTD += \
".\FIR.obj" \
".\ezdsp_setup.obj" \
".\main.obj" 

ASM_DEPS__QTD += \
".\FIR.pp" 

C_DEPS__QTD += \
".\ezdsp_setup.pp" \
".\main.pp" 

ASM_SRCS_QUOTED += \
"../FIR.asm" 

C_SRCS_QUOTED += \
"../ezdsp_setup.c" \
"../main.c" 


# Each subdirectory must supply rules for building sources it contributes
FIR.obj: ../FIR.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="FIR.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

ezdsp_setup.obj: ../ezdsp_setup.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="ezdsp_setup.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


