/* ###################################################################
 **     THIS COMPONENT MODULE IS GENERATED BY USER
 **     Filename    : Init.c
 **     Project     : semg_mkl15z128vlh4
 **     Processor   : MKL15Z128VLH4
 **     Component   :
 **     Version     :
 **     Datasheet   :
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2013-07-12, 15:40, # CodeGen: 0
 **     Author	    : Dong
 **     Abstract    :
 **			This file contains user initialization of data, on-chip and peripheral devices.
 **
 **			The followings will be initialized:
 **			    - User data
 **				- On-chip devices
 **					- SPI0, SPI1
 **					- SPI0_TX_DMA, SPI0_RX_DMA, SPI1_TX_DMA, SPI1_RX_DMA
 **					- DMA
 **					- UART0, UART2
 **					- PTA2
 **					- PTB1, PTB19
 **					- PTC1, PTC2
 **					- PTD4
 **					- PTE18, PTE19
 **				- Peripheral devices
 **					- ADC
 **     Settings    :
 **
 **     Contents    :
 **     			UserInit - UserInit(void);
 **
 **     Mail      	: pzdongdong@163.com
 **
 **     Revision    : No.  Name        Date/Time        Content
 ** ###################################################################*/
/*!
 * @file Init.c
 * @version 01.00
 * @brief
 *      This file contains user initialization of data, on-chip and peripheral devices.
 *      <p>The followings will be initialized:</p>
 *      <ul>
 *      <li> User data
 *      <li> On-chip devices
 *          <ul>
 *          <li> SPI0, SPI1
 *          <li> SPI0_TX_DMA, SPI0_RX_DMA, SPI1_TX_DMA, SPI1_RX_DMA
 *          <li> DMA
 *          <li> UART0, UART2
 *          <li> PTA2
 *          <li> PTB1, PTB19
 *          <li> PTC1, PTC2
 *          <li> PTD4
 *          <li> PTE18, PTE19
 *          </ul>
 *      <li> Peripheral devices
 *          <ul>
 *          <li> ADC
 *          </ul>
 *      </ul>
 */
/*!
 *  @addtogroup UserInitialization  User Initialization
 *      This module contains user initialization of data, on-chip and peripheral devices.
 *      <p>The followings will be initialized:</p>
 *      <ul>
 *      <li> User data
 *      <li> On-chip devices
 *          <ul>
 *          <li> SPI0, SPI1
 *          <li> SPI0_TX_DMA, SPI0_RX_DMA, SPI1_TX_DMA, SPI1_RX_DMA
 *          <li> DMA
 *          <li> UART0, UART2
 *          <li> PTA2
 *          <li> PTB1, PTB19
 *          <li> PTC1, PTC2
 *          <li> PTD4
 *          <li> PTE18, PTE19
 *          </ul>
 *      <li> Peripheral devices
 *          <ul>
 *          <li> ADC
 *          </ul>
 *      </ul>
 *  @{
 */

/* MODULE Init. */

/* {Default RTOS Adapter} No RTOS includes */
#include "SysTick.h"
#include "SS_SPI1.h"
#include "SM_SPI0.h"
#include "EINT_SYNC_INT.h"
#include "BitIO_UPRDY.h"
#include "BitIO_AD_NOT_RESET0.h"
#include "BitIO_AD_START0.h"
#include "BitIO_AD_NOT_CS0.h"
#include "EINT_AD_NOT_DRDY0.h"
#include "BitIO_AD_NOT_RESET1.h"
#include "BitIO_AD_START1.h"
#include "BitIO_AD_NOT_CS1.h"
#include "EINT_AD_NOT_DRDY1.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Events.h"
#include "Cpu.h"
#include "DMAT_M_SPI_TX.h"
#include "DMA_CTRL.h"
#include "DMAT_M_SPI_RX.h"

#include "MyHeaders.h"
#include "string.h"

static void UserDataInit(void);
static void MCUDataInit(TMCUDataPtr userDataPtr);
static void ARMDataInit(TARMDataPtr userDataPtr);
static void OnChipInit(void);
static void PeripheralInit(void);
static void GPIOInit(void);
static void SPIInit(void);
static void DMAInit(void);
static void UARTInit(void);

/*
 * ===================================================================
 *     Method      :  UserInit (Component on-chip and peripheral devices)
 */
/*!
 *     @brief
 *          Initialize on-chip and peripheral devices.
 *          The method is called in the main function and will be called
 *          only once.
 *     @param
 *          void
 *     @return
 *          void
 */
/* ===================================================================*/
void UserInit(void)
{
//    InitTask();         /* Initialize task list. */
#if DEBUG
    printf("|-+UserDataInit begins...\n");
#endif
    UserDataInit();     /* Initialize user data. */
#if DEBUG
    printf("| -UserDataInit finished.\n");
    printf("|-+OnChipInit begins...\n");
#endif
    __DI();
    OnChipInit();       /* Initialize on-chip devices. */
    __EI();
#if DEBUG
    printf("| -OnChipInit finished.\n");
    printf("|-+PeripheralInit begins...\n");
#endif
    PeripheralInit();   /* Initialize peripheral devices. */
#if DEBUG
    printf("| -PeripheralInit finished.\n");
#endif
}

/*
 * ===================================================================
 *     Method      :  UserDataInit ()
 */
/*!
 *     @brief
 *          Initialize user data.
 *          The method is called in the UserInit function and will be called
 *          only once.
 *          Function ADCDataInit is defined in ADC.h. Function MCUDataInit
 *          and function ARMDataInit is defined below.
 *     @param
 *          void
 *     @return
 *          void
 */
/* ===================================================================*/
static void UserDataInit(void)
{
    ADCDataInit(NULL);
    MCUDataInit(NULL);
    ARMDataInit(NULL);

    return;
}

/*
 * ===================================================================
 *     Method      :  MCUDataInit ()
 */
/*!
 *     @brief
 *         	Initialize MCU data, setting, status.
 *         	The method is called in the UserDataInit function and will be called
 *         	only once.
 *     @param
 *         	userDataPtr     - Pointer to specific user data.
 *     @return
 *          void
 */
/* ===================================================================*/
static void MCUDataInit(TMCUDataPtr userDataPtr)
{
    extern TMCU tMCU;
    extern TMCUPtr tMCUPtr;

    memset(&tMCU, 0, sizeof(TMCU));

    tMCU.mcuStatus.isReceivingADCData = FALSE;
    tMCU.mcuStatus.isMasterReceived = FALSE;
    tMCU.mcuStatus.isMasterSent = FALSE;
    tMCU.mcuStatus.isSlaveReceived = FALSE;
    tMCU.mcuStatus.isSlaveSent = FALSE;
    tMCU.mcuStatus.isSPI0RxDMATransCompleted = FALSE;
    tMCU.mcuStatus.isSPI0TxDMATransCompleted = FALSE;
    tMCU.mcuStatus.isSPI1RxDMATransCompleted = FALSE;
    tMCU.mcuStatus.isSPI1TxDMATransCompleted = FALSE;
    tMCU.mcuStatus.isDelayed = FALSE;
    tMCU.mcuStatus.isUartReceived = FALSE;
    tMCU.mcuStatus.isUartSent = FALSE;

    tMCUPtr = &tMCU;

    return;
}

/*
 * ===================================================================
 *     Method      :  ARMDataInit ()
 */
/*!
 *     @brief
 *          Initialize ARM data, setting, status.
 *          The method is called in the UserDataInit function and will be called
 *          only once.
 *     @param
 *          userDataPtr     - Pointer to specific user data.
 *     @return
 *          void
 */
/* ===================================================================*/
static void ARMDataInit(TARMDataPtr userDataPtr)
{
    extern TARM tARM;
    extern TARMPtr tARMPtr;

    memset(&tARM, 0, sizeof(TARM));

    tARM.armStatus.isRequiringData = FALSE;
    //tARM.armStatus.eARMDataBufFlag = eLEFT;
    tARM.armStatus.isUploadReady = FALSE;
    tARM.armStatus.isForeBufferEmpty = FALSE;
    tARM.armStatus.isForeBufferFull = FALSE;
    tARM.armStatus.isBackBufferEmpty = FALSE;
    tARM.armStatus.isBackBufferFull = FALSE;
    tARM.armStatus.transmitionContent = eNothing;
    tARM.armStatus.backBufferStatus = eNull;
    tARM.armStatus.foreBufferStatus = eNull;
    tARM.foreBuffer = NULL;
    tARM.backBuffer = NULL;

    tARM.armDataLeft.dataFrame[0] = DATA_FRAME_HEAD_BIT;                        /* Head bit */
    tARM.armDataLeft.dataFrame[1] = MCU_NUMBER;                                 /* MCU Number */
    tARM.armDataLeft.dataFrame[2] = 0x0CU;                                      /* Data length high bits */
    tARM.armDataLeft.dataFrame[3] = 0xB0U;                                      /* Data length low bits */
    tARM.armDataLeft.dataFrame[4] = 0x00U;                                      /* Time stamp high bits */
    tARM.armDataLeft.dataFrame[5] = 0x00U;                                      /* Time stamp low bits */
    tARM.armDataLeft.dataFrame[6] = 0x01U & eLeftBuffer;                        /* Status high bits */
    tARM.armDataLeft.dataFrame[7] = 0x00U;                                      /* Status low bits */

    for(int i = 0; i < USING_CHANNEL_COUNT * USING_ADC_COUNT; i++)
    {
        int off = i * CHANNEL_PACKAGE_LENGTH;
        tARM.armDataLeft.dataFrame[8 + off] = CHANNEL_PACKAGE_HEAD_BIT;                   /* Channel package head bit */
        tARM.armDataLeft.dataFrame[9 + off] = i;                                          /* Channel number */
        tARM.armDataLeft.dataFrame[10 + off] = 0x00U;                                     /* Channel package status */
    }

    tARM.armDataLeft.dataFrame[DATA_FRAME_LENGTH - 1] = DATA_FRAME_TAIL_BIT;

    tARM.armDataRight.dataFrame[0] = DATA_FRAME_HEAD_BIT;
    tARM.armDataRight.dataFrame[1] = MCU_NUMBER;
    tARM.armDataRight.dataFrame[2] = 0x0CU;                                      /* Data length high bits */
    tARM.armDataRight.dataFrame[3] = 0xB0U;                                      /* Data length low bits */
    tARM.armDataRight.dataFrame[4] = 0x00U;                                      /* Time stamp high bits */
    tARM.armDataRight.dataFrame[5] = 0x00U;                                      /* Time stamp low bits */
    tARM.armDataRight.dataFrame[6] = 0x01U & eRightBuffer;                       /* Status high bits */
    tARM.armDataRight.dataFrame[7] = 0x00U;                                      /* Status low bits */

    for(int i = 0; i < USING_CHANNEL_COUNT * USING_ADC_COUNT; i++)
    {
        int off = i * CHANNEL_PACKAGE_LENGTH;
        tARM.armDataRight.dataFrame[8 + off] = CHANNEL_PACKAGE_HEAD_BIT;                   /* Channel package head bit */
        tARM.armDataRight.dataFrame[9 + off] = MCU_NUMBER * USING_ADC_COUNT + i;           /* Channel number */
        tARM.armDataRight.dataFrame[10 + off] = 0x00U;                                     /* Channel package status */
    }

    tARM.armDataRight.dataFrame[DATA_FRAME_LENGTH - 1] = DATA_FRAME_TAIL_BIT;

    tARMPtr = &tARM;

    return;
}

/*
 * ===================================================================
 *     Method      :  OnChipInit (Component on-chip devices)
 */
/*!
 *     @brief
 *          Initialize on-chip devices.
 *          The method is called in the UserInit function and will be called
 *          only once.
 *     @param
 *          void
 *     @return
 *          void
 */
/* ===================================================================*/
static void OnChipInit(void)
{
#if DEBUG
    printf("| |-+SysTickInit begins...\n");
#endif
    SysTickInit();
#if DEBUG
    printf("| | -SysTickInit finished.\n");
    printf("| |-+GPIOInit begins...\n");
#endif
    GPIOInit();
#if DEBUG
    printf("| | -GPIOInit finished.\n");
    printf("| |-+DMAInit begins...\n");
#endif
    DMAInit();
#if DEBUG
    printf("| | -DMAInit finished.\n");
    printf("| |-+UARTInit begins...\n");
#endif
    UARTInit();
#if DEBUG
    printf("| | -UARTInit finished.\n");
    printf("| |-+SPIInit begins...\n");
#endif
    SPIInit();
#if DEBUG
    printf("| | -SPIInit finished.\n");
#endif
}

/*
 * ===================================================================
 *     Method      :  PeripheralInit (Component Peripheral devices)
 */
/*!
 *     @brief
 *          Initialize Peripheral devices.
 *          The method is called in the UserInit function and will be called
 *          only once.
 *     @param
 *          void
 *     @return
 *          void
 */
/* ===================================================================*/
static void PeripheralInit(void)
{
#if DEBUG
    printf("| |-+ADCInit begins...\n");
#endif
    /* Initialize ADC. */
    ADCInit(eADC0);
#if USING_ADC_COUNT == 2
    ADCInit(eADC1);
#endif
#if DEBUG
    printf("| | -ADCInit finished.\n");
#endif
}

/*
 * ===================================================================
 *     Method      :  GPIOInit (Component GPIO)
 */
/*!
 *     @brief
 *          Initialize GPIO.
 *          The method is called in the OnChipInit function and will be called
 *          only once.
 *     @param
 *          void
 *     @return
 *          void
 */
/* ===================================================================*/
static void GPIOInit(void)
{
    /*
     * Initialize Port UPRDY for output to ARM.
     * Inform arm upload data are ready to retrieve.
     * Default: 0
     */
    IO_UPRDY = IOUploadReadyInit(NULL);

    /*
     * Initialize Port START for output to ADC.
     * High to start the ADC to convert.
     * Default: 0
     */
    IO_AD_START0 = IOADStart0Init(NULL);
    IO_AD_START1 = IOADStart1Init(NULL);

    /*
     * Initialize Port NOT_RESET for output to ADC.
     * Reset ADC when low.
     * Default: 1
     */
    IO_AD_NOT_RESET0 = IOADNotReset0Init(NULL);
    IO_AD_NOT_RESET1 = IOADNotReset1Init(NULL);

    /*
     * Initialize Port NOT_CS for output to ADC.
     * Low to enable SPI of ADC.
     * Default: 1
     */
    IO_AD_NOT_CS0 = IOADNotCS0Init(NULL);
    IO_AD_NOT_CS1 = IOADNotCS1Init(NULL);

//    /*
//     * Initialize bidirection Port TEST_SIGNAL for test some functions.
//     * Initial direction is output.
//     * Default: 0
//     */
//    IO_TEST_SGINAL = IOTestSignalInit(NULL);

    /*
     * Initialize Port NOT_DRDY for input from ADC.
     * Low when ADC is ready to be read.
     * Meanwhile, an interrupt will be triggered on falling edge
     * calling MCU to read data from ADC.
     */
    EINT_AD_NOT_DRDY0 = EIntADNotReady0Init(NULL);
    EINT_AD_NOT_DRDY1 = EIntADNotReady1Init(NULL);

    /*
     * Initialize Port SYNC_INT for external interrupt from ARM.
     * When level changes, an interrupt will be triggered on rising edge
     * for synchronization signal for transmitting data to ARM.
     */
    EINT_SYNC_INT = EIntSyncInterruptInit(NULL);
}

/*
 * ===================================================================
 *     Method      :  SPIInit (Component SPI)
 */
/*!
 *     @brief
 *          Initialize SPI.
 *          The method is called in the OnChipInit function and will be called
 *          only once.
 *     @param
 *          void
 *     @return
 *          void
 */
/* ===================================================================*/
static void SPIInit(void)
{
#if USING_SPI0
    SPI0 = SPI0Init(NULL);      /* Initialize SPI0 in slave mode, transmitter data to ARM. */
    SPI0Enable();
//    SPI0EnableRxDMA();
//    SPI0EnableTxDMA();
#endif

#if USING_SPI1
    SPI1 = SPI1Init(NULL);      /* Initialize SPI1 in master mode, read ADC data. */
    SPI1Enable();
//    SPI1EnableRxDMA();
//    SPI1EnableTxDMA();
#endif
}

/*
 * ===================================================================
 *     Method      :  DMAInit (Component DMA)
 */
/*!
 *     @brief
 *         	Initialize DMA controller. Including SPI transmission and reception DMA method.
 *         	The method is called in the OnChipInit function and will be called
 *         	only once.
 *     @param
 *          void
 *     @return
 *          void
 */
/* ===================================================================*/
static void DMAInit(void)
{
#if USING_DMA
    DMA_CTRL = DMAControllerInit(NULL);
    DMAControllerEnable();
#endif

#if USING_SPI0_DMA
    SPI0_TX_DMA = SPI0TxDMAInit(NULL);
//    SPI0TxDMADisable();
    SPI0TxDMAAllocateChannel();
    SPI0_RX_DMA = SPI0RxDMAInit(NULL);
//    SPI0RxDMADisable();
    SPI0RxDMAAllocateChannel();
#endif

#if USING_SPI1_DMA
    SPI1_TX_DMA = SPI1TxDMAInit(NULL);
//    SPI1TxDMADisable();
    SPI1TxDMAAllocateChannel();
    SPI1_RX_DMA = SPI1RxDMAInit(NULL);
//    SPI1RxDMADisable();
    SPI1RxDMAAllocateChannel();
#endif
}

/*
 * ===================================================================
 *     Method      :  UARTInit (Component UART)
 */
/*!
 *     @brief
 *          Initialize UART.
 *          The method is called in the OnChipInit function and will be called
 *          only once.
 *     @param
 *          void
 *     @return
 *          void
 */
/* ===================================================================*/
static void UARTInit(void)
{
#if USING_UART1
    UART1 = UART1Init(NULL);    /* Initialize UART1. */
#endif

#if USING_UART2
    UART2 = UART2Init(NULL);     /* Initialize UART2 for printing debug message. */
#endif
}

    /* END Init. */

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
