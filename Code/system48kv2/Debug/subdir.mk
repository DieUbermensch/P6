################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ezdsp_setup.c \
../main.c 

ASM_SRCS += \
../RMS128.asm \
../RMS128band.asm \
../RMS32band.asm \
../RMS32up.asm \
../RMS64band.asm \
../delay1.asm \
../delay128.asm \
../delay16.asm \
../delay2.asm \
../delay32.asm \
../delay4.asm \
../delay64.asm \
../delay8.asm \
../mainDown1.asm \
../mainDown128.asm \
../mainDown16.asm \
../mainDown2.asm \
../mainDown32.asm \
../mainDown4.asm \
../mainDown64.asm \
../mainDown8.asm \
../mainUp1.asm \
../mainUp128.asm \
../mainUp16.asm \
../mainUp2.asm \
../mainUp32.asm \
../mainUp4.asm \
../mainUp64.asm \
../mainUp8.asm 

CMD_SRCS += \
../lnkx.cmd 

ASM_DEPS += \
./RMS128.pp \
./RMS128band.pp \
./RMS32band.pp \
./RMS32up.pp \
./RMS64band.pp \
./delay1.pp \
./delay128.pp \
./delay16.pp \
./delay2.pp \
./delay32.pp \
./delay4.pp \
./delay64.pp \
./delay8.pp \
./mainDown1.pp \
./mainDown128.pp \
./mainDown16.pp \
./mainDown2.pp \
./mainDown32.pp \
./mainDown4.pp \
./mainDown64.pp \
./mainDown8.pp \
./mainUp1.pp \
./mainUp128.pp \
./mainUp16.pp \
./mainUp2.pp \
./mainUp32.pp \
./mainUp4.pp \
./mainUp64.pp \
./mainUp8.pp 

OBJS += \
./RMS128.obj \
./RMS128band.obj \
./RMS32band.obj \
./RMS32up.obj \
./RMS64band.obj \
./delay1.obj \
./delay128.obj \
./delay16.obj \
./delay2.obj \
./delay32.obj \
./delay4.obj \
./delay64.obj \
./delay8.obj \
./ezdsp_setup.obj \
./main.obj \
./mainDown1.obj \
./mainDown128.obj \
./mainDown16.obj \
./mainDown2.obj \
./mainDown32.obj \
./mainDown4.obj \
./mainDown64.obj \
./mainDown8.obj \
./mainUp1.obj \
./mainUp128.obj \
./mainUp16.obj \
./mainUp2.obj \
./mainUp32.obj \
./mainUp4.obj \
./mainUp64.obj \
./mainUp8.obj 

C_DEPS += \
./ezdsp_setup.pp \
./main.pp 

OBJS__QTD += \
".\RMS128.obj" \
".\RMS128band.obj" \
".\RMS32band.obj" \
".\RMS32up.obj" \
".\RMS64band.obj" \
".\delay1.obj" \
".\delay128.obj" \
".\delay16.obj" \
".\delay2.obj" \
".\delay32.obj" \
".\delay4.obj" \
".\delay64.obj" \
".\delay8.obj" \
".\ezdsp_setup.obj" \
".\main.obj" \
".\mainDown1.obj" \
".\mainDown128.obj" \
".\mainDown16.obj" \
".\mainDown2.obj" \
".\mainDown32.obj" \
".\mainDown4.obj" \
".\mainDown64.obj" \
".\mainDown8.obj" \
".\mainUp1.obj" \
".\mainUp128.obj" \
".\mainUp16.obj" \
".\mainUp2.obj" \
".\mainUp32.obj" \
".\mainUp4.obj" \
".\mainUp64.obj" \
".\mainUp8.obj" 

ASM_DEPS__QTD += \
".\RMS128.pp" \
".\RMS128band.pp" \
".\RMS32band.pp" \
".\RMS32up.pp" \
".\RMS64band.pp" \
".\delay1.pp" \
".\delay128.pp" \
".\delay16.pp" \
".\delay2.pp" \
".\delay32.pp" \
".\delay4.pp" \
".\delay64.pp" \
".\delay8.pp" \
".\mainDown1.pp" \
".\mainDown128.pp" \
".\mainDown16.pp" \
".\mainDown2.pp" \
".\mainDown32.pp" \
".\mainDown4.pp" \
".\mainDown64.pp" \
".\mainDown8.pp" \
".\mainUp1.pp" \
".\mainUp128.pp" \
".\mainUp16.pp" \
".\mainUp2.pp" \
".\mainUp32.pp" \
".\mainUp4.pp" \
".\mainUp64.pp" \
".\mainUp8.pp" 

C_DEPS__QTD += \
".\ezdsp_setup.pp" \
".\main.pp" 

ASM_SRCS_QUOTED += \
"../RMS128.asm" \
"../RMS128band.asm" \
"../RMS32band.asm" \
"../RMS32up.asm" \
"../RMS64band.asm" \
"../delay1.asm" \
"../delay128.asm" \
"../delay16.asm" \
"../delay2.asm" \
"../delay32.asm" \
"../delay4.asm" \
"../delay64.asm" \
"../delay8.asm" \
"../mainDown1.asm" \
"../mainDown128.asm" \
"../mainDown16.asm" \
"../mainDown2.asm" \
"../mainDown32.asm" \
"../mainDown4.asm" \
"../mainDown64.asm" \
"../mainDown8.asm" \
"../mainUp1.asm" \
"../mainUp128.asm" \
"../mainUp16.asm" \
"../mainUp2.asm" \
"../mainUp32.asm" \
"../mainUp4.asm" \
"../mainUp64.asm" \
"../mainUp8.asm" 

C_SRCS_QUOTED += \
"../ezdsp_setup.c" \
"../main.c" 


# Each subdirectory must supply rules for building sources it contributes
RMS128.obj: ../RMS128.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="RMS128.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

RMS128band.obj: ../RMS128band.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="RMS128band.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

RMS32band.obj: ../RMS32band.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="RMS32band.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

RMS32up.obj: ../RMS32up.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="RMS32up.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

RMS64band.obj: ../RMS64band.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="RMS64band.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

delay1.obj: ../delay1.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="delay1.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

delay128.obj: ../delay128.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="delay128.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

delay16.obj: ../delay16.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="delay16.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

delay2.obj: ../delay2.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="delay2.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

delay32.obj: ../delay32.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="delay32.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

delay4.obj: ../delay4.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="delay4.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

delay64.obj: ../delay64.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="delay64.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

delay8.obj: ../delay8.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="delay8.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
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

mainDown128.obj: ../mainDown128.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainDown128.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

mainDown16.obj: ../mainDown16.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainDown16.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

mainDown2.obj: ../mainDown2.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainDown2.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

mainDown32.obj: ../mainDown32.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainDown32.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

mainDown4.obj: ../mainDown4.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainDown4.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

mainDown64.obj: ../mainDown64.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainDown64.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

mainDown8.obj: ../mainDown8.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainDown8.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

mainUp1.obj: ../mainUp1.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainUp1.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

mainUp128.obj: ../mainUp128.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainUp128.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

mainUp16.obj: ../mainUp16.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainUp16.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

mainUp2.obj: ../mainUp2.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainUp2.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

mainUp32.obj: ../mainUp32.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainUp32.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

mainUp4.obj: ../mainUp4.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainUp4.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

mainUp64.obj: ../mainUp64.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainUp64.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

mainUp8.obj: ../mainUp8.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/C5500 Code Generation Tools 4.3.9/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="mainUp8.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


