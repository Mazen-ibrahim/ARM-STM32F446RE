/***********************************************************
    
		NAME: GPIO_program.c
		Create: 17/6/2023     
		Author: Mazen Ibrahim
		Verison: _V1_
	
***********************************************************/



/*****************INCLUDE LIBRARYS************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*********************************************************/


/***************** INCLUDE MCAL  *************************/
#include "GPIO_private.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"
/*********************************************************/


/***************** INCLUDE HALS  ************************/




/*********************************************************/



void MGPIO_vSetPinMode( PORT_NAME copy_ePortName , PIN_NUM copy_ePinNum , PIN_MODE copy_eMode )
{   
    if(copy_ePinNum < 16 )
	{

		switch(copy_ePortName)
		{
			case PORTA:  GPIOA->MODER |= (u32) ((copy_eMode)<<(2U*copy_ePinNum));  break;
			
			
			case PORTB:  GPIOB->MODER |= (u32) ((copy_eMode)<<(2U*copy_ePinNum));  break;
			
			
			case PORTC:  GPIOC->MODER |= (u32) ((copy_eMode)<<(2U*copy_ePinNum));  break;
			
			
			case PORTD:  GPIOD->MODER |= (u32) ((copy_eMode)<<(2U*copy_ePinNum));  break;
			
			
			case PORTE:  GPIOE->MODER |= (u32) ((copy_eMode)<<(2U*copy_ePinNum));  break;
			
			
			case PORTH:  GPIOH->MODER |= (u32) ((copy_eMode)<<(2U*copy_ePinNum));  break;
			
			
			default : /******Error*******/ break;
			
		}
		
	}	
	
	else
	{
		
		/***********Warning************/
		
	}
	
	
	
}

void MGPIO_vSetPinOutputType( PORT_NAME copy_ePortName , PIN_NUM copy_ePinNum , OUTPUT_TYPE copy_eType )
{
	if(copy_ePinNum < 16)
	{
		switch(copy_ePortName)
		{
			
			case PORTA:  GPIOA->OTYPER |= (u32) ((copy_eType)<<(copy_ePinNum));  break;


			case PORTB:  GPIOB->OTYPER |= (u32) ((copy_eType)<<(copy_ePinNum));  break;


			case PORTC:  GPIOC->OTYPER |= (u32) ((copy_eType)<<(copy_ePinNum));  break;


			case PORTD:  GPIOD->OTYPER |= (u32) ((copy_eType)<<(copy_ePinNum));  break;


			case PORTE:  GPIOE->OTYPER |= (u32) ((copy_eType)<<(copy_ePinNum));  break;


			case PORTH:  GPIOH->OTYPER |= (u32) ((copy_eType)<<(copy_ePinNum));  break;
			
			
			default : /******Error*******/ break;
			
		}
		
	}
	
	else
	{
		/***********Warning***********/
		
	}
	
}


void MGPIO_vSetPinSpeedLevel( PORT_NAME copy_ePortName , PIN_NUM copy_ePinNum , SPEED_LEVEL copy_eLevel )
{
	if(copy_ePinNum < 16 )
	{
		switch(copy_ePortName)
		{
			case PORTA:  GPIOA->OSPEEDER |= (u32) ((copy_eLevel)<<(2U*copy_ePinNum));  break;
			
			
			case PORTB:  GPIOB->OSPEEDER |= (u32) ((copy_eLevel)<<(2U*copy_ePinNum));  break;
			
			
			case PORTC:  GPIOC->OSPEEDER |= (u32) ((copy_eLevel)<<(2U*copy_ePinNum));  break;
			
			
			case PORTD:  GPIOD->OSPEEDER |= (u32) ((copy_eLevel)<<(2U*copy_ePinNum));  break;
			
			
			case PORTE:  GPIOE->OSPEEDER |= (u32) ((copy_eLevel)<<(2U*copy_ePinNum));  break;
			
			
			case PORTH:  GPIOH->OSPEEDER |= (u32) ((copy_eLevel)<<(2U*copy_ePinNum));  break;
			
			
			default : /******Error*******/ break;
			
		}
	}	
	
	else
	{
		
		/***********Warning************/
		
	}
	
	
	
}


void MGPIO_vSetPinInputType( PORT_NAME copy_ePortName , PIN_NUM copy_ePinNum , INPUT_TYPE copy_eType )
{
	
	if(copy_ePinNum < 16 )
	{
		switch(copy_ePortName)
		{
			case PORTA:  GPIOA->PUPDR |= (u32) ((copy_eType)<<(2U*copy_ePinNum));  break;
			
			
			case PORTB:  GPIOB->PUPDR |= (u32) ((copy_eType)<<(2U*copy_ePinNum));  break;
			
			
			case PORTC:  GPIOC->PUPDR |= (u32) ((copy_eType)<<(2U*copy_ePinNum));  break;
			
			
			case PORTD:  GPIOD->PUPDR |= (u32) ((copy_eType)<<(2U*copy_ePinNum));  break;
			
			
			case PORTE:  GPIOE->PUPDR |= (u32) ((copy_eType)<<(2U*copy_ePinNum));  break;
			
			
			case PORTH:  GPIOH->PUPDR |= (u32) ((copy_eType)<<(2U*copy_ePinNum));  break;
			
			
			default : /******Error*******/ break;
			
		}
		
		
	}	
	
	else
	{
		
		/***********Warning************/
		
	}
	
	
}


u8 MGPIO_vGetPinState( PORT_NAME copy_ePortName , PIN_NUM copy_ePinNum )
{   
    PIN_STATE state = LOW ;
	
	if(copy_ePinNum < 16)
	{
		switch(copy_ePortName)
		{
			case PORTA: state =  GET_BIT(GPIOA->IDR,copy_ePinNum); break;
            case PORTB: state =  GET_BIT(GPIOB->IDR,copy_ePinNum); break;
            case PORTC: state =  GET_BIT(GPIOC->IDR,copy_ePinNum); break;
            case PORTD: state =  GET_BIT(GPIOD->IDR,copy_ePinNum); break;
            case PORTE: state =  GET_BIT(GPIOE->IDR,copy_ePinNum); break;
            case PORTH: state =  GET_BIT(GPIOH->IDR,copy_ePinNum); break;
			default : /*****ERROR*****/ break;
		}
	}
	
	else
	{
		/********WARNING***********/
		
	}
	
	return state;
	
	
}


void MGPIO_vSetPinOutputState( PORT_NAME copy_ePortName , PIN_NUM copy_ePinNum , PIN_STATE state )
{
	if(copy_ePinNum < 16)
	{  
        if( state == HIGH)
		{
			switch(copy_ePortName)
			{
				case PORTA:  SET_BIT(GPIOA->ODR,copy_ePinNum); break;	
				case PORTB:  SET_BIT(GPIOB->ODR,copy_ePinNum); break;
				case PORTC:  SET_BIT(GPIOC->ODR,copy_ePinNum); break;
				case PORTD:  SET_BIT(GPIOD->ODR,copy_ePinNum); break;
				case PORTE:  SET_BIT(GPIOE->ODR,copy_ePinNum); break;
				case PORTH:  SET_BIT(GPIOH->ODR,copy_ePinNum); break;			
				default : /*****ERROR*****/ break;
			}
		}
		
		else if ( state == LOW )
		{
			switch(copy_ePortName)
			{
				case PORTA:  CLR_BIT(GPIOA->ODR,copy_ePinNum); break;	
				case PORTB:  CLR_BIT(GPIOB->ODR,copy_ePinNum); break;
				case PORTC:  CLR_BIT(GPIOC->ODR,copy_ePinNum); break;
				case PORTD:  CLR_BIT(GPIOD->ODR,copy_ePinNum); break;
				case PORTE:  CLR_BIT(GPIOE->ODR,copy_ePinNum); break;
				case PORTH:  CLR_BIT(GPIOH->ODR,copy_ePinNum); break;			
				default : /*****ERROR*****/ break;
			}
		}
		
		else
		{
			/******ERROR*******/
		}

	}
	
	else
	{
		/********WARNING***********/
		
	}
	
}


void MGPIO_vEnablePin( PORT_NAME copy_ePortName , PIN_NUM copy_ePinNum , ENABLE_PIN state )
{
	if(copy_ePinNum < 16)
	{
		
		if(state == SET)
		{
			switch(copy_ePortName)
			{
				case PORTA:  SET_BIT(GPIOA->BSRR,copy_ePinNum); break;	
				case PORTB:  SET_BIT(GPIOB->BSRR,copy_ePinNum); break;
				case PORTC:  SET_BIT(GPIOC->BSRR,copy_ePinNum); break;
				case PORTD:  SET_BIT(GPIOD->BSRR,copy_ePinNum); break;
				case PORTE:  SET_BIT(GPIOE->BSRR,copy_ePinNum); break;
				case PORTH:  SET_BIT(GPIOH->BSRR,copy_ePinNum); break;			
				default : /*****ERROR*****/ break;
			}
			
		}
		
		else if ( state == RESET)
		{
			switch(copy_ePortName)
			{
				case PORTA:  SET_BIT(GPIOA->BSRR,16  + copy_ePinNum); break;	
				case PORTB:  SET_BIT(GPIOB->BSRR,16  + copy_ePinNum); break;
				case PORTC:  SET_BIT(GPIOC->BSRR,16  + copy_ePinNum); break;
				case PORTD:  SET_BIT(GPIOD->BSRR,16  + copy_ePinNum); break;
				case PORTE:  SET_BIT(GPIOE->BSRR,16  + copy_ePinNum); break;
				case PORTH:  SET_BIT(GPIOH->BSRR,16  + copy_ePinNum); break;			
				default : /*****ERROR*****/ break;
			}
			
			
		}
		
		
		else
		{
		   /*************ERROR***********/	
			
		}
		
	}
	
	else
	{
		/************ERROR***********/
		
	}
	
	
	
}

void MGPIO_vPinLock( PORT_NAME copy_ePortName , PIN_NUM copy_ePinNum )
{
	if( copy_ePinNum < 16 )
	{
		switch(copy_ePortName)
		{
			case PORTA:  
			            GPIOA->LCKR |= 0x00010000 | copy_ePinNum  ;
						GPIOA->LCKR |= 0x00000000 | copy_ePinNum  ;
						GPIOA->LCKR |= 0x00010000 | copy_ePinNum  ;
						while(GET_BIT(GPIOA->LCKR,16) != 1 ); 
						break;	
			case PORTB: 
			            GPIOB->LCKR |= 0x00010000 | copy_ePinNum  ;
						GPIOB->LCKR |= 0x00000000 | copy_ePinNum  ;
						GPIOB->LCKR |= 0x00010000 | copy_ePinNum  ;						
						while(GET_BIT(GPIOB->LCKR,16) != 1 ); 
						break;	
			case PORTC:  
			            GPIOC->LCKR |= 0x00010000 | copy_ePinNum  ;
						GPIOC->LCKR |= 0x00000000 | copy_ePinNum  ;
						GPIOC->LCKR |= 0x00010000 | copy_ePinNum  ;					
						while(GET_BIT(GPIOC->LCKR,16) != 1 ); 
						break;
						
			case PORTD:  
			            GPIOD->LCKR |= 0x00010000 | copy_ePinNum  ;
						GPIOD->LCKR |= 0x00000000 | copy_ePinNum  ;
						GPIOD->LCKR |= 0x00010000 | copy_ePinNum  ;				
						while(GET_BIT(GPIOD->LCKR,16) != 1 ); 
						break;	
						
			case PORTE:  
			            GPIOE->LCKR |= 0x00010000 | copy_ePinNum  ;
						GPIOE->LCKR |= 0x00000000 | copy_ePinNum  ;
						GPIOE->LCKR |= 0x00010000 | copy_ePinNum  ; 
						while(GET_BIT(GPIOE->LCKR,16) != 1 ); 
						break;
						
			case PORTH:  
			            GPIOE->LCKR |= 0x00010000 | copy_ePinNum  ;
						GPIOE->LCKR |= 0x00000000 | copy_ePinNum  ;
						GPIOE->LCKR |= 0x00010000 | copy_ePinNum  ;
						while(GET_BIT(GPIOH->LCKR,16) != 1 ); 
						break;				
			default : /*****ERROR*****/ break;
			
			
		}
	}
	
	else
	{
		/************ERROR************/
		
	}
	
	
	
}


void MGPIO_vSetAltPin( PORT_NAME copy_ePortName , PIN_NUM copy_ePinNum , ALTERNATE_MODE mode )
{  
    //Use Alternate Fucntion Low Register
	if(copy_ePinNum < 8)
	{
		switch(copy_ePortName)
		{
		case PORTA: GPIOA->AFRL |= (mode << 4*copy_ePinNum); break;
		case PORTB: GPIOB->AFRL |= (mode << 4*copy_ePinNum); break;
		case PORTC: GPIOC->AFRL |= (mode << 4*copy_ePinNum); break;
		case PORTD: GPIOD->AFRL |= (mode << 4*copy_ePinNum); break;
		case PORTE: GPIOE->AFRL |= (mode << 4*copy_ePinNum); break;
		case PORTH: GPIOH->AFRL |= (mode << 4*copy_ePinNum); break;
		default: /***********ERROR**************/ break;
			
		}
	  	
		
	}
	
	//Use Alternate Fucntion High Register
	else if ( copy_ePinNum < 16)
	{
		switch(copy_ePortName)
		{
		 case PORTA: GPIOA->AFRH |= (mode << 4*(copy_ePinNum - 8)); break;
		 case PORTB: GPIOB->AFRH |= (mode << 4*(copy_ePinNum - 8)); break;
		 case PORTC: GPIOC->AFRH |= (mode << 4*(copy_ePinNum - 8)); break;
		 case PORTD: GPIOD->AFRH |= (mode << 4*(copy_ePinNum - 8)); break;
		 case PORTE: GPIOE->AFRH |= (mode << 4*(copy_ePinNum - 8)); break;
		 case PORTH: GPIOH->AFRH |= (mode << 4*(copy_ePinNum - 8)); break;
		 default: /***********ERROR**************/ break;
			
		}
		
		
	}
	
 	
	else
	{
		
		/****************ERROR****************/
	}
	
}
