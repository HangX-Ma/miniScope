/**
 * @file config_stc8ax.h
 * @author MContour (m-contour@qq.com)
 * @brief core and peripheral definition for stc8ax 
 * @details This file contains all the peripheral register's definitions, bits 
 *          definitions and memory mapping for STC8x Connectivity line.
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Apache 2.0 LICENSE
 * 
 *****************************************************************************
 * Copyright (c) [2022-04-27] [MContour m-contour@qq.com]
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************
 */
#ifndef __CONFIG_STC8AX_H__
#define __CONFIG_STC8AX_H__

#include "base_stc8x.h"
//包含本头文件后,不用另外再包含"REG51.H"

/**
 * @defgroup Special_function_registers
 * Special function registers locate at the expension RAM area.
 * If you want to read/write the special function registers, the BIT7 of P_SW2 needs to be set as 1.
 */

/**
 * @defgroup Peripherals
 * Peripherals basic usage functions
 */

/** @addtogroup STC
 * @{
 */

/** @defgroup configuration
 * @{
 */


//! kernel special function register setting 
sfr ACC         =   (uint8_t)0xE0;                      //!< accumulator
sfr B           =   (uint8_t)0xF0;                      //!< B register
sfr PSW         =   (uint8_t)0xD0;                      //!< program state register
sfr SP          =   (uint8_t)0x81;                      //!< stack pointer
sfr DPL         =   (uint8_t)0x82;                      //!< Data Pointer (low byte)
sfr DPH         =   (uint8_t)0x83;                      //!< Data Pointer (high byte)
sfr TA          =   (uint8_t)0xAE;                      //!< DPTR timing control register
sfr DPS         =   (uint8_t)0xE3;                      //!< DPTR pointer selector
sfr DPL1        =   (uint8_t)0xE4;                      //!< The second set of data pointers (low bytes)
sfr DPH1        =   (uint8_t)0xE5;                      //!< The second set of data pointers (high bytes)

sbit CY         =   PSW^7;                              /*!< carry/borrow flag bit */
sbit AC         =   PSW^6;                              /*!< auxiliary carry/borrow flag bit */
sbit F0         =   PSW^5;                              /*!< user flag bit 0 */
sbit RS1        =   PSW^4;                              /*!< working state selection bit RS1 */
sbit RS0        =   PSW^3;                              /*!< working state selection bit RS0 */
sbit OV         =   PSW^2;                              /*!< overflow flag bit */
sbit F1         =   PSW^1;                              /*!< user flag bit 1 */
sbit P          =   PSW^0;                              /*!< party check flag bit */

/** @defgroup Peripheral_memory_map
 * @{
 */

//! system management special function register setting 
/* bus speed control register setting */
#define     BUS_SPEED_ADDR              ((uint8_t)0xA1)

/* Bit definition for BUS_SPEED register */
// * RW_S configuration
#define     BUS_SPEED_RW_S              ((uint8_t)0xC0) /*!< RW_S[1:0] bits (control line selection) */
#define     BUS_SPEED_RW_S_0            ((uint8_t)0x40) /*!< Bit 0 */
#define     BUS_SPEED_RW_S_1            ((uint8_t)0x80) /*!< Bit 1 */

#define     BUS_SPEED_RW_S_GROUP1       ((uint8_t)0x00) /*!< select P4.4 pin as RD and P4.3 as WR */
#define     BUS_SPEED_RW_S_GROUP2       ((uint8_t)0x40) /*!< select P3.7 pin as RD and P3.6 as WR */
#define     BUS_SPEED_RW_S_GROUP3       ((uint8_t)0x80) /*!< select P4.2 pin as RD and P4.0 as WR */

// * SPEED configuration
#define     BUS_SPEED_SPEED             ((uint8_t)0x03) /*!< SPEED[1:0] bits (bus read/write speed control) */
#define     BUS_SPEED_SPEED_0           ((uint8_t)0x01) /*!< Bit 0 */
#define     BUS_SPEED_SPEED_1           ((uint8_t)0x02) /*!< Bit 1 */

#define     BUS_SPEED_SPEED_VAL0        ((uint8_t)0x00) /*!< speed numeric value 0 */
#define     BUS_SPEED_SPEED_VAL1        ((uint8_t)0x01) /*!< speed numeric value 1 */
#define     BUS_SPEED_SPEED_VAL2        ((uint8_t)0x02) /*!< speed numeric value 2 */
#define     BUS_SPEED_SPEED_VAL3        ((uint8_t)0x03) /*!< speed numeric value 3 */


sfr BUS_SPEED   =   BUS_SPEED_ADDR; //! bus speed control register

/*  auxiliary register setting */
#define     AUXR_ADDR                   ((uint8_t)0x8E)

/* Bit definition for AUXR register */
// * EXTRAM configuration
#define     AUXR_EXTRAM                 ((uint8_t)0x02) /*!< external RAM access control */

sfr AUXR        =   AUXR_ADDR;      //! auxiliary register

/* peripheral port switch register setting */
#define     PERIPHERAL_PORT_SW1_ADDR    ((uint8_t)0xA2)
#define     PERIPHERAL_PORT_SW2_ADDR    ((uint8_t)0xBA)

/* Bit definition for P_SW1 register */
// * S1_S configuration
#define     P_SW1_S1_S                  ((uint8_t)0xC0) /*!< S1_S[1:0] bits (serial port 1 function pins selection) */
#define     P_SW1_S1_S_0                ((uint8_t)0x40) /*!< Bit 0 TxD */
#define     P_SW1_S1_S_1                ((uint8_t)0x80) /*!< Bit 1 RxD */

#define     P_SW1_S1_S_GROUP1           ((uint8_t)0x00) /*!< select P3.0 pin as RxD and P3.1 as TxD */
#define     P_SW1_S1_S_GROUP2           ((uint8_t)0x40) /*!< select P3.6 pin as RxD and P3.7 as TxD */
#define     P_SW1_S1_S_GROUP3           ((uint8_t)0x80) /*!< select P1.6 pin as RxD and P1.7 as TxD */
#define     P_SW1_S1_S_GROUP4           ((uint8_t)0xC0) /*!< select P4.3 pin as RxD and P4.4 as TxD */

// * CCP_S configuration
#define     P_SW1_CCP_S                 ((uint8_t)0x30) /*!< CCP_S[1:0] bits (PCA function pins selection) */
#define     P_SW1_CCP_S_0               ((uint8_t)0x10) /*!< Bit 0 */
#define     P_SW1_CCP_S_1               ((uint8_t)0x20) /*!< Bit 1 */

#define     P_SW1_CCP_S_GROUP1          ((uint8_t)0x00) /*!< select P1.2 pin as ECI, P1.7 as CPP0, P1.6 as CPP1, P1.5 as CPP2, P1.4 as CPP3 */
#define     P_SW1_CCP_S_GROUP2          ((uint8_t)0x10) /*!< select P2.2 pin as ECI, P2.3 as CPP0, P2.4 as CPP1, P2.5 as CPP2, P2.6 as CPP3 */
#define     P_SW1_CCP_S_GROUP3          ((uint8_t)0x20) /*!< select P7.4 pin as ECI, P7.0 as CPP0, P7.1 as CPP1, P7.2 as CPP2, P7.3 as CPP3 */
#define     P_SW1_CCP_S_GROUP4          ((uint8_t)0x30) /*!< select P3.5 pin as ECI, P3.3 as CPP0, P3.2 as CPP1, P3.1 as CPP2, P3.0 as CPP3 */

// * SPI_S configuration
#define     P_SW1_SPI_S                 ((uint8_t)0x0C) /*!< SPI_S[1:0] bits (SPI function pins selection) */
#define     P_SW1_SPI_S_0               ((uint8_t)0x04) /*!< Bit 0 */
#define     P_SW1_SPI_S_1               ((uint8_t)0x08) /*!< Bit 1 */

#define     P_SW1_SPI_S_GROUP1          ((uint8_t)0x00) /*!< select P1.2 pin as SS, P1.3 as MOSI, P1.4 as MISO, P1.5 as SCLK */
#define     P_SW1_SPI_S_GROUP2          ((uint8_t)0x04) /*!< select P2.2 pin as SS, P2.3 as MOSI, P2.4 as MISO, P2.5 as SCLK */
#define     P_SW1_SPI_S_GROUP3          ((uint8_t)0x08) /*!< select P7.4 pin as SS, P7.5 as MOSI, P7.6 as MISO, P7.7 as SCLK */
#define     P_SW1_SPI_S_GROUP4          ((uint8_t)0x0C) /*!< select P3.5 pin as SS, P3.4 as MOSI, P3.3 as MISO, P3.2 as SCLK */

/* Bit definition for P_SW1 register */
// * EAXFR configuration
#define     P_SW2_EAXFR                 ((uint8_t)0x80) /*!< XFR control register */

// * I2C_S configuration
#define     P_SW2_I2C_S                 ((uint8_t)0x30) /*!< I2C_S[1:0] bits (I2C function pins selection) */
#define     P_SW2_I2C_S_0               ((uint8_t)0x10) /*!< Bit 0 SDA */
#define     P_SW2_I2C_S_1               ((uint8_t)0x20) /*!< Bit 1 SCL */

#define     P_SW2_I2C_S_GROUP1          ((uint8_t)0x00) /*!< select P1.5 pin as SCL, P1.4 as SDA */
#define     P_SW2_I2C_S_GROUP2          ((uint8_t)0x10) /*!< select P2.5 pin as SCL, P2.4 as SDA */
#define     P_SW2_I2C_S_GROUP3          ((uint8_t)0x20) /*!< select P7.7 pin as SCL, P7.6 as SDA */
#define     P_SW2_I2C_S_GROUP4          ((uint8_t)0x30) /*!< select P3.2 pin as SCL, P3.3 as SDA */

// * CMPO_S configuration
#define     P_SW2_CMPO_S                ((uint8_t)0x08) /*!< CMPO selection: [0] P3.4; [1] P4.1 */

// * S4_S configuration
#define     P_SW2_S4_S                  ((uint8_t)0x04) /*!< serial port 4 function pins selection: [0] RxD4=P0.2, TxD4=P0.3; [1] RxD4=P5.2, TxD4=P5.3 */

// * S3_S configuration
#define     P_SW2_S3_S                  ((uint8_t)0x02) /*!< serial port 3 function pins selection: [0] RxD3=P0.0, TxD3=P0.1; [1] RxD3=P5.0, TxD3=P5.1  */

// * S2_S configuration
#define     P_SW2_S2_S                  ((uint8_t)0x01) /*!< serial port 2 function pins selection: [0] RxD2=P1.0, TxD2=P1.1; [1] RxD2=P4.0, TxD2=P4.2  */

sfr P_SW1       =   PERIPHERAL_PORT_SW1_ADDR;   //!< Peripheral Port Switch Register 1
sfr P_SW2       =   PERIPHERAL_PORT_SW2_ADDR;   //!< Peripheral Port Switch Register 2

/**
 * @brief system clock control interface
 * 
 */
typedef struct
{
    __IO uint8_t RCC_CKSEL;
    __IO uint8_t RCC_CLKDIV;
    __IO uint8_t RCC_IRC24MCR;
    __IO uint8_t RCC_XOSCCR;
    __IO uint8_t RCC_IRC32KCR;
} SYSCLK_TypeDef;

// * system clock special function register setting in internal expansion RAM 
/* internel oscillator frequency control and adjustment registers*/
#define     IRTRIM_ADDR                 ((uint8_t)0x9F)
#define     LIRTRIM_ADDR                ((uint8_t)0x9E)

/* Bit definition for IRTRIM register */
// user define the value from 0~255 for this register

/* Bit definition for LIRTRIM register */
#define     LIRTRIM_BITS                ((uint8_t)0x03)
#define     LIRTRIM_BITS_0              ((uint8_t)0x01)
#define     LIRTRIM_BITS_1              ((uint8_t)0x02)

#define     LIRTRIM_BITS_FT000          ((uint8_t)0x00) /*!< on fine-turning */
#define     LIRTRIM_BITS_FT001          ((uint8_t)0x01) /*!< Internal high accurate IRC fine-turning 0.01% */
#define     LIRTRIM_BITS_FT004          ((uint8_t)0x02) /*!< Internal high accurate IRC fine-turning 0.04% */
#define     LIRTRIM_BITS_FT010          ((uint8_t)0x03) /*!< Internal high accurate IRC fine-turning 0.10% */


sfr IRTRIM      =   IRTRIM_ADDR;    //! internal IRC frequency adjustment register
sfr LIRTRIM     =   LIRTRIM_ADDR;   //! internal IRC frequency subtle adjustment register

/* system clock base address */
#define     SYSCLK_BASE                 ((uint16_t)0xFE00)

#define     CKSEL_ADDR                  (SYSCLK_BASE + 0x0000)
#define     CLKDIV_ADDR                 (SYSCLK_BASE + 0x0001)
#define     IRC24MCR_ADDR               (SYSCLK_BASE + 0x0002)
#define     XOSCCR_ADDR                 (SYSCLK_BASE + 0x0003)
#define     IRC32KCR_ADDR               (SYSCLK_BASE + 0x0004)

/* Bit definition for CKSEL register */
// * MCLKODIV configuration
#define     CKSEL_MCLKODIV              ((uint8_t)0xF0) /*!< MCLKODIV[3:0] bits (main clock output division coefficient) */
#define     CKSEL_MCLKODIV_0            ((uint8_t)0x10) /*!< Bit 0 */
#define     CKSEL_MCLKODIV_1            ((uint8_t)0x20) /*!< Bit 1 */
#define     CKSEL_MCLKODIV_2            ((uint8_t)0x40) /*!< Bit 2 */
#define     CKSEL_MCLKODIV_3            ((uint8_t)0x80) /*!< Bit 3 */

#define     CKSEL_MCLKODIV_DIV0         ((uint8_t)0x00) /*!< no MCLK output */
#define     CKSEL_MCLKODIV_DIV1         ((uint8_t)0x10) /*!< MCLK input clock not divided */
#define     CKSEL_MCLKODIV_DIV2         ((uint8_t)0x20) /*!< MCLK input clock divided by 2 */
#define     CKSEL_MCLKODIV_DIV4         ((uint8_t)0x40) /*!< MCLK input clock divided by 4 */
#define     CKSEL_MCLKODIV_DIV8         ((uint8_t)0x60) /*!< MCLK input clock divided by 8 */
#define     CKSEL_MCLKODIV_DIV16        ((uint8_t)0x80) /*!< MCLK input clock divided by 16 */
#define     CKSEL_MCLKODIV_DIV32        ((uint8_t)0xA0) /*!< MCLK input clock divided by 32 */
#define     CKSEL_MCLKODIV_DIV64        ((uint8_t)0xC0) /*!< MCLK input clock divided by 64 */
#define     CKSEL_MCLKODIV_DIV128       ((uint8_t)0xE0) /*!< MCLK input clock divided by 128 */

// * MCLKO_S configuration
#define     CKSEL_MCLKO_S               ((uint8_t)0x08) /*!< divided MCLK output pin: [0] P5.4; [1] P1.6 */

// * MCKSEL configuration
#define     CKSEL_MCKSEL                ((uint8_t)0x03) /*!< MCLKODIV[1:0] bits (system clock output division coefficient) */
#define     CKSEL_MCKSEL_0              ((uint8_t)0x01) /*!< Bit 0 */
#define     CKSEL_MCKSEL_1              ((uint8_t)0x02) /*!< Bit 1 */

#define     CKSEL_MCKSEL_IRC24MCR       ((uint8_t)0x00) /*!< select internal 24MHz High accurate IRC */
#define     CKSEL_MCKSEL_XOSCCR_O       ((uint8_t)0x01) /*!< select outer clock input */
#define     CKSEL_MCKSEL_XOSCCR_C       ((uint8_t)0x02) /*!< select outer clock input */
#define     CKSEL_MCKSEL_IRC32KST       ((uint8_t)0x03) /*!< select internal 32kHz low speed IRC */

/* Bit definition for CLKDIV register */
// user define the value from 0~255 for this register. Maximum 0.55% per bit, minium 0.02% per bit, average 0.24% per bit

/* Bit definition for IRC24MCR register */
// * ENIRC24M configuration
#define     IRC24MCR_ENIRC24M           ((uint8_t)0x80) /*!< IRC24MCR enabling control */

// * IRC24MST configuration
#define     IRC24MCR_IRC24MST           ((uint8_t)0x01) /*!< IRC24MCR stable state flag */

/* Bit definition for XOSCCR register */
// * ENXOSC configuration
#define     XOSCCR_ENXOSC               ((uint8_t)0x80) /*!< external oscillator enabling control */

// * XITYPE configuration
#define     XOSCCR_XITYPE               ((uint8_t)0x40) /*!< external oscillator type selection */

// * XOSCST configuration
#define     XOSCCR_XOSCST               ((uint8_t)0x01) /*!< external oscillator stable state flag */

/* Bit definition for IRC32KCR register */
// * ENIRC32K configuration
#define     IRC32KCR_ENIRC32K           ((uint8_t)0x80) /*!< IRC32KCR enabling control */

// * IRC32KST configuration
#define     IRC32KCR_IRC32KST           ((uint8_t)0x01) /*!< IRC32KCR stable state flag */

/**
 * @brief define the SYSCLK type
 * @note To access XDATA peripherals, use the \c volatile keyword to ensure 
 * that the C compiler does not optimize out necessary memory accesses.
 */
#define     SYSCLK          ((SYSCLK_TypeDef xdata *) SYSCLK_BASE)

#define     CKSEL           (*(__IO uint8_t xdata *)   CKSEL_ADDR)     //!< system clock selection
#define     CLKDIV          (*(__IO uint8_t xdata *)   CLKDIV_ADDR)    //!< system clock division
#define     IRC24MCR        (*(__IO uint8_t xdata *)   IRC24MCR_ADDR)  //!< internal 24MHz oscillator control
#define     XOSCCR          (*(__IO uint8_t xdata *)   XOSCCR_ADDR)    //!< external oscillator control
#define     IRC32KCR        (*(__IO uint8_t xdata *)   IRC32KCR_ADDR)  //!< internal 32kHz oscillator control

//! system power special function register setting
/* power control base address */
#define     PCON_ADDR                   ((uint8_t)0x87)
#define     VOCTRL_ADDR                 ((uint8_t)0xBB)

/* Bit definition for PCON register */
// * LVDF configuration
#define     PCON_LVDF                   ((uint8_t)0x20)     /*!< low voltage check flag bit */

// * POF configuration
#define     PCON_POF                    ((uint8_t)0x10)     /*!< Power-on reset flag bit */

// * PD configuration
#define     PCON_PD                     ((uint8_t)0x02)     /*!< peripherals stopping mode control bit */

// * IDL configuration
#define     PCON_IDL                    ((uint8_t)0x01)     /*!< peripherals IDLE mode control bit */

/* Bit definition for VOCTRL register */
// * SCC configuration
#define     VOCTRL_SCC                   ((uint8_t)0x80)     /*!< static current control bit: [0] internal circuit 1.5uA; [1] external circuit lower than 0.15uA */

sfr PCON        =   PCON_ADDR;          //! power source control register
sfr VOCTRL      =   VOCTRL_ADDR;        //! voltage level control register

//! system reset special function register control
/* reset control base address */
#define     WDT_CONTR_ADDR              ((uint8_t)0xC1)
// #define     IAP_ADDR      0xC7u
#define     RSTCFG_ADDR                 ((uint8_t)0xFF)

/* Bit definition for WDT_CONTR register */
// * WDT_FLAG configuration
#define     WDT_CONTR_WDT_FLAG          ((uint8_t)0x80)     /*!< Watch dog overflow flag */

// * EN_WDT configuration
#define     WDT_CONTR_EN_WDT            ((uint8_t)0x20)     /*!< Watch dog enabling bit：[0] off; [1] on */

// * CLR_WDT configuration
#define     WDT_CONTR_CLR_WDT           ((uint8_t)0x10)     /*!< Watch dog timer auto clearance by firmware：[0] off; [1] on */

// * IDL_WDT configuration
#define     WDT_CONTR_IDL_WDT           ((uint8_t)0x08)     /*!< Watch dog counting function control on IDLE model [0] stop; [1] resume */

// * WDT_PS configuration
#define     WDT_CONTR_WDT_PS            ((uint8_t)0x07)     /*!< WDT_PS[2:0] bits (watch dog timer clock division coefficient) */
#define     WDT_CONTR_WDT_PS0           ((uint8_t)0x01)     /*!< Bit 0 */
#define     WDT_CONTR_WDT_PS1           ((uint8_t)0x02)     /*!< Bit 1 */
#define     WDT_CONTR_WDT_PS2           ((uint8_t)0x04)     /*!< Bit 2 */

/**
 * @note  watch dog overflow time = (12x32768x2^(WDT_PS+1))/SYSCLK
 */
#define     WDT_CONTR_WDT_PS_DIV2       ((uint8_t)0x00)     /*!< Watch dog input clock divided by 2 */
#define     WDT_CONTR_WDT_PS_DIV4       ((uint8_t)0x01)     /*!< Watch dog input clock divided by 4 */
#define     WDT_CONTR_WDT_PS_DIV8       ((uint8_t)0x02)     /*!< Watch dog input clock divided by 8 */
#define     WDT_CONTR_WDT_PS_DIV16      ((uint8_t)0x03)     /*!< Watch dog input clock divided by 16 */
#define     WDT_CONTR_WDT_PS_DIV32      ((uint8_t)0x04)     /*!< Watch dog input clock divided by 32 */
#define     WDT_CONTR_WDT_PS_DIV64      ((uint8_t)0x05)     /*!< Watch dog input clock divided by 64 */
#define     WDT_CONTR_WDT_PS_DIV128     ((uint8_t)0x06)     /*!< Watch dog input clock divided by 128 */
#define     WDT_CONTR_WDT_PS_DIV256     ((uint8_t)0x07)     /*!< Watch dog input clock divided by 256 */

/* Bit definition for RSTCFG register */
// * ENLVR configuration
#define     RSTCFG_ENLVR                ((uint8_t)0x40)     /*!< low voltage reset control bit */

// * P54RST configuration
#define     RSTCFG_P54RST               ((uint8_t)0x10)     /*!< RST pin selection: [0] regard P5.4 as normal pin; [1]: regard P5.4 as RST */

// * LVDS configuration
#define     RSTCFG_LVDS                 ((uint8_t)0x03)     /*!< WDT_PS[1:0] bits（low voltage threshold selection） */
#define     RSTCFG_LVDS_0               ((uint8_t)0x01)     /*!< Bit 0 */
#define     RSTCFG_LVDS_1               ((uint8_t)0x02)     /*!< Bit 1 */

#define     RSTCFG_LVDS_2V2             ((uint8_t)0x00)     /*!< low voltage threshold 2.2V */
#define     RSTCFG_LVDS_2V4             ((uint8_t)0x01)     /*!< low voltage threshold 2.4V */
#define     RSTCFG_LVDS_2V7             ((uint8_t)0x02)     /*!< low voltage threshold 2.7V */
#define     RSTCFG_LVDS_3V0             ((uint8_t)0x03)     /*!< low voltage threshold 3.0V */

sfr WDT_CONTR   =   WDT_CONTR_ADDR;     //! Watch dog control register
// sfr IAP_CONTR   =   IAP_ADDR;
sfr RSTCFG      =   RSTCFG_ADDR;        //! Reset configuration register

/* wake up timer base address */
#define     WKT_BASE                    ((uint8_t)0xAA)
#define     WKTCL_ADDR                  (WKT_BASE + 0x0000u)
#define     WKTCH_ADDR                  (WKT_BASE + 0x0001u)

/* WKTCH offset */
#define WKTEN       0x80

sfr WKTCL       =   WKTCL_ADDR;         //! Power down wake up timer low bytes
sfr WKTCH       =   WKTCH_ADDR;         //! Power down wake up timer high bytes

//! GPIO peripherals
#define     GPIO_BASE       ((uint8_t)0x80)
#define     PxM0_BASE       ((uint8_t)0x94)
#define     PxM1_BASE       ((uint8_t)0x93)
#define     PxPU_BASE       ((uint16_t)0xFE10)
#define     PxNCS_BASE      ((uint16_t)0xFE18)

/* GPIO address definition */
#define     P0_ADDR         (GPIO_BASE + 0x00u) 
#define     P1_ADDR         (GPIO_BASE + 0x10u) 
#define     P2_ADDR         (GPIO_BASE + 0x20u) 
#define     P3_ADDR         (GPIO_BASE + 0x30u) 
#define     P4_ADDR         (GPIO_BASE + 0x40u) 
#define     P5_ADDR         (GPIO_BASE + 0x48u) 
#define     P6_ADDR         (GPIO_BASE + 0x68u) 
#define     P7_ADDR         (GPIO_BASE + 0x78u) 

/* PxM0: GPIO configuration registers 0 address definition */
#define     P0M0_ADDR       PxM0_BASE 
#define     P1M0_ADDR       ((uint8_t)0x92)
#define     P2M0_ADDR       ((uint8_t)0x96)
#define     P3M0_ADDR       ((uint8_t)0xB2)
#define     P4M0_ADDR       ((uint8_t)0xB4)
#define     P5M0_ADDR       ((uint8_t)0xCA)
#define     P6M0_ADDR       ((uint8_t)0xCC)
#define     P7M0_ADDR       ((uint8_t)0xE2)

/* PxM1: GPIO configuration registers 1 address definition */
#define     P0M1_ADDR       PxM1_BASE 
#define     P1M1_ADDR       ((uint8_t)0x91)
#define     P2M1_ADDR       ((uint8_t)0x95)
#define     P3M1_ADDR       ((uint8_t)0xB1)
#define     P4M1_ADDR       ((uint8_t)0xB3)
#define     P5M1_ADDR       ((uint8_t)0xC9)
#define     P6M1_ADDR       ((uint8_t)0xCB)
#define     P7M1_ADDR       ((uint8_t)0xE1)

/* GPIO pull up resistor control register address definition */
#define     P0PU_ADDR        (PxPU_BASE + 0x00u)
#define     P1PU_ADDR        (PxPU_BASE + 0x01u)
#define     P2PU_ADDR        (PxPU_BASE + 0x02u)
#define     P3PU_ADDR        (PxPU_BASE + 0x03u)
#define     P4PU_ADDR        (PxPU_BASE + 0x04u)
#define     P5PU_ADDR        (PxPU_BASE + 0x05u)
#define     P6PU_ADDR        (PxPU_BASE + 0x06u)
#define     P7PU_ADDR        (PxPU_BASE + 0x07u)

/*GPIO schmidt trigger control register address definition */

#define    P0NCS_ADDR       (PxNCS_BASE + 0x00u)
#define    P1NCS_ADDR       (PxNCS_BASE + 0x01u)
#define    P2NCS_ADDR       (PxNCS_BASE + 0x02u)
#define    P3NCS_ADDR       (PxNCS_BASE + 0x03u)
#define    P4NCS_ADDR       (PxNCS_BASE + 0x04u)
#define    P5NCS_ADDR       (PxNCS_BASE + 0x05u)
#define    P6NCS_ADDR       (PxNCS_BASE + 0x06u)
#define    P7NCS_ADDR       (PxNCS_BASE + 0x07u)


/* GPIO registers configuration */
sfr P0          =   P0_ADDR;
sfr P1          =   P1_ADDR;
sfr P2          =   P2_ADDR;
sfr P3          =   P3_ADDR;
sfr P4          =   P4_ADDR;
sfr P5          =   P5_ADDR;
sfr P6          =   P6_ADDR;
sfr P7          =   P7_ADDR;

/**
 * @note GPIO mode selection
 * \verbatim 
 * | PnM1.x | PnM0.x |         Pn.x Mode         |
 * |   0    |   0    | quasi- bidirectional port | ([weak pull up] up to 20mA constant-current; pull current between 150~270uA)
 * |   0    |   1    |      push-pul output      | ([strong pull up] up to 20mA contant-current; current-limited resistor is needed)
 * |   1    |   0    |   high impedance output   | (no current)
 * |   1    |   1    |     open drain output     | (internal pull up resistor disconnected; external pull up resistor is needed)
 * \endverbatim
 */

/* Bit definition for GPIO control registers */
/* GPIO configuration registers 0 */
sfr P0M0        =   P0M0_ADDR;
sfr P1M0        =   P1M0_ADDR;
sfr P2M0        =   P2M0_ADDR;
sfr P3M0        =   P3M0_ADDR;
sfr P4M0        =   P4M0_ADDR;
sfr P5M0        =   P5M0_ADDR;
sfr P6M0        =   P6M0_ADDR;
sfr P7M0        =   P7M0_ADDR;

/* GPIO configuration registers 1 */
sfr P0M1        =   P0M1_ADDR;
sfr P1M1        =   P1M1_ADDR;
sfr P2M1        =   P2M1_ADDR;
sfr P3M1        =   P3M1_ADDR;
sfr P4M1        =   P4M1_ADDR;
sfr P5M1        =   P5M1_ADDR;
sfr P6M1        =   P6M1_ADDR;
sfr P7M1        =   P7M1_ADDR;

/* Bit definition for GPIO pins */
sbit P00        =   P0^0;
sbit P01        =   P0^1;
sbit P02        =   P0^2;
sbit P03        =   P0^3;
sbit P04        =   P0^4;
sbit P05        =   P0^5;
sbit P06        =   P0^6;
sbit P07        =   P0^7;
sbit P10        =   P1^0;
sbit P11        =   P1^1;
sbit P12        =   P1^2;
sbit P13        =   P1^3;
sbit P14        =   P1^4;
sbit P15        =   P1^5;
sbit P16        =   P1^6;
sbit P17        =   P1^7;
sbit P20        =   P2^0;
sbit P21        =   P2^1;
sbit P22        =   P2^2;
sbit P23        =   P2^3;
sbit P24        =   P2^4;
sbit P25        =   P2^5;
sbit P26        =   P2^6;
sbit P27        =   P2^7;
sbit P30        =   P3^0;
sbit P31        =   P3^1;
sbit P32        =   P3^2;
sbit P33        =   P3^3;
sbit P34        =   P3^4;
sbit P35        =   P3^5;
sbit P36        =   P3^6;
sbit P37        =   P3^7;
sbit P40        =   P4^0;
sbit P41        =   P4^1;
sbit P42        =   P4^2;
sbit P43        =   P4^3;
sbit P44        =   P4^4;
sbit P45        =   P4^5;
sbit P46        =   P4^6;
sbit P47        =   P4^7;
sbit P50        =   P5^0;
sbit P51        =   P5^1;
sbit P52        =   P5^2;
sbit P53        =   P5^3;
sbit P54        =   P5^4;
sbit P55        =   P5^5;
sbit P56        =   P5^6;
sbit P57        =   P5^7;
sbit P60        =   P6^0;
sbit P61        =   P6^1;
sbit P62        =   P6^2;
sbit P63        =   P6^3;
sbit P64        =   P6^4;
sbit P65        =   P6^5;
sbit P66        =   P6^6;
sbit P67        =   P6^7;
sbit P70        =   P7^0;
sbit P71        =   P7^1;
sbit P72        =   P7^2;
sbit P73        =   P7^3;
sbit P74        =   P7^4;
sbit P75        =   P7^5;
sbit P76        =   P7^6;
sbit P77        =   P7^7;

// * GPIO pull up resistor control registers: [0] off; [1] on*/
#define     P0PU        (*(__IO uint8_t xdata *) P0PU_ADDR)             // Extended SFR
#define     P1PU        (*(__IO uint8_t xdata *) P1PU_ADDR)             // Extended SFR
#define     P2PU        (*(__IO uint8_t xdata *) P2PU_ADDR)             // Extended SFR
#define     P3PU        (*(__IO uint8_t xdata *) P3PU_ADDR)             // Extended SFR
#define     P4PU        (*(__IO uint8_t xdata *) P4PU_ADDR)             // Extended SFR
#define     P5PU        (*(__IO uint8_t xdata *) P5PU_ADDR)             // Extended SFR
#define     P6PU        (*(__IO uint8_t xdata *) P6PU_ADDR)             // Extended SFR
#define     P7PU        (*(__IO uint8_t xdata *) P7PU_ADDR)             // Extended SFR

// * GPIO Schmitt trigger control registers: [0] off; [1] on */
#define     P0NCS       (*(__IO uint8_t xdata *) P1NCS_ADDR)            // Extended SFR
#define     P1NCS       (*(__IO uint8_t xdata *) P2NCS_ADDR)            // Extended SFR
#define     P2NCS       (*(__IO uint8_t xdata *) P3NCS_ADDR)            // Extended SFR
#define     P3NCS       (*(__IO uint8_t xdata *) P4NCS_ADDR)            // Extended SFR
#define     P4NCS       (*(__IO uint8_t xdata *) P5NCS_ADDR)            // Extended SFR
#define     P5NCS       (*(__IO uint8_t xdata *) P6NCS_ADDR)            // Extended SFR
#define     P6NCS       (*(__IO uint8_t xdata *) P7NCS_ADDR)            // Extended SFR
#define     P7NCS       (*(__IO uint8_t xdata *) P8NCS_ADDR)            // Extended SFR

#define GPIO_Px(x)  (P##x)
#define Px_M1(x) 	(P##x##M1)
#define Px_M0(x) 	(P##x##M0)
#define Px_PU(x)    (P##x##PU)
#define Px_SR(x)    (P##x##SR)
#define Px_DR(x)    (P##x##DR)
#define Px_IE(x)    (P##x##IE)
#define Px_NCS(x)   (P##x##NCS)

//! ISR peripherals
<<<<<<< HEAD
/* ISR basic address definition */
#define    IE_ADDR                      ((uint8_t)0xA8)
#define    IE2_ADDR                     ((uint8_t)0xAF)
#define    ISR_PRIORITY_CONTR_BASE      ((uint8_t)0xB5)

#define    IP_ADDR                      (ISR_PRIORITY_CONTR_BASE + 0x03)
#define    IPH_ADDR                     (ISR_PRIORITY_CONTR_BASE + 0x02)
#define    IP2_ADDR                     (ISR_PRIORITY_CONTR_BASE + 0x00)
#define    IP2H_ADDR                    (ISR_PRIORITY_CONTR_BASE + 0x01)

#define    INTCLKO_ADDR                 ((uint8_t)0x8F)
#define    AUXINTIF_ADDR                ((uint8_t)0xEF)

/* Bit definition for IE2 registers [0] off; [1] on */
#define     IE2_ET4         ((uint8_t)0x40)             /*!< Timer T4 overflow interrupt enabling bit */
#define     IE2_ET3         ((uint8_t)0x20)             /*!< Timer T3 overflow interrupt enabling bit */
#define     IE2_ES4         ((uint8_t)0x10)             /*!< serial port S4 interrupt enabling bit */
#define     IE2_ES3         ((uint8_t)0x08)             /*!< serial port S3 interrupt enabling bit */
#define     IE2_ET2         ((uint8_t)0x04)             /*!< Timer T2 overflow interrupt enabling bit */
#define     IE2_ESPI        ((uint8_t)0x02)             /*!< SPI interrupt enabling bit */
#define     IE2_ES2         ((uint8_t)0x01)             /*!< serial port S2 interrupt enabling bit */

/* Bit definition for IP registers */
#define     IP_PPCA         ((uint8_t)0x80)
#define     IP_PLVD         ((uint8_t)0x40)
#define     IP_PADC         ((uint8_t)0x20)
#define     IP_PS           ((uint8_t)0x10)
#define     IP_PT1          ((uint8_t)0x08)
#define     IP_PX1          ((uint8_t)0x04)
#define     IP_PT0          ((uint8_t)0x02)
#define     IP_PX0          ((uint8_t)0x01)

/* Bit definition for IPH registers */
#define     IPH_PPCAH       ((uint8_t)0x80)
#define     IPH_PLVDH       ((uint8_t)0x40)
#define     IPH_PADCH       ((uint8_t)0x20)
#define     IPH_PSH         ((uint8_t)0x10)
#define     IPH_PT1H        ((uint8_t)0x08)
#define     IPH_PX1H        ((uint8_t)0x04)
#define     IPH_PT0H        ((uint8_t)0x02)
#define     IPH_PX0H        ((uint8_t)0x01)

/* Bit definition for IP2 registers */
#define     IP2_PI2C        ((uint8_t)0x40)
#define     IP2_PCMP        ((uint8_t)0x20)
#define     IP2_PX4         ((uint8_t)0x10)
#define     IP2_PPWMFD      ((uint8_t)0x08)
#define     IP2_PPWM        ((uint8_t)0x04)
#define     IP2_PSPI        ((uint8_t)0x02)
#define     IP2_PS2         ((uint8_t)0x01)

/* Bit definition for IP2H registers */
#define     IP2H_PI2CH      ((uint8_t)0x40)
#define     IP2H_PCMPH      ((uint8_t)0x20)
#define     IP2H_PX4H       ((uint8_t)0x10)
#define     IP2H_PPWMFDH    ((uint8_t)0x08)
#define     IP2H_PPWMH      ((uint8_t)0x04)
#define     IP2H_PSPIH      ((uint8_t)0x02)
#define     IP2H_PS2H       ((uint8_t)0x01)

/* Bit definition for INTCLKO registers */
#define     INTCLKO_EX4     ((uint8_t)0x40)             /*!< external interrupt 4 interrupt enabling flag */
#define     INTCLKO_EX3     ((uint8_t)0x20)             /*!< external interrupt 3 interrupt enabling flag */
#define     INTCLKO_EX2     ((uint8_t)0x10)             /*!< external interrupt 2 interrupt enabling flag */
#define     INTCLKO_T2CLKO  ((uint8_t)0x04)


/* Bit definition for AUXINTIF registers */
#define     AUXINTIF_INT4IF ((uint8_t)0x40)             /*!< external interrupt 4 interrupt request flag */
#define     AUXINTIF_INT3IF ((uint8_t)0x20)             /*!< external interrupt 3 interrupt request flag */
#define     AUXINTIF_INT2IF ((uint8_t)0x10)             /*!< external interrupt 2 interrupt request flag */
#define     AUXINTIF_T4IF   ((uint8_t)0x04)             /*!< timer 4 overflow interrupt request flag */
#define     AUXINTIF_T3IF   ((uint8_t)0x02)             /*!< timer 3 overflow interrupt request flag */
#define     AUXINTIF_T2IF   ((uint8_t)0x01)             /*!< timer 2 overflow interrupt request flag */

<<<<<<< HEAD
/* ISR special function register */
sfr IE          =   IE_ADDR;                            //! interrupt enabling register
sfr IE2         =   IE2_ADDR;                           //! interrupt enabling register 2
sfr IP          =   IP_ADDR;                            //! interrupt priority control register IP
sfr IP2         =   IP2_ADDR;                           //! interrupt priority control register IP2
sfr IPH         =   IPH_ADDR;                           //! interrupt priority control register IPH
sfr IP2H        =   IP2H_ADDR;                          //! interrupt priority control register IP2H
sfr INTCLKO     =   INTCLKO_ADDR;                       //! external interrupt and clock output control registers
sfr AUXINTIF    =   AUXINTIF_ADDR;                      //! interrupt flag auxiliary register


/* Bit definition for IE register (interrupt enabling register) */ 
sbit IE_EA      =   IE^7;                               /*!< totoal interrupt enabling control bit */
sbit IE_ELVD    =   IE^6;                               /*!< low voltage check interrupt enabling control bit */
sbit IE_EADC    =   IE^5;                               /*!< A/D convertion interrupt enabling control bit */
sbit IE_ES      =   IE^4;                               /*!< serial port 1 interrupt enabling control bit */
sbit IE_ET1     =   IE^3;                               /*!< timer T1 overflow interrupt enabling control bit */
sbit IE_EX1     =   IE^2;                               /*!< external interrupt 1 interrupt enabling control bit */
sbit IE_ET0     =   IE^1;                               /*!< timer T0 interrupt enabling control bit */
sbit IE_EX0     =   IE^0;                               /*!< external interrupt 0 interrupt enabling control bit */

/* Bit definition for IP register */
sbit IP_PPCA       =   IP^7;
sbit IP_PLVD       =   IP^6;
sbit IP_PADC       =   IP^5;
sbit IP_PS         =   IP^4;
sbit IP_PT1        =   IP^3;
sbit IP_PX1        =   IP^2;
sbit IP_PT0        =   IP^1;
sbit IP_PX0        =   IP^0;

//! Timer peripherals
/* timer basic address definition */
#define     Timer_BASE      ((uint8_t)0x88)
#define     TCON_ADDR       (Timer_BASE + 0x00u)
#define     TMOD_ADDR       (Timer_BASE + 0x01u)
#define     TL0_ADDR        (Timer_BASE + 0x02u)
#define     TL1_ADDR        (Timer_BASE + 0x03u)
#define     TH0_ADDR        (Timer_BASE + 0x04u)
#define     TH1_ADDR        (Timer_BASE + 0x05u)

#define     T2T3T4_BASE     ((uint8_t)0xD1)
#define     T4T3M_ADDR      (T2T3T4_BASE + 0x00u)
#define     T4H_ADDR        (T2T3T4_BASE + 0x01u)
#define     T4L_ADDR        (T2T3T4_BASE + 0x02u)
#define     T3H_ADDR        (T2T3T4_BASE + 0x03u)
#define     T3L_ADDR        (T2T3T4_BASE + 0x04u)
#define     T2H_ADDR        (T2T3T4_BASE + 0x05u)
#define     T2L_ADDR        (T2T3T4_BASE + 0x06u)

/* Bit definition for TMOD register */
#define     TMOD_T1_GATE    ((uint8_t)0x80)        /*!< Timer/Counter T1 control. T1 works when TR1=1 and INT1 is high. */
#define     TMOD_T1_CT      ((uint8_t)0x40)        /*!< Timer/Counter T1 function selection: [0] timer-internal SYSCLK input; [1] counter-P3.5 input */

#define     TMOD_T1_SEL     ((uint8_t)0x30)        /*!< Mode selection [1:0] (decided by M1 and M0) */
#define     TMOD_T1_M1      ((uint8_t)0x20)        /*!< BIT [1] */
#define     TMOD_T1_M0      ((uint8_t)0x10)        /*!< BIT [0] */

#define     TMOD_T1_SEL_16B_AUTO_RELOAD             ((uint8_t)0x00)     /*!< 16 bits auto reload mode. When T1 overflowing, T1 reload [TH1, TL1] */
#define     TMOD_T1_SEL_16B_REPEATED                ((uint8_t)0x10)     /*!< 16 bits repeated mode. When T1 overflowing, T1 starts from 0. */
#define     TMOD_T1_SEL_8B_AUTO_RELOAD              ((uint8_t)0x20)     /*!< 8 bits auto reload mode. When T1 overflowing, T1 reload [TL1] with [TH1]. */
#define     TMOD_T1_SEL_STOP                        ((uint8_t)0x30)     /*!< T1 stop working */


#define     TMOD_T0_GATE    ((uint8_t)0x08)        /*!< Timer T0 control. T1 works when TR1=1 and INT1 is high. */
#define     TMOD_T0_CT      ((uint8_t)0x04)        /*!< Timer/Counter T1 function selection: [0] timer-internal SYSCLK input; [1] counter-P3.4 input */

#define     TMOD_T0_SEL     ((uint8_t)0x30)        /*!< Mode selection [1:0] (decided by M1 and M0) */
#define     TMOD_T0_M1      ((uint8_t)0x02)        /*!< BIT [1] */
#define     TMOD_T0_M0      ((uint8_t)0x01)        /*!< BIT [0] */

#define     TMOD_T0_SEL_16B_AUTO_RELOAD             ((uint8_t)0x00)     /*!< 16 bits auto reload mode. When T0 overflowing, T0 reload [TH0, TL0] */
#define     TMOD_T0_SEL_16B_REPEATED                ((uint8_t)0x10)     /*!< 16 bits repeated mode. When T0 overflowing, T0 starts from 0. */
#define     TMOD_T0_SEL_8B_AUTO_RELOAD              ((uint8_t)0x20)     /*!< 8 bits auto reload mode. When T0 overflowing, T0 reload [TL0] with [TH0]. */
#define     TMOD_T0_SEL_UNSHIELDED_16B_AUTO_RELOAD  ((uint8_t)0x30)     /*!< unshielded 16 bits auto reload mode, which has the highest prioty */

/* Bit definition for AUXR register */
#define     AUXR_T0x12      ((uint8_t)0x80)        /*!< timer T0 speed selection ([0], CPU clock divied by 12; [1], CPU clock no division)*/
#define     AUXR_T1x12      ((uint8_t)0x40)        /*!< timer T1 speed selection ([0], CPU clock divied by 12; [1], CPU clock no division) */

#define     AUXR_T2x12      ((uint8_t)0x04)        /*!< timer T2 speed selection ([0], CPU clock divied by 12; [1], CPU clock no division) */
#define     AUXR_T2R        ((uint8_t)0x10)        /*!< timer T2 running control bit */
#define     AUXR_T2CT       ((uint8_t)0x08)        /*!< Timer/Counter T2 function selection: [0] timer-internal SYSCLK input; [1] counter-P1.2 input */

/* Bit definition for INTCLKO register  */
#define     INTCLKO_T1CLKO  ((uint8_t)0x02)        /*!< timer T0 output control ([0], timer output disabled; [1], T0 overflow, P3.5 revert its level) */ 
#define     INTCLKO_T0CLKO  ((uint8_t)0x01)        /*!< timer T1 output control ([0], timer output disabled; [1], T1 overflow, P3.4 revert its level) */ 

#define     INTCLKO_T0CLKO  ((uint8_t)0x04)        /*!< timer T2 output control ([0], timer output disabled; [1], T2 overflow, P1.3 revert its level)*/ 

/* Bit definition for T4T3M register */
#define     T4T3M_T4R       ((uint8_t)0x80)        /*!< timer T4 running control flag */ 
#define     T4T3M_T4_CT     ((uint8_t)0x40)        /*!< Timer/Counter T4 function selection: [0] timer-internal SYSCLK input; [1] counter-P0.6 input */
#define     T4T3M_T4x12     ((uint8_t)0x20)        /*!< timer T4 speed selection ([0], CPU clock divied by 12; [1], CPU clock no division) */
#define     T4T3M_T4CLKO    ((uint8_t)0x10)        /*!< timer T4 output control ([0], timer output disabled; [1], T4 overflow, P0.7 revert its level)*/ 
#define     T4T3M_T3R       ((uint8_t)0x08)        /*!< timer T3 running control flag */ 
#define     T4T3M_T3_CT     ((uint8_t)0x04)        /*!< Timer/Counter T3 function selection: [0] timer-internal SYSCLK input; [1] counter-P0.6 input */
#define     T4T3M_T3x12     ((uint8_t)0x02)        /*!< timer T3 speed selection ([0], CPU clock divied by 12; [1], CPU clock no division) */
#define     T4T3M_T3CLKO    ((uint8_t)0x01)        /*!< timer T3 output control ([0], timer output disabled; [1], T3 overflow, P0.7 revert its level)*/ 

/* timer special function registers */
sfr TCON        =   TCON_ADDR;                      //!< Timer control regiseter
sfr TMOD        =   TMOD_ADDR;                      //!< Timer mode regiseter
sfr TL0         =   TL0_ADDR;                       //!< Timer T0 low 8 bytes regiseter
sfr TL1         =   TL1_ADDR;                       //!< Timer T1 low 8 bytes regiseter
sfr TH0         =   TH0_ADDR;                       //!< Timer T0 high 8 bytes regiseter
sfr TH1         =   TH1_ADDR;                       //!< Timer T1 high 8 bytes regiseter
sfr T4T3M       =   T4T3M_ADDR;                     //!< Timer T3/T4 control regiseter
sfr T4H         =   T4H_ADDR;                       //!< Timer T4 high 8 bytes regiseter
sfr T4L         =   T4L_ADDR;                       //!< Timer T4 low 8 bytes regiseter
sfr T3H         =   T3H_ADDR;                       //!< Timer T3 high 8 bytes regiseter
sfr T3L         =   T3L_ADDR;                       //!< Timer T3 low 8 bytes regiseter
sfr T2H         =   T2H_ADDR;                       //!< Timer T2 high 8 bytes regiseter
sfr T2L         =   T2L_ADDR;                       //!< Timer T2 low 8 bytes regiseter

/* Bit definition for TCON register */
sbit TCON_TF1        =   TCON^7;                         /*!< timer T1 overflow interrupt flag */
sbit TCON_TR1        =   TCON^6;                         /*!< timer T1 running enabling control flag */
sbit TCON_TF0        =   TCON^5;                         /*!< timer T0 overflow interrupt flag */
sbit TCON_TR0        =   TCON^4;                         /*!< timer T0 running enabling control flag */
sbit TCON_IE1        =   TCON^3;                         /*!< external interrupt 1 request flag */
sbit TCON_IT1        =   TCON^2;                         /*!< external interrupt 1 trigger ways selection bit */
sbit TCON_IE0        =   TCON^1;                         /*!< external interrupt 0 request flag */
sbit TCON_IT0        =   TCON^0;                         /*!< external interrupt 0 trigger ways selection bit */

//! UART peripherals
/**
 * @brief UART generic I/O definition
 */
typedef struct {
    __IO uint8_t SxCON;
    __IO uint8_t SxBUF;
}UARTx_TypeDef;

/* UART basic address definition */
#define     UART_BASE       ((uint8_t)0x98)
#define     UART1_BASE      (UART_BASE + 0x00)
#define     UART2_BASE      (UART_BASE + 0x02)
#define     UART3_BASE      (UART_BASE + 0x04)
#define     UART4_BASE      (UART_BASE + 0x06)

#define     SCON_ADDR       ((uint8_t)0x98)
#define     SBUF_ADDR       ((uint8_t)0x99)
#define     S2CON_ADDR      ((uint8_t)0x9A)
#define     S2BUF_ADDR      ((uint8_t)0x9B)
#define     S3CON_ADDR      ((uint8_t)0xAC)
#define     S3BUF_ADDR      ((uint8_t)0xAD)
#define     S4CON_ADDR      ((uint8_t)0x84)
#define     S4BUF_ADDR      ((uint8_t)0x85)
#define     SADDR_ADDR      ((uint8_t)0xA9)
#define     SADEN_ADDR      ((uint8_t)0xB9)

/* Bit definition for AUXR register */
#define     AUXR_UART_M0x6  ((uint8_t)0x20)             /*!< serial port 1 mode 0 communication speed selection: [0], no change; [1], 6 times speed */
#define     AUXR_S1ST2      ((uint8_t)0x01)             /*!< serial port 1 baud rate emitter selection: [0], T1; [1], T2 */

/* Bit definition for PCON register */
#define     PCON_SMOD       ((uint8_t)0x80)             /*!< serial port 1 baud rate speed selection: [0], no change; [1], mode 1,2,3 baud rate double times */
#define     PCON_SMOD0      ((uint8_t)0x40)             /*!< frame error detection control bit : [0], function not enabled; [1], SCON-SM0/FE works as FE */

/* Bit definition for S2CON register */
#define     S2SM0           ((uint8_t)0x80)
#define     S2ST4           ((uint8_t)0x40)
#define     S2SM2           ((uint8_t)0x20)
#define     S2REN           ((uint8_t)0x10)
#define     S2TB8           ((uint8_t)0x08)
#define     S2RB8           ((uint8_t)0x04)
#define     S2TI            ((uint8_t)0x02)
#define     S2RI            ((uint8_t)0x01)

/* Bit definition for S3CON register */
#define     S3SM0           ((uint8_t)0x80)
#define     S3ST4           ((uint8_t)0x40)
#define     S3SM2           ((uint8_t)0x20)
#define     S3REN           ((uint8_t)0x10)
#define     S3TB8           ((uint8_t)0x08)
#define     S3RB8           ((uint8_t)0x04)
#define     S3TI            ((uint8_t)0x02)
#define     S3RI            ((uint8_t)0x01)

/* Bit definition for S4CON register */
#define     S4SM0           ((uint8_t)0x80)
#define     S4ST4           ((uint8_t)0x40)
#define     S4SM2           ((uint8_t)0x20)
#define     S4REN           ((uint8_t)0x10)
#define     S4TB8           ((uint8_t)0x08)
#define     S4RB8           ((uint8_t)0x04)
#define     S4TI            ((uint8_t)0x02)
#define     S4RI            ((uint8_t)0x01)

/* UART special function registers */
sfr SCON        =   SCON_ADDR;          //!< serial 1 control register
sfr SBUF        =   SBUF_ADDR;          //!< serial 1 data register
sfr S2CON       =   S2CON_ADDR;         //!< serial 2 control register
sfr S2BUF       =   S2BUF_ADDR;         //!< serial 2 data register
sfr S3CON       =   S3CON_ADDR;         //!< serial 3 control register
sfr S3BUF       =   S3BUF_ADDR;         //!< serial 3 data register
sfr S4CON       =   S4CON_ADDR;         //!< serial 4 control register
sfr S4BUF       =   S4BUF_ADDR;         //!< serial 4 data register
sfr SADDR       =   SADDR_ADDR;         //!< serial 1 slave address register
sfr SADEN       =   SADEN_ADDR;         //!< serial 1 slave shielded address register

#define     UART1               ((UARTx_TypeDef idata* xdata *) UART1_BASE)
#define     UART2               ((UARTx_TypeDef idata* xdata *) UART2_BASE)
#define     UART3               ((UARTx_TypeDef idata* xdata *) UART3_BASE)
#define     UART4               ((UARTx_TypeDef idata* xdata *) UART4_BASE)

/* Bit definition for SCON register */
sbit SCON_SM0        =   SCON^7;
sbit SCON_SM1        =   SCON^6;
sbit SCON_SM2        =   SCON^5;
sbit SCON_REN        =   SCON^4;
sbit SCON_TB8        =   SCON^3;
sbit SCON_RB8        =   SCON^2;
sbit SCON_TI         =   SCON^1;
sbit SCON_RI         =   SCON^0;

//! COMP peripherals
/* COMP basic address definition */
#define     CMPCR1_ADDR             ((uint8_t)0xE6)
#define     CMPCR2_ADDR             ((uint8_t)0xE7)

/* Bit definition for CMPCR1 register */
#define     CMPCR1_CMPEN            ((uint8_t)0x80)      /*!< Comparator module enabling bit */
#define     CMPCR1_CMPIF            ((uint8_t)0x40)      /*!< Comparator interrupt flag bit <*/
#define     CMPCR1_PIE              ((uint8_t)0x20)      /*!< Comparator rising edge interrupt enabling bit */
#define     CMPCR1_NIE              ((uint8_t)0x10)      /*!< Comparator falling edge interrupt enabling bit */
#define     CMPCR1_PIS              ((uint8_t)0x08)      /*!< Comparator positive selection bit: [0], select P3.7 as the positive source; [1], select by ADC_CONTR-ADC_CHS */
#define     CMPCR1_NIS              ((uint8_t)0x04)      /*!< Comparator negtive selection bit: [0], select REFV; select P3.6 as the negtive source*/
#define     CMPCR1_CMPOE            ((uint8_t)0x02)      /*!< Comparator output control bit: [0], disable output; [1], P3.4 or P4.1 ouput pin, decided by P_SW2-CMPO_S */
#define     CMPCR1_CMPRES           ((uint8_t)0x01)      /*!< The result of a comparator comparison: [0], CMP+ lower than CMP-; [1], CMP+ higher than CMP-; */

/* Bit definition for CMPCR2 register */
#define     CMPAR2_INVCMPO          ((uint8_t)0x80       /*!< Comparator output control: [0], positive output, 0 eq low level, 1 eq high level; [1], negtive output, 0 eq high level, 1 eq low level */
#define     CMPAR2_DISFLT           ((uint8_t)0x40       /*!< Analog filter function control: [0], enable; [1], disable */

#define     CMPAR2_LCDTY            ((uint8_t)0x3F)      /*!< LCDTY[5:0] Digital filter function control. filtering time = LCDTY+2 */
#define     CMPAR2_LCDTY_0          ((uint8_t)0x01)      /*!< Bit 0 */
#define     CMPAR2_LCDTY_1          ((uint8_t)0x02)      /*!< Bit 1 */
#define     CMPAR2_LCDTY_2          ((uint8_t)0x04)      /*!< Bit 2 */
#define     CMPAR2_LCDTY_3          ((uint8_t)0x08)      /*!< Bit 3 */
#define     CMPAR2_LCDTY_4          ((uint8_t)0x10)      /*!< Bit 4 */
#define     CMPAR2_LCDTY_5          ((uint8_t)0x20)      /*!< Bit 5 */

#define     CMPAR2_LCDTY_VAL0       ((uint8_t)0x00)      /*!< n=0, no filtering */
#define     CMPAR2_LCDTY_VAL1       ((uint8_t)0x01)      /*!< n=1 */
#define     CMPAR2_LCDTY_VAL2       ((uint8_t)0x02)      /*!< n=2 */
#define     CMPAR2_LCDTY_VAL3       ((uint8_t)0x03)      /*!< n=3 */
#define     CMPAR2_LCDTY_VAL4       ((uint8_t)0x04)      /*!< n=4 */
#define     CMPAR2_LCDTY_VAL5       ((uint8_t)0x05)      /*!< n=5 */
#define     CMPAR2_LCDTY_VAL6       ((uint8_t)0x06)      /*!< n=6 */
#define     CMPAR2_LCDTY_VAL7       ((uint8_t)0x07)      /*!< n=7 */
#define     CMPAR2_LCDTY_VAL8       ((uint8_t)0x08)      /*!< n=8 */
#define     CMPAR2_LCDTY_VAL9       ((uint8_t)0x09)      /*!< n=9 */
#define     CMPAR2_LCDTY_VAL10      ((uint8_t)0x0A)      /*!< n=10 */
#define     CMPAR2_LCDTY_VAL11      ((uint8_t)0x0B)      /*!< n=11 */
#define     CMPAR2_LCDTY_VAL12      ((uint8_t)0x0C)      /*!< n=12 */
#define     CMPAR2_LCDTY_VAL13      ((uint8_t)0x0D)      /*!< n=13 */
#define     CMPAR2_LCDTY_VAL14      ((uint8_t)0x0E)      /*!< n=14 */
#define     CMPAR2_LCDTY_VAL15      ((uint8_t)0x0F)      /*!< n=15 */
#define     CMPAR2_LCDTY_VAL16      ((uint8_t)0x10)      /*!< n=16 */
#define     CMPAR2_LCDTY_VAL17      ((uint8_t)0x11)      /*!< n=17 */
#define     CMPAR2_LCDTY_VAL18      ((uint8_t)0x12)      /*!< n=18 */
#define     CMPAR2_LCDTY_VAL19      ((uint8_t)0x13)      /*!< n=19 */
#define     CMPAR2_LCDTY_VAL20      ((uint8_t)0x14)      /*!< n=20 */
#define     CMPAR2_LCDTY_VAL21      ((uint8_t)0x15)      /*!< n=21 */
#define     CMPAR2_LCDTY_VAL22      ((uint8_t)0x16)      /*!< n=22 */
#define     CMPAR2_LCDTY_VAL23      ((uint8_t)0x17)      /*!< n=23 */
#define     CMPAR2_LCDTY_VAL24      ((uint8_t)0x18)      /*!< n=24 */
#define     CMPAR2_LCDTY_VAL25      ((uint8_t)0x19)      /*!< n=25 */
#define     CMPAR2_LCDTY_VAL26      ((uint8_t)0x1A)      /*!< n=26 */
#define     CMPAR2_LCDTY_VAL27      ((uint8_t)0x1B)      /*!< n=27 */
#define     CMPAR2_LCDTY_VAL28      ((uint8_t)0x1C)      /*!< n=28 */
#define     CMPAR2_LCDTY_VAL29      ((uint8_t)0x1D)      /*!< n=29 */
#define     CMPAR2_LCDTY_VAL30      ((uint8_t)0x1E)      /*!< n=30 */
#define     CMPAR2_LCDTY_VAL31      ((uint8_t)0x1F)      /*!< n=31 */
#define     CMPAR2_LCDTY_VAL32      ((uint8_t)0x20)      /*!< n=32 */
#define     CMPAR2_LCDTY_VAL33      ((uint8_t)0x21)      /*!< n=33 */
#define     CMPAR2_LCDTY_VAL34      ((uint8_t)0x22)      /*!< n=34 */
#define     CMPAR2_LCDTY_VAL35      ((uint8_t)0x23)      /*!< n=35 */
#define     CMPAR2_LCDTY_VAL36      ((uint8_t)0x24)      /*!< n=36 */
#define     CMPAR2_LCDTY_VAL37      ((uint8_t)0x25)      /*!< n=37 */
#define     CMPAR2_LCDTY_VAL38      ((uint8_t)0x26)      /*!< n=38 */
#define     CMPAR2_LCDTY_VAL39      ((uint8_t)0x27)      /*!< n=39 */
#define     CMPAR2_LCDTY_VAL40      ((uint8_t)0x28)      /*!< n=40 */
#define     CMPAR2_LCDTY_VAL41      ((uint8_t)0x29)      /*!< n=41 */
#define     CMPAR2_LCDTY_VAL42      ((uint8_t)0x2A)      /*!< n=42 */
#define     CMPAR2_LCDTY_VAL43      ((uint8_t)0x2B)      /*!< n=43 */
#define     CMPAR2_LCDTY_VAL44      ((uint8_t)0x2C)      /*!< n=44 */
#define     CMPAR2_LCDTY_VAL45      ((uint8_t)0x2D)      /*!< n=45 */
#define     CMPAR2_LCDTY_VAL46      ((uint8_t)0x2E)      /*!< n=46 */
#define     CMPAR2_LCDTY_VAL47      ((uint8_t)0x2F)      /*!< n=47 */
#define     CMPAR2_LCDTY_VAL48      ((uint8_t)0x30)      /*!< n=48 */
#define     CMPAR2_LCDTY_VAL49      ((uint8_t)0x31)      /*!< n=49 */
#define     CMPAR2_LCDTY_VAL50      ((uint8_t)0x32)      /*!< n=50 */
#define     CMPAR2_LCDTY_VAL51      ((uint8_t)0x33)      /*!< n=51 */
#define     CMPAR2_LCDTY_VAL52      ((uint8_t)0x34)      /*!< n=52 */
#define     CMPAR2_LCDTY_VAL53      ((uint8_t)0x35)      /*!< n=53 */
#define     CMPAR2_LCDTY_VAL54      ((uint8_t)0x36)      /*!< n=54 */
#define     CMPAR2_LCDTY_VAL55      ((uint8_t)0x37)      /*!< n=55 */
#define     CMPAR2_LCDTY_VAL56      ((uint8_t)0x38)      /*!< n=56 */
#define     CMPAR2_LCDTY_VAL57      ((uint8_t)0x39)      /*!< n=57 */
#define     CMPAR2_LCDTY_VAL58      ((uint8_t)0x3A)      /*!< n=58 */
#define     CMPAR2_LCDTY_VAL59      ((uint8_t)0x3B)      /*!< n=59 */
#define     CMPAR2_LCDTY_VAL60      ((uint8_t)0x3C)      /*!< n=60 */
#define     CMPAR2_LCDTY_VAL61      ((uint8_t)0x3D)      /*!< n=61 */
#define     CMPAR2_LCDTY_VAL62      ((uint8_t)0x3E)      /*!< n=62 */
#define     CMPAR2_LCDTY_VAL63      ((uint8_t)0x3F)      /*!< n=63 */

sfr CMPCR1      =   CMPCR1_ADDR;    //!< comparator control register 1
sfr CMPCR2      =   CMPCR2_ADDR;    //!< comparator control register 2

//! EEPROM peripherals
/**
 * @brief EEPROM generic I/O definition
 */
typedef struct {
    __IO uint8_t IAP_DATA;
    __IO uint8_t IAP_ADDRH;
    __IO uint8_t IAP_ADDRL;
    __IO uint8_t IAP_CMD;
    __IO uint8_t IAP_TRIG;
    __IO uint8_t IAP_CONTR;
}IAP_EEPROM_TypeDef;

/* EEPROM basic address definition */
#define     IAP_EEPROM_BASE         ((uint8_t)0xC2)
#define     IAP_DATA_ADDR           ((uint8_t)0xC2)
#define     IAP_ADDRH_ADDR          ((uint8_t)0xC3)
#define     IAP_ADDRL_ADDR          ((uint8_t)0xC4)
#define     IAP_CMD_ADDR            ((uint8_t)0xC5)
#define     IAP_TRIG_ADDR           ((uint8_t)0xC6)
#define     IAP_CONTR_ADDR          ((uint8_t)0xC7)

/* Bit definition for IAP_CONTR register */
#define     IAP_CONTR_IAPEN         ((uint8_t)0x80)     /*!< EEPROM operation enable control bit: [0], disable; [1], enable */
#define     IAP_CONTR_SWBS          ((uint8_t)0x40)     /*!< software reset select control bit, (need to be used with SWRST): [0], user code start; [1] ISP monitor space start */
#define     IAP_CONTR_SWRST         ((uint8_t)0x20)     /*!< software reset control bit: [0], no action; [1], enable software reset */
#define     IAP_CONTR_CMD_FAIL      ((uint8_t)0x10)     /*!< EEPROM operation failure status bit, requires software reset: [0], right; [1], false */

#define     IAP_CONTR_IAP_WT        ((uint8_t)0x07)     /*!< IAP_WT[2:0], Set the wait time for EEPROM operation */
#define     IAP_CONTR_IAP_WT_0      ((uint8_t)0x01)     /*!< Bit 0 */
#define     IAP_CONTR_IAP_WT_1      ((uint8_t)0x02)     /*!< Bit 1 */
#define     IAP_CONTR_IAP_WT_2      ((uint8_t)0x04)     /*!< Bit 2 */

#define     IAP_CONTR_IAP_WT_VAL7   ((uint8_t)0x07)     /*!< read_t: 2 ticks; write: 7   ticks; erase page: 5k   ticks; clock fq: 1MHz */
#define     IAP_CONTR_IAP_WT_VAL6   ((uint8_t)0x06)     /*!< read_t: 2 ticks; write: 14  ticks; erase page: 10k  ticks; clock fq: 2MHz */
#define     IAP_CONTR_IAP_WT_VAL5   ((uint8_t)0x05)     /*!< read_t: 2 ticks; write: 21  ticks; erase page: 15k  ticks; clock fq: 3MHz */
#define     IAP_CONTR_IAP_WT_VAL4   ((uint8_t)0x04)     /*!< read_t: 2 ticks; write: 42  ticks; erase page: 30k  ticks; clock fq: 6MHz */
#define     IAP_CONTR_IAP_WT_VAL3   ((uint8_t)0x03)     /*!< read_t: 2 ticks; write: 84  ticks; erase page: 60k  ticks; clock fq: 12MHz */
#define     IAP_CONTR_IAP_WT_VAL2   ((uint8_t)0x02)     /*!< read_t: 2 ticks; write: 140 ticks; erase page: 100k ticks; clock fq: 20MHz */
#define     IAP_CONTR_IAP_WT_VAL1   ((uint8_t)0x01)     /*!< read_t: 2 ticks; write: 168 ticks; erase page: 120k ticks; clock fq: 24MHz */
#define     IAP_CONTR_IAP_WT_VAL0   ((uint8_t)0x00)     /*!< read_t: 2 ticks; write: 301 ticks; erase page: 215k ticks; clock fq: 30MHz */

/* Bit definition for IAP_CMD register */
#define     IAP_CMD_CMD             ((uint8_t)0x03)     /*!< CMD[1:0], Send EEPROM Operation Command */
#define     IAP_CMD_CMD_0           ((uint8_t)0x01)     /*!< Bit 0 */
#define     IAP_CMD_CMD_1           ((uint8_t)0x02)     /*!< Bit 1 */

#define     IAP_CMD_CMD_VAL0        ((uint8_t)0x00)     /*!< nop */
#define     IAP_CMD_CMD_VAL1        ((uint8_t)0x01)     /*!< read 1 byte at target address */
#define     IAP_CMD_CMD_VAL2        ((uint8_t)0x02)     /*!< write 1 byte to target address, converting 1 to 0 */
#define     IAP_CMD_CMD_VAL3        ((uint8_t)0x03)     /*!< Erase EEPROM. Erase the 1 page (1 sector/512 bytes) to FFH where the destination address is located.  */

#define     IAP_EEPROM              ((IAP_EEPROM_TypeDef idata* xdata *) IAP_EEPROM_BASE)

/* IAP special function registers */
sfr IAP_DATA    =   IAP_DATA_ADDR;                      //!< IAP data regiseter
sfr IAP_ADDRH   =   IAP_ADDRH_ADDR;                     //!< IAP high address regiseter
sfr IAP_ADDRL   =   IAP_ADDRL_ADDR;                     //!< IAP low address regiseter
sfr IAP_CMD     =   IAP_CMD_ADDR;                       //!< IAP command regiseter
sfr IAP_TRIG    =   IAP_TRIG_ADDR;                      //!< IAP trigger regiseter
sfr IAP_CONTR   =   IAP_CONTR_ADDR;                     //!< IAP control regiseter

//! ADC peripherals
/**
 * @brief ADC generic I/O definition
 */
typedef struct {
    __IO uint8_t ADC_CONTR;
    __IO uint8_t ADC_RESH;
    __IO uint8_t ADC_RESL;
    __IO uint8_t ADCCFG;
}ADC_TypeDef;

/* ADC basic address definition */
#define     ADC_BASE        ((uint8_t)0xBC))

#define     ADC_CONTR_ADDR  ((uint8_t)0xBC)
#define     ADC_RESH_ADDR   ((uint8_t)0xBD)
#define     ADC_RESL_ADDR   ((uint8_t)0xBE)
#define     ADCCFG_ADDR     ((uint8_t)0xDE)

/* Bit definition for ADC_CONTR register */
#define     ADC_CONTR_ADC_POWER       ((uint8_t)0x80)           /*!< ADC power control: [0], closed; [1], open */
#define     ADC_CONTR_ADC_START       ((uint8_t)0x40)           /*!< ADC conversion start control: [0], no action; [1], start ADC, auto firmware clearance for this bit */
#define     ADC_CONTR_ADC_FLAG        ((uint8_t)0x20)           /*!< ADC conversion over flag: firmware set 1 when conversion finished. interrupt request sent to CPU. Software reset to 0 needed. */

#define     ADC_CONTR_ADC_CHS         ((uint8_t)0x0F)           /*!< ADC_CHS[3:0], ADC analog channel selection bits */
#define     ADC_CONTR_ADC_CHS_0       ((uint8_t)0x01)           /*!< Bit 0 */
#define     ADC_CONTR_ADC_CHS_1       ((uint8_t)0x02)           /*!< Bit 1 */
#define     ADC_CONTR_ADC_CHS_2       ((uint8_t)0x04)           /*!< Bit 2 */
#define     ADC_CONTR_ADC_CHS_3       ((uint8_t)0x08)           /*!< Bit 3 */

#define     ADC_CONTR_ADC_CHS_VAL0    ((uint8_t)0x00)           /*!< P1.0/ADC0 */
#define     ADC_CONTR_ADC_CHS_VAL1    ((uint8_t)0x01)           /*!< P1.1/ADC1 */
#define     ADC_CONTR_ADC_CHS_VAL2    ((uint8_t)0x02)           /*!< P1.2/ADC2 */
#define     ADC_CONTR_ADC_CHS_VAL3    ((uint8_t)0x03)           /*!< P1.3/ADC3 */
#define     ADC_CONTR_ADC_CHS_VAL4    ((uint8_t)0x04)           /*!< P1.4/ADC4 */
#define     ADC_CONTR_ADC_CHS_VAL5    ((uint8_t)0x05)           /*!< P1.5/ADC5 */
#define     ADC_CONTR_ADC_CHS_VAL6    ((uint8_t)0x06)           /*!< P1.6/ADC6 */
#define     ADC_CONTR_ADC_CHS_VAL7    ((uint8_t)0x07)           /*!< P1.7/ADC7 */
#define     ADC_CONTR_ADC_CHS_VAL8    ((uint8_t)0x08)           /*!< P0.0/ADC8 */
#define     ADC_CONTR_ADC_CHS_VAL9    ((uint8_t)0x09)           /*!< P0.1/ADC9 */
#define     ADC_CONTR_ADC_CHS_VAL10   ((uint8_t)0x0A)           /*!< P0.2/ADC10 */
#define     ADC_CONTR_ADC_CHS_VAL11   ((uint8_t)0x0B)           /*!< P0.3/ADC11 */
#define     ADC_CONTR_ADC_CHS_VAL12   ((uint8_t)0x0C)           /*!< P0.4/ADC12 */
#define     ADC_CONTR_ADC_CHS_VAL13   ((uint8_t)0x0D)           /*!< P0.5/ADC13 */
#define     ADC_CONTR_ADC_CHS_VAL14   ((uint8_t)0x0E)           /*!< P0.6/ADC14 */
#define     ADC_CONTR_ADC_CHS_VAL15   ((uint8_t)0x0F)           /*!< REFV */

/* Bit definition for ADCCFG register */
#define     ADCCFG_ADC_RESFMT         ((uint8_t)0x20)           /*!< ADC conversion result format control bit: [0], align Left; [1], align right */

#define     ADCCFG_SPEED              ((uint8_t)0x0F)           /*!< SPEED[3:0], ADC clock control */
#define     ADCCFG_SPEED_0            ((uint8_t)0x01)          /*!< Bit 0 */
#define     ADCCFG_SPEED_1            ((uint8_t)0x02)          /*!< Bit 1 */
#define     ADCCFG_SPEED_2            ((uint8_t)0x04)          /*!< Bit 2 */
#define     ADCCFG_SPEED_3            ((uint8_t)0x08)          /*!< Bit 3 */

// F_ADC＝SYSclk/2/16/（SPEED[3:0]+1）
#define     ADCCFG_SPEED_VAL0         ((uint8_t)0x00)          /*!< SYSCLK tick number: 32 ticks*/
#define     ADCCFG_SPEED_VAL1         ((uint8_t)0x01)          /*!< SYSCLK tick number: 64 ticks*/
#define     ADCCFG_SPEED_VAL2         ((uint8_t)0x02)          /*!< SYSCLK tick number: 96 ticks*/
#define     ADCCFG_SPEED_VAL3         ((uint8_t)0x03)          /*!< SYSCLK tick number: 128 ticks*/
#define     ADCCFG_SPEED_VAL4         ((uint8_t)0x04)          /*!< SYSCLK tick number: 160 ticks*/
#define     ADCCFG_SPEED_VAL5         ((uint8_t)0x05)          /*!< SYSCLK tick number: 192 ticks*/
#define     ADCCFG_SPEED_VAL6         ((uint8_t)0x06)          /*!< SYSCLK tick number: 224 ticks*/
#define     ADCCFG_SPEED_VAL7         ((uint8_t)0x07)          /*!< SYSCLK tick number: 256 ticks*/
#define     ADCCFG_SPEED_VAL8         ((uint8_t)0x08)          /*!< SYSCLK tick number: 288 ticks*/
#define     ADCCFG_SPEED_VAL9         ((uint8_t)0x09)          /*!< SYSCLK tick number: 320 ticks*/
#define     ADCCFG_SPEED_VAL10        ((uint8_t)0x0A)          /*!< SYSCLK tick number: 352 ticks*/
#define     ADCCFG_SPEED_VAL11        ((uint8_t)0x0B)          /*!< SYSCLK tick number: 384 ticks*/
#define     ADCCFG_SPEED_VAL12        ((uint8_t)0x0C)          /*!< SYSCLK tick number: 416 ticks*/
#define     ADCCFG_SPEED_VAL13        ((uint8_t)0x0D)          /*!< SYSCLK tick number: 448 ticks*/
#define     ADCCFG_SPEED_VAL14        ((uint8_t)0x0E)          /*!< SYSCLK tick number: 480 ticks*/
#define     ADCCFG_SPEED_VAL15        ((uint8_t)0x0F)          /*!< SYSCLK tick number: 512 ticks*/

#define     ADC                       ((ADC_TypeDef idata* xdata *) ADC_BASE)

/* ADC special function registers */
sfr ADC_CONTR   =   ADC_CONTR_ADDR;                 //!< ADC control register
sfr ADC_RESH    =   ADC_RESH_ADDR;                  //!< ADC conversion result high bytes register
sfr ADC_RESL    =   ADC_RESL_ADDR;                  //!< ADC conversion result low bytes register
sfr ADCCFG      =   ADCCFG_ADDR;                    //!< ADC configuration register

//! PCA peripherals
/**
 * @brief PCA generic I/O definition
 */
typedef struct {
    __IO uint8_t CCAPMx;
    uint8_t RESERVED0[4];
    __IO uint8_t CCAPxL;
    uint8_t RESERVED1[3];
    __IO uint8_t PCA_PWMx;
    uint8_t RESERVED2[4];
    __IO uint8_t CCAPxH;
}PCAx_TypeDef;

/* PCA basic address definition */
#define     PCAx_BASE       ((uint8_t)0xDA)
#define     PCA0_BASE       (PCAx_BASE + 0x00)
#define     PCA1_BASE       (PCAx_BASE + 0x01)
#define     PCA2_BASE       (PCAx_BASE + 0x02)
#define     PCA3_BASE       (PCAx_BASE + 0x03)

#define     CCON_ADDR       ((uint8_t)0xD8)
#define     CMOD_ADDR       ((uint8_t)0xD9)
#define     CL_ADDR         ((uint8_t)0xE9)
#define     CH_ADDR         ((uint8_t)0xF9)
#define     CCAPM0_ADDR     ((uint8_t)0xDA)
#define     CCAPM1_ADDR     ((uint8_t)0xDB)
#define     CCAPM2_ADDR     ((uint8_t)0xDC)
#define     CCAPM3_ADDR     ((uint8_t)0xDD)
#define     CCAP0L_ADDR     ((uint8_t)0xEA)
#define     CCAP1L_ADDR     ((uint8_t)0xEB)
#define     CCAP2L_ADDR     ((uint8_t)0xEC)
#define     CCAP3L_ADDR     ((uint8_t)0xED)
#define     CCAP0H_ADDR     ((uint8_t)0xFA)
#define     CCAP1H_ADDR     ((uint8_t)0xFB)
#define     CCAP2H_ADDR     ((uint8_t)0xFC)
#define     CCAP3H_ADDR     ((uint8_t)0xFD)
#define     PCA_PWM0_ADDR   ((uint8_t)0xF2)
#define     PCA_PWM1_ADDR   ((uint8_t)0xF3)
#define     PCA_PWM2_ADDR   ((uint8_t)0xF4)
#define     PCA_PWM3_ADDR   ((uint8_t)0xF5)

/* Bit definition for CMOD register */
#define     CMOD_CIDL       ((uint8_t)0x80)             /*!< Whether to stop PCA counting in idle mode: [0], continue; [1], stop */

#define     CMOD_CPS        ((uint8_t)0x0E)             /*!< CPS[2:0], PCA counting pulse source selection bit */
#define     CMOD_CPS_0      ((uint8_t)0x02)             /*!< Bit 0 */
#define     CMOD_CPS_1      ((uint8_t)0x04)             /*!< Bit 1 */
#define     CMOD_CPS_2      ((uint8_t)0x08)             /*!< Bit 2 */

#define     CMOD_CPS_SC1    ((uint8_t)0x00)             /*!< SYSCLK/12 */
#define     CMOD_CPS_SC2    ((uint8_t)0x02)             /*!< SYSCLK/2 */
#define     CMOD_CPS_SC3    ((uint8_t)0x04)             /*!< Overshoot pulse of Timer T0  */
#define     CMOD_CPS_SC4    ((uint8_t)0x06)             /*!< ECI pin's external input clock */
#define     CMOD_CPS_SC5    ((uint8_t)0x08)             /*!< SYSCLK/1 */
#define     CMOD_CPS_SC6    ((uint8_t)0x0A)             /*!< SYSCLK/4 */
#define     CMOD_CPS_SC7    ((uint8_t)0x0C)             /*!< SYSCLK/6 */
#define     CMOD_CPS_SC8    ((uint8_t)0x0E)             /*!< SYSCLK/8 */

#define     CMOD_ECF        ((uint8_t)0x01)             /*!< PCA counter overflow interrupt: [0], disable; [1], enable */

/*
    CCAPPN: allow PCA module N to compare function 
    CCAPPn: allow PCA module N to do up-edge capture 
    CCAPNn: allow PCA module N to do down-edge capture 
    Matn:   allow PCA module N to do matching function 
    TOGn:   allow PCA module N to do high-speed pulse output function 
    pwnn:   allow PCA module N to do pulse width modulation output function 
    ECCFn:  allow PCA module N to do matching/capture interrupt
 */


/* Bit definition for CCAPM0 register */
#define     CCAPM0_ECOM0           ((uint8_t)0x40)
#define     CCAPM0_CCAPP0          ((uint8_t)0x20)
#define     CCAPM0_CCAPN0          ((uint8_t)0x10)
#define     CCAPM0_MAT0            ((uint8_t)0x08)
#define     CCAPM0_TOG0            ((uint8_t)0x04)
#define     CCAPM0_PWM0            ((uint8_t)0x02)
#define     CCAPM0_ECCF0           ((uint8_t)0x01)

/* Bit definition for CCAPM1 register */
#define     CCAPM1_ECOM1           ((uint8_t)0x40)
#define     CCAPM1_CCAPP1          ((uint8_t)0x20)
#define     CCAPM1_CCAPN1          ((uint8_t)0x10)
#define     CCAPM1_MAT1            ((uint8_t)0x08)
#define     CCAPM1_TOG1            ((uint8_t)0x04)
#define     CCAPM1_PWM1            ((uint8_t)0x02)
#define     CCAPM1_ECCF1           ((uint8_t)0x01)

/* Bit definition for CCAPM2 register */
#define     CCAPM2_ECOM2           ((uint8_t)0x40)
#define     CCAPM2_CCAPP2          ((uint8_t)0x20)
#define     CCAPM2_CCAPN2          ((uint8_t)0x10)
#define     CCAPM2_MAT2            ((uint8_t)0x08)
#define     CCAPM2_TOG2            ((uint8_t)0x04)
#define     CCAPM2_PWM2            ((uint8_t)0x02)
#define     CCAPM2_ECCF2           ((uint8_t)0x01)

/* Bit definition for CCAPM3 register */
#define     CCAPM3_ECOM3           ((uint8_t)0x40)
#define     CCAPM3_CCAPP3          ((uint8_t)0x20)
#define     CCAPM3_CCAPN3          ((uint8_t)0x10)
#define     CCAPM3_MAT3            ((uint8_t)0x08)
#define     CCAPM3_TOG3            ((uint8_t)0x04)
#define     CCAPM3_PWM3            ((uint8_t)0x02)
#define     CCAPM3_ECCF3           ((uint8_t)0x01)

/* PCA special function registers */
sfr CCON        =   CCON_ADDR;                  //!< PCA control register
sfr CMOD        =   CMOD_ADDR;                  //!< PCA mode register
sfr CL          =   CL_ADDR;                    //!< PCA counter low bytes
sfr CH          =   CH_ADDR;                    //!< PCA counter high bytes
sfr CCAPM0      =   CCAPM0_ADDR;                //!< PCA module 0 mode control register
sfr CCAPM1      =   CCAPM1_ADDR;                //!< PCA module 1 mode control register
sfr CCAPM2      =   CCAPM2_ADDR;                //!< PCA module 2 mode control register
sfr CCAPM3      =   CCAPM3_ADDR;                //!< PCA module 3 mode control register
sfr CCAP0L      =   CCAP0L_ADDR;                //!< PCA module 0 low bytes
sfr CCAP1L      =   CCAP1L_ADDR;                //!< PCA module 1 low bytes
sfr CCAP2L      =   CCAP2L_ADDR;                //!< PCA module 2 low bytes
sfr CCAP3L      =   CCAP3L_ADDR;                //!< PCA module 3 low bytes
sfr CCAP0H      =   CCAP0H_ADDR;                //!< PCA module 0 high bytes
sfr CCAP1H      =   CCAP1H_ADDR;                //!< PCA module 1 high bytes
sfr CCAP2H      =   CCAP2H_ADDR;                //!< PCA module 2 high bytes
sfr CCAP3H      =   CCAP3H_ADDR;                //!< PCA module 3 high bytes
sfr PCA_PWM0    =   PCA_PWM0_ADDR;              //!< PCA0 PWM mode register
sfr PCA_PWM1    =   PCA_PWM1_ADDR;              //!< PCA1 PWM mode register
sfr PCA_PWM2    =   PCA_PWM2_ADDR;              //!< PCA2 PWM mode register
sfr PCA_PWM3    =   PCA_PWM3_ADDR;              //!< PCA3 PWM mode register

// PCA generic struct type definitions
#define     PCA0                    ((PCAx_TypeDef idata * xdata *) PCA0_BASE)
#define     PCA1                    ((PCAx_TypeDef idata * xdata *) PCA1_BASE)
#define     PCA2                    ((PCAx_TypeDef idata * xdata *) PCA2_BASE)
#define     PCA3                    ((PCAx_TypeDef idata * xdata *) PCA3_BASE)

/* Bit definition for CCON register */
sbit CCON_CF         =   CCON^7;                /*!< PCA counter overflow interrupt flag */
sbit CCON_CR         =   CCON^6;                /*!< PCA counter enabling control bit */
sbit CCON_CCF3       =   CCON^3;                /*!< CCF3 PCA module interrupt flag */
sbit CCON_CCF2       =   CCON^2;                /*!< CCF2 PCA module interrupt flag */
sbit CCON_CCF1       =   CCON^1;                /*!< CCF1 PCA module interrupt flag */
sbit CCON_CCF0       =   CCON^0;                /*!< CCF0 PCA module interrupt flag */

//! PWM peripherals
/**
 * @brief General PWM function I/O
 */
typedef struct {
    __IO  uint8_t PWMxT1H;
    __IO  uint8_t PWMxT1L;
    __IO  uint8_t PWMxT2H;
    __IO  uint8_t PWMxT2L;
    __IO  uint8_t PWMxCR;
    __IO  uint8_t PWMxHLD;
}PWMx_TypeDef;

/* PWM basic address definition */
#define     PWMCFG_ADDR     ((uint8_t)0xF1)
#define     PWMIF_ADDR      ((uint8_t)0xF6)
#define     PWMFDCR_ADDR    ((uint8_t)0xF7)
#define     PWMCR_ADDR      ((uint8_t)0xFE)

#define     PWMC_BASE       ((uint16_t)0xFFF0)
#define     PWMCH_ADDR      (PWMC_BASE + 0x0000)
#define     PWMCL_ADDR      (PWMC_BASE + 0x0001)
#define     PWMCKS_ADDR     (PWMC_BASE + 0x0002)

#define     PWM0_BASE       ((uint16_t)0xFF00)
#define     PWM1_BASE       ((uint16_t)0xFF10)
#define     PWM2_BASE       ((uint16_t)0xFF20)
#define     PWM3_BASE       ((uint16_t)0xFF30)
#define     PWM4_BASE       ((uint16_t)0xFF40)
#define     PWM5_BASE       ((uint16_t)0xFF50)
#define     PWM6_BASE       ((uint16_t)0xFF60)
#define     PWM7_BASE       ((uint16_t)0xFF70)

#define     TADCP_BASE      ((uint16_t)0xFFF3)
#define     TADCPH_ADDR     (TADCP_BASE + 0x0000)
#define     TADCPL_ADDR     (TADCP_BASE + 0x0001)

#define     PWM0T1_ADDR     (PWM0_BASE + 0x00)
#define     PWM0T1H_ADDR    (PWM0T1_ADDR +  0x00)
#define     PWM0T1L_ADDR    (PWM0T1H_ADDR + 0x01)
#define     PWM0T2_ADDR     (PWM0T1L_ADDR + 0x01)
#define     PWM0T2H_ADDR    (PWM0T2_ADDR +  0x00)
#define     PWM0T2L_ADDR    (PWM0T2H_ADDR + 0x01)
#define     PWM0CR_ADDR     (PWM0T2L_ADDR + 0x01)
#define     PWM0HLD_ADDR    (PWM0CR_ADDR +  0x01)

#define     PWM1T1_ADDR     (PWM1_BASE + 0x00)
#define     PWM1T1H_ADDR    (PWM1T1_ADDR +  0x00)
#define     PWM1T1L_ADDR    (PWM1T1H_ADDR + 0x01)
#define     PWM1T2_ADDR     (PWM1T1L_ADDR + 0x01)
#define     PWM1T2H_ADDR    (PWM1T2_ADDR +  0x00)
#define     PWM1T2L_ADDR    (PWM1T2H_ADDR + 0x01)
#define     PWM1CR_ADDR     (PWM1T2L_ADDR + 0x01)
#define     PWM1HLD_ADDR    (PWM1CR_ADDR +  0x01)

#define     PWM2T1_ADDR     (PWM2_BASE + 0x00)
#define     PWM2T1H_ADDR    (PWM2T1_ADDR +  0x00)
#define     PWM2T1L_ADDR    (PWM2T1H_ADDR + 0x01)
#define     PWM2T2_ADDR     (PWM2T1L_ADDR + 0x01)
#define     PWM2T2H_ADDR    (PWM2T2_ADDR +  0x00)
#define     PWM2T2L_ADDR    (PWM2T2H_ADDR + 0x01)
#define     PWM2CR_ADDR     (PWM2T2L_ADDR + 0x01)
#define     PWM2HLD_ADDR    (PWM2CR_ADDR +  0x01)

#define     PWM3T1_ADDR     (PWM3_BASE + 0x00)
#define     PWM3T1H_ADDR    (PWM3T1_ADDR +  0x00)
#define     PWM3T1L_ADDR    (PWM3T1H_ADDR + 0x01)
#define     PWM3T2_ADDR     (PWM3T1L_ADDR + 0x01)
#define     PWM3T2H_ADDR    (PWM3T2_ADDR +  0x00)
#define     PWM3T2L_ADDR    (PWM3T2H_ADDR + 0x01)
#define     PWM3CR_ADDR     (PWM3T2L_ADDR + 0x01)
#define     PWM3HLD_ADDR    (PWM3CR_ADDR +  0x01)

#define     PWM4T1_ADDR     (PWM4_BASE + 0x00)
#define     PWM4T1H_ADDR    (PWM4T1_ADDR +  0x00)
#define     PWM4T1L_ADDR    (PWM4T1H_ADDR + 0x01)
#define     PWM4T2_ADDR     (PWM4T1L_ADDR + 0x01)
#define     PWM4T2H_ADDR    (PWM4T2_ADDR +  0x00)
#define     PWM4T2L_ADDR    (PWM4T2H_ADDR + 0x01)
#define     PWM4CR_ADDR     (PWM4T2L_ADDR + 0x01)
#define     PWM4HLD_ADDR    (PWM4CR_ADDR +  0x01)

#define     PWM5T1_ADDR     (PWM5_BASE + 0x00)
#define     PWM5T1H_ADDR    (PWM5T1_ADDR +  0x00)
#define     PWM5T1L_ADDR    (PWM5T1H_ADDR + 0x01)
#define     PWM5T2_ADDR     (PWM5T1L_ADDR + 0x01)
#define     PWM5T2H_ADDR    (PWM5T2_ADDR +  0x00)
#define     PWM5T2L_ADDR    (PWM5T2H_ADDR + 0x01)
#define     PWM5CR_ADDR     (PWM5T2L_ADDR + 0x01)
#define     PWM5HLD_ADDR    (PWM5CR_ADDR +  0x01)

#define     PWM6T1_ADDR     (PWM6_BASE + 0x00)
#define     PWM6T1H_ADDR    (PWM6T1_ADDR +  0x00)
#define     PWM6T1L_ADDR    (PWM6T1H_ADDR + 0x01)
#define     PWM6T2_ADDR     (PWM6T1L_ADDR + 0x01)
#define     PWM6T2H_ADDR    (PWM6T2_ADDR +  0x00)
#define     PWM6T2L_ADDR    (PWM6T2H_ADDR + 0x01)
#define     PWM6CR_ADDR     (PWM6T2L_ADDR + 0x01)
#define     PWM6HLD_ADDR    (PWM6CR_ADDR +  0x01)

#define     PWM7T1_ADDR     (PWM7_BASE + 0x00)
#define     PWM7T1H_ADDR    (PWM7T1_ADDR +  0x00)
#define     PWM7T1L_ADDR    (PWM7T1H_ADDR + 0x01)
#define     PWM7T2_ADDR     (PWM7T1L_ADDR + 0x01)
#define     PWM7T2H_ADDR    (PWM7T2_ADDR +  0x00)
#define     PWM7T2L_ADDR    (PWM7T2H_ADDR + 0x01)
#define     PWM7CR_ADDR     (PWM7T2L_ADDR + 0x01)
#define     PWM7HLD_ADDR    (PWM7CR_ADDR +  0x01)

/* Bit definition for PWMCFG register */
#define     PWMCFG_CBIF     ((uint8_t)0x80)             /*!< Zero interrupt flag bit for PWM counter overflow happens */
#define     PWMCFG_ETADC    ((uint8_t)0x40)             /*!< Whether PWM associates with ADC */

/* Bit definition for PWMIF register */
#define     PWMIF_C7IF      ((uint8_t)0x80)             /*!< Interrupt flag bit for channel 7 PWM */
#define     PWMIF_C6IF      ((uint8_t)0x40)             /*!< Interrupt flag bit for channel 6 PWM */
#define     PWMIF_C5IF      ((uint8_t)0x20)             /*!< Interrupt flag bit for channel 5 PWM */
#define     PWMIF_C4IF      ((uint8_t)0x10)             /*!< Interrupt flag bit for channel 4 PWM */
#define     PWMIF_C3IF      ((uint8_t)0x08)             /*!< Interrupt flag bit for channel 3 PWM */
#define     PWMIF_C2IF      ((uint8_t)0x04)             /*!< Interrupt flag bit for channel 2 PWM */
#define     PWMIF_C1IF      ((uint8_t)0x02)             /*!< Interrupt flag bit for channel 1 PWM */
#define     PWMIF_C0IF      ((uint8_t)0x01)             /*!< Interrupt flag bit for channel 0 PWM */

/* Bit definition for PWMFDCR register */
#define     PWMFDCR_INVCMP  ((uint8_t)0x80)             /*!< Abnormal signal processing of comparator result: [0] low to high abnormal signal; [1], high to low abnormal signal */
#define     PWMFDCR_INVIO   ((uint8_t)0x40)             /*!< external port P3.5 abnormal signal processing: [0] low to high abnormal signal; [1], high to low abnormal signal*/
#define     PWMFDCR_ENFD    ((uint8_t)0x20)             /*!< PWM external abnormal detection control bit: [0], disable; [1], enable */
#define     PWMFDCR_FLTFLIO ((uint8_t)0x10)             /*!< Control bit of PWM output port when external PWM abnormity occurs: [0], no action; [1], high impedance */
#define     PWMFDCR_EFDI    ((uint8_t)0x08)             /*!< PWM abnormal detection interrupt enabling bit: [0], disable; [1], enable */
#define     PWMFDCR_FDCMP   ((uint8_t)0x04)             /*!< Comparator output anomaly detection enable bit: [0], comparator is unrelative with PWM; [1], Set the PWM abnormal detection source as the comparator output */
#define     PWMFDCR_FDIO    ((uint8_t)0x02)             /*!< P3.5 port level anomaly detection enable bit: [0], P3.5 port level is PWM Independent; [1], Set the abnormal detection source of PWM to P3.5 port */
#define     PWMFDCR_FDIF    ((uint8_t)0x01)             /*!< Abnormal PWM detection interrupt flag bit */

/* Bit definition for PWMCR register */
#define     PWMCR_ENPWM     ((uint8_t)0x80)             /*!< Enable enhanced PWM waveform generator: [0], disable; [1], enable */
#define     PWMCR_ECBI      ((uint8_t)0x40)             /*!< PWM counter zeroing interrupt enable bit: [0], disable; [1], enable */

/* Bit definition for PWMCKS register */
#define     PWMCKS_SELT2    ((uint8_t)0x0F)             /*!< PWM clock source selection: [0], PWM clock source is the system clock frequency divider after the clock; [1], The PWM clock source is the overflow pulse of Timer 2 */

// If SELT2=1, the following setting will be invalid.
#define     PWMCKS_PWM_PS    ((uint8_t)0x0F)             /*!< PWM_PS[3:0], System clock pre-frequency parameter */
#define     PWMCKS_PWM_PS_0  ((uint8_t)0x01)             /*!< Bit 0 */
#define     PWMCKS_PWM_PS_1  ((uint8_t)0x02)             /*!< Bit 1 */
#define     PWMCKS_PWM_PS_2  ((uint8_t)0x04)             /*!< Bit 2 */
#define     PWMCKS_PWM_PS_3  ((uint8_t)0x08)             /*!< Bit 3 */

#define     PWMCKS_PWM_PS_SCLK_DIV1     ((uint8_t)0x00)  /*!< pre-frequency = SCLK/1 */
#define     PWMCKS_PWM_PS_SCLK_DIV2     ((uint8_t)0x01)  /*!< pre-frequency = SCLK/2 */
#define     PWMCKS_PWM_PS_SCLK_DIV3     ((uint8_t)0x02)  /*!< pre-frequency = SCLK/3 */
#define     PWMCKS_PWM_PS_SCLK_DIV4     ((uint8_t)0x03)  /*!< pre-frequency = SCLK/4 */
#define     PWMCKS_PWM_PS_SCLK_DIV5     ((uint8_t)0x04)  /*!< pre-frequency = SCLK/5 */
#define     PWMCKS_PWM_PS_SCLK_DIV6     ((uint8_t)0x05)  /*!< pre-frequency = SCLK/6 */
#define     PWMCKS_PWM_PS_SCLK_DIV7     ((uint8_t)0x06)  /*!< pre-frequency = SCLK/7 */
#define     PWMCKS_PWM_PS_SCLK_DIV8     ((uint8_t)0x07)  /*!< pre-frequency = SCLK/8 */
#define     PWMCKS_PWM_PS_SCLK_DIV9     ((uint8_t)0x08)  /*!< pre-frequency = SCLK/9 */
#define     PWMCKS_PWM_PS_SCLK_DIV10    ((uint8_t)0x09)  /*!< pre-frequency = SCLK/10 */
#define     PWMCKS_PWM_PS_SCLK_DIV11    ((uint8_t)0x0A)  /*!< pre-frequency = SCLK/11 */
#define     PWMCKS_PWM_PS_SCLK_DIV12    ((uint8_t)0x0B)  /*!< pre-frequency = SCLK/12 */
#define     PWMCKS_PWM_PS_SCLK_DIV13    ((uint8_t)0x0C)  /*!< pre-frequency = SCLK/13 */
#define     PWMCKS_PWM_PS_SCLK_DIV14    ((uint8_t)0x0D)  /*!< pre-frequency = SCLK/14 */
#define     PWMCKS_PWM_PS_SCLK_DIV15    ((uint8_t)0x0E)  /*!< pre-frequency = SCLK/15 */
#define     PWMCKS_PWM_PS_SCLK_DIV16    ((uint8_t)0x0F)  /*!< pre-frequency = SCLK/16 */


/* PWM special function registers */
sfr PWMCFG      =   PWMCFG_ADDR;        //!< Enhanced PWM configuration register
sfr PWMIF       =   PWMIF_ADDR;         //!< Enhanced PWM interrupt flag register
sfr PWMFDCR     =   PWMFDCR_ADDR;       //!< Enhanced PWM Anomaly Detection Control Decision Register
sfr PWMCR       =   PWMCR_ADDR;         //!< Enhanced PWM configuration register

#define     PWMC            (*(__IO uint16_t xdata *) PWMC_BASE)         //!< [PWMCH,PWMCL]
#define     PWMCH           (*(__IO uint8_t xdata *)  PWMCH_ADDR)        //!< High Byte PWM counter register
#define     PWMCL           (*(__IO uint8_t xdata *)  PWMCL_ADDR)        //!< Low Byte PWM counter register
#define     PWMCKS          (*(__IO uint8_t xdata *)  PWMCKS_ADDR)       //!< PWM clock selection register
#define     TADCP           (*(__IO uint16_t xdata *) TADCP_BASE)        //!< [TADCPH, TADCPL]
#define     TADCPH          (*(__IO uint8_t xdata *)  TADCPH_ADDR)       //!< The trigger ADC counts high bytes register
#define     TADCPL          (*(__IO uint8_t xdata *)  TADCPL_ADDR)       //!< The trigger ADC counts low bytes register

#define     PWMxT1(PWMxT1_ADDR)      (*(__IO uint16_t xdata *) PWMxT1_ADDR)  //!< PWMxT1 counter [PWMxT1H, PWMxT1L]
#define     PWMxT2(PWMxT2_ADDR)      (*(__IO uint16_t xdata *) PWMxT2_ADDR)  //!< PWMxT2 counter [PWMxT2H, PWMxT2L]
#define     PWMxCR(PWMxCR_ADDR)      (*(__IO uint8_t xdata *) PWMxCR_ADDR)  //!< PWMx control register
#define     PWMxHLD(PWMxHLD_ADDR)    (*(__IO uint8_t xdata *) PWMxHLD_ADDR) //!< PWMx level holder control register

#define     PWM0            ((PWMx_TypeDef xdata *) PWM0_BASE)          //!< PWM0 generic struct type
#define     PWM1            ((PWMx_TypeDef xdata *) PWM1_BASE)          //!< PWM1 generic struct type
#define     PWM2            ((PWMx_TypeDef xdata *) PWM2_BASE)          //!< PWM2 generic struct type
#define     PWM3            ((PWMx_TypeDef xdata *) PWM3_BASE)          //!< PWM3 generic struct type
#define     PWM4            ((PWMx_TypeDef xdata *) PWM4_BASE)          //!< PWM4 generic struct type
#define     PWM5            ((PWMx_TypeDef xdata *) PWM5_BASE)          //!< PWM5 generic struct type
#define     PWM6            ((PWMx_TypeDef xdata *) PWM6_BASE)          //!< PWM6 generic struct type
#define     PWM7            ((PWMx_TypeDef xdata *) PWM7_BASE)          //!< PWM7 generic struct type

#define     PWM0T1          (*(__IO uint16_t xdata *) PWM0T1_ADDR)
#define     PWM0T1H         (*(__IO uint8_t xdata *) PWM0T1H_ADDR)
#define     PWM0T1L         (*(__IO uint8_t xdata *) PWM0T1L_ADDR)
#define     PWM0T2          (*(__IO uint16_t xdata *) PWM0T2_ADDR)
#define     PWM0T2H         (*(__IO uint8_t xdata *) PWM0T2H_ADDR)
#define     PWM0T2L         (*(__IO uint8_t xdata *) PWM0T2L_ADDR)
#define     PWM0CR          (*(__IO uint8_t xdata *) PWM0CR_ADDR)
#define     PWM0HLD         (*(__IO uint8_t xdata *) PWM0HLD_ADDR)

#define     PWM1T1          (*(__IO uint16_t xdata *) PWM1T1_ADDR)
#define     PWM1T1H         (*(__IO uint8_t xdata *) PWM1T1H_ADDR)
#define     PWM1T1L         (*(__IO uint8_t xdata *) PWM1T1L_ADDR)
#define     PWM1T2          (*(__IO uint16_t xdata *) PWM1T2_ADDR)
#define     PWM1T2H         (*(__IO uint8_t xdata *) PWM1T2H_ADDR)
#define     PWM1T2L         (*(__IO uint8_t xdata *) PWM1T2L_ADDR)
#define     PWM1CR          (*(__IO uint8_t xdata *) PWM1CR_ADDR)
#define     PWM1HLD         (*(__IO uint8_t xdata *) PWM1HLD_ADDR)

#define     PWM2T1          (*(__IO uint16_t xdata *) PWM2T1_ADDR)
#define     PWM2T1H         (*(__IO uint8_t xdata *) PWM2T1H_ADDR)
#define     PWM2T1L         (*(__IO uint8_t xdata *) PWM2T1L_ADDR)
#define     PWM2T2          (*(__IO uint16_t xdata *) PWM2T2_ADDR)
#define     PWM2T2H         (*(__IO uint8_t xdata *) PWM2T2H_ADDR)
#define     PWM2T2L         (*(__IO uint8_t xdata *) PWM2T2L_ADDR)
#define     PWM2CR          (*(__IO uint8_t xdata *) PWM2CR_ADDR)
#define     PWM2HLD         (*(__IO uint8_t xdata *) PWM2HLD_ADDR)

#define     PWM3T1          (*(__IO uint16_t xdata *) PWM3T1_ADDR)
#define     PWM3T1H         (*(__IO uint8_t xdata *) PWM3T1H_ADDR)
#define     PWM3T1L         (*(__IO uint8_t xdata *) PWM3T1L_ADDR)
#define     PWM3T2          (*(__IO uint16_t xdata *) PWM3T2_ADDR)
#define     PWM3T2H         (*(__IO uint8_t xdata *) PWM3T2H_ADDR)
#define     PWM3T2L         (*(__IO uint8_t xdata *) PWM3T2L_ADDR)
#define     PWM3CR          (*(__IO uint8_t xdata *) PWM3CR_ADDR)
#define     PWM3HLD         (*(__IO uint8_t xdata *) PWM3HLD_ADDR)

#define     PWM4T1          (*(__IO uint16_t xdata *) PWM4T1_ADDR)
#define     PWM4T1H         (*(__IO uint8_t xdata *) PWM4T1H_ADDR)
#define     PWM4T1L         (*(__IO uint8_t xdata *) PWM4T1L_ADDR)
#define     PWM4T2          (*(__IO uint16_t xdata *) PWM4T2_ADDR)
#define     PWM4T2H         (*(__IO uint8_t xdata *) PWM4T2H_ADDR)
#define     PWM4T2L         (*(__IO uint8_t xdata *) PWM4T2L_ADDR)
#define     PWM4CR          (*(__IO uint8_t xdata *) PWM4CR_ADDR)
#define     PWM4HLD         (*(__IO uint8_t xdata *) PWM4HLD_ADDR)

#define     PWM5T1          (*(__IO uint16_t xdata *) PWM5T1_ADDR)
#define     PWM5T1H         (*(__IO uint8_t xdata *) PWM5T1H_ADDR)
#define     PWM5T1L         (*(__IO uint8_t xdata *) PWM5T1L_ADDR)
#define     PWM5T2          (*(__IO uint16_t xdata *) PWM5T2_ADDR)
#define     PWM5T2H         (*(__IO uint8_t xdata *) PWM5T2H_ADDR)
#define     PWM5T2L         (*(__IO uint8_t xdata *) PWM5T2L_ADDR)
#define     PWM5CR          (*(__IO uint8_t xdata *) PWM5CR_ADDR)
#define     PWM5HLD         (*(__IO uint8_t xdata *) PWM5HLD_ADDR)

#define     PWM6T1          (*(__IO uint16_t xdata *) PWM6T1_ADDR)
#define     PWM6T1H         (*(__IO uint8_t xdata *) PWM6T1H_ADDR)
#define     PWM6T1L         (*(__IO uint8_t xdata *) PWM6T1L_ADDR)
#define     PWM6T2          (*(__IO uint16_t xdata *) PWM6T2_ADDR)
#define     PWM6T2H         (*(__IO uint8_t xdata *) PWM6T2H_ADDR)
#define     PWM6T2L         (*(__IO uint8_t xdata *) PWM6T2L_ADDR)
#define     PWM6CR          (*(__IO uint8_t xdata *) PWM6CR_ADDR)
#define     PWM6HLD         (*(__IO uint8_t xdata *) PWM6HLD_ADDR)

#define     PWM7T1          (*(__IO uint16_t xdata *) PWM7T1_ADDR)
#define     PWM7T1H         (*(__IO uint8_t xdata *) PWM7T1H_ADDR)
#define     PWM7T1L         (*(__IO uint8_t xdata *) PWM7T1L_ADDR)
#define     PWM7T2          (*(__IO uint16_t xdata *) PWM7T2_ADDR)
#define     PWM7T2H         (*(__IO uint8_t xdata *) PWM7T2H_ADDR)
#define     PWM7T2L         (*(__IO uint8_t xdata *) PWM7T2L_ADDR)
#define     PWM7CR          (*(__IO uint8_t xdata *) PWM7CR_ADDR)
#define     PWM7HLD         (*(__IO uint8_t xdata *) PWM7HLD_ADDR)

//! SPI peripherals
/**
 * @brief SPI general I/O interface
 */
typedef struct {
    __IO uint8_t SPSTAT;
    __IO uint8_t SPCTL;
    __IO uint8_t SPDAT;
}SPI_TypeDef;

/* SPI basic address definition */
#define     SPI_BASE        ((uint8_t)0xCD)
#define     SPSTAT_ADDR     ((uint8_t)0xCD)
#define     SPCTL_ADDR      ((uint8_t)0xCE)
#define     SPDAT_ADDR      ((uint8_t)0xCF)

/* Bit definition for SPSTAT register */
#define     SPSTAT_SPIF     ((uint8_t)0x80)             /*!< SPI interrupt flag bit */
#define     SPSTAT_WCOL     ((uint8_t)0x40)             /*!< SPI writing confliction flag bit */

/* Bit definition for SPCTL register */
#define     SPCTL_SSIG      ((uint8_t)0x80)             /*!< SS fucntion selection: [0], use SS to determine slave or master; [1], use MSTR rather than SS */
#define     SPCTL_SPEN      ((uint8_t)0x40)             /*!< SPI enabling control bit */
#define     SPCTL_DORD      ((uint8_t)0x20)             /*!< SPI data sending/receiving order: [0], MSB; [1], LSB */
#define     SPCTL_MSTR      ((uint8_t)0x10)             /*!< device mater or slave mode selection: [MASTER], SSIG=0, SS pin high, MSTR=1; SSIG=1, MSTR=1; [SLAVE], SSIG=0, SS pin low; SSIG=1, MSTR=0 */
#define     SPCTL_CPOL      ((uint8_t)0x08)             /*!< SPI clock polarity control: [0] Sclk Idle Time is low level, SCLK front clock edge for the rising edge, after the clock edge for the falling edge; [1], Sclk idle time for high-level, SCLK front clock edge for the down edge, after the clock edge for the rising edge */
#define     SPCTL_CPHA      ((uint8_t)0x04)             /*!< SPI clock phase control: [0], The data SS pin drives the first bit data for the low level and changes the data at the SCLK's back clock edge, and the front clock edge samples the data (must be SSIG = 0); [1], Data is sampled along the front clock edge of SCLK and the back clock edge */

#define     SPCTL_SPR       ((uint8_t)0x03)             /*!< SPR[1:0], SPI clock frequency selection */
#define     SPCTL_SPR_0     ((uint8_t)0x01)             /*!< Bit 0 */
#define     SPCTL_SPR_1     ((uint8_t)0x02)             /*!< Bit 1 */

#define     SPCTL_SPR_SCLK_DIV4     ((uint8_t)0x00)     /*!< SYSCLK/4 */
#define     SPCTL_SPR_SCLK_DIV8     ((uint8_t)0x01)     /*!< SYSCLK/8 */
#define     SPCTL_SPR_SCLK_DIV16    ((uint8_t)0x02)     /*!< SYSCLK/16 */
#define     SPCTL_SPR_SCLK_DIV32    ((uint8_t)0x03)     /*!< SYSCLK/32 */

/**
 * @brief define the SPI_TypeDef pointer type
 * @note To access XDATA peripherals, use the \c volatile keyword to ensure 
 * that the C compiler does not optimize out necessary memory accesses. \n
 * \code{.c} ((SPI_TypeDef idata * xdata *) SPI_BASE) \endcode 
 * means \b SPI_TypeDef pointer is stored in \e xdata space but 
 * points to \e idata space. If you want to use this struct type, prefix 
 * \code{.c} (SPI_TypeDef idata *) \endcode is needed, such as 
 * \code{.c} (SPI_TypeDef idata *) var \endcode, in witch the
 * \c var is \b SPI_TypeDef .
 */
#define     SPI             ((SPI_TypeDef idata * xdata* ) SPI_BASE)    //!< SPI generic struct type definition

/* SPI special function registers */
sfr SPSTAT      =   SPSTAT_ADDR;        //!< SPI State Register
sfr SPCTL       =   SPCTL_ADDR;         //!< SPI Control Register
sfr SPDAT       =   SPDAT_ADDR;         //!< SPI Data Register


//! I2C peripherals
/**
 * @brief I2C general I/O configuration
 */
typedef struct {
    __IO uint8_t I2CCFG;
    __IO uint8_t I2CMSCR;
    __IO uint8_t I2CMSST;
    __IO uint8_t I2CSLCR;
    __IO uint8_t I2CSLST;
    __IO uint8_t I2CSLADR;
    __IO uint8_t I2CTXD;
    __IO uint8_t I2CRXD;
    __IO uint8_t I2CMSAUX;
}I2C_TypeDef;


/* Basic address */
#define     I2C_BASE        ((uint16_t)0xFE80)
#define     I2CCFG_ADDR     (I2C_BASE + 0x0000)
#define     I2CMSCR_ADDR    (I2C_BASE + 0x0001)
#define     I2CMSST_ADDR    (I2C_BASE + 0x0002)
#define     I2CSLCR_ADDR    (I2C_BASE + 0x0003)
#define     I2CSLST_ADDR    (I2C_BASE + 0x0004)
#define     I2CSLADR_ADDR   (I2C_BASE + 0x0005)
#define     I2CTXD_ADDR     (I2C_BASE + 0x0006)
#define     I2CRXD_ADDR     (I2C_BASE + 0x0007)
#define     I2CMSAUX_ADDR   (I2C_BASE + 0x0008)

/* Bit definition for I2CCFG register */
// The wait parameter set by the MSSPEED parameter is valid only if the I2C module is working in host mode.
#define     I2CCFG_ENI2C    ((uint8_t)0x80)             /*!< I2C fucntion enablling control bit: [0], disable; [1], enable */
#define     I2CCFG_MSSL     ((uint8_t)0x40)             /*!< I2C fucntion selection: [0], slave; [1], master */

#define     I2CCFG_MSSPEED            ((uint8_t)0x3F)       /*!< MSSPEED[5:0], I2C bus speed control (waiting ticks) I2C_speed = Fosc/2/(MSSPEED * 2 + 4)*/
#define     I2CCFG_MSSPEED_0          ((uint8_t)0x01)       /*!< Bit 0 */
#define     I2CCFG_MSSPEED_1          ((uint8_t)0x02)       /*!< Bit 1 */
#define     I2CCFG_MSSPEED_2          ((uint8_t)0x04)       /*!< Bit 2 */
#define     I2CCFG_MSSPEED_3          ((uint8_t)0x08)       /*!< Bit 3 */
#define     I2CCFG_MSSPEED_4          ((uint8_t)0x10)       /*!< Bit 4 */
#define     I2CCFG_MSSPEED_5          ((uint8_t)0x20)       /*!< Bit 5 */

#define     I2CCFG_MSSPEED_VAL0       ((uint8_t)0x00)      /*!< tick_n=0+4 */
#define     I2CCFG_MSSPEED_VAL1       ((uint8_t)0x01)      /*!< tick_n=1+4 */
#define     I2CCFG_MSSPEED_VAL2       ((uint8_t)0x02)      /*!< tick_n=2+4 */
#define     I2CCFG_MSSPEED_VAL3       ((uint8_t)0x03)      /*!< tick_n=3+4 */
#define     I2CCFG_MSSPEED_VAL4       ((uint8_t)0x04)      /*!< tick_n=4+4 */
#define     I2CCFG_MSSPEED_VAL5       ((uint8_t)0x05)      /*!< tick_n=5+4 */
#define     I2CCFG_MSSPEED_VAL6       ((uint8_t)0x06)      /*!< tick_n=6+4 */
#define     I2CCFG_MSSPEED_VAL7       ((uint8_t)0x07)      /*!< tick_n=7+4 */
#define     I2CCFG_MSSPEED_VAL8       ((uint8_t)0x08)      /*!< tick_n=8+4 */
#define     I2CCFG_MSSPEED_VAL9       ((uint8_t)0x09)      /*!< tick_n=9+4 */
#define     I2CCFG_MSSPEED_VAL10      ((uint8_t)0x0A)      /*!< tick_n=10+4 */
#define     I2CCFG_MSSPEED_VAL11      ((uint8_t)0x0B)      /*!< tick_n=11+4 */
#define     I2CCFG_MSSPEED_VAL12      ((uint8_t)0x0C)      /*!< tick_n=12+4 */
#define     I2CCFG_MSSPEED_VAL13      ((uint8_t)0x0D)      /*!< tick_n=13+4 */
#define     I2CCFG_MSSPEED_VAL14      ((uint8_t)0x0E)      /*!< tick_n=14+4 */
#define     I2CCFG_MSSPEED_VAL15      ((uint8_t)0x0F)      /*!< tick_n=15+4 */
#define     I2CCFG_MSSPEED_VAL16      ((uint8_t)0x10)      /*!< tick_n=16+4 */
#define     I2CCFG_MSSPEED_VAL17      ((uint8_t)0x11)      /*!< tick_n=17+4 */
#define     I2CCFG_MSSPEED_VAL18      ((uint8_t)0x12)      /*!< tick_n=18+4 */
#define     I2CCFG_MSSPEED_VAL19      ((uint8_t)0x13)      /*!< tick_n=19+4 */
#define     I2CCFG_MSSPEED_VAL20      ((uint8_t)0x14)      /*!< tick_n=20+4 */
#define     I2CCFG_MSSPEED_VAL21      ((uint8_t)0x15)      /*!< tick_n=21+4 */
#define     I2CCFG_MSSPEED_VAL22      ((uint8_t)0x16)      /*!< tick_n=22+4 */
#define     I2CCFG_MSSPEED_VAL23      ((uint8_t)0x17)      /*!< tick_n=23+4 */
#define     I2CCFG_MSSPEED_VAL24      ((uint8_t)0x18)      /*!< tick_n=24+4 */
#define     I2CCFG_MSSPEED_VAL25      ((uint8_t)0x19)      /*!< tick_n=25+4 */
#define     I2CCFG_MSSPEED_VAL26      ((uint8_t)0x1A)      /*!< tick_n=26+4 */
#define     I2CCFG_MSSPEED_VAL27      ((uint8_t)0x1B)      /*!< tick_n=27+4 */
#define     I2CCFG_MSSPEED_VAL28      ((uint8_t)0x1C)      /*!< tick_n=28+4 */
#define     I2CCFG_MSSPEED_VAL29      ((uint8_t)0x1D)      /*!< tick_n=29+4 */
#define     I2CCFG_MSSPEED_VAL30      ((uint8_t)0x1E)      /*!< tick_n=30+4 */
#define     I2CCFG_MSSPEED_VAL31      ((uint8_t)0x1F)      /*!< tick_n=31+4 */
#define     I2CCFG_MSSPEED_VAL32      ((uint8_t)0x20)      /*!< tick_n=32+4 */
#define     I2CCFG_MSSPEED_VAL33      ((uint8_t)0x21)      /*!< tick_n=33+4 */
#define     I2CCFG_MSSPEED_VAL34      ((uint8_t)0x22)      /*!< tick_n=34+4 */
#define     I2CCFG_MSSPEED_VAL35      ((uint8_t)0x23)      /*!< tick_n=35+4 */
#define     I2CCFG_MSSPEED_VAL36      ((uint8_t)0x24)      /*!< tick_n=36+4 */
#define     I2CCFG_MSSPEED_VAL37      ((uint8_t)0x25)      /*!< tick_n=37+4 */
#define     I2CCFG_MSSPEED_VAL38      ((uint8_t)0x26)      /*!< tick_n=38+4 */
#define     I2CCFG_MSSPEED_VAL39      ((uint8_t)0x27)      /*!< tick_n=39+4 */
#define     I2CCFG_MSSPEED_VAL40      ((uint8_t)0x28)      /*!< tick_n=40+4 */
#define     I2CCFG_MSSPEED_VAL41      ((uint8_t)0x29)      /*!< tick_n=41+4 */
#define     I2CCFG_MSSPEED_VAL42      ((uint8_t)0x2A)      /*!< tick_n=42+4 */
#define     I2CCFG_MSSPEED_VAL43      ((uint8_t)0x2B)      /*!< tick_n=43+4 */
#define     I2CCFG_MSSPEED_VAL44      ((uint8_t)0x2C)      /*!< tick_n=44+4 */
#define     I2CCFG_MSSPEED_VAL45      ((uint8_t)0x2D)      /*!< tick_n=45+4 */
#define     I2CCFG_MSSPEED_VAL46      ((uint8_t)0x2E)      /*!< tick_n=46+4 */
#define     I2CCFG_MSSPEED_VAL47      ((uint8_t)0x2F)      /*!< tick_n=47+4 */
#define     I2CCFG_MSSPEED_VAL48      ((uint8_t)0x30)      /*!< tick_n=48+4 */
#define     I2CCFG_MSSPEED_VAL49      ((uint8_t)0x31)      /*!< tick_n=49+4 */
#define     I2CCFG_MSSPEED_VAL50      ((uint8_t)0x32)      /*!< tick_n=50+4 */
#define     I2CCFG_MSSPEED_VAL51      ((uint8_t)0x33)      /*!< tick_n=51+4 */
#define     I2CCFG_MSSPEED_VAL52      ((uint8_t)0x34)      /*!< tick_n=52+4 */
#define     I2CCFG_MSSPEED_VAL53      ((uint8_t)0x35)      /*!< tick_n=53+4 */
#define     I2CCFG_MSSPEED_VAL54      ((uint8_t)0x36)      /*!< tick_n=54+4 */
#define     I2CCFG_MSSPEED_VAL55      ((uint8_t)0x37)      /*!< tick_n=55+4 */
#define     I2CCFG_MSSPEED_VAL56      ((uint8_t)0x38)      /*!< tick_n=56+4 */
#define     I2CCFG_MSSPEED_VAL57      ((uint8_t)0x39)      /*!< tick_n=57+4 */
#define     I2CCFG_MSSPEED_VAL58      ((uint8_t)0x3A)      /*!< tick_n=58+4 */
#define     I2CCFG_MSSPEED_VAL59      ((uint8_t)0x3B)      /*!< tick_n=59+4 */
#define     I2CCFG_MSSPEED_VAL60      ((uint8_t)0x3C)      /*!< tick_n=60+4 */
#define     I2CCFG_MSSPEED_VAL61      ((uint8_t)0x3D)      /*!< tick_n=61+4 */
#define     I2CCFG_MSSPEED_VAL62      ((uint8_t)0x3E)      /*!< tick_n=62+4 */
#define     I2CCFG_MSSPEED_VAL63      ((uint8_t)0x3F)      /*!< tick_n=63+4 */


/* Bit definition for I2CMSCR register */
#define     I2CMSCR_EMSI        ((uint8_t)0x80)             /*!< master mode interrupt enabling control bit */

#define     I2CMSCR_MSCMD       ((uint8_t)0x0F)             /*!< MSCMD[3:0], master command */
#define     I2CMSCR_MSCMD_0     ((uint8_t)0x01)             /*!< Bit 0 */
#define     I2CMSCR_MSCMD_1     ((uint8_t)0x02)             /*!< Bit 1 */
#define     I2CMSCR_MSCMD_2     ((uint8_t)0x04)             /*!< Bit 2 */
#define     I2CMSCR_MSCMD_3     ((uint8_t)0x08)             /*!< Bit 3 */

#define     I2CMSCR_MSCMD_IDLE      ((uint8_t)0x00)             /*!< idle, no action */
#define     I2CMSCR_MSCMD_START     ((uint8_t)0x01)             /*!< start command */
#define     I2CMSCR_MSCMD_SEND_DATA ((uint8_t)0x02)             /*!< send data command */
#define     I2CMSCR_MSCMD_RECV_ACK  ((uint8_t)0x03)             /*!< receive ACK command */
#define     I2CMSCR_MSCMD_RECV_DATA ((uint8_t)0x04)             /*!< receive data command */
#define     I2CMSCR_MSCMD_SEND_ACK  ((uint8_t)0x05)             /*!< send ACK command */
#define     I2CMSCR_MSCMD_STOP      ((uint8_t)0x06)             /*!< stop command */
#define     I2CMSCR_MSCMD_SSDRACK   ((uint8_t)0x09)             /*!< Start Command + SEND Data Command + receive ACK command */
#define     I2CMSCR_MSCMD_SDRACK    ((uint8_t)0x0A)             /*!< Send Data Command + receive ACK command */
#define     I2CMSCR_MSCMD_RDSACK0   ((uint8_t)0x0B)             /*!< Receive Data Command + send ACK (0) command */
#define     I2CMSCR_MSCMD_RDSNAK1   ((uint8_t)0x0C)             /*!< Receive Data Command + send NAK (1) command. */

/* Bit definition for I2CMSST register */
#define     I2CMSST_MSBUSY          ((uint8_t)0x80)             /*!< I2C control bit on master mode. [0], idle; [1], busy(READ ONLY) */
#define     I2CMSST_MSIF            ((uint8_t)0x40)             /*!< master mode interrupt request bit (interrupt flag bit)) */
#define     I2CMSST_MSACKI          ((uint8_t)0x02)             /*!< master mode, ACK received after '0011' command sent to I2CMSCR-MSCMD */
#define     I2CMSST_MSACKO          ((uint8_t)0x01)             /*!< master mode, ACK signal wait to be sent */

/* Bit definition for I2CSLCR register ([0], disable; [1], enable)*/
#define     I2CSLCR_ESTAI           ((uint8_t)0x40)             /*!< The START signal interrupt permission bit is received from the slave mode */
#define     I2CSLCR_ERXI            ((uint8_t)0x20)             /*!< Interrupt allowed bit after receiving 1 byte data from slave mode */
#define     I2CSLCR_ETXI            ((uint8_t)0x10)             /*!< Interrupt allowed bit after sending 1 byte data from slave mode */
#define     I2CSLCR_ESTOI           ((uint8_t)0x08)             /*!< Receive STOP signal interrupt permission bit from slave mode */
#define     I2CSLCR_SLRST           ((uint8_t)0x01)             /*!< Reset slave mode */

/* Bit definition for I2CSLST register */
#define     I2CSLST_SLBUSY          ((uint8_t)0x80)             /*!< slave mode interrupt enabling control bit */
#define     I2CSLST_STAIF           ((uint8_t)0x40)             /*!< The interrupt request bit after the START signal is received from slave mode. */
#define     I2CSLST_RXIF            ((uint8_t)0x20)             /*!< Interrupt request bit after receiving 1 byte of data from slave mode */
#define     I2CSLST_TXIF            ((uint8_t)0x10)             /*!< Interrupt request bit after 1 byte of data has been sent from slave mode */
#define     I2CSLST_STOIF           ((uint8_t)0x08)             /*!< The interrupt request bit after the STOP signal is received from slave mode */
// #define     I2CSLST_TXING           ((uint8_t)0x04)             
#define     I2CSLST_SLACKI          ((uint8_t)0x02)             /*!< ACK data received when in slave mode */
#define     I2CSLST_SLACKO          ((uint8_t)0x01)             /*!< ACK signal to be sent on slave mode */

/* Bit definition for I2CMSAUX register */
#define     I2CMSAUX_WDTA           ((uint8_t)0x01)             /*!< I2C data is automatically sent in master mode allowing bits */


/* I2C special function registers */
#define     I2CCFG          (*(__IO uint8_t xdata *) I2CCFG_ADDR)    //!< I2C configuration register
#define     I2CMSCR         (*(__IO uint8_t xdata *) I2CMSCR_ADDR)   //!< I2C master control register
#define     I2CMSST         (*(__IO uint8_t xdata *) I2CMSST_ADDR)   //!< I2C master state register
#define     I2CSLCR         (*(__IO uint8_t xdata *) I2CSLCR_ADDR)   //!< I2C slave control register
#define     I2CSLST         (*(__IO uint8_t xdata *) I2CSLST_ADDR)   //!< I2C slave state register
#define     I2CSLADR        (*(__IO uint8_t xdata *) I2CSLADR_ADDR)  //!< I2C slave address register
#define     I2CTXD          (*(__IO uint8_t xdata *) I2CTXD_ADDR)    //!< I2C data sending register
#define     I2CRXD          (*(__IO uint8_t xdata *) I2CRXD_ADDR)    //!< I2C data reveiving register
#define     I2CMSAUX        (*(__IO uint8_t xdata *) I2CMSAUX_ADDR)  //!< I2C master auxiliary control register

#define     I2C             ((I2C_TypeDef xdata *) I2C_BASE)        //!< I2C generic struct type definition


/** @} */

/** @} */

/** @} */

#endif

