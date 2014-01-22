/* ###################################################################
 **     THIS COMPONENT MODULE IS GENERATED BY USER.
 **     Filename    : Globals.h
 **     Project     : semg_mkl15z128vlh4
 **     Processor   : MKL15Z128VLH4
 **     Component   :
 **     Version     :
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2013-07-12, 12:30, # CodeGen: 0
 **     Author	    : Dong
 **     Abstract    :
 **          This file defines global variables used in this project.
 **
 **
 **     Mail      	: pzdongdong@163.com
 **
 **     Revision    : No.  Name        Date/Time        Content
 ** ###################################################################*/
/*!
 * @file Globals.h
 * @version 01.00
 * @brief
 *      This file defines global variables used in this project.
 */
/*!
 * @addtogroup GlobalVariables Global Variables
 *     This module defines global variables used in this project.
 * @{
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_
/* MODULE GLOBALS VARIABLES */

#include "PE_Types.h"
#include "Macros.h"
#include "Settings.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*
 * ===================================================================
 * System Global Variables
 * ===================================================================
 */
    /*!
     * @addtogroup SysGlbVar System Global Variables
     * @{
     */
TADC tADC[USING_ADC_COUNT];             /*!< The structure of ADC device. */
TADCPtr tADCPtr[USING_ADC_COUNT];       /*!< The pointer to structure of ADC device. */
TMCU tMCU;                              /*!< The structure of MCU device. */
TMCUPtr tMCUPtr;                        /*!< The pointer to structure of MCU device. */
TARM tARM;                              /*!< The structure of ARM device. */
TARMPtr tARMPtr;                        /*!< The pointer to structure of ARM device. */
    /*!
     * @}
     */

/*
 * ===================================================================
 * Logic device data structure pointer
 * ===================================================================
 */

    /*!
     * @addtogroup LogDevDatStrPtr Logic Device Data Structure Pointer
     * @{
     */
        /*!
         * @{
         */
#if USING_SPI1
LDD_TDeviceData* masterSPI1DevData; /*!< Pointer to SPI1 device data structure in master mode. */
#endif

#if USING_SPI0
LDD_TDeviceData* slaveSPI0DevData; /*!< Pointer to SPI0 device data structure in slave mode. */
#endif

#if USING_SPI0_DMA
LDD_TDeviceData* slaveSPIRxDMADevData;  /*!< Pointer to SPI0 DMA reception device data structure in slave mode. */
LDD_TDeviceData* slaveSPITxDMADevData;  /*!< Pointer to SPI0 DMA transmission device data structure in slave mode. */
#endif

#if USING_SPI1_DMA
LDD_TDeviceData* masterSPIRxDMADevData; /*!< Pointer to SPI1 DMA reception device data structure in master mode. */
LDD_TDeviceData* masterSPITxDMADevData; /*!< Pointer to SPI1 DMA transmission device data structure in master mode. */
#endif

#if USING_UART0
LDD_TDeviceData* uart0DevData; /*!< Pointer to UAURT0 device data structure. */
#endif

#if USING_UART1
LDD_TDeviceData* uart1DevData; /*!< Pointer to UART1 device data structure. */
#endif

#if USING_UART2
LDD_TDeviceData* uart2DevData; /*!< Pointer to UART2 device data structure. */
#endif

//#if USING_DMA
/* Already defined in DMA_CTRL.h */
LDD_TDeviceData* dmaControllerDevData;             /*!< Pointer to DMA controller device data structure. */
//LDD_TDeviceData* dmaController4SlaveSPIDevData;    /*!< Pointer to DMA controller for slave SPI device data structure. */
//LDD_TDeviceData* dmaController4MasterSPIDevData;   /*!< Pointer to DMA controller for master SPI device data structure. */
//#endif
        /*!
         * @}
         */

        /*!
         * @{
         */
LDD_TDeviceData* portA2DevData;  /*!< Pointer to PortA Pin2 device data structure, signal: SYNC_INT. */
LDD_TDeviceData* portB1DevData;  /*!< Pointer to PortB Pin1 device data structure, signal: START. */
LDD_TDeviceData* portB19DevData; /*!< Pointer to PortB Pin19 device data structure, signal: UPDRDY. */
LDD_TDeviceData* portC1DevData;  /*!< Pointer to PortC Pin1 device data structure, signal: DAISY_IN. */
LDD_TDeviceData* portC2DevData;  /*!< Pointer to PortC Pin2 device data structure, signal: CLKSEL. */
//LDD_TDeviceData* portC3DevData;  /*!< Pointer to PortC Pin3 device data structure, signal: TEST_SIGNAL. */
LDD_TDeviceData* portD4DevData;  /*!< Pointer to PortD Pin4 device data structure, signal: ~DRDY. */
LDD_TDeviceData* portE18DevData; /*!< Pointer to PortE Pin18 device data structure, signal: ~PWDN. */
LDD_TDeviceData* portE19DevData; /*!< Pointer to PortE Pin19 device data structure, signal: ~RESET. */
        /*!
         * @}
         */
    /*!
     * @}
     */

/* END Globals. */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
/* #ifndef GLOBALS_H_ */

/*!
 * @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Dong
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
