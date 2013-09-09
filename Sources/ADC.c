/* ###################################################################
 **     THIS COMPONENT MODULE IS GENERATED BY USER
 **     Filename    : ADC.c
 **     Project     : semg_mkl15z128vlh4
 **     Processor   : MKL15Z128VLH4
 **     Component   : ADS1198
 **     Version     : APRIL 2010-REVISED NOVEMBER 2011
 **     Datasheet   : SBAS471C
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2013-07-12, 20:06, # CodeGen: 0
 **     Author	    : Dong
 **     Abstract    :
 **			This file contains ADC operation functions.
 **     Settings    :
 **
 **     Contents    :
 **         Init               - void ADCInit(void);
 **         Configure          - LDD_TError ADCConfigure(void);
 **         Enable             - LDD_TError ADCEnable(void);
 **         Disable            - LDD_TError ADCDisable(void);
 **         PowerUp            - LDD_TError ADCPowerUp(void);
 **         PowerDown          - LDD_TError ADCPowerDown(void);
 **         UseInClock         - LDD_TError ADCUseInternalClock(void);
 **         UseExClock         - LDD_TError ADCUseExternalClock(void);
 **         StartConvert       - LDD_TError ADCStartConvertByHardware(void);
 **                            - LDD_TError ADCStartConvertByCommand(void);
 **         StopConvert        - LDD_TError ADCStopConvertByHardware(void);
 **                            - LDD_TError ADCStopConvertByCommand(void);
 **         Reset              - void ADCResetByHardware(void);
 **                            - LDD_TError ADCResetByCommand(void);
 **         DaisyConnect       - LDD_TError ADCDaisyConnect(void);
 **         DirectConnect      - LDD_TError ADCDirectConnect(void);
 **         WakeUp             - LDD_TError ADCWakeUp();
 **         StandBy            - LDD_TError ADCStandBy();
 **         RDATAC             - LDD_TError ADCReadDataContinuous(void);
 **         SDATAC             - LDD_TError ADCStopDataContinuous(void);
 **         SendCommand        - LDD_TError ADCSendCommand(byte* cmd, uint8 len);
 **         ReadRegister       - LDD_TError ADCReadRegister(byte regAddr, uint8 n, byte* dat, uint16 len);
 **         WriteRegister      - LDD_TError ADCWriteRegister(byte regAddr, uint8 n, byte* dat, uint16 len);
 **         ReadData           - LDD_TError ADCReadContinuousData();
 **                            - LDD_TError ADCReadData();
 **         ADCDataInit        - ADCDataInit(TADCDataPtr userDataPtr);
 **         CheckCommand       - LDD_TError CheckCommand(byte cmd);
 **
 **     Mail      	: pzdongdong@163.com
 **     
 **     Revision    : No.  Name        Date/Time        Content
 ** ###################################################################*/
/*!
 * @file ADC.c
 * @version 01.00
 * @brief	
 * 		This file contains ADC operation functions.
 */
/*!
 *  @addtogroup ADC_module	ADC module documentation
 *      This module contains ADC operation functions.
 *  @{
 */

/* MODULE ADC. */

/* {Default RTOS Adapter} No RTOS includes */
#include "SM_SPI1.h"
#include "BitIO_NOT_PWDN.h"
#include "BitIO_NOT_RESET.h"
#include "BitIO_START.h"
#include "BitIO_DAISY_IN.h"
#include "BitIO_CLKSEL.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Events.h"
#include "Cpu.h"

#include "limits.h"
#include "string.h"
#include "stdlib.h"

#include "MyHeaders.h"

/* 
 * ===================================================================
 * Global Variables
 * ===================================================================
 */
extern volatile bool flagUartReceived;
extern volatile bool flagUartSent;

/*
 * ===================================================================
 *     Method      :  ADCInit (Component ADC)
 */
/*!
 *     @brief
 *          Initializes ADC. 
 *          The method is called in the PeripheralInit function and will be called
 *          only once.
 */
/* ===================================================================*/
void ADCInit(void)
{ 
    ADCEnable();                /* Clear ~CS, select ADC */
    DelaySomeMs(1);
    ADCUseInternalClock();      /* Set CLKSEL, ADC uses internal clock  */
    DelaySomeMs(1);
    ADCStopConvertByHardware(); /* Clear START, ADC does not convert */
    DelaySomeMs(1);
    ADCPowerUp();               /* Set ~PWDN */
    DelaySomeMs(1);
//    ADCDirectConnect();         /* Use direct connect mode */
    ADCResetByHardware();       /* Reset ADC when power on */
    DelaySomeMs(1);
    ADCConfigure();             /* Configure the register of ADC. */
}

/*
 * ===================================================================
 *     Method      :  ADCEnable (Component ADC)
 */
/*!
 *     @brief
 *          Signal ~CS is low, enable ADC.
 *     @return
 *                          - ERR_OK: Output of this pin is OK.
 *                          - ERR_COMMON: Output of this pin goes wrong.
 */
/* ===================================================================*/
LDD_TError ADCEnable(void)
{
//    LDD_TError err;
    
    return ERR_OK;
}

/*
 * ===================================================================
 *     Method      :  ADCDisable (Component ADC)
 */
/*!
 *     @brief
 *          Signal ~CS is High, disable ADC. 
 *     @return
 *                          - ERR_OK: Output of this pin is OK.
 *                          - ERR_COMMON: Output of this pin goes wrong.
 */
/* ===================================================================*/
LDD_TError ADCDisable(void)
{
//    LDD_TError err;
    
    return ERR_OK;
}

/*
 * ===================================================================
 *     Method      : ADCConfigure (Module ADC)
 */
/*!
 *     @brief
 *          Configure the registers of ADC via SPI1.    
 *     @return
 *                          - See PE_Error.h
 */
/* ===================================================================*/
LDD_TError ADCConfigure(void)
{
//    LDD_TError err;
    
    return ERR_OK;
}

/*
 * ===================================================================
 *     Method      :  ADCPowerUp (Component ADC)
 */
/*!
 *     @brief
 *          Signal ~PWDN is high, ADC power up. 
 *     @return
 *                          - ERR_OK: Output of this pin is OK.
 *                          - ERR_COMMON: Output of this pin goes wrong.
 */
/* ===================================================================*/
LDD_TError ADCPowerUp(void)
{
    LDD_TError err;
    
    IONotResetSetVal(); /* Set ~PWDN, ADC power up */
    
    if(!IONotResetGetVal())
    {
        err = ERR_COMMON;
        PrintErrorMessage(err);
    }
    else
    {
        err = ERR_OK;
    }
    
    return err;
}

/*
 * ===================================================================
 *     Method      :  ADCPowerDown (Component ADC)
 */
/*!
 *     @brief
 *          Signal ~PWDN is low, ADC power down. 
 *     @return
 *                          - ERR_OK: Output of this pin is OK.
 *                          - ERR_COMMON: Output of this pin goes wrong.
 */
/* ===================================================================*/
LDD_TError ADCPowerDown(void)
{
    LDD_TError err;
    
    IONotResetClrVal(); /* Clear ~PWDN, ADC power down */
    
    if(IONotResetGetVal())
    {
        err = ERR_COMMON;
        PrintErrorMessage(err);
    }
    else
    {
        err = ERR_OK;
    }
    
    return err;
}

/*
 * ===================================================================
 *     Method      :  ADCUseInternalClock (Component ADC)
 */
/*!
 *     @brief
 *          Signal CLKSEL is high, ADC uses internal clock. 
 *     @return
 *                          - ERR_OK: Output of this pin is OK.
 *                          - ERR_COMMON: Output of this pin goes wrong.
 */
/* ===================================================================*/
LDD_TError ADCUseInternalClock(void)
{
    LDD_TError err;
    
    IOClockSelectSetVal(); /* Set CLKSEL, use internal clock */
    
    if(!IOClockSelectGetVal())
    {
        err = ERR_COMMON;
        PrintErrorMessage(err);
    }
    else
    {
        err = ERR_OK;
    }
    
    return err;
}

/*
 * ===================================================================
 *     Method      :  ADCUseExternalClock (Component ADC)
 */
/*!
 *     @brief
 *          Signal CLKSEL is low, ADC uses external clock. 
 *     @return
 *                          - ERR_OK: Output of this pin is OK.
 *                          - ERR_COMMON: Output of this pin goes wrong.
 */
/* ===================================================================*/
LDD_TError ADCUseExternalClock(void)
{
    LDD_TError err;
    
    IOClockSelectClrVal(); /* Clear CLKSEL, use external clock */
    
    if(IOClockSelectGetVal())
    {
        err = ERR_COMMON;
        PrintErrorMessage(err);
    }
    else
    {
        err = ERR_OK;
    }
    
    return err;
}

/*
 * ===================================================================
 *     Method      :  ADCStartConvertByHardware (Component ADC)
 */
/*!
 *     @brief
 *          Signal START is high, ADC starts to convert.
 *          This function starts ADC to convert via signal START.
 *     @return
 *                          - ERR_OK: Output of this pin is OK.
 *                          - ERR_COMMON: Output of this pin goes wrong.
 */
/* ===================================================================*/
LDD_TError ADCStartConvertByHardware(void)
{
    LDD_TError err;
    
    IOStartSetVal(); /* Set START, ADC starts to convert */
    
    if(!IOStartGetVal())
    {
        err = ERR_COMMON;
        PrintErrorMessage(err);
    }
    else
    {
        err = ERR_OK;
    }
    
    return err;
}

/*
 * ===================================================================
 *     Method      :  ADCStartConvertByCommand (Component ADC)
 */
/*!
 *     @brief
 *          MCU sends START command to ADC, ADC starts to convert.
 *          This function starts ADC to convert via SPI1.
 *          In this method, signal START must be low.
 *     @return
 *                          - See PE_Error.h
 */
/* ===================================================================*/
LDD_TError ADCStartConvertByCommand(void)
{
    LDD_TError err;
    byte cmd = ADC_CMD_START;
    
    IOStartClrVal(); /* Clear START, in this method, signal START must be low */
    
    /* Sends START command via SPI1 */
    err = ADCSendCommand(&cmd, 1);
    DelaySomeMs(1);
    
    if(err != ERR_OK)
    {
        PrintErrorMessage(err);
    }
    
    return err;
}

/*
 * ===================================================================
 *     Method      :  ADCStopConvertByHardware (Component ADC)
 */
/*!
 *     @brief
 *          Signal START is low, ADC stops converting.
 *          This function starts ADC to convert via signal START.
 *     @return
 *                          - ERR_OK: Output of this pin is OK.
 *                          - ERR_COMMON: Output of this pin goes wrong.
 */
/* ===================================================================*/
LDD_TError ADCStopConvertByHardware(void)
{
    LDD_TError err;
    
    IOStartClrVal(); /* Clear START, ADC does not convert */
    
    if(IOStartGetVal())
    {
        err = ERR_COMMON;
        PrintErrorMessage(err);
    }
    else
    {
        err = ERR_OK;
    }
    
    return err;
}

/*
 * ===================================================================
 *     Method      :  ADCStartConvertByCommand (Component ADC)
 */
/*!
 *     @brief
 *          MCU sends STOP command to ADC, ADC stops to convert.
 *          This function stops ADC to convert via SPI1.
 *          In this method, signal START must be low.
 *     @return
 *                          - See PE_Error.h
 */
/* ===================================================================*/
LDD_TError ADCStopConvertByCommand(void)
{
    LDD_TError err;
    byte cmd = ADC_CMD_STOP;
    
    IOStartClrVal(); /* Clear START, in this method, signal START must be low */
    
    /* Sends STOP command via SPI1 */
    err = ADCSendCommand(&cmd, 1);
    DelaySomeMs(1);
    
    if(err != ERR_OK)
    {
        PrintErrorMessage(err);
    }
    
    return err;
}

/*
 * ===================================================================
 *     Method      :  ADCResetByHardware (Component ADC)
 */
/*!
 *     @brief
 *          Signal ~RESET varies from high to low to high, ADC resets. 
 *          This function resets ADC via signal RESET.
 */
/* ===================================================================*/
void ADCResetByHardware(void)
{
    IONotResetSetVal(); /* Set ~RESET */
    DelaySomeMs(100);
    IONotResetClrVal(); /* Clear ~RESET, reset ADC */
    DelaySomeMs(100);
    IONotResetSetVal(); /* Set ~RESET */
}

/*
 * ===================================================================
 *     Method      :  ADCResetByCommand (Component ADC)
 */
/*!
 *     @brief
 *          MCU sends RESET command to ADC, ADC resets.
 *          This function resets ADC via SPI1.
 *          Avoid sending any commands during reset.
 *     @return
 *                          - See PE_Error.h
 */
/* ===================================================================*/
LDD_TError ADCResetByCommand(void)
{
    LDD_TError err;
    byte cmd = ADC_CMD_RESET;
    
    /* Sends RESET command via SPI1 */
    err = ADCSendCommand(&cmd, 1);
    DelaySomeMs(1);
    
    if(err != ERR_OK)
    {
        PrintErrorMessage(err);
    }
    
    return err;
}

/*  
 * ===================================================================
 *     Method      :  ADCDaisyConnect (Component ADC)
 */
/*!
 *     @brief
 *          Signal Daisy_IN is high, ADC connects in daisy mode. 
 *     @return
 *                          - ERR_OK: Output of this pin is OK.
 *                          - ERR_COMMON: Output of this pin goes wrong.
 */
/* ===================================================================*/
LDD_TError ADCDaisyConnect(void)
{
    LDD_TError err;
    
    IODaisyInSetVal(); /* Set DIASY_IN high, connect ADC in daisy mode */
    
    if(!IODaisyInGetVal())
    {
        err = ERR_COMMON;
        PrintErrorMessage(err);
    }
    else
    {
        err = ERR_OK;
    }
    
    return err;
}

/*
 * ===================================================================
 *     Method      :  ADCDirectConnect (Component ADC)
 */
/*!
 *     @brief
 *          Signal Daisy_IN is low, ADC connects in direct mode. 
 *     @return
 *                          - ERR_OK: Output of this pin is OK.
 *                          - ERR_COMMON: Output of this pin goes wrong.
 */
/* ===================================================================*/
LDD_TError ADCDirectConnect(void)
{
    LDD_TError err;
    
    IODaisyInClrVal(); /* Clear DIASY_IN high, connect ADC in direct mode */
    
    if(IODaisyInGetVal())
    {
        err = ERR_COMMON;
        PrintErrorMessage(err);
    }
    else
    {
        err = ERR_OK;
    }
    
    return err;
}

/*
 * ===================================================================
 *     Method      : ADCWakeUp (Component ADC)
 */
/*!
 *     @brief
 *          Send command WAKEUP to ADC via SPI1 to wake up ADC
 *          from low-power standby mode.
 *     @return
 *                          - See PE_Error.h
 */
/* ===================================================================*/
LDD_TError ADCWakeUp(void)
{
    LDD_TError err;
    byte cmd = ADC_CMD_WAKEUP;

    err = ADCSendCommand(&cmd, 1);
    DelaySomeMs(1);
    
    if(err != ERR_OK)
    {
        PrintErrorMessage(err);
    }
    
    return err;
}

/*
 * ===================================================================
 *     Method      : ADCStandBy (Component ADC)
 */
/*!
 *     @brief
 *          Send command STANDBY via SPI1 to make ADC entering
 *          the low-power standby mode.
 *     @return
 *                          - See PE_Error.h
 */
/* ===================================================================*/
LDD_TError ADCStandBy(void)
{
    LDD_TError err;
    byte cmd = ADC_CMD_STANDBY;
    
    err = ADCSendCommand(&cmd, 1);
    DelaySomeMs(1);
    
    if(err != ERR_OK)
    {
        PrintErrorMessage(err);
    }
    
    return err;
}

/*
 * ===================================================================
 *     Method      : ADCReadDataContinuous (Component ADC)
 */
/*!
 *     @brief
 *          Send command RDATAC via SPI1 to make the conversion data
 *          of ADC can read continuously without command RDATA.
 *     @return
 *                          - See PE_Error.h
 */
/* ===================================================================*/
LDD_TError ADCReadDataContinuous(void)
{
    LDD_TError err;
    byte cmd = ADC_CMD_RDATAC;
    
    err = ADCSendCommand(&cmd, 1);
    DelaySomeMs(1);
    
    if(err != ERR_OK)
    {
        PrintErrorMessage(err);
    }
    
    return err;
}

/*
 * ===================================================================
 *     Method      : ADCWakeUp (Component ADC)
 */
/*!
 *     @brief
 *          Send command SDATAC to ADC via SPI1 to stop ADC's RDATAC mode.
 *     @return
 *                          - See PE_Error.h
 */
/* ===================================================================*/
LDD_TError ADCStopReadDataContinuous(void)
{
    LDD_TError err;
    byte cmd = ADC_CMD_SDATAC;
    
    err = ADCSendCommand(&cmd, 1);
    DelaySomeMs(1);
    
    if(err != ERR_OK)
    {
        PrintErrorMessage(err);
    }
    
    return err;
}

/*
 * ===================================================================
 *     Method      : ADCSendCommand (Component ADC)
 */
/*!
 *     @brief
 *          Send command to ADC via SPI1.
 *     @param[in]
 *          cmd             - Pointer to command to be sent.
 *                            See group ADC Commands in Macros.h.
 *     @param[in]
 *          len             - The length of command.
 *                            The available value is 1 for most commands,
 *                            except for command read/write register
 *                            which must be 2.
 *     @return
 *                          - Error code of the the transmission status.
 *                          - Possible codes:             
 *                              - ERR_OK       - OK.
 *                              - ERR_SPEED    - This device does not work in
 *                                               the active clock configuration.
 *                              - ERR_DISABLED - Component is disabled.
 *                              - ERR_BUSY     - The previous receive request is
 *                                               pending.
 *                              - etc.         - See PE_Error.h.
 */
/* ===================================================================*/
LDD_TError ADCSendCommand(byte* cmd, uint8 len)
{
    LDD_TError err;
    
    /* Check the command. */
    err = CheckCommand(*cmd, len);
    if(err != ERR_OK)
    {
        PrintErrorMessage(err);
        return err;
    }
    
    /* Prepare the buffer of command transmitted to ADC. */
//    err = SPI1Send(cmd, len);
    if(err != ERR_OK)
    {
        PrintErrorMessage(err);         /* If error occurred, print the error message, */
        return err;                     /* then return error type. */
    }
    
    /* Enable the SPI transmission interrupt to transmit. */
//    SPI1EnableTxInterrupt();
    
    return err;
}

/*
 * ===================================================================
 *     Method      : ADCReadRegister (Component ADC)
 */
/*!
 *     @brief
 *          Read data from regisger of ADC via SPI1.
 *     @param[in]
 *          regAddr         - The first address of register(s) to be read.
 *     @param[in]
 *          n               - The number of registers to be read.
 *     @param[out]
 *          dat             - Pointer to buffer where received data in.
 *     @param[in]
 *          len             - The length of data bytes to be read.
 *     @return
 *                          - Error code of the the transmission status.
 *                          - Possible codes:             
 *                              - ERR_OK       - OK.             
 *                              - ERR_SPEED    - This device does not work in
 *                                               the active clock configuration.           
 *                              - ERR_DISABLED - Component is disabled.
 *                              - ERR_BUSY     - The previous receive request is
 *                                               pending.
 *                              - etc.         - See PE_Error.h.
 */                                
/* ===================================================================*/
LDD_TError ADCReadRegister(byte regAddr, uint8 n, byte* dat, uint16 len)
{
    extern volatile bool flagMasterReceived;
    LDD_TError err;
    byte* dummy = NULL;
    byte strCmd[2];                                     /* Read register command is a double-byte command. */
    
    /* Check if the register address is valid. */
    if(regAddr < ADC_REG_ID || regAddr > ADC_REG_WCT2)
    {
        err = ERR_PARAM_ADDRESS;
        PrintErrorMessage(err);
        
        return err;
    }
    
    /* Check if the number of registers to be read is valid. */
    if(n < MIN_REGISTER_READ_NUMBER || n > MAX_REGISTER_READ_NUMBER)
    {
        err = ERR_RANGE;
        PrintErrorMessage(err);
        
        return err;
    }
    
    /* Check if the reception buffer is valid. */
    if(dat == NULL)
    {
        err = ERR_PARAM_BUFFER_COUNT;
        PrintErrorMessage(err);
        
        return err;
    }
    
    /* Check if the length of data bytes is valid. */
    if(len < 0 || len > USHRT_MAX)
    {
        err = ERR_PARAM_LENGTH;
        PrintErrorMessage(err);
        
        return err;
    }
    
    /* Make sure the flag is FALSE before reception begins. */
    flagMasterReceived = FALSE;
    
    dummy = (byte*)malloc(len);                 /* Dummy message provides clock for slave SPI device. */
    if(dummy == NULL)                               /* If the allocation failed, return with error. */
    {
        err = ERR_NOTAVAIL;
        PrintErrorMessage(err);
        
        return err;
    }
    memset(dummy, 0, len);                      /* The first byte received is always 0, so an extra byte is necessary. */
    
    /* Send the read data command to ADC. */
    strCmd[0] = ADC_CMD_RREG(regAddr);              /* According to user manual, read ADC register command, */
    strCmd[1] = n - 1;                              /* and if the number of registers to be read is n, n - 1 should be sent to ADC. */
    err = ADCSendCommand(strCmd, 2);
    if(err != ERR_OK)
    {
#if DEBUG
        printf("Send command error\n");             /* If error occurred, print message, */
#endif
        free(dummy);                                /* and free the memory allocated dynamically, */
        return err;                                 /* then return the error type. */
    }
    
    /* 
     * Prepare the buffer of dummy message transmitted to ADC
     * as the clock for slave SPI device to transmit data.
     */
    err = SPI1Send(dummy, len);
    if(err != ERR_OK)
    {
        PrintErrorMessage(err);
#if DEBUG
        printf("Send dummy error\n");
#endif        
        free(dummy);
        return err;
    }
    
    /* Prepare the reception buffer for the data. */
    err = SPI1Receive(dat, len);                /* The first byte received is always 0, so an extra byte is necessary. */
    if(err != ERR_OK)
    {
        PrintErrorMessage(err);
#if DEBUG
        printf("Read data error\n");
#endif
        free(dummy);
        return err;
    }
    
    /* 
     * Enable the transmission and reception interrupts
     * to Send dummy message and receive data.
     */
    SPI1EnableInterrupt();
    
    /* Wait until the reception finishes. */
    while(!flagMasterReceived);
    
    free(dummy);
    return err;
}

/*
 * ===================================================================
 *     Method      : ADCWriteRegister (Component ADC)
 */
/*!
 *     @brief
 *          Write data to register of ADC via SPI1.
 *     @param[in]
 *          regAddr         - The first address of register(s) to be written.
 *     @param[in]
 *          n               - The number of registers to be written.
 *     @param[in]
 *          dat             - Pointer to buffer where data to be written in.
 *     @param[in]
 *          len             - The length of data bytes to be written.
 *     @return
 *                          - Error code of the the transmission status.
 *                          - Possible codes:             
 *                              - ERR_OK           - OK.             
 *                              - ERR_SPEED        - This device does not work in
 *                                                   the active clock configuration.           
 *                              - ERR_DISABLED     - Component is disabled.
 *                              - ERR_BUSY         - The previous receive request is
 *                                                   pending.
 *                              - etc.             - See PE_Error.h.
 */                                
/* ===================================================================*/
LDD_TError ADCWriteRegister(byte regAddr, uint8 n, byte* dat, uint16 len)
{
    extern volatile bool flagMasterSent;
    LDD_TError err;
    byte strCmd[2];                                     /* Write register command is a double-byte command. */
    
    /* Check if the register address is valid. */
    if(regAddr < ADC_REG_ID || regAddr > ADC_REG_WCT2)
    {
        err = ERR_PARAM_ADDRESS;
        PrintErrorMessage(err);
        
        return err;
    }
    
    /* Check if the number of registers to be written is valid. */
    if(n < MIN_REGISTER_READ_NUMBER || n > MAX_REGISTER_READ_NUMBER)
    {
        err = ERR_RANGE;
        PrintErrorMessage(err);
        
        return err;
    }
    
    /* Check if the transmission buffer is valid. */
    if(dat == NULL)
    {
        err = ERR_PARAM_BUFFER_COUNT;
        PrintErrorMessage(err);
        
        return err;
    }
    
    /* Check if the length of data bytes is valid. */
    if(len < 0 || len > USHRT_MAX)
    {
        err = ERR_PARAM_LENGTH;
        PrintErrorMessage(err);
        
        return err;
    }
    
    /* Make sure the flag is FALSE before transmission begins. */
    flagMasterSent = FALSE;
    
    /* Send the write data command to ADC. */
    strCmd[0] = ADC_CMD_WREG(regAddr);              /* According to user manual, write ADC register command, */
    strCmd[1] = n - 1;                              /* and if the number of registers to be written is n, n - 1 should be sent to ADC. */
    err = ADCSendCommand(strCmd, 2);
    if(err != ERR_OK)
    {
#if DEBUG
        printf("Send command error\n");             /* If error occurred, print message, */
#endif
        return err;                                 /* then return the error type. */
    }

    /* Prepare the transmission buffer for the data. */
    err = SPI1Send(dat, len);
    if(err != ERR_OK)
    {
        PrintErrorMessage(err);
#if DEBUG
        printf("Write data error\n");
#endif
        return err;
    }
     
    /* Enable the transmission interrupts to Send data. */
    SPI1EnableTxInterrupt();
    
    /* Wait until the transmission finishes. */
    while(!flagMasterSent);
    
    return err;
}

/*
 * ===================================================================
 *     Method      : ADCReadContinuousData (Component ADC)
 */
/*!
 *     @brief
 *          Read conversion data from ADC in RDATAC mode via SPI1.
 *     @param[out]
 *          dat             - Pointer to buffer where received data in.
 *     @param[in]
 *          len             - The length of data bytes to be read.
 *     @return
 *                          - Error code of the the transmission status.
 *                          - Possible codes:             
 *                              - ERR_OK       - OK.             
 *                              - ERR_SPEED    - This device does not work in
 *                                               the active clock configuration.           
 *                              - ERR_DISABLED - Component is disabled.
 *                              - ERR_BUSY     - The previous receive request is
 *                                               pending.
 *                              - etc.         - See PE_Error.h.
 */  
/* ===================================================================*/
LDD_TError ADCReadContinuousData(byte* dat, uint16 len)
{
    extern volatile bool flagMasterReceived;
    LDD_TError err;
    byte* dummy = NULL;
    
    /* Check if the reception buffer is valid. */
    if(dat == NULL)
    {
        err = ERR_PARAM_BUFFER_COUNT;
        PrintErrorMessage(err);
        
        return err;
    }
    
    /* Check if the length of data bytes is valid. */
    if(len < 0 || len > USHRT_MAX)
    {
        err = ERR_PARAM_LENGTH;
        PrintErrorMessage(err);
        
        return err;
    }
    
    /* Make sure the flag is FALSE before reception begins. */
    flagMasterReceived = FALSE;
    
    dummy = (byte*)malloc(len + 1);             /* Dummy message provides clock for slave SPI device. */
    if(dummy == NULL)                           /* If the allocation failed, return with error. */
    {
        err = ERR_NOTAVAIL;
        PrintErrorMessage(err);
        
        return err;
    }
    memset(dummy, 0, len + 1);
    
    /* 
     * Prepare the buffer of dummy message transmitted to ADC
     * as the clock for slave SPI device to transmit data.
     */
    err = SPI1Send(dummy, len + 1);
    if(err != ERR_OK)
    {
        PrintErrorMessage(err);
#if DEBUG
        printf("Send dummy error\n");
#endif        
        free(dummy);
        return err;
    }
    
    /* Prepare the reception buffer for the data. */
    err = SPI1Receive(dat, len);
    if(err != ERR_OK)
    {
        PrintErrorMessage(err);
#if DEBUG
        printf("Read data error\n");
#endif
        free(dummy);
        return err;
    }
    
    /* 
     * Enable the transmission and reception interrupts
     * to Send dummy message and receive data.
     */
    SPI1EnableInterrupt();
    
    /* Wait until the reception finishes. */
    while(!flagMasterReceived);
    
    free(dummy);
    return err;
}

/*
 * ===================================================================
 *     Method      : ADCReadData (Component ADC)
 */
/*!
 *     @brief
 *          Read conversion data from ADC in RDATA mode via SPI1.
 *     @param[out]
 *          dat             - Pointer to buffer where received data in.
 *     @param[in]
 *          len             - The length of data bytes to be read.
 *     @return
 *                          - Error code of the the transmission status.
 *                          - Possible codes:             
 *                              - ERR_OK       - OK.             
 *                              - ERR_SPEED    - This device does not work in
 *                                               the active clock configuration.           
 *                              - ERR_DISABLED - Component is disabled.
 *                              - ERR_BUSY     - The previous receive request is
 *                                               pending.
 *                              - etc.         - See PE_Error.h.
 */                                
/* ===================================================================*/
LDD_TError ADCReadData(byte* dat, uint16 len)
{
    extern volatile bool flagMasterReceived;
    LDD_TError err;
    byte* dummy = NULL;
    byte cmd;
    
    /* Check if the reception buffer is valid. */
    if(dat == NULL)
    {
        err = ERR_PARAM_BUFFER_COUNT;
        PrintErrorMessage(err);
        
        return err;
    }
    
    /* Check if the length of data bytes is valid. */
    if(len < 0 || len > USHRT_MAX)
    {
        err = ERR_PARAM_LENGTH;
        PrintErrorMessage(err);
        
        return err;
    }
    
    /* Make sure the flag is FALSE before reception begins. */
    flagMasterReceived = FALSE;
    
    dummy = (byte*)malloc(len + 1);                 /* Dummy message provides clock for slave SPI device. */
    if(dummy == NULL)                               /* If the allocation failed, return with error. */
    {
        err = ERR_NOTAVAIL;
        PrintErrorMessage(err);
        
        return err;
    }
    memset(dummy, 0, len + 1);
    
    /* Send the read data command to ADC. */
    cmd = ADC_CMD_RDATA;
    err = ADCSendCommand(&cmd, 1);
    if(err != ERR_OK)
    {
#if DEBUG
        printf("Send command error\n");             /* If error occurred, print message, */
#endif
        free(dummy);                                /* and free the memory allocated dynamically, */
        return err;                                 /* then return the error type. */
    }
    
    /* 
     * Prepare the buffer of dummy message transmitted to ADC
     * as the clock for slave SPI device to transmit data.
     */
    err = SPI1Send(dummy, len + 1);
    if(err != ERR_OK)
    {
        PrintErrorMessage(err);
#if DEBUG
        printf("Send dummy error\n");
#endif        
        free(dummy);
        return err;
    }
    
    /* Prepare the reception buffer for the data. */
    err = SPI1Receive(dat, len);
    if(err != ERR_OK)
    {
        PrintErrorMessage(err);
#if DEBUG
        printf("Read data error\n");
#endif
        free(dummy);
        return err;
    }
    
    /* 
     * Enable the transmission and reception interrupts
     * to Send dummy message and receive data.
     */
    SPI1EnableInterrupt();
    
    /* Wait until the reception finishes. */
    while(!flagMasterReceived);
    
    free(dummy);
    return err;
}

/*
 * ===================================================================
 *     Method      : ADCDataInit(Module ADC)
 */
/*!
 *     @brief
 *         	This method initialize the ADC data structure.
 *     @param
 *         	userDataPtr     - Pointer to specific user data. 
 *     @return
 *         	                - ADC data structure.
 */
/* ===================================================================*/
TADCData ADCDataInit(TADCDataPtr userDataPtr)
{
    TADCData data;

    data.head = (userDataPtr == NULL) ? 0xFFU : userDataPtr->head;
    data.loffStatP = (userDataPtr == NULL) ? 0xFFU : userDataPtr->loffStatP;
    data.loffStatN = (userDataPtr == NULL) ? 0xFFU : userDataPtr->loffStatN;
    data.regGPIOData = (userDataPtr == NULL) ? 0xFFU : userDataPtr->regGPIOData;
    memset(data.rawData, 0xFFU, sizeof(data.rawData));
    memset(data.channelData, 0xFF, sizeof(data.channelData));

    return data;
}

/*
 * ===================================================================
 *     Method      : CheckCommand (Module ADC)
 */
/*!
 *     @brief
 *         	This method checks if the command is valid.
 *     @param[in]
 *         	cmd             - Command to be checked.
 *     @param[in]
 *          len             - The length of command to be checked.
 *                            The available value is 1 for most commands,
 *                            except for command read/write register
 *                            which must be 2.
 *     @return
 *         	                - ERR_OK: Command is valid and the length is legal.
 *         	                - ERR_PARAM_COMMAND: Command is invalid.
 *         	                - ERR_PARAM_LENGTH: Length is illegal.
 */
/* ===================================================================*/
LDD_TError CheckCommand(byte cmd, uint8 len)
{
    if(cmd != ADC_CMD_WAKEUP  &&
       cmd != ADC_CMD_STANDBY &&
       cmd != ADC_CMD_RESET   &&
       cmd != ADC_CMD_START   &&
       cmd != ADC_CMD_STOP    &&
       cmd != ADC_CMD_RDATAC  &&
       cmd != ADC_CMD_SDATAC  &&
       cmd != ADC_CMD_RDATA   &&
       (cmd < ADC_CMD_RREG(ADC_REG_ID) || cmd > ADC_CMD_RREG(ADC_REG_WCT2)) &&
       (cmd < ADC_CMD_WREG(ADC_REG_ID) || cmd > ADC_CMD_WREG(ADC_REG_WCT2))
      )
    {
        return ERR_PARAM_COMMAND; 
    }
    
    if(
       (
        (cmd == ADC_CMD_WAKEUP  ||
         cmd == ADC_CMD_STANDBY ||
         cmd == ADC_CMD_RESET   ||
         cmd == ADC_CMD_START   ||
         cmd == ADC_CMD_STOP    ||
         cmd == ADC_CMD_RDATAC  ||
         cmd == ADC_CMD_SDATAC  ||
         cmd == ADC_CMD_RDATA
        ) && 
        len !=1
       ) ||
       (
        (
         (cmd >= ADC_CMD_RREG(ADC_REG_ID) && cmd <= ADC_CMD_RREG(ADC_REG_WCT2)) ||
         (cmd >= ADC_CMD_WREG(ADC_REG_ID) && cmd <= ADC_CMD_WREG(ADC_REG_WCT2))
        ) &&
        len != 2
       )
      )
    {
         return ERR_PARAM_LENGTH; 
    }
    
    return ERR_OK;
}

/* END ADC. */

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
