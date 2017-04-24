################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
EK_TM4C1294XL.obj: ../EK_TM4C1294XL.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/home/ayyappa/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/ayyappa/workspace_v6_1_3/httpServer" --include_path="/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/TivaWare_C_Series-2.1.1.71b" --include_path="/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/bios_6_45_01_29/packages/ti/sysbios/posix" --include_path="/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/ndk_2_25_00_09" --include_path="/home/ayyappa/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C1294NCPDT --define=ccs --define=TIVAWARE --diag_wrap=off --display_error_number --diag_warning=225 --diag_warning=255 --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="EK_TM4C1294XL.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

empty.obj: ../empty.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/home/ayyappa/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/ayyappa/workspace_v6_1_3/httpServer" --include_path="/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/TivaWare_C_Series-2.1.1.71b" --include_path="/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/bios_6_45_01_29/packages/ti/sysbios/posix" --include_path="/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/ndk_2_25_00_09" --include_path="/home/ayyappa/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C1294NCPDT --define=ccs --define=TIVAWARE --diag_wrap=off --display_error_number --diag_warning=225 --diag_warning=255 --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="empty.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: ../empty.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"/home/ayyappa/ti/xdctools_3_31_03_43_core/xs" --xdcpath="/home/ayyappa/ti/tirtos_tivac_2_16_01_14/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/tidrivers_tivac_2_16_01_13/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/bios_6_45_02_31/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/ndk_2_25_00_09/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/uia_2_00_05_50/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/ns_1_11_00_10/packages;/home/ayyappa/ti/ccsv6/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M4F -p ti.platforms.tiva:TM4C1294NCPDT -r release -c "/home/ayyappa/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS" --compileOptions "-mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path=\"/home/ayyappa/workspace_v6_1_3/httpServer\" --include_path=\"/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/TivaWare_C_Series-2.1.1.71b\" --include_path=\"/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/bios_6_45_01_29/packages/ti/sysbios/posix\" --include_path=\"/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/ndk_2_25_00_09\" --include_path=\"/home/ayyappa/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include\" -g --gcc --define=ccs=\"ccs\" --define=PART_TM4C1294NCPDT --define=ccs --define=TIVAWARE --diag_wrap=off --display_error_number --diag_warning=225 --diag_warning=255 --gen_func_subsections=on --abi=eabi  " "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/compiler.opt: | configPkg/linker.cmd
configPkg/: | configPkg/linker.cmd

pinout.obj: ../pinout.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/home/ayyappa/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/home/ayyappa/workspace_v6_1_3/httpServer" --include_path="/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/TivaWare_C_Series-2.1.1.71b" --include_path="/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/bios_6_45_01_29/packages/ti/sysbios/posix" --include_path="/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/ndk_2_25_00_09" --include_path="/home/ayyappa/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" -g --gcc --define=ccs="ccs" --define=PART_TM4C1294NCPDT --define=ccs --define=TIVAWARE --diag_wrap=off --display_error_number --diag_warning=225 --diag_warning=255 --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="pinout.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


