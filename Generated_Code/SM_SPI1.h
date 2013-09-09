/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : SM_SPI1.h
**     Project     : ProcessorExpert
**     Processor   : MKL15Z128VLH4
**     Component   : SPIMaster_LDD
**     Version     : Component 01.091, Driver 01.02, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-09-09, 19:12, # CodeGen: 128
**     Abstract    :
**         This component "SPIMaster_LDD" implements MASTER part of synchronous
**         serial master-slave communication.
**     Settings    :
**          Component name                                 : SM_SPI1
**          Device                                         : SPI1
**          Interrupt service/event                        : Disabled
**          Settings                                       : 
**            Input pin                                    : Enabled
**              Pin                                        : PTD7/SPI1_MISO/UART0_TX/SPI1_MOSI
**              Pin signal                                 : SPI1_IN
**            Output pin                                   : Enabled
**              Pin                                        : ADC0_SE7b/PTD6/LLWU_P15/SPI1_MOSI/UART0_RX/SPI1_MISO
**              Pin signal                                 : SPI1_OUT
**            Clock pin                                    : 
**              Pin                                        : ADC0_SE6b/PTD5/SPI1_SCK/UART2_TX/TPM0_CH5
**              Pin signal                                 : SPI1_SCK
**            Chip select list                             : 0
**            Attribute set list                           : 1
**              Attribute set 0                            : 
**                Width                                    : 8 bits
**                MSB first                                : yes
**                Clock polarity                           : Low
**                Clock phase                              : Change on leading edge
**                Parity                                   : None
**                Chip select toggling                     : no
**                Clock rate index                         : 0
**            Clock rate                                   : 4 MHz
**            HW input buffer size                         : Max buffer size
**            HW input watermark                           : 1
**            HW output buffer size                        : Max buffer size
**            HW output watermark                          : 1
**          Initialization                                 : 
**            Initial chip select                          : 0
**            Initial attribute set                        : 0
**            Enabled in init. code                        : no
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnBlockSent                                : Disabled
**              OnBlockReceived                            : Disabled
**              OnError                                    : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init    - LDD_TDeviceData* SM_SPI1_Init(LDD_TUserData *UserDataPtr);
**         Enable  - LDD_TError SM_SPI1_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable - LDD_TError SM_SPI1_Disable(LDD_TDeviceData *DeviceDataPtr);
**         Main    - void SM_SPI1_Main(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file SM_SPI1.h
** @version 01.02
** @brief
**         This component "SPIMaster_LDD" implements MASTER part of synchronous
**         serial master-slave communication.
*/         
/*!
**  @addtogroup SM_SPI1_module SM_SPI1 module documentation
**  @{
*/         

#ifndef __SM_SPI1_H
#define __SM_SPI1_H

/* MODULE SM_SPI1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "Cpu.h"
#include "SPI_PDD.h"

#ifdef __cplusplus
extern "C" {
#endif 


/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define SM_SPI1_PRPH_BASE_ADDRESS  0x40077000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define SM_SPI1_Init_METHOD_ENABLED    /*!< Init method of the component SM_SPI1 is enabled (generated) */
#define SM_SPI1_Enable_METHOD_ENABLED  /*!< Enable method of the component SM_SPI1 is enabled (generated) */
#define SM_SPI1_Disable_METHOD_ENABLED /*!< Disable method of the component SM_SPI1 is enabled (generated) */
#define SM_SPI1_Main_METHOD_ENABLED    /*!< Main method of the component SM_SPI1 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */

#define SM_SPI1_CHIP_SELECT_COUNT 0U   /*!< Number of chip selects */
#define SM_SPI1_CONFIGURATION_COUNT 1U /*!< Number of predefined configurations */

/* Communication error data type */


/*
** ===================================================================
**     Method      :  SM_SPI1_Init (component SPIMaster_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc.
**         If the "Enable in init. code" is set to "yes" value then the
**         device is also enabled(see the description of the Enable()
**         method). In this case the Enable() method is not necessary
**         and needn't to be generated. 
**         This method can be called only once. Before the second call
**         of Init() the Deinit() must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Device data structure pointer.
*/
/* ===================================================================*/
LDD_TDeviceData* SM_SPI1_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  SM_SPI1_Enable (component SPIMaster_LDD)
*/
/*!
**     @brief
**         This method enables SPI device. This method is intended to
**         be used together with <Disable()> method to temporary switch
**         On/Off the device after the device is initialized. This
**         method is required if the <Enabled in init. code> property
**         is set to "no" value.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
*/
/* ===================================================================*/
LDD_TError SM_SPI1_Enable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  SM_SPI1_Disable (component SPIMaster_LDD)
*/
/*!
**     @brief
**         Disables the SPI device. When the device is disabled, some
**         component methods should not be called. If so, error
**         ERR_DISABLED may be reported. This method is intended to be
**         used together with <Enable()> method to temporary switch
**         on/off the device after the device is initialized. This
**         method is not required. The <Deinit()> method can be used to
**         switch off and uninstall the device.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
*/
/* ===================================================================*/
LDD_TError SM_SPI1_Disable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  SM_SPI1_Main (component SPIMaster_LDD)
*/
/*!
**     @brief
**         This method is available only in the polling mode (Interrupt
**         service/event = 'no'). If interrupt service is disabled this
**         method replaces the interrupt handler. This method should be
**         called if Receive/SendBlock was invoked before in order to
**         run the reception/transmission. The end of the
**         receiving/transmitting is indicated by OnBlockSent or
**         OnBlockReceived event. 
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
*/
/* ===================================================================*/
void SM_SPI1_Main(LDD_TDeviceData *DeviceDataPtr);

/* END SM_SPI1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif
/* ifndef __SM_SPI1_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.2 [05.07]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
