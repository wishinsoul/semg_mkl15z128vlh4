/* ###################################################################
 **     THIS COMPONENT MODULE IS GENERATED BY USER
 **     Filename    : Process.h
 **     Project     : semg_mkl15z128vlh4
 **     Processor   : MKL15Z128VLH4
 **     Component   :
 **     Version     :
 **     Datasheet   :
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2013-Aug 5, 2013, 8:54:36 PM, # CodeGen: 1
 **     Author	    : Dong
 **     Abstract    :
 **			This file contains functions for kinds of data processing.
 **     Settings    :
 **
 **     Contents    :
 **         Process         - void Process(void);
 **         SplitRawData    - LDD_TError SplitRawData(TADCDataPtr adcDataPtr);
 **
 **     Mail      	: pzdongdong@163.com
 **
 **     Revision    : No.  Name        Data/Time        Content
 ** ###################################################################*/
/*!
 * @file Process.h
 * @version 01.00
 * @brief
 *		This file contains functions for kinds of data processing.
 */
/*!
 *  @addtogroup Proc Process module documentation
 *      This module contains functions for kinds of data processing.
 *  @{
 */

#ifndef PROCESS_H_
#define PROCESS_H_
/* Module Process */

/* {Default RTOS Adapter} No RTOS includes */
#include "Macros.h"
#include "PE_Types.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*
 * ===================================================================
 *     Method      : Process(Module Process)
 */
/*!
 *     @brief
 *          The primary routine of processing the data.
 */
/* ===================================================================*/
void Process(void);

/*
 * ===================================================================
 *     Method      : SplitRawData(Module Process)
 */
/*!
 *     @brief
 *          This method splits the ADC raw data to each part of the ADC data
 *          structure.
 *     @param[in]
 *          adcDataPtr      - Pointer to ADC data structure.
 *     @return
 *                          - ERR_PARAM_DATA: The head byte of the raw is not valid,
 *                                            so the data is invalid.
 *                          - ERR_OK: Succeeded to split.
 */
/* ===================================================================*/
LDD_TError SplitRawData(TADCDataPtr adcDataPtr);

/*
 * ===================================================================
 *     Method      : SplitRawData(Module Process)
 */
/*!
 *     @brief
 *          This method copies ADC data from ADC structure to MCU structure.
 *          The format of data in MCU structure
       @verbatim
       --------------------------------
       | (Chn) | 1ms 2ms 3ms ... 99ms |
       --------------------------------
       | (Ch1) | [0] [1] [2] ... [99] |
       | (Ch2) | [0] [1] [2] ... [99] |
       | (Ch3) | [0] [1] [2] ... [99] |
       | (Ch4) | [0] [1] [2] ... [99] |
       | (Ch5) | [0] [1] [2] ... [99] |
       | (Ch6) | [0] [1] [2] ... [99] |
       | (Ch7) | [0] [1] [2] ... [99] |
       | (Ch8) | [0] [1] [2] ... [99] |
       --------------------------------
       @endverbatim
 *     @param
 *          void
 *     @return
 *          void
 */
/* ===================================================================*/
void CopyADCDataToMCUData();
    /* END Process. */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
/* PROCESS_H_ */

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
