/***********************************************************
    
		NAME: USART_interface.h
		Create: 22/8/2023     
		Author: Mazen Ibrahim
		Verison: _V1_
	
***********************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#include "STD_TYPES.h"

//Define Enum to Hold USART_Errors
typedef enum
{
	USART_NULLPOINTER,
  USART_OK,	
  USART_NOK 
   
}USART_STATUS;


//Define Enum To Hold USART Names
typedef enum
{
  USART_1,
  USART_2,
  USART_6  
	
}USART_NAME;


//Define Enum To Hold Parity Types
typedef enum
{
  USART_PARITY_EVEN,
  USART_PARITY_ODD,
  USART_PARITY_NONE
	
}PARTIY_TYPES;

//Define Enum To Hold Operation Mode
typedef enum
{
  USART_RX,	
  USART_TX,
  USART_RX_TX,
  USART_MASK  
	
}USART_MODES;


//Define Enum to Hold Stop Bits Types
typedef enum
{
	USART_STOPBITS_1,
  USART_STOPBITS_0_5,
  USART_STOPBITS_2,
  USART_STOPBITS_1_5  
	
}STOP_TYPES;


//Define Enum to Hold Data Bits Types
typedef enum
{
	USART_DATA_8,
	USART_DATA_9
	
}DATA_TYPES;


/*
Description: Function Used to Set Clock For USART.
Parameters: Name of USART Used 
Return:
   1- USART_OK 
   2- USART_NOK
   3- USART_NULLPOINTER   
*/
USART_STATUS usart_init(USART_NAME usart);


/*
Description: Function Used to Set Mode of USART.
Parameters: Name of USART Used , Mode Need to Operate USART
Return:
   1- USART_OK 
   2- USART_NOK
   3- USART_NULLPOINTER   
*/
USART_STATUS usart_set_mode( USART_NAME usart, USART_MODES mode );


/*
Description: Function Used to Set BaudRate of USART.
Parameters: Name of USART Used , BaudRate Needed
Return:
   1- USART_OK 
   2- USART_NOK
   3- USART_NULLPOINTER 
   
*/
USART_STATUS usart_set_baudrate( USART_NAME usart, u32 baudRate);


/*
Description: Function Used to Set Data Bits needed to be send 
Parameter: Name of USART Used , Number of Bits 
Return:
   1- USART_OK 
   2- USART_NOK
   3- USART_NULLPOINTER 
*/
USART_STATUS usart_set_databits( USART_NAME usart, DATA_TYPES bits );


/*
Description: Function Used to Set Stop Bits needed to be send 
Parameter: Name of USART Used , Number of Bits 
Return:
   1- USART_OK 
   2- USART_NOK
   3- USART_NULLPOINTER 
*/
USART_STATUS usart_set_stopbits( USART_NAME usart, STOP_TYPES stopbits );


/*
Description: Function Used to Set Parity Type needed to be send 
Parameter: Name of USART Used , Type of Parity 
Return:
   1- USART_OK 
   2- USART_NOK
   3- USART_NULLPOINTER 
*/
USART_STATUS usart_set_parity( USART_NAME usart, PARTIY_TYPES parity  );



/*
Description: Function Used to Enable USART. 
Parameter: Name of USART Used  
Return:
   1- USART_OK 
   2- USART_NOK
   3- USART_NULLPOINTER 
*/
USART_STATUS usart_enable( USART_NAME usart );




/*
Description: Function Used to Disable USART. 
Parameter: Name of USART Used  
Return:
   1- USART_OK 
   2- USART_NOK
   3- USART_NULLPOINTER 
*/
USART_STATUS usart_disable( USART_NAME usart );


/*
Description: Function Used to Enable Recieve Interrupt Enable For USART. 
Parameter: Name of USART Used  
Return:
   1- USART_OK 
   2- USART_NOK
   3- USART_NULLPOINTER 
*/
USART_STATUS usart_enable_rx_interrupt(USART_NAME usart);


/*
Description: Function Used to Disable Recieve Interrupt Enable For USART. 
Parameter: Name of USART Used  
Return:
   1- USART_OK 
   2- USART_NOK
   3- USART_NULLPOINTER 
*/
USART_STATUS usart_disable_rx_interrupt(USART_NAME usart);


/*
Description: Function Used to Enable Transfer Interrupt Enable For USART. 
Parameter: Name of USART Used  
Return:
   1- USART_OK 
   2- USART_NOK
   3- USART_NULLPOINTER 
*/
USART_STATUS usart_enable_tx_interrupt(USART_NAME usart);


/*
Description: Function Used to Disable Transfer Interrupt Enable For USART. 
Parameter: Name of USART Used  
Return:
   1- USART_OK 
   2- USART_NOK
   3- USART_NULLPOINTER 
*/
USART_STATUS usart_disable_tx_interrupt(USART_NAME usart);



/*
Description: Function Used to Send Byte to USART. 
Parameter: Name of USART Used , Data to be Send 
Return:
   1- USART_OK 
   2- USART_NOK
   3- USART_NULLPOINTER 
*/
USART_STATUS usart_send_Sync(USART_NAME usart, u8 data);



/*
Description: Function Used to Recieve Byte From USART. 
Parameter: Name of USART Used  , Pointer to Variable to Hold Data Recieved
Return:
   1- USART_OK 
   2- USART_NOK
   3- USART_NULLPOINTER 
     
*/
USART_STATUS usart_recv_Sync(USART_NAME usart, u8*usart_data);




/*
Description: Function Used to Send Byte to USART depend on Interrupt. 
Parameter: Name of USART Used , Data to be send , Pointer to callback function  
Return:
   1- USART_OK 
   2- USART_NOK
   3- USART_NULLPOINTER 
*/
USART_STATUS usart_send_Async(USART_NAME usart , u8 data , void(*Notify)(void));



/*
Description: Function Used to Recieve Byte from USART depend on Interrupt. 
Parameter: Name of USART Used  
Return:
   1- USART_OK 
   2- USART_NOK
   3- USART_NULLPOINTER 
*/
USART_STATUS usart_recv_Async(USART_NAME usart , u8* data , void(*Notify)(void));





#endif