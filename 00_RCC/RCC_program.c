/***********************************************************
    
		NAME: RCC_program.c
		Create: 8/6/2023     
		Author: Mazen Ibrahim
		Verison: _V1_
	
***********************************************************/


/*****************INCLUDE LIBRARYS************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*********************************************************/


/***************** INCLUDE MCAL  *************************/
#include "RCC_private.h"
#include "RCC_config.h"
#include "RCC_interface.h"
/*********************************************************/



void MRCC_vEnableClock( BusName_t BusName , u8 Copy_u8PerNum )
{
	
   switch(BusName)
   {
	  case AHB_Bus_1 : SET_BIT(RCC_AHB1ENR,Copy_u8PerNum); break;
      case AHB_Bus_2 : SET_BIT(RCC_AHB2ENR,Copy_u8PerNum); break;
      case APB_Bus_1 : SET_BIT(RCC_APB1ENR,Copy_u8PerNum); break;
      case APB_Bus_2 : SET_BIT(RCC_APB2ENR,Copy_u8PerNum); break;	
      default: /*ERROR*/ break;	  
	   
   }   
	
	
}

void MRCC_vDisableClock( BusName_t BusName , u8 Copy_u8PerNum )
{
	 switch(BusName)
   {
	  case AHB_Bus_1 : CLR_BIT(RCC_AHB1ENR,Copy_u8PerNum); break;
      case AHB_Bus_2 : CLR_BIT(RCC_AHB2ENR,Copy_u8PerNum); break;
      case APB_Bus_1 : CLR_BIT(RCC_APB1ENR,Copy_u8PerNum); break;
      case APB_Bus_2 : CLR_BIT(RCC_APB2ENR,Copy_u8PerNum); break;	
      default: /*ERROR*/ break;	  
	   
   } 
	
	
}

void MRCC_vEnableClockSecurity(void)
{

	SET_BIT(RCC_CR,19);
	
}

void MRCC_vDisableClockSecurity(void)
{

	CLR_BIT(RCC_CR,19);
	
}

void MRCC_vInitClock(ClockSource_t copy_tClkSrc , HSESrc_t copy_tHSESrc, PLLSrc_t copy_tPLLSrc)
{
	
	switch(copy_tClkSrc)
	{
		case HSE:
		    
	      	switch(copy_tHSESrc)
			{
				case HSE_Crystal: 
				 
				  //Enable HSE_Crystal
				  SET_BIT(RCC_CR,16U);
				  
				  //Disable BYPASS
				  CLR_BIT(RCC_CR,18U);
				  
				  //Enable HSE as System Clock
				  SET_BIT(RCC_CFGR,0U);
				  CLR_BIT(RCC_CFGR,1U);
				  
				break;
				
				
				case HSE_RC:
				
				  //Enable HSE_RC
				  SET_BIT(RCC_CR,16U);
				  
				  //Enable BYPASS
				  SET_BIT(RCC_CR,18U);
				  
				  //Enable HSE as System Clock
				  SET_BIT(RCC_CFGR,0U);
				  CLR_BIT(RCC_CFGR,1U);
				
				break;
				
				
				default : /*Error*/  break;     
				
			}
	       
		
		
		break;
		
		
		
		case HSI:
            //Enable HSI
		    SET_BIT(RCC_CR,0U);
				  
			//Enable HSI as System Clock
			CLR_BIT(RCC_CFGR,0U);
			CLR_BIT(RCC_CFGR,1U);
		
		break;
		
		
		case PLL:
		   switch(copy_tPLLSrc)
		   {
		      case  HSE_PLL :   
			  
			  	//Enable HSE_Crystal
				SET_BIT(RCC_CR,16U);
				
				//Enable PLL
				SET_BIT(RCC_CR,24U);
			    
			    //Enable HSE_PLL
				SET_BIT(RCC_PLLCFGR,22);
				
				//Enable System Clock as PLL
				CLR_BIT(RCC_CFGR,0U);
				SET_BIT(RCC_CFGR,1U);
			  
			  break;	   
			   
			  case  HSI_PLL : 
			  
			    //Enable HSI
		        SET_BIT(RCC_CR,0U);
                
				//Enable PLL
				SET_BIT(RCC_CR,24U);
			    
		        //Enable HSI_PLL
				CLR_BIT(RCC_PLLCFGR,22);
			    
				//Enable System Clock as PLL
				CLR_BIT(RCC_CFGR,0U);
				SET_BIT(RCC_CFGR,1U);
				
			  break;
			   
		   }
		
		break;
		
	}
	
}

void MRCC_vInitClockSystem(void)
{
	#if CLK_SRC == HSI 
	    
		//Enable HSI
		SET_BIT(RCC_CR,0U);
				  
		//Enable HSI as System Clock
		CLR_BIT(RCC_CFGR,0U);
		CLR_BIT(RCC_CFGR,1U);
	
	
	#elif CLK_SRC == HSE 
	    #if HSE_TYPE == HSECrystal
			//Enable HSE_Crystal
			SET_BIT(RCC_CR,16U);
			
			//Disable BYPASS
			CLR_BIT(RCC_CR,18U);
			
			//Enable HSE as System Clock
			SET_BIT(RCC_CFGR,0U);
			CLR_BIT(RCC_CFGR,1U);

        #elif HSE_TYPE == HSERC
            //Enable HSE_RC
			SET_BIT(RCC_CR,16U);
				  
			//Enable BYPASS
			SET_BIT(RCC_CR,18U);
				  
			//Enable HSE as System Clock
			SET_BIT(RCC_CFGR,0U);
			CLR_BIT(RCC_CFGR,1U);
      		
        #else 
            /******* Warning ********/		
	    
		#endif
		
	#elif CLK_SRC == PLL
	   #if PLL_TYPE == PLLHSE
			//Enable HSE_Crystal
			SET_BIT(RCC_CR,16U);
			
			//Enable PLL
			SET_BIT(RCC_CR,24U);
			
			//Enable HSE_PLL
			SET_BIT(RCC_PLLCFGR,22)
			
			//Enable System Clock as PLL
			CLR_BIT(RCC_CFGR,0U);
			SET_BIT(RCC_CFGR,1U);
		
	   #elif PLL_TYPE == PLLHSI
	        //Enable HSI
		    SET_BIT(RCC_CR,0U);
		   
		    //Enable PLL
		    SET_BIT(RCC_CR,24U);
		   
		    //Enable HSI_PLL
		    CLR_BIT_BIT(RCC_PLLCFGR,22)
		   
		    //Enable System Clock as PLL
		    CLR_BIT(RCC_CFGR,0U);
		    SET_BIT(RCC_CFGR,1U);
		   
	   #else
	       /******* Warning ********/		
   
	   #endif	
	   
	   
	#else
		/******* Warning ********/
	
	
	
	#endif
	
	
	
	
}
