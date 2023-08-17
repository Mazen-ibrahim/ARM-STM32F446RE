/***********************************************************
    
		NAME: External_program.h
		Create: 14/8/2023     
		Author: Mazen Ibrahim
		Verison: _V1_
	
***********************************************************/



/********************* Include Library *******************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*********************************************************/



/******************** Include MCAL ***********************/
#include "External_private.h"
#include "External_config.h"
#include "External_interface.h"
/*********************************************************/


//Define Static Global Pointers to Functions 
static void(*CallBack_EXTI_0)(void) = 0;
static void(*CallBack_EXTI_1)(void) = 0;
static void(*CallBack_EXTI_2)(void) = 0;
static void(*CallBack_EXTI_3)(void) = 0;
static void(*CallBack_EXTI_4)(void) = 0;
static void(*CallBack_EXTI_5_9)(void) = 0;
static void(*CallBack_EXTI_10_15)(void) = 0;


EXTERNAL_STATUS  Select_InterruptPin(u8 Copy_u8InterruptNumber , PIN_NAME  Copy_PinName )
{
	EXTERNAL_STATUS status = EXTERNAL_OK;
	
	if( Copy_u8InterruptNumber <= 15 )
	{
        if( Copy_u8InterruptNumber <= 3)
		{
			SYSCFG_REG -> EXTICR1 |= Copy_PinName << 4*Copy_u8InterruptNumber;
		}	

        else if (Copy_u8InterruptNumber <= 7)
		{
			SYSCFG_REG -> EXTICR2 |= Copy_PinName << 4*(Copy_u8InterruptNumber - 4);
			
		}	

        else if ( Copy_u8InterruptNumber <= 11)
		{
			SYSCFG_REG -> EXTICR3 |= Copy_PinName << 4*(Copy_u8InterruptNumber - 8);
		}			
		
		else
		{
			SYSCFG_REG -> EXTICR4 |= Copy_PinName << 4*(Copy_u8InterruptNumber - 12);
			
		}
         
	}
	
	else
	{
	  status = EXTERNAL_NOK;	
	  
	}
	
	return status;
	
}



EXTERNAL_STATUS ExternalInterrupt_Enable(u8 Copy_u8InterruptNumber)
{
	EXTERNAL_STATUS status = EXTERNAL_OK;
	
	if( Copy_u8InterruptNumber <= 22)
	{
		EXTERNEL_REG ->IMR |= 1<<Copy_u8InterruptNumber; 
		
	}
	
	else
	{
		
		status = EXTERNAL_NOK;
	}
	
	return status;
	
}


EXTERNAL_STATUS ExternalInterrupt_Disable(u8 Copy_u8InterruptNumber)
{
	
	EXTERNAL_STATUS status = EXTERNAL_OK;
	
	if( Copy_u8InterruptNumber <= 22)
	{
		EXTERNEL_REG ->IMR &= ~(1<<Copy_u8InterruptNumber); 
		
	}
	
	else
	{
		
		status = EXTERNAL_NOK;
	}
	
	return status;
	
	
}


EXTERNAL_STATUS EventInterrupt_Enable(u8 Copy_u8InterruptNumber)
{
	
	EXTERNAL_STATUS status = EXTERNAL_OK;
	
	if( Copy_u8InterruptNumber <= 22)
	{
		EXTERNEL_REG ->EMR |= 1<<Copy_u8InterruptNumber; 
		
	}
	
	else
	{
		
		status = EXTERNAL_NOK;
	}
	
	return status;
	
	
}


EXTERNAL_STATUS EventInterrupt_Disable(u8 Copy_u8InterruptNumber)
{
	
	EXTERNAL_STATUS status = EXTERNAL_OK;
	
	if( Copy_u8InterruptNumber <= 22)
	{
		EXTERNEL_REG ->EMR &= ~(1<<Copy_u8InterruptNumber); 
		
	}
	
	else
	{
		
		status = EXTERNAL_NOK;
	}
	
	return status;
	
	
}


EXTERNAL_STATUS Interrupt_SelectEdge(u8 Copy_u8InterruptNumber , EDGE_TYPE Copy_u8EdgeType)
{
	EXTERNAL_STATUS status = EXTERNAL_OK;
	
	if(Copy_u8InterruptNumber <= 22)
	{
	    switch(Copy_u8EdgeType)
		{
			case RISING_EDGE:
			  
			          EXTERNEL_REG ->RSTR |= 1<<Copy_u8InterruptNumber;
			
			          break;
			
			
			case FALLING_EDGE:
			
			           EXTERNEL_REG ->FTSR |= 1<<Copy_u8InterruptNumber;
			
			          break;
			
			
			
			case RISING_FALLING:
			
			          EXTERNEL_REG ->RSTR |= 1<<Copy_u8InterruptNumber;
			          EXTERNEL_REG ->FTSR |= 1<<Copy_u8InterruptNumber;
					  
			          break;
					  
			default : status = EXTERNAL_NOK;
            		
		}
        	   
	}
	
	else
	{
		status = EXTERNAL_NOK;
	}
	
	
	return status;
	
}


EXTERNAL_STATUS Interrupt_SoftwareTrigger(u8 Copy_u8InterruptNumber)
{
	
	EXTERNAL_STATUS status = EXTERNAL_OK;
	
	if( Copy_u8InterruptNumber <= 22)
	{
		EXTERNEL_REG -> SWIER |= 1<<Copy_u8InterruptNumber;
	}
	
	else
	{
		status = EXTERNAL_NOK;
		
	}
	
	
	return status;
}


EXTERNAL_STATUS EXTI_SetCallBack(u8 Copy_u8InterruptNumber , void(*Copy_CallBack)(void))
{
	 EXTERNAL_STATUS status = EXTERNAL_OK;
	 if(Copy_u8InterruptNumber <= 15)
	 {
		 if(Copy_CallBack == EXTERNAL_NULLPOINTER)
		 {
			 status = EXTERNAL_NULLPOINTER;
			 return status;
		 }			 
		 else
		 {  
			 
			 if( Copy_u8InterruptNumber == 0 )
			 {
				 CallBack_EXTI_1 = Copy_CallBack; 
			 }
			 
			 else if( Copy_u8InterruptNumber == 1 )
			 {
				 CallBack_EXTI_1 = Copy_CallBack; 
			 }

			 else if( Copy_u8InterruptNumber == 2 )
			 {
				 CallBack_EXTI_2 = Copy_CallBack; 
			 }

			 else if( Copy_u8InterruptNumber == 3 )
			 {
				 CallBack_EXTI_3 = Copy_CallBack; 
			 }
			 
			 else if( Copy_u8InterruptNumber == 4 )
			 {
				 CallBack_EXTI_4 = Copy_CallBack; 
			 }
			 
			 else if( Copy_u8InterruptNumber <=9 )
			 {
				 CallBack_EXTI_5_9 = Copy_CallBack; 
			 }
			 
			 else if ( Copy_u8InterruptNumber <=15)
			 {
				 CallBack_EXTI_10_15 = Copy_CallBack;
			 }
			 
		 }
	 }	 
	 else
	 {
		 status = EXTERNAL_NOK;
	 }
	 
	 return status;
	 
}


//ISR of EXTI0
void EXTI0_IRQHandler(void)
{
	if(CallBack_EXTI_0!= EXTERNAL_NULLPOINTER)
	{
		CallBack_EXTI_0();
	}
	else
	{
		//Define Behaviour Need To Handle Null Pointer
	}
	
}

//ISR of EXTI1
void EXTI1_IRQHandler(void)
{
	if(CallBack_EXTI_1!= EXTERNAL_NULLPOINTER)
	{
		CallBack_EXTI_1();
	}
	else
	{
		//Define Behaviour Need To Handle Null Pointer
	}
	
	
}


//ISR of EXTI2
void EXTI2_IRQHandler(void)
{
	
	if(CallBack_EXTI_2!= EXTERNAL_NULLPOINTER)
	{
		CallBack_EXTI_2();
	}
	else
	{
		//Define Behaviour Need To Handle Null Pointer
	}
	
	
}



//ISR of EXTI3
void EXTI3_IRQHandler(void)
{
	if(CallBack_EXTI_3!= EXTERNAL_NULLPOINTER)
	{
		CallBack_EXTI_3();
	}
	else
	{
		//Define Behaviour Need To Handle Null Pointer
	}
	
	
}


//ISR of EXTI4
void EXTI4_IRQHandler(void)
{
 
	if(CallBack_EXTI_4!= EXTERNAL_NULLPOINTER)
	{
		CallBack_EXTI_4();
	}
	else
	{
		//Define Behaviour Need To Handle Null Pointer
	}
	
}

//ISR of EXTI5-9
void  EXTI9_5_IRQHandler(void)
{
	if(CallBack_EXTI_5_9!= EXTERNAL_NULLPOINTER)
	{
		CallBack_EXTI_5_9();
	}
	else
	{
		//Define Behaviour Need To Handle Null Pointer
	}
	
}

//ISR of EXTI10-15 
void EXTI15_10_IRQHandler(void)
{
	if(CallBack_EXTI_10_15!= EXTERNAL_NULLPOINTER)
	{
		CallBack_EXTI_10_15();
	}
	else
	{
		//Define Behaviour Need To Handle Null Pointer
	}
	
}
