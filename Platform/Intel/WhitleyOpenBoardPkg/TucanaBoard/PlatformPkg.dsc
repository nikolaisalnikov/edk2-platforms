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
  gMinPlatformPkgTokenSpaceGuid.PcdPerformanceEnable                        |FALSE

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
  FLASH_DEFINITION                    = WhitleyOpenBoardPkg/$(BOARD_NAME)/PlatformPkg.fdf

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
!include $(RP_PKG)/Include/Dsc/EnableRichDebugMessages.dsc
#!include $(RP_PKG)/Include/Dsc/EnableAllDebugMessages.dsc

!include WhitleyOpenBoardPkg/$(BOARD_NAME)/Include/Dsc/UbaSingleBoardPei.dsc

[Components]
  UefiCpuPkg/SecCore/SecCore.inf

  !include MinPlatformPkg/Include/Dsc/CorePeiInclude.dsc

  MdeModulePkg/Universal/PCD/Pei/Pcd.inf {
    <LibraryClasses>
      #
      # Beware of circular dependencies on PCD if you want to use another DebugLib instance.
      #
      PcdLib|MdePkg/Library/BasePcdLibNull/BasePcdLibNull.inf
      NULL|$(FSP_BIN_PKG)/Library/FspPcdListLibNull/FspPcdListLibNull.inf                 # Include FSP DynamicEx PCD
      NULL|$(FSP_BIN_PKG)/Library/FspPcdListLibNull/FspPcdListLibNullFvLateSilicon.inf    # Include FvLateSilicon DynamicEx PCD
      NULL|$(FSP_BIN_PKG)/Library/FspPcdListLibNull/FspPcdListLibNullFvLateOpenBoard.inf  # Include FvLateBoard DynamicEx PCD
  }
  $(RP_PKG)/Universal/PeiExStatusCodeRouter/ExReportStatusCodeRouterPei.inf
  $(RP_PKG)/Universal/PeiExStatusCodeHandler/ExStatusCodeHandlerPei.inf
  $(RP_PKG)/Universal/PeiInterposerToSvidMap/PeiInterposerToSvidMap.inf

  $(RP_PKG)/Features/Variable/PlatformVariable/Pei/PlatformVariableInitPei.inf

  $(RP_PKG)/Platform/Pei/PlatformInfo/PlatformInfo.inf

  $(PLATFORM_PKG)/PlatformInit/ReportFv/ReportFvPei.inf

  $(PLATFORM_PKG)/PlatformInit/SiliconPolicyPei/SiliconPolicyPeiPreMem.inf{
    <LibraryClasses>
      SiliconWorkaroundLib|WhitleySiliconPkg/Library/SiliconWorkaroundLibNull/SiliconWorkaroundLibNull.inf
  }
  $(RP_PKG)/Platform/Pei/EmulationPlatformInit/EmulationPlatformInit.inf
  $(PLATFORM_PKG)/PlatformInit/PlatformInitPei/PlatformInitPostMem.inf {
    <LibraryClasses>
      TestPointCheckLib|MinPlatformPkg/Test/Library/TestPointCheckLibNull/TestPointCheckLibNull.inf
      BoardInitLib|$(PLATFORM_PKG)/PlatformInit/Library/BoardInitLibNull/BoardInitLibNull.inf
  }

  IntelFsp2WrapperPkg/FspmWrapperPeim/FspmWrapperPeim.inf
!if ($(FSP_MODE) == 0)
  IntelFsp2WrapperPkg/FspsWrapperPeim/FspsWrapperPeim.inf
  $(RP_PKG)/Platform/Pei/DummyPchSpi/DummyPchSpi.inf
!endif

  $(RP_PKG)/BiosInfo/BiosInfo.inf

  WhitleySiliconPkg/Pch/SouthClusterLbg/MultiPch/Pei/MultiPchPei.inf
  UefiCpuPkg/PiSmmCommunication/PiSmmCommunicationPei.inf

  UefiCpuPkg/CpuMpPei/CpuMpPei.inf

  UefiCpuPkg/Universal/Acpi/S3Resume2Pei/S3Resume2Pei.inf {
    <LibraryClasses>
    !if gMinPlatformPkgTokenSpaceGuid.PcdPerformanceEnable == TRUE
      TimerLib|UefiCpuPkg/Library/SecPeiDxeTimerLibUefiCpu/SecPeiDxeTimerLibUefiCpu.inf
    !endif
  }

  !include MinPlatformPkg/Include/Dsc/CoreDxeInclude.dsc

  $(RP_PKG)/Platform/Dxe/PlatformType/PlatformType.inf

  MinPlatformPkg/Test/TestPointDumpApp/TestPointDumpApp.inf

  MdeModulePkg/Universal/SectionExtractionDxe/SectionExtractionDxe.inf
  MdeModulePkg/Universal/Acpi/S3SaveStateDxe/S3SaveStateDxe.inf
  MdeModulePkg/Universal/Acpi/BootScriptExecutorDxe/BootScriptExecutorDxe.inf

  MdeModulePkg/Universal/LockBox/SmmLockBox/SmmLockBox.inf
  UefiCpuPkg/PiSmmCommunication/PiSmmCommunicationSmm.inf

  ShellPkg/Application/Shell/Shell.inf {
      <LibraryClasses>
      ShellCommandLib|ShellPkg/Library/UefiShellCommandLib/UefiShellCommandLib.inf
      NULL|ShellPkg/Library/UefiShellLevel2CommandsLib/UefiShellLevel2CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellLevel1CommandsLib/UefiShellLevel1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellLevel3CommandsLib/UefiShellLevel3CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellDriver1CommandsLib/UefiShellDriver1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellDebug1CommandsLib/UefiShellDebug1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellInstall1CommandsLib/UefiShellInstall1CommandsLib.inf
      NULL|ShellPkg/Library/UefiShellNetwork1CommandsLib/UefiShellNetwork1CommandsLib.inf
      HandleParsingLib|ShellPkg/Library/UefiHandleParsingLib/UefiHandleParsingLib.inf
      PrintLib|MdePkg/Library/BasePrintLib/BasePrintLib.inf
      BcfgCommandLib|ShellPkg/Library/UefiShellBcfgCommandLib/UefiShellBcfgCommandLib.inf
      IoLib|MdePkg/Library/BaseIoLibIntrinsic/BaseIoLibIntrinsic.inf

    <PcdsFixedAtBuild>
      gEfiMdePkgTokenSpaceGuid.PcdDebugPropertyMask|0xFF
      gEfiShellPkgTokenSpaceGuid.PcdShellLibAutoInitialize|FALSE
      gEfiMdePkgTokenSpaceGuid.PcdUefiLibMaxPrintBufferSize|8000
  }

  $(RP_PKG)/Cpu/Dxe/PlatformCpuPolicy/PlatformCpuPolicy.inf
  UefiCpuPkg/CpuDxe/CpuDxe.inf
  UefiCpuPkg/CpuS3DataDxe/CpuS3DataDxe.inf

  $(RP_PKG)/Features/Pci/Dxe/PciHostBridge/PciHostBridge.inf
  IntelSiliconPkg/Feature/Flash/SpiFvbService/SpiFvbServiceSmm.inf

  $(RP_PKG)/Features/Pci/Dxe/PciPlatform/PciPlatform.inf

!if $(CPUTARGET) == "ICX"
  $(RP_PKG)/Features/Acpi/AcpiPlatform/AcpiPlatform.inf
  $(RP_PKG)/Features/Acpi/AcpiTables/AcpiTables10nm.inf
!endif
  $(RP_PKG)/Features/AcpiVtd/AcpiVtd.inf

  $(PLATFORM_PKG)/Acpi/AcpiSmm/AcpiSmm.inf

  $(PLATFORM_PKG)/PlatformInit/PlatformInitDxe/PlatformInitDxe.inf {
  <LibraryClasses>
    BoardInitLib|$(RP_PKG)/Library/BoardInitLib/BoardInitDxeLib.inf
  }
  $(RP_PKG)/Platform/Dxe/S3NvramSave/S3NvramSave.inf {
!if ($(FSP_MODE) == 0)
    <BuildOptions>
        *_*_*_CC_FLAGS  = -D FSP_API_MODE
!endif
  }

  $(PLATFORM_PKG)/FspWrapper/SaveMemoryConfig/SaveMemoryConfig.inf

  $(PLATFORM_SI_BIN_PACKAGE)/CpxMicrocode/MicrocodeUpdates.inf
  $(PLATFORM_SI_BIN_PACKAGE)/IcxMicrocode/MicrocodeUpdates.inf

  MdeModulePkg/Bus/Pci/PciSioSerialDxe/PciSioSerialDxe.inf
  MdeModulePkg/Universal/Console/TerminalDxe/TerminalDxe.inf
  BoardModulePkg/LegacySioDxe/LegacySioDxe.inf
  BoardModulePkg/BoardBdsHookDxe/BoardBdsHookDxe.inf

  MdeModulePkg/Bus/Pci/NvmExpressDxe/NvmExpressDxe.inf

  MdeModulePkg/Universal/PlatformDriOverrideDxe/PlatformDriOverrideDxe.inf

  MdeModulePkg/Universal/SmbiosDxe/SmbiosDxe.inf
  MdeModulePkg/Universal/SmbiosMeasurementDxe/SmbiosMeasurementDxe.inf
  MdeModulePkg/Bus/Ata/AtaBusDxe/AtaBusDxe.inf
  MdeModulePkg/Bus/Ata/AtaAtapiPassThru/AtaAtapiPassThru.inf

  #
  # SiliconPkg code for Platform Integration are defined here
  #
!if $(CPUTARGET) == "CPX"
  DEFINE CPU_CPX_SUPPORT                     = TRUE
!else
  DEFINE CPU_CPX_SUPPORT                     = FALSE
!endif