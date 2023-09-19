/***********************************************************
    
		NAME: NVIC_program.c
		Create: 12/7/2023     
		Author: Mazen Ibrahim
		Verison: _V1_
	
***********************************************************/



/*****************INCLUDE LIBRARYS************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*********************************************************/


/***************** INCLUDE MCAL  *************************/
#include "NVIC_private.h"
#include "NVIC_config.h"
#include "NVIC_interface.h"
/*********************************************************/


/***************** INCLUDE HALS  ************************/




/*********************************************************/



u8 MNVIC_EnableIRQ(u8 Interrupt_Number)
{
	NVIC_TYPE_STATUS status = NVIC_OK;
	
	if(  Interrupt_Number <=31 )
	{
		NVIC_ISEN->NVIC_ISER0 |= 1<<Interrupt_Number;
	     
	}
	
	else if (Interrupt_Number >=32 && Interrupt_Number<=63)
	{
		NVIC_ISEN->NVIC_ISER1 |= 1<<Interrupt_Number - 32;
		
	}
	
	else if (Interrupt_Number>=64 && Interrupt_Number <=95)
	{   
	    NVIC_ISEN->NVIC_ISER2 |= 1<<Interrupt_Number - 64 ;
	}
	
	else
	{
		
		status = NVIC_NOK;
	}
	
	return status;
	
}


u8 MNVIC_DisableIRQ(u8 Interrupt_Number)
{
	NVIC_TYPE_STATUS status = NVIC_OK;
	
	if(  Interrupt_Number <=31 )
	{
		NVIC_ICEN->NVIC_ICER0 |= (1<<Interrupt_Number);
	     
	}
	
	else if (Interrupt_Number >=32 && Interrupt_Number<=63)
	{
		NVIC_ICEN->NVIC_ICER1 |= (1<<Interrupt_Number - 32);
		
	}
	
	else if (Interrupt_Number>=64 && Interrupt_Number <=95)
	{   
		NVIC_ICEN->NVIC_ICER2 |= (1<<Interrupt_Number - 64);
	}
	
	else
	{
		
		status = NVIC_NOK;
	}
	
	return status;
	
}



u8 MNVIC_EnablePendingIRQ(u8 Interrupt_Number)
{
	NVIC_TYPE_STATUS status = NVIC_OK;
	
	if( Interrupt_Number <=31 )
	{
		NVIC_ISPRN->NVIC_ISPR0 |= (1<<Interrupt_Number);
	     
	}
	
	else if (Interrupt_Number >=32 && Interrupt_Number<=63)
	{
		NVIC_ISPRN->NVIC_ISPR1 |= (1<<Interrupt_Number - 32);
		
	}
	
	else if (Interrupt_Number>=64 && Interrupt_Number <=95)
	{   
		NVIC_ISPRN->NVIC_ISPR2 |= (1<<Interrupt_Number - 64);
	}
	
	else
	{
		
		status = NVIC_NOK;
	}
	
	return status;
	
}



u8 MNVIC_DisablePendingIRQ(u8 Interrupt_Number)
{
	NVIC_TYPE_STATUS status = NVIC_OK;
	
	if( Interrupt_Number <=31 )
	{
		NVIC_ICPRN->NVIC_ICPR0 |= (1<<Interrupt_Number);
	     
	}
	
	else if (Interrupt_Number >=32 && Interrupt_Number<=63)
	{
		NVIC_ICPRN->NVIC_ICPR1 |= (1<<Interrupt_Number - 32);
		
	}
	
	else if (Interrupt_Number>=64 && Interrupt_Number <=95)
	{   
		NVIC_ICPRN->NVIC_ICPR2 |= (1<<Interrupt_Number - 64);
	}
	
	else
	{
		
		status = NVIC_NOK;
	}
	
	return status;
	
}



u8 MNVIC_GetPendingIRQ(u8 Interrupt_Number , u8 *Interrupt_Status)
{
	NVIC_TYPE_STATUS status = NVIC_OK;
	
	if( Interrupt_Number <=31 )
	{
	    *Interrupt_Status = GET_BIT(NVIC_ICPRN->NVIC_ICPR0,Interrupt_Number);     
	}
	
	else if (Interrupt_Number >=32 && Interrupt_Number<=63)
	{
	    *Interrupt_Status = GET_BIT(NVIC_ICPRN->NVIC_ICPR1,Interrupt_Number - 32);  	
	}
	
	else if (Interrupt_Number>=64 && Interrupt_Number <=95)
	{
		*Interrupt_Status = GET_BIT(NVIC_ICPRN->NVIC_ICPR2,Interrupt_Number - 64);  
	}
	
	else
	{
		
		status = NVIC_NOK;
	}
	
	return status;
	
}



u8 MNVIC_ReadInterruptStatus(u8 Interrupt_Number , u8 *Interrupt_Status)
{
	NVIC_TYPE_STATUS status = NVIC_OK;
	
	if(  Interrupt_Number <=31 )
	{
		
	 *Interrupt_Status = GET_BIT( NVIC_IABRN->NVIC_IABR0,Interrupt_Number);
	
	}
	
	else if (Interrupt_Number >=32 && Interrupt_Number<=63)
	{
		*Interrupt_Status = GET_BIT( NVIC_IABRN->NVIC_IABR1,Interrupt_Number - 32 );
		
	}
	
	else if (Interrupt_Number>=64 && Interrupt_Number <=95)
	{   
		*Interrupt_Status = GET_BIT( NVIC_IABRN ->NVIC_IABR2,Interrupt_Number - 64 );
	}
	
	else
	{
		
		status = NVIC_NOK;
	}
	
	return status;
	
}


u8 MNVIC_SetPriority(u8 Interrupt_Number , u8 Priority_Number)
{
	NVIC_TYPE_STATUS status = NVIC_OK;
	
	u8 Register_Offset = Interrupt_Number / 4 ;
	
	if( Interrupt_Number == ( (4*Register_Offset) + 0 ) )
	{
 	    
		*((volatile u32*)(NVIC_IPR_BASE_ADDRESS + (0x04*Register_Offset))) |= Priority_Number << 0;	
	
	}
	
	else if( Interrupt_Number == ( (4*Register_Offset) + 1 ) )
	{
		
		*((volatile u32*)(NVIC_IPR_BASE_ADDRESS + (0x04*Register_Offset))) |= Priority_Number << 8;
	
	}
	 
	else if( Interrupt_Number == ( (4*Register_Offset) + 2 ) )
	{
		
		*((volatile u32*)(NVIC_IPR_BASE_ADDRESS + (0x04*Register_Offset))) |= Priority_Number << 16;
		
	}
	
	else if( Interrupt_Number == ( (4*Register_Offset) + 3 ) )
	{
		
		*((volatile u32*)(NVIC_IPR_BASE_ADDRESS + (0x04*Register_Offset))) |= Priority_Number << 24;
		
	}
	
	else
	{
		status = NVIC_NOK;
		
	}
	
	
	return status;
	
}

u8 MNVIC_GetPriority(u8 Interrupt_Number, u32 *Priority_Number)
{
	NVIC_TYPE_STATUS status  = NVIC_OK;
	
	u8 Register_Offset = Interrupt_Number / 4 ;
	
	if( Interrupt_Number == ( (4*Register_Offset) + 0 ) )
	{
 	    
		*Priority_Number = 	*((volatile u32*)(NVIC_IPR_BASE_ADDRESS + 0x04 +Register_Offset));	
	
	}
	
	else if( Interrupt_Number == ( (4*Register_Offset) + 1 ) )
	{
		
		*Priority_Number = 	*((volatile u32*)(NVIC_IPR_BASE_ADDRESS + 0x04 +Register_Offset));
	
	}
	 
	else if( Interrupt_Number == ( (4*Register_Offset) + 2 ) )
	{
		
		*Priority_Number = 	*((volatile u32*)(NVIC_IPR_BASE_ADDRESS + 0x04 +Register_Offset)) ;
		
	}
	
	else if( Interrupt_Number == ( (4*Register_Offset) + 3 ) )
	{
		
		*Priority_Number = 	*((volatile u32*)(NVIC_IPR_BASE_ADDRESS + 0x04 +Register_Offset));
		
	}
	
	else
	{
		status = NVIC_NOK;
		
	}
	
	
	return status;
	
	
}


u8 MNVIC_TriggerInterrupt(u8 Interrupt_Number)
{
   NVIC_TYPE_STATUS status = NVIC_OK;
   
   if(Interrupt_Number <= 84 )
   {  
	  NVIC_STIRN   =  Interrupt_Number  ;
   }
   
   return status;
	
}