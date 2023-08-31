/***********************************************************
    
		NAME: USART_program.c
		Create: 22/8/2023     
		Author: Mazen Ibrahim
		Verison: _V1_
	
***********************************************************/


/********************* Include Library *******************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*********************************************************/


/********************* Include MCAL **********************/
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "USART_private.h"
#include "USART_config.h"
#include "USART_interface.h"
/*********************************************************/


//Define Pointer to Function to Notify Fucntion of USART_TX
static void(*Notify_TX)(void) = 0;


//Define Pointer to Function to Notify Fucntion of USART_RX
static void(*Notify_RX)(void) = 0;

//Define Pointer to Variable to Hold Data Recieved by USART
static u8 *Data_1_RX = 0;
static u8 *Data_2_RX = 0;
static u8 *Data_6_RX = 0;


//Define State of USART
static u8 USART_1_STATE = IDLE;
static u8 USART_2_STATE = IDLE;
static u8 USART_6_STATE = IDLE;


USART_STATUS usart_init(USART_NAME usart)
{
	USART_STATUS Status = USART_OK;
	
	switch(usart)
	{
		
		case USART_1: 
			     //Enable GPIO Perhipheral
		       MRCC_vEnableClock(AHB_Bus_1, 0);
			     //Enable Clock For USART_1
		       MRCC_vEnableClock(APB_Bus_2, 4);
		       //Enable Pins Needed for USART
		       MGPIO_vSetPinMode(PORTA,PIN_9,ALT_F);  //TX
		       MGPIO_vSetPinMode(PORTA,PIN_10,ALT_F); //RX
		       MGPIO_vSetPinOutputType(PORTA,PIN_9,PUSH_PULL);
		       MGPIO_vSetPinInputType(PORTA,PIN_10,NO_PULL); 

		break;
		
		case USART_2: 
			     //Enable GPIO Perhipheral
		       MRCC_vEnableClock(AHB_Bus_1, 0);
			     //Enable Clock For USART_2
		       MRCC_vEnableClock(APB_Bus_1, 17);
		       //Enable Pins Needed for USART
		       MGPIO_vSetPinMode(PORTA,PIN_2,ALT_F);  //TX
		       MGPIO_vSetPinMode(PORTA,PIN_3,ALT_F); //RX
		       MGPIO_vSetPinOutputType(PORTA,PIN_2,PUSH_PULL);
		       MGPIO_vSetPinInputType(PORTA,PIN_3,NO_PULL); 

		       
		break;
		
		
		case USART_6: 
			     //Enable GPIO Perhipheral
		       MRCC_vEnableClock(AHB_Bus_1, 2);
			     //Enable Clock For USART_6
		       MRCC_vEnableClock(APB_Bus_2, 5);
		       //Enable Pins Needed for USART
		       MGPIO_vSetPinMode(PORTC,PIN_6,ALT_F);  //TX
		       MGPIO_vSetPinMode(PORTC,PIN_7,ALT_F); //RX
		       MGPIO_vSetPinOutputType(PORTC,PIN_6,PUSH_PULL);
		       MGPIO_vSetPinInputType(PORTC,PIN_7,NO_PULL); 

		break;
		
		default: Status = USART_NOK;
		
	}
	
	return Status;
}


USART_STATUS usart_set_mode( USART_NAME usart, USART_MODES mode )
{

	USART_STATUS  Status = USART_OK;
	
	switch( usart )
	{
		
	  case USART_1 :
	  
			switch(mode)
			{
				
			  case USART_RX :   MUSART_1->CR1 |= (u32)(1<<2);     break;
			  
			  case USART_TX:    MUSART_1->CR1 |= (u32)(1<<3);     break;
			  
			  case USART_RX_TX: MUSART_1->CR1 |= (u32)(3<<2);     break;
			  
			  case USART_MASK:  MUSART_1->CR1 &= (u32)(~(3<<2));  break;
			 
			  default : Status = USART_NOK;
			}
			
      break;   	  
		
	  case USART_2 :
	  
	  		switch(mode)
			{
				
			  case USART_RX :   MUSART_2->CR1 |= (u32)(1<<2);     break;
			  
			  case USART_TX:    MUSART_2->CR1 |= (u32)(1<<3);     break;
			  
			  case USART_RX_TX: MUSART_2->CR1 |= (u32)(3<<2);     break;
			  
			  case USART_MASK:  MUSART_2->CR1 &= (u32)(~(3<<2));  break;
			 
			  default : Status = USART_NOK;
			}
	  
	  break;

      case USART_6 :
	  
	   		switch(mode)
			{
				
				
			  case USART_RX :   MUSART_6->CR1 |= (u32)(1<<2);     break;
			  
			  case USART_TX:    MUSART_6->CR1 |= (u32)(1<<3);     break;
			  
			  case USART_RX_TX: MUSART_6->CR1 |= (u32)(3<<2);     break;
			  
			  case USART_MASK:  MUSART_6->CR1 &= (u32)(~(3<<2));  break;
			 
			  default : Status = USART_NOK;
			}

      break;
	  

      default:  Status = USART_NOK;	  
		
	}
	
	
	return Status;
}


USART_STATUS usart_set_baudrate( USART_NAME usart, u32 baudRate)
{
	USART_STATUS Status = USART_OK;
	u32 Decimal_1;
	f64 Decimal_2;
	u32 Div  = 36000000;
	f64 Frac = 36000000.00; 
	
	
	
	switch( usart )
	{
		case USART_1:  
		    Div  = 72000000;	
		    Frac = 72000000.00;
		    Div  = Div / ( baudRate * 16);
		    Frac = 16*((Frac /(baudRate*16))-Div);
        Decimal_1 = (u32)Frac;
        Decimal_2 = (f64)(100*(Frac-Decimal_1));	
				if(Decimal_2 > 50)
					{
						Decimal_1++;
						if(Decimal_1 == 16)
						{ 
							Decimal_1 = 0;
							Div++;
						}
					}
        MUSART_1->BRP  = (Div<<4);
        MUSART_1->BRP += Decimal_1; 					
		
		break;
					
		case USART_2: 
				Div  = 36000000;	
		    Frac = 36000000.00;
		    Div  = Div / ( baudRate * 16);
		    Frac = 16*((Frac /(baudRate*16))-Div);
        Decimal_1 = (u32)Frac;
        Decimal_2 = (f64)(100*(Frac-Decimal_1));	
				if(Decimal_2 > 50)
					{
						Decimal_1++;
						if(Decimal_1 == 16)
						{ 
							Decimal_1 = 0;
							Div++;
						}
					}
        MUSART_2->BRP  = (Div<<4);
        MUSART_2->BRP += Decimal_1; 					
			
		break;
					
		case USART_6:
				Div  = 36000000;	
		    Frac = 36000000.00;
		    Div  = Div / ( baudRate * 16);
		    Frac = 16*((Frac /(baudRate*16))-Div);
        Decimal_1 = (u32)Frac;
        Decimal_2 = (f64)(100*(Frac-Decimal_1));	
				if(Decimal_2 > 50)
					{
						Decimal_1++;
						if(Decimal_1 == 16)
						{ 
							Decimal_1 = 0;
							Div++;
						}
					}
        MUSART_6->BRP  = (Div<<4);
        MUSART_6->BRP += Decimal_1; 					
			
		break;
					
		default: Status = USART_NOK;
		
	}
	
	return Status;
	
}

USART_STATUS usart_set_databits( USART_NAME usart, DATA_TYPES bits )
{
	
	USART_STATUS Status = USART_OK;
  
	
	switch(usart)
	{
		case USART_1: MUSART_1->CR1 |= bits <<12; break;

		
    case USART_2: MUSART_2->CR1 |= bits <<12;  break;


    case USART_6: MUSART_6->CR1 |= bits <<12; break;		
		
		
		default: Status = USART_NOK;
	}
	
	

	return Status;
}


USART_STATUS usart_set_stopbits( USART_NAME usart,  STOP_TYPES stopbits )
{
	USART_STATUS Status = USART_OK;
	
	
	switch(usart)
	{
		case USART_1: MUSART_1->CR2 |= stopbits <<12;  break;
		case USART_2: MUSART_2->CR2 |= stopbits <<12;  break;
		case USART_6: MUSART_6->CR2 |= stopbits <<12;  break;
		default: Status = USART_NOK;     
	}
	
	return Status;
}


USART_STATUS usart_set_parity( USART_NAME usart, PARTIY_TYPES parity  )
{
	USART_STATUS Status = USART_OK;
	

	switch(usart)
	{
		case USART_1:   
		    
       switch( parity )
			 {
				 case USART_PARITY_NONE: MUSART_1->CR1 &= ~(1<<10);  break;
				 case USART_PARITY_EVEN: MUSART_1->CR1 &= ~(1<<9);   break;
				 case USART_PARITY_ODD:  MUSART_1->CR1 |=  (1<<9);   break;
				 default: Status = USART_NOK;
			 }				 
		
		break;
		
		
		case USART_2:   
			  		    
       switch( parity )
			 {
				 case USART_PARITY_NONE: MUSART_2->CR1 &= ~(1<<10);  break;
				 case USART_PARITY_EVEN: MUSART_2->CR1 &= ~(1<<9);   break;
				 case USART_PARITY_ODD:  MUSART_2->CR1 |=  (1<<9);   break;
				 default: Status = USART_NOK;
			 }
		
		break;
		
		
		case USART_6:   
					    
       switch( parity )
			 {
				 case USART_PARITY_NONE: MUSART_6->CR1 &= ~(1<<10);  break;
				 case USART_PARITY_EVEN: MUSART_6->CR1 &= ~(1<<9);   break;
				 case USART_PARITY_ODD:  MUSART_6->CR1 |=  (1<<9);   break;
				 default: Status = USART_NOK;
			 }
		
		break;
		
		default: Status = USART_NOK; 
		
	}
	
	return Status;
	
}

USART_STATUS usart_enable( USART_NAME usart )
{
	
	USART_STATUS Status = USART_OK;
	
	switch(usart)
	{
	  case USART_1: MUSART_1->CR1 |= (1<<13); break;

    case USART_2: MUSART_2->CR2 |= (1<<13); break;

    case USART_6: MUSART_6->CR1 |= (1<<13); break;

    default: Status = USART_NOK;		
	}
	
	return Status;
	
}

USART_STATUS usart_disable( USART_NAME usart )
{
	
	
	USART_STATUS Status = USART_OK;
	
	switch(usart)
	{
	  case USART_1: MUSART_1->CR1 &= ~(1<<13); break;

    case USART_2: MUSART_2->CR2 &= ~(1<<13); break;

    case USART_6: MUSART_6->CR1 &= ~(1<<13); break;

    default: Status = USART_NOK;
		
	}
	
	return Status;
	
}



USART_STATUS usart_enable_rx_interrupt(USART_NAME usart)
{
	USART_STATUS Status = USART_OK;
	
	switch(usart)
	{
	  case USART_1: MUSART_1->CR1 |= 1<<5;  break;
    case USART_2:	MUSART_2->CR1 |= 1<<5;  break;		
		case USART_6: MUSART_6->CR1 |= 1<<5;  break;
		default: Status = USART_NOK;
	}
	
	return Status;
	
}

USART_STATUS usart_disable_rx_interrupt(USART_NAME usart)
{
	USART_STATUS Status = USART_OK;
	
	switch(usart)
	{
	  case USART_1: MUSART_1->CR1 &= ~(1<<5);  break;
    case USART_2:	MUSART_2->CR1 &= ~(1<<5);  break;		
		case USART_6: MUSART_6->CR1 &= ~(1<<5);  break;
		default: Status = USART_NOK;
	}
	
	return Status;
	
}


USART_STATUS usart_enable_tx_interrupt(USART_NAME usart)
{
		USART_STATUS Status = USART_OK;
	
		switch(usart)
		{
			case USART_1: MUSART_1->CR1 |= (1<<7);  break;
			case USART_2:	MUSART_2->CR1 |= (1<<7);  break;		
			case USART_6: MUSART_6->CR1 |= (1<<7);  break;
			default: Status = USART_NOK;
		}
		
		return Status;
	
}


USART_STATUS usart_disable_tx_interrupt(USART_NAME usart)
{
		USART_STATUS Status = USART_OK;
	
		switch(usart)
		{
			case USART_1: MUSART_1->CR1 &= ~(1<<7);  break;
			case USART_2:	MUSART_2->CR1 &= ~(1<<7);  break;		
			case USART_6: MUSART_6->CR1 &= ~(1<<7);  break;
			default: Status = USART_NOK;
		}
		
		return Status;
	
}




USART_STATUS usart_send_Sync(USART_NAME usart, u8 data)
{
		USART_STATUS Status = USART_OK;
	
		switch(usart)
		{
			case USART_1: 
					while( GET_BIT(MUSART_1->SR , 6) == 0 );
					MUSART_1->DR = data;
			break;
			
			case USART_2: 
					while( GET_BIT(MUSART_2->SR , 6) == 0 );
					MUSART_1->DR = data;
			break;
			
			case USART_6: 
					while( GET_BIT(MUSART_6->SR , 6) == 0 );
					MUSART_1->DR = data;
			break;
			
			default: Status = USART_NOK;
		}
		
		return Status;
	
}


USART_STATUS usart_recv_Sync(USART_NAME usart, u8*usart_data)
{
	USART_STATUS Status = USART_OK;
		switch(usart)
		{
			case USART_1: 
					while( GET_BIT(MUSART_1->SR , 5) == 0 );
					*usart_data = (u8) MUSART_1->DR ;
	
			break;
			
			case USART_2: 
					while( GET_BIT(MUSART_2->SR , 5) == 0 );
					*usart_data = (u8) MUSART_2->DR ;
			break;
			
			case USART_6: 
					while( GET_BIT(MUSART_6->SR , 5) == 0 );
					*usart_data = (u8) MUSART_6->DR ;
			break;
			
			default: Status = USART_NOK;
		}
	
	return Status; 
		
}

USART_STATUS usart_send_Async(USART_NAME usart , u8 data , void(*Notify)(void))
{
	USART_STATUS Status = USART_OK;
	
	if( Notify == NULL)
	{
		Status = USART_NULLPOINTER ;
		return Status;
	}
	
	else
	{ 
		
		switch(usart)
		{
			case USART_1: 
        if( USART_1_STATE == IDLE)
				{
					 USART_1_STATE = Busy_TX;
					 MUSART_1->DR = data;
					 Notify_TX = Notify;	
					 usart_enable_tx_interrupt(USART_1);
				}
			
			break;
			
			
			case USART_2:
				
        if( USART_2_STATE == IDLE)
				{
					 USART_2_STATE = Busy_TX;
					 MUSART_2->DR = data;
					 Notify_TX = Notify;	
					 usart_enable_tx_interrupt(USART_2);
				}
			
			break;
			
			
			
			case USART_6:
				
        if( USART_6_STATE == IDLE)
				{
					 USART_6_STATE = Busy_TX;
					 MUSART_6->DR = data;
					 Notify_TX = Notify;	
					 usart_enable_tx_interrupt(USART_6);
				}
				
			break;
						
			default : Status = USART_NOK;
			
		}
		
	}
	
	
	return Status;
}


USART_STATUS usart_recv_Async(USART_NAME usart , u8* data , void(*Notify)(void))
 {
	
		USART_STATUS Status = USART_OK;
	
	if( Notify == NULL)
	{
		Status = USART_NULLPOINTER ;
		return Status;
	}
	
	else
	{
		switch(usart)
		{
			case USART_1: 
				if(USART_1_STATE == IDLE)
				{ 
					 USART_1_STATE = Busy_RX;
					 Data_1_RX = data; 
					 Notify_RX = Notify;
					 usart_disable_rx_interrupt(USART_1);	
				}
		
			break;
			
			
			case USART_2:
				
				if(USART_2_STATE == IDLE)
				{ 
					 USART_2_STATE = Busy_RX;
					 Data_2_RX = data;  
					 Notify_RX = Notify;
					 usart_disable_rx_interrupt(USART_1);	
				}
				
			break;
			
			
			
			case USART_6:
				
				if(USART_6_STATE == IDLE)
				{ 
					 USART_6_STATE = Busy_RX;
					 Data_6_RX = data;  
					 Notify_RX = Notify;
					 usart_disable_rx_interrupt(USART_1);	
				}
				
			break;
			
			
			default : Status = USART_NOK;
			
		}
		
	}
	
	
	return Status;
	
	
}






//Define ISR of USART_1
void USART1_IRQHandler(void)
{
	if( USART_1_STATE == Busy_TX)
	{
		if( Notify_TX != NULL )
		{
       Notify_TX();
			 USART_1_STATE = IDLE;
		}			
		
	}
	
	else if ( USART_1_STATE == Busy_RX)
	{
	  if( Notify_RX != NULL)
		{ 
			*Data_1_RX = (u8)MUSART_1->DR; 
			Notify_RX();
			USART_1_STATE = IDLE;

		}			
		
	}
	
}


//Define ISR of USART_2
void USART2_IRQHandler(void)
{
	
	if( USART_2_STATE == Busy_TX)
	{
		if( Notify_TX != NULL )
		{
       Notify_TX();
			 USART_2_STATE = IDLE;
		}			
		
	}
	
	else if ( USART_2_STATE == Busy_RX)
	{
	  if( Notify_RX != NULL)
		{ 
			*Data_2_RX = (u8)MUSART_2->DR; 
			Notify_RX();
			USART_2_STATE = IDLE;

		}			
		
	}
	
}


//Define ISR of USART_6
void USART6_IRQHandler(void)
{
	
	if( USART_6_STATE == Busy_TX)
	{
		if( Notify_TX != NULL )
		{
			
       Notify_TX();
			 USART_6_STATE = IDLE;
		}			
		
	}
	
	else if ( USART_6_STATE == Busy_RX)
	{
	  if( Notify_RX != NULL)
		{
			
			*Data_6_RX = (u8)MUSART_6->DR; 
			Notify_RX();
			USART_6_STATE = IDLE;

		}			
		
	}
	
}

