################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ezdsp_setup.c \
../main.c 

ASM_SRCS += \
../delay1.asm \
../mainDown1.asm \
../mainDown2.asm \
../mainUp1.asm \
../mainUp1v2.asm 

CMD_SRCS += \
../lnkx.cmd 

ASM_DEPS += \
./delay1.pp \
./mainDown1.pp \
./mainDown2.pp \
./mainUp1.pp \
./mainUp1v2.pp 

OBJS += \
./delay1.obj \
./ezdsp_setup.obj \
./main.obj \
./mainDown1.obj \
./mainDown2.obj \
./mainUp1.obj \
./mainUp1v2.obj 

C_DEPS += \
./ezdsp_setup.pp \
./main.pp 

OBJS__QTD += \
".\delay1.obj" \
".\ezdsp_setup.obj" \
".\main.obj" \
".\mainDown1.obj" \
".\mainDown2.obj" \
".\mainUp1.obj" \
".\mainUp1v2.obj" 

ASM_DEPS__QTD += \
".\delay1.pp" \
".\mainDown1.pp" \
".\mainDown2.pp" \
".\mainUp1.pp" \
".\mainUp1v2.pp" 

C_DEPS__QTD += \
".\ezdsp_setup.pp" \
".\main.pp" 

ASM_SRCS_QUOTED += \
"../delay1.asm" \
"../mainDown1.asm" \
"../mainDown2.asm" \
"../mainUp1.asm" \
"../mainUp1v2.asm" 

C_SRCS_QUOTED += \
"../ezdsp_setup.c" \
"../main.c" 


# Each subdirectory must supply rules for building sources it contributes
delay1.obj: ../delay1.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="delay1.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
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

mainDown1.obj: ../mainDown1.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainDown1.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

mainDown2.obj: ../mainDown2.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainDown2.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

mainUp1.obj: ../mainUp1.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainUp1.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

mainUp1v2.obj: ../mainUp1v2.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainUp1v2.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


