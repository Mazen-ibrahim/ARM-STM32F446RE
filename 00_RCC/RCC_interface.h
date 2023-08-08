/***********************************************************
    
		NAME: RCC_interface.h
		Create: 6/6/2023     
		Author: Mazen Ibrahim
		Verison: _V1_
	
***********************************************************/


/*********************************************************
******** Guard of file will call on time in .c ***********
*********************************************************/


#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
 
 
 
/*Define Buses in System*/
typedef enum 
{
	AHB_Bus_1 = 0 ,
	AHB_Bus_2 = 1 ,
	APB_Bus_1 = 2 ,
	APB_Bus_2 = 3
	
}BusName_t;


/*Define Clocks in System*/
typedef enum
{
	RCC_HSE = 0,
	RCC_HSI = 1,
	RCC_PLL = 2,
}ClockSource_t;


/*Define HSE Clock Types*/
typedef enum 
{
	HSE_Crystal = 0,
	HSE_RC = 1,
	
}HSESrc_t;


/*Define PLL Clock Types*/
typedef enum 
{
	HSE_PLL = 0,
	HSI_PLL = 1,
	
}PLLSrc_t;


/***************RCC AHB1 CLK Enable************/
#define _PERIPHERAL_EN_GPIOA         0U
#define _PERIPHERAL_EN_GPIOB         1U
#define _PERIPHERAL_EN_GPIOC         2U
#define _PERIPHERAL_EN_GPIOD         3U
#define _PERIPHERAL_EN_GPIOE         4U
#define _PERIPHERAL_EN_GPIOH         7U
#define _PERIPHERAL_EN_CRC           12U
#define _PERIPHERAL_EN_DMA1          21U
#define _PERIPHERAL_EN_DMA2          22U 
/*********************************************/



/***************RCC AHB2 CLK Enable************/
#define _PERIPHERAL_EN_OTGFS         7U
/*********************************************/



/***************RCC APB1 CLK Enable************/
#define _PERIPHERAL_EN_TIMER2        0U
#define _PERIPHERAL_EN_TIMER3        1U
#define _PERIPHERAL_EN_TIMER4        2U
#define _PERIPHERAL_EN_TIMER5        3U
#define _PERIPHERAL_EN_WWDG          11U
#define _PERIPHERAL_EN_SPI2          14U
#define _PERIPHERAL_EN_SPI3          15U
#define _PERIPHERAL_EN_USART2        17U
#define _PERIPHERAL_EN_I2C1          21U
#define _PERIPHERAL_EN_I2C2          22U
#define _PERIPHERAL_EN_I2C3          23U
#define _PERIPHERAL_EN_PWR           28U
/*********************************************/



/***************RCC APB2 CLK Enable************/
#define _PERIPHERAL_EN_TIMER1        0U
#define _PERIPHERAL_EN_USART1        4U
#define _PERIPHERAL_EN_USART6        5U
#define _PERIPHERAL_EN_ADC1          8U
#define _PERIPHERAL_EN_SDIO          11U
#define _PERIPHERAL_EN_SPI1          12U
#define _PERIPHERAL_EN_SPI4          13U
#define _PERIPHERAL_EN_SYSCFG        14U
#define _PERIPHERAL_EN_TIMER9        16U
#define _PERIPHERAL_EN_TIMER10       17U
#define _PERIPHERAL_EN_TIMER11       18U
/*********************************************/



/*
 Fucntion to Enable Perpherial
  Parameters :  
	1- BusName_t: The Bus Of Perpherial(AHB1,AHB2,APB1,APB2) 
    2- Copy_u8PerNum: Number of Perpherial in Selected Register
*/
void MRCC_vEnableClock( BusName_t BusName , u8 Copy_u8PerNum );


/*
 Fucntion to Disable Perpherial
  Parameters :  
    1- BusName_t: The Bus Of Perpherial(AHB1,AHB2,APB1,APB2) 
    2- Copy_u8PerNum: Number of Perpherial in Selected Register
*/
void MRCC_vDisableClock( BusName_t BusName , u8 Copy_u8PerNum );


/*
 Fucntion to Enable Clock Security
  Parameters : void
*/
void MRCC_vEnableClockSecurity(void);


/*
 Fucntion to Disable Clock Security
  Parameters : void
*/
void MRCC_vDisableClockSecurity(void);


/*
 Fucntion to Intialize the Clock of System 
  Parameters : 
    1- ClockSource_t: Used to set the clock source in system(RCC_HSE ,RCC_HSI ,RCC_PLL)  
	2- HSESrc_t: used to set the type of HSE Clock(HSE_Crystal,HSE_RC)  
	3- PLLSrc_t: used to set the source of PLL(HSE_PLL,HSI_PLL)
*/
void MRCC_vInitClock(ClockSource_t copy_tClkSrc , HSESrc_t copy_tHSESrc, PLLSrc_t copy_tPLLSrc);


/*
 Fucntion to Intialize the Clock of System by PreBuild Method
  Parameters : void 
*/
void MRCC_vInitClockSystem(void);



#endif // RCC_INTERFACE_H_