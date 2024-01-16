/** @file
  PeiBoardInit.

  @copyright
  Copyright 2018 - 2021 Intel Corporation. <BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef _PEI_BOARD_INIT_PEIM_H_
#define _PEI_BOARD_INIT_PEIM_H_

#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Ppi/UbaCfgDb.h>
#include <Guid/PlatformInfo.h>
#include <Library/PeiServicesLib.h>
#include <Library/HobLib.h>
#include <Library/PeiServicesTablePointerLib.h>
#include <Library/GpioLib.h>
#include <GpioPinsSklH.h>
#include <Ppi/DynamicSiLibraryPpi.h>

// TypeTucana
EFI_STATUS
TypeTucanaPlatformUpdateUsbOcMappings (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
);

EFI_STATUS
TypeTucanaPlatformUpdateAcpiTablePcds (
  VOID
);

EFI_STATUS
TypeTucanaInstallClockgenData (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
);

EFI_STATUS
TypeTucanaInstallPcdData (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
);

EFI_STATUS
TypeTucanaPchEarlyUpdate (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
);

EFI_STATUS
TypeTucanaIioPortBifurcationInit (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
);

EFI_STATUS
TypeTucanaInstallSlotTableData (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
);

EFI_STATUS
TypeTucanaInstallKtiEparamData (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
);

// TypeTucana
EFI_STATUS
TypeTucanaInstallGpioData (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
) ;

EFI_STATUS
TypeTucanaInstallSoftStrapData (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
);
#endif // _PEI_BOARD_INIT_PEIM_H_
