/***********************************************************
    
		NAME: External_interface.h
		Create: 14/8/2023     
		Author: Mazen Ibrahim
		Verison: _V1_
	
***********************************************************/

#ifndef EXTERNAL_INTERFACE_H_
#define EXTERNAL_INTERFACE_H_




//Define Enum for Type of Edge Selection
typedef enum 
{
	RISING_EDGE      = 0,
	FALLING_EDGE     = 1,
	RISING_FALLING   = 2
}EDGE_TYPE;

//Define Enum for External Return Status;
typedef enum 
{
	EXTERNAL_NULLPOINTER = 0,
	EXTERNAL_OK          = 1,
	EXTERNAL_NOK         = 2

}EXTERNAL_STATUS;

typedef enum 
{
  PA = 0b0000,
  PB = 0b0001,
  PC = 0b0010,
  PD = 0b0011,
  PE = 0b0100,
  PH = 0b0111
	
}PIN_NAME;


/*
Description: Function Used to Configure Externel Interrupt Pin Based on Interrupt line Number
Parameters:  Number of Interrupt line(0..15) , Pin Name (PA,PB,PC,PD,PE,PH) 
Return: 
  1- EXTERNAL_OK
  2- EXTERNAL_NOK
*/
EXTERNAL_STATUS  Select_InterruptPin(u8 Copy_u8InterruptNumber , PIN_NAME  Copy_PinName );


/*
Description: Function Used to Enable Externel Interrupt Based on Interrupt line Number
Parameters:  Number of Interrupt line(0..22)
Return: 
  1- EXTERNAL_OK
  2- EXTERNAL_NOK
*/
EXTERNAL_STATUS ExternalInterrupt_Enable(u8 Copy_u8InterruptNumber);


/*
Description: Function Used to Disable Externel Interrupt Based on Interrupt line Number
Parameters:  Number of Interrupt line(0..22)
Return: 
  1- EXTERNAL_OK
  2- EXTERNAL_NOK
*/
EXTERNAL_STATUS ExternalInterrupt_Disable(u8 Copy_u8InterruptNumber);




/*
Description: Function Used to Enable Event Interrupt Based on Interrupt line Number
Parameters:  Number of Interrupt line(0..22)
Return:
  1- EXTERNAL_OK
  2- EXTERNAL_NOK
*/
EXTERNAL_STATUS EventInterrupt_Enable(u8 Copy_u8InterruptNumber);


/*
Description: Function Used to Disable Event Interrupt Based on Interrupt line Number
Parameters:  Number of Interrupt line(0..22)
Return: 
  1- EXTERNAL_OK
  2- EXTERNAL_NOK
*/
EXTERNAL_STATUS EventInterrupt_Disable(u8 Copy_u8InterruptNumber);


/*
Description: Function Used to Select Externel Interrupt and Event Interruput Edge 
Parameters: Number of Interrupt line(0..22) , Type of Edge (RISING_EDGE, FALLING_EDGE, RISSING_FALLING)  
Return: 
  1- EXTERNAL_OK
  2- EXTERNAL_NOK
*/
EXTERNAL_STATUS Interrupt_SelectEdge(u8 Copy_u8InterruptNumber , EDGE_TYPE Copy_u8EdgeType);


/*
Description: Function Used to Trigger Externel Interrupt and Event Interruput Based on Software 
Parameters:  Number of Interrupt line(0..22)  
Return: 
  1- EXTERNAL_OK
  2- EXTERNAL_NOK
*/
EXTERNAL_STATUS Interrupt_SoftwareTrigger(u8 Copy_u8InterruptNumber);




/*
Description: Function Used to Set CallBack Function for External Interrupt Based on Interrupt line Number
Parameters: Pointer to CallBack Function
Return
 1- EXTERNAL_OK
 2- EXTERNAL_NOK
 3- EXTERNAL_NULLPOINTER
*/
EXTERNAL_STATUS EXTI_SetCallBack(u8 Copy_u8InterruptNumber , void(*Copy_CallBack)(void));




#endif