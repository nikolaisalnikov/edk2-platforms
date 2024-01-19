/** @file

  @copyright
  Copyright 2020 - 2021 Intel Corporation. <BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "PeiBoardInit.h"
#include <Library/UbaGpioUpdateLib.h>

#include <Library/GpioLib.h>
#include <Library/UbaGpioInitLib.h>
#include <GpioPinsSklH.h>
#include <Library/PcdLib.h>

//
// Board     : Wilson City RP
//
static GPIO_INIT_CONFIG mGpioTableWilsonCityRP [] =
  {
 // {GPIO_SKL_H_GPP_A0,  { GpioPadModeGpio, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // Reserved
  {GPIO_SKL_H_GPP_A1,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirInOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JLPC_DP, BMC GPIOAC0, LPC_LAD0
  {GPIO_SKL_H_GPP_A2,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirInOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JLPC_DP, BMC GPIOAC1, LPC_LAD1
  {GPIO_SKL_H_GPP_A3,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirInOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JLPC_DP, BMC GPIOAC2, LPC_LAD2
  {GPIO_SKL_H_GPP_A4,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirInOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JLPC_DP, BMC GPIOAC3, LPC_LAD3
  {GPIO_SKL_H_GPP_A5,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JLPC_FRAME_N, ESPI_CS0_N
  {GPIO_SKL_H_GPP_A6,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // IRQ_SERIRQ, ESPI_CS1_N
  {GPIO_SKL_H_GPP_A7,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // IRQ_PIRQA_N, ESPI_ALERT0_N
 // {GPIO_SKL_H_GPP_A8,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // FM_LPC_CLKRUN_N
  {GPIO_SKL_H_GPP_A9,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // CLK_24M_66M_LPC0_ESPI
  {GPIO_SKL_H_GPP_A10, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirIn, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // TP_GPP_A_10
  {GPIO_SKL_H_GPP_A11, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // FM_LPC_PME_N
  {GPIO_SKL_H_GPP_A12, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirIn, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // IRQ_PCH_SCI_WHEA_N
  {GPIO_SKL_H_GPP_A13, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // FM_EUP_LOT6_N
  {GPIO_SKL_H_GPP_A14, { GpioPadModeNative3, GpioHostOwnDefault, GpioDirOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // RST_ESPI_RESET_N
  {GPIO_SKL_H_GPP_A15, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // FM_SUSACK_N
  //{GPIO_SKL_H_GPP_A16, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirIn, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // TP_PCH_GPP_A_16
  //{GPIO_SKL_H_GPP_A17, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirIn, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // TP_PCH_GPP_A_17
  //{GPIO_SKL_H_GPP_A18, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirIn, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // FM_BIOS_ADV_FUNCTIONS
//  {GPIO_SKL_H_GPP_A20, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirNone, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // TP_PCH_GPP_A_20
//  {GPIO_SKL_H_GPP_A21, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirNone, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // TP_PCH_GPP_A_21
//  {GPIO_SKL_H_GPP_A22, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirNone, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // TP_PCH_GPP_A_22
//  {GPIO_SKL_H_GPP_A23, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirNone, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // TP_PCH_GPP_A_23
    {GPIO_SKL_H_GPP_B0,  { GpioPadModeGpio, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermWpu20K, GpioPadConfigLock}}, // PVNN_PCH_AUX (VID0)
    {GPIO_SKL_H_GPP_B1,  { GpioPadModeGpio, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermWpu20K, GpioPadConfigLock}}, // PVNN_PCH_AUX (VID1)
    {GPIO_SKL_H_GPP_B2,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutLow, GpioIntLevel|GpioIntSci, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // TPM_SPI_IRQ
    // Для остальных пинов (GPP_B3 - GPP_B10) вы можете использовать "N.C." если они не используются.
    {GPIO_SKL_H_GPP_B11, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutLow, GpioIntLevel|GpioIntSci, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // CPLD_PMBUS_ALERT#
    {GPIO_SKL_H_GPP_B12, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirIn, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // Test Point
    {GPIO_SKL_H_GPP_B13, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // Platform Reset
    {GPIO_SKL_H_GPP_B14, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirInOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermWpd20K, GpioPadConfigLock}}, // J6 (Top Swap Override Strap), JSPI0, SPEAKER_SSB
    {GPIO_SKL_H_GPP_B15, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirInOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JOCP (BIF2#), PCH_GPP_B15
    {GPIO_SKL_H_GPP_B16, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirInOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JOCP (PWRRBK#), PCH_GPP_B16
    {GPIO_SKL_H_GPP_B17, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // J5 (Flash Descriptor Security Override Strap), BMC GPIOH7, PCH_GPP_B17
    {GPIO_SKL_H_GPP_B18, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermWpd20K, GpioPadConfigLock}}, // J1 (No Reboot), PCH_GPP_B18
    {GPIO_SKL_H_GPP_B19, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // BMC GPIOA4, PCH_GPP_B19
    {GPIO_SKL_H_GPP_B20, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirInOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // BMC GPIOA5, PCH_GPP_B20
    {GPIO_SKL_H_GPP_B21, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // BMC GPIOA6, PCH_GPP_B21
    {GPIO_SKL_H_GPP_B22, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermWpd20K, GpioPadConfigLock}}, // Boot BIOS Strap, PCH_GPP_B22
    {GPIO_SKL_H_GPP_B23, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirInOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermWpd20K, GpioPadConfigLock}}, // BMC GPIOF0, FM_PCH_BMC_THERMTRIP_N
    {GPIO_SKL_H_GPP_C0,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // SMBus Clock
    {GPIO_SKL_H_GPP_C1,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // SMBus Data
    {GPIO_SKL_H_GPP_C2,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermWpd20K, GpioPadConfigLock}}, // TLS Confidentiality Strap
    {GPIO_SKL_H_GPP_C3,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // SMLink0 Clock
    {GPIO_SKL_H_GPP_C4,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // SMLink0 Data
    {GPIO_SKL_H_GPP_C5,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirOut, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermWpd20K, GpioPadConfigLock}}, // eSPI Enable
    {GPIO_SKL_H_GPP_C6,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // SMLink1 Clock
    {GPIO_SKL_H_GPP_C7,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutLow, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // SMLink1 Data
    {GPIO_SKL_H_GPP_C8,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JOCP (BIF0#)
    {GPIO_SKL_H_GPP_C9,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirIn, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // NMI Input
    {GPIO_SKL_H_GPP_C10, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // VROC KEY
    {GPIO_SKL_H_GPP_C11, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // CPU ERR0
    {GPIO_SKL_H_GPP_C12, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // CPU ERR1
    {GPIO_SKL_H_GPP_C13, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // CPU ERR2
    {GPIO_SKL_H_GPP_C14, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JPMBUS PMBUS_ALERT_N
    {GPIO_SKL_H_GPP_C15, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // Reserved
    {GPIO_SKL_H_GPP_C16, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JPCH_GPIO
    {GPIO_SKL_H_GPP_C17, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JPCH_GPIO
    {GPIO_SKL_H_GPP_C18, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // BMC SRST#
    {GPIO_SKL_H_GPP_C19, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // CPLD CPU CATERR
    {GPIO_SKL_H_GPP_C20, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // BMC I2C SW
    {GPIO_SKL_H_GPP_C21, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JOCP (BIF1#)
    {GPIO_SKL_H_GPP_C22, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntLvlHigh, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // Reserved
    {GPIO_SKL_H_GPP_C23, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntLvlHigh, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // CPLD (THROTTLE_N)

    {GPIO_SKL_H_GPP_D0,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JOCP (PRSNTB0#)
    {GPIO_SKL_H_GPP_D1,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // BMC GPIOAB0 (BIOS POST COMPLETE)
    {GPIO_SKL_H_GPP_D2,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // BMC GPIOZ1 (RSVD)
    {GPIO_SKL_H_GPP_D3,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // J4 Enable Socflash (RSVD)
    {GPIO_SKL_H_GPP_D4,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // BMC GPIOZ2
    {GPIO_SKL_H_GPP_D5,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JOCP (PRSNTB1#)
    {GPIO_SKL_H_GPP_D6,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JOCP (PRSNTB2#)
    {GPIO_SKL_H_GPP_D7,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JOCP (PRSNTB3#)
    {GPIO_SKL_H_GPP_D8,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // CPLD (PCH_DATA)
    // {GPIO_SKL_H_GPP_D11, { ... }}, // N.C. (No Connect)
    {GPIO_SKL_H_GPP_D12, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JSSGPIO (SSATA SGPIO DATA1), SGPIO_SSATA_DATA1
    // {GPIO_SKL_H_GPP_D13, { ... }}, // Reserved
    // {GPIO_SKL_H_GPP_D14, { ... }}, // Reserved
    {GPIO_SKL_H_GPP_D15, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JSSGPIO (SSATA SGPIO DATA0), SGPIO_SSATA_DATA0
    // {GPIO_SKL_H_GPP_D16, { ... }}, // Reserved
    // {GPIO_SKL_H_GPP_D17, { ... }}, // Reserved
    // {GPIO_SKL_H_GPP_D18, { ... }}, // Reserved
    // {GPIO_SKL_H_GPP_D19, { ... }}, // Reserved
    {GPIO_SKL_H_GPP_D20, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // CPLD (PS PWROK SEL), FM_PS_PWROK_DLY_SEL
    // {GPIO_SKL_H_GPP_D21, { ... }}, // N.C. (No Connect)
    // {GPIO_SKL_H_GPP_D22, { ... }}, // N.C. (No Connect)
    // {GPIO_SKL_H_GPP_D23, { ... }}  // N.C. (No Connect)

    {GPIO_SKL_H_GPP_E0,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // PCIE/SATA Strap, PCH_GPP_E0
    {GPIO_SKL_H_GPP_E1,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // PCIE/SATA Strap, PCH_GPP_E1
    {GPIO_SKL_H_GPP_E2,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // PCIE/SATA Strap, PCH_GPP_E2
    {GPIO_SKL_H_GPP_E3,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // CPLD (ADR TRIGGER#), FM_ADR_TRIGGER_N

    // Пины GPP_E4 до GPP_E7 отмечены как "N.C.", поэтому для них не требуется конфигурация.
    // Однако, если вы хотите их включить, они будут выглядеть следующим образом:
    // {GPIO_SKL_H_GPP_E4,  { ... }}, // N.C. (No Connect)
    // {GPIO_SKL_H_GPP_E5,  { ... }}, // N.C. (No Connect)
    // {GPIO_SKL_H_GPP_E6,  { ... }}, // N.C. (No Connect)

    {GPIO_SKL_H_GPP_E7,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // BMC_GPY2 (RSVD), FM_ADR_SMI_GPIO_N
    {GPIO_SKL_H_GPP_E8,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // SATA LED, LED_SATA_ACT_N

    // Пины GPP_E9 до GPP_E12 имеют конкретные функции и не отмечены как "N.C." или "Reserved":
    {GPIO_SKL_H_GPP_E9,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // USB Port 0&1 Overcurrent, USB2_OC1_N
    {GPIO_SKL_H_GPP_E10, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // USB Port 2&3 Overcurrent, USB2_OC2_N
    // {GPIO_SKL_H_GPP_E11, { ... }}, // Reserved
    // {GPIO_SKL_H_GPP_E12, { ... }}  // Reserved

    {GPIO_SKL_H_GPP_F0,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // PCIE/SATA Strap, PCH_GPP_F0
    {GPIO_SKL_H_GPP_F1,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // PCIE/SATA Strap, PCH_GPP_F1
    {GPIO_SKL_H_GPP_F2,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // PCIE/SATA Strap, PCH_GPP_F2
    {GPIO_SKL_H_GPP_F3,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // PCIE/SATA Strap, PCH_GPP_F3
    {GPIO_SKL_H_GPP_F4,  { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // PCIE/SATA Strap, PCH_GPP_F4
    // Пины GPP_F5 до GPP_F7 отмечены как "N.C.", поэтому для них не требуется конфигурация.
    // Однако, если вы хотите их включить, они будут выглядеть следующим образом:
    // {GPIO_SKL_H_GPP_F5,  { ... }}, // N.C. (No Connect)
    // {GPIO_SKL_H_GPP_F6,  { ... }}, // N.C. (No Connect)
    // {GPIO_SKL_H_GPP_F7,  { ... }}, // N.C. (No Connect)

    // Пины GPP_F8 и GPP_F9 отмечены как "Reserved", их конфигурация обычно оставляется по умолчанию или они не включаются.
    // {GPIO_SKL_H_GPP_F8,  { ... }}, // Reserved
    // {GPIO_SKL_H_GPP_F9,  { ... }}, // Reserved
    //{GPIO_SKL_H_GPP_F10, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JSGPIO (SATA SGPIO CLOCK), SGPIO_SATA_CLOCK
    //{GPIO_SKL_H_GPP_F11, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JSGPIO (SATA SGPIO LOAD), SGPIO_SATA_LOAD, RSVD
    //{GPIO_SKL_H_GPP_F12, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JSGPIO (SATA SGPIO DATA1), SGPIO_SATA_DATA1, RSVD
    //{GPIO_SKL_H_GPP_F13, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JSGPIO (SATA SGPIO DATA0), SGPIO_SATA_DATA0, RSVD
    //{GPIO_SKL_H_GPP_F14, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // SSATA LED, LED_SSATA_ACT_N


    // Пины GPP_F17 до GPP_F18 отмечены как "Reserved", их конфигурация обычно оставляется по умолчанию или они не включаются.
    // {GPIO_SKL_H_GPP_F17, { ... }}, // Reserved
    // {GPIO_SKL_H_GPP_F18, { ... }}, // Reserved

    // Пины GPP_F19 до GPP_F21 отмечены как "Reserved" для интерфейса LAN, их конфигурация обычно оставляется по умолчанию.
    // {GPIO_SKL_H_GPP_F19, { ... }}, // Reserved, LAN_SMBCLK
    // {GPIO_SKL_H_GPP_F20, { ... }}, // Reserved, LAN_SMBDAT
    // {GPIO_SKL_H_GPP_F21, { ... }}, // Reserved, LAN_SMBALRT

    {GPIO_SKL_H_GPP_F22, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JSGPIO (SSATA SGPIO CLOCK), SGPIO_SSATA_CLOCK
    {GPIO_SKL_H_GPP_F23, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirNone, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}  // JSGPIO (SSATA SGPIO LOAD), SGPIO_SSATA_LOAD

   // Пины GPP_G0 до GPP_G11 помечены как "N.C." и не требуют конфигурации.

    {GPIO_SKL_H_GPP_G12, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // BOARD ID (BMC GPIOA2), BOARD_ID0
    {GPIO_SKL_H_GPP_G13, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // BOARD ID (BMC GPIOA1), BOARD_ID1
    {GPIO_SKL_H_GPP_G14, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // BOARD ID (BMC GPIOA0), BOARD_ID2
    {GPIO_SKL_H_GPP_G17, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // ADR COMPLETE, FM_ADR_COMPLETE
    {GPIO_SKL_H_GPP_G18, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirOut, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // NMI Output (BMC GPIO5), PCH_NMI_N
    // {GPIO_SKL_H_GPP_G19, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirOut, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // SMI Output (BMC GPIOB5), PCH_SMI_N (RSVD)
    {GPIO_SKL_H_GPP_G20, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirOut, GpioOutDefault, GpioIntNmiSmi, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // PMBUS ALERT N, IRQ_SML1_PMBUS_ALERT_N

    // Пины GPP_G21, GPP_G22 и GPP_G23 помечены как "N.C." и не требуют конфигурации.

    {GPIO_SKL_H_GPP_H10, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JSMB_VR (SMB_VR_CLK), SMB_SMLINK2_STBY_LVC3_SCL
    {GPIO_SKL_H_GPP_H11, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // JSMB_VR (SMB_VR_DAT), SMB_SMLINK2_STBY_LVC3_SDA
    {GPIO_SKL_H_GPP_H12, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermWpd20K, GpioPadConfigLock}}, // SMB_VR_ALERT, IRQ_SML2_ALERT_N
    // {GPIO_SKL_H_GPP_H13, { ... }}, // Reserved
    // {GPIO_SKL_H_GPP_H14, { ... }}, // Reserved
    {GPIO_SKL_H_GPP_H15, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermWpu20K, GpioPadConfigLock}}, // ADR Timer Hold Off Strap, IRQ_SML3_ALERT_N
    // {GPIO_SKL_H_GPP_H16, { ... }}, // Reserved
    // {GPIO_SKL_H_GPP_H17, { ... }}  // Reserved
    // {GPIO_SKL_H_GPP_H18, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermWpu20K, GpioPadConfigLock}}, // Reserved, IRQ_SML4_ALERT_N
    // {GPIO_SKL_H_GPP_H19, { ... }}, // N.C. (No Connect)
    {GPIO_SKL_H_GPP_H20, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // M.2 PCIE/SATA Strap, FM_SSATA_PCIE_M2_1_SEL
    // {GPIO_SKL_H_GPP_H21, { ... }}, // N.C. (No Connect)
    {GPIO_SKL_H_GPP_H22, { GpioPadModeNative1, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // M.2 PCIE/SATA Strap, FM_SSATA_PCIE_M2_2_SEL
    // {GPIO_SKL_H_GPP_H23, { ... }}  // N.C. (No Connect)
    {GPIO_SKL_H_GPP_I7, { GpioPadModeGpio, GpioHostOwnDefault, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetPwrGood, GpioTermNone, GpioPadConfigLock}}, // Test Point, LAN_TRST_N
    
};

EFI_STATUS
TypeWilsonCityRPInstallGpioData (
  IN UBA_CONFIG_DATABASE_PPI    *UbaConfigPpi
)
{
  EFI_STATUS                            Status;

  Status = UbaConfigPpi->AddData (
                                 UbaConfigPpi,
                                 &gPlatformGpioInitDataGuid,
                                 &mGpioTableWilsonCityRP,
                                 sizeof(mGpioTableWilsonCityRP)
                                 );
  Status = PcdSet32S (PcdOemSku_GPIO_TABLE_SIZE, sizeof (mGpioTableWilsonCityRP));
  ASSERT_EFI_ERROR (Status);
  return Status;
}
