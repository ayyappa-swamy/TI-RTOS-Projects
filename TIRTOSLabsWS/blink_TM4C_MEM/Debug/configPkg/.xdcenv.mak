#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /home/ayyappa/ti/ccsv6/ccs_base;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/tidrivers_tivac_2_16_01_13/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/bios_6_45_02_31/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/ndk_2_25_00_09/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/uia_2_00_05_50/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/ns_1_11_00_10/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/bios_6_41_00_26/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/ndk_2_24_01_18/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/uia_2_00_02_39/packages
override XDCROOT = /home/ayyappa/ti/xdctools_3_31_03_43_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /home/ayyappa/ti/ccsv6/ccs_base;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/tidrivers_tivac_2_16_01_13/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/bios_6_45_02_31/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/ndk_2_25_00_09/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/uia_2_00_05_50/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/ns_1_11_00_10/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/bios_6_41_00_26/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/ndk_2_24_01_18/packages;/home/ayyappa/ti/tirtos_tivac_2_16_01_14/products/uia_2_00_02_39/packages;/home/ayyappa/ti/xdctools_3_31_03_43_core/packages;..
HOSTOS = Linux
endif
