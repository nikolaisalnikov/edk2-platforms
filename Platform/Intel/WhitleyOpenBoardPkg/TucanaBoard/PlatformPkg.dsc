## @file PlatformPkg.dsc
# BoardPortTemplate reference platform single board build target.
#
#
# @copyright
# Copyright 2008 - 2020 Intel Corporation. <BR>
#
# SPDX-License-Identifier: BSD-2-Clause-Patent
##

[Defines]
  PLATFORM_NAME                       = WhitleyOpenBoardPkgTucana
  PEI_ARCH                            = IA32
  DXE_ARCH                            = X64

!include WhitleyOpenBoardPkg/PlatformPkg.dsc

#
# Feature enable/disable flags
#
[PcdsFeatureFlag]
  #
  # MinPlatform control flags
  #
  gMinPlatformPkgTokenSpaceGuid.PcdStopAfterDebugInit                       |FALSE
  gMinPlatformPkgTokenSpaceGuid.PcdStopAfterMemInit                         |FALSE
  gMinPlatformPkgTokenSpaceGuid.PcdBootToShellOnly                          |FALSE
  gMinPlatformPkgTokenSpaceGuid.PcdPerformanceEnable                        |TRUE

  #
  # Debugging features
  #
  gAcpiDebugFeaturePkgTokenSpaceGuid.PcdAcpiDebugFeatureEnable              |FALSE
  gBeepDebugFeaturePkgTokenSpaceGuid.PcdBeepDebugFeatureEnable              |FALSE
  gPostCodeDebugFeaturePkgTokenSpaceGuid.PcdPostCodeDebugFeatureEnable      |FALSE
  gUsb3DebugFeaturePkgTokenSpaceGuid.PcdUsb3DebugFeatureEnable              |FALSE

  #
  # Network features
  #
  gNetworkFeaturePkgTokenSpaceGuid.PcdNetworkFeatureEnable                  |FALSE

  #
  # OutOfBandManagement features
  #
  gIpmiFeaturePkgTokenSpaceGuid.PcdIpmiFeatureEnable                        |FALSE
  gSpcrFeaturePkgTokenSpaceGuid.PcdSpcrFeatureEnable                        |FALSE

  #
  # PowerManagement features
  #
  gS3FeaturePkgTokenSpaceGuid.PcdS3FeatureEnable                            |FALSE

  #
  # SystemInformation features
  #
  gSmbiosFeaturePkgTokenSpaceGuid.PcdSmbiosFeatureEnable                    |FALSE

  #
  # UserInterface features
  #
  gLogoFeaturePkgTokenSpaceGuid.PcdLogoFeatureEnable                        |FALSE
  gUserAuthFeaturePkgTokenSpaceGuid.PcdUserAuthenticationFeatureEnable      |FALSE
  gVirtualKeyboardFeaturePkgTokenSpaceGuid.PcdVirtualKeyboardFeatureEnable  |FALSE

!include AdvancedFeaturePkg/Include/AdvancedFeatures.dsc

[Defines]
  DEFINE BOARD_NAME                   = TucanaBoard
  PLATFORM_GUID                       = 905d6302-4261-4495-b40b-8705cb6ed8a3
  OUTPUT_DIRECTORY                    = Build/$(RP_PKG)
  SUPPORTED_ARCHITECTURES             = X64
  BUILD_TARGETS                       = DEBUG|RELEASE
  FLASH_DEFINITION                    = $(RP_PKG)/$(BOARD_NAME)/PlatformPkg.fdf

#
# Advanced feature selection/enablement
#

[PcdsFixedAtBuild]
  gPlatformTokenSpaceGuid.PcdBoardId|0x80 # TypeTucanaBoard

[PcdsDynamicExHii]
  gEfiMdePkgTokenSpaceGuid.PcdPlatformBootTimeOut|L"Timeout"|gEfiGlobalVariableGuid|0x0|5 # Variable: L"Timeout"

#
# Increase debug message levels
# Several options are provided, last uncommented one will take effect
#
#!include $(RP_PKG)/Include/Dsc/EnableRichDebugMessages.dsc
#!include $(RP_PKG)/Include/Dsc/EnableAllDebugMessages.dsc

!include $(RP_PKG)/$(BOARD_NAME)/Include/Dsc/UbaSingleBoardPei.dsc