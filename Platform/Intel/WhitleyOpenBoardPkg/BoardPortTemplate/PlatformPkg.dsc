## @file PlatformPkg.dsc
# BoardPortTemplate reference platform single board build target.
#
#
# @copyright
# Copyright 2008 - 2020 Intel Corporation. <BR>
#
# SPDX-License-Identifier: BSD-2-Clause-Patent
##

# TucanaBoardPkg.dsc
[Defines]
  PLATFORM_NAME                 = TucanaBoard
  SUPPORTED_ARCHITECTURES       = IA32|X64
  BUILD_TARGETS                 = DEBUG|RELEASE
  CPU_SUPPORT_XEON_SCALABLE_3RD_GEN = TRUE
  CPU_TDP                       = 270W
  SOCKET_TYPE                   = SocketP+
  MEMORY_CHANNELS_PER_CPU       = 8
  MEMORY_SPEEDS_SUPPORTED       = DDR4_3200MHz|DDR4_2933MHz
  MAX_MEMORY_CAPACITY           = 4096GB
  CPU0_PCIE_SLOTS               = 2xPCIeGen4X16|1xOCPV3.0|1xSlimlineX8
  CPU1_PCIE_SLOTS               = 1xPCIeGen4X16|2xPCIeGen4X8|3xSlimlineX8
  SATA_PORTS                    = 12xSATA6Gb/s
  BMC_CONTROLLER                = AspeedAST2500
  BMC_NETWORK_PORT              = RealtekRTL8211EGbE
  LAN_NETWORK_PORT              = IntelI210GbE
  USB_PORTS                     = 2xUSB3.2TypeA|2xUSBpinheaders
  VIDEO_OUTPUT                 = 1xVGAinternal
  SERIAL_PORTS                 = 1xCOMexternal|1xCOM2boxheader|1xCOM1boxheader
  TPM_VERSION                   = TPM2.0

# Additional components and settings may be added as needed.


!include $(RP_PKG)/PlatformPkg.dsc