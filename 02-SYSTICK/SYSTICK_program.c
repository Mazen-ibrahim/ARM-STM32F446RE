/***********************************************************
    
		NAME: SYSTICK_program.c
		Create: 28/6/2023     
		Author: Mazen Ibrahim
		Verison: _V1_
	
***********************************************************/


/***************** INCLUDE LIBRARYS **********************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*********************************************************/

/***************** INCLUDE MCAL  *************************/
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"
#include "SYSTICK_interface.h"
/*********************************************************/


//Pointer to hold CallBack Function of SYSTICK
static  void(*SYSTICK_CallBack)(void) = 0U;

//Global Variable to Hold Mode of Timer Periodic or Single
static volatile u8 G_u8SetMode ;


void MSTK_voidInit(void)
{
	//SET CLK_SRC of SYSTICK
	#if CLK_SRC == AHB_8
      CLR_BIT(SYSTICK->CTRL,CLK_SRC_BIT);
	
	#elif CLK_SRC == PRO_CLK
	  SET_BIT(SYSTICK->CTRL,CLK_SRC_BIT);
		
	#endif
    
	//SET INTERRUPT of SYSTICK 
    #if INTERRUPT  == ENABLE
      SET_BIT(SYSTICK->CTRL,TICKINT);
	  
    #elif INTERRUPT == DISABLE
      CLR_BIT(SYSTICK->CTRL,TICKINT);
	  
    #endif	
	
	//Disable SYSTICK Timer
	CLR_BIT(SYSTICK->CTRL,ENABLE_BIT);
	
}



void MSTK_voidSetBusyWait(u32 copy_u32Ticks)
{
	//SET Load Register by copy_u32Ticks
	SYSTICK->LOAD = copy_u32Ticks;
	
	//Enable SYSTICK to start
	SET_BIT(SYSTICK->CTRL,ENABLE_BIT);
	
	//Polling on CounterFlag
	while(GET_BIT(SYSTICK->CTRL,COUNT_FLAG ) == 0);
	
	//Stop SYSTICk
	CLR_BIT(SYSTICK->CTRL,ENABLE_BIT);
	SYSTICK->LOAD = 0;
	SYSTICK->VAL  = 0;
	
}


u32 MSTK_u32CurrentValue(void)
{
	u32 Current_Value = 0;
	Current_Value = SYSTICK->VAL;
	return Current_Value;
}



u32 MSTK_u32ElapsedValue(void)
{
	u32 ElapsedTime = 0;
	ElapsedTime = ((SYSTICK->LOAD)-(SYSTICK->VAL));
	return ElapsedTime;
}



void MSTK_voidSetIntervelPeriodic(u32 copy_u32Ticks, void(*Copy_ptrFunc)(void))
{
    //Load Tick to Load Register
	SYSTICK->LOAD = copy_u32Ticks;

    //Save CallBack 
    SYSTICK_CallBack = Copy_ptrFunc;

    //Set Mode of Timer 
    G_u8SetMode = STK_PERODIC;

    //Enable SYSTICK Interrupt
    SET_BIT(SYSTICK->CTRL,TICK_INT);

    //Start Timer
    SET_BIT(SYSTICK->CTRL,ENABLE_BIT);	
	
}


void MSTK_voidSetIntervelSingle(u32 copy_u32Ticks, void(*Copy_ptrFunc)(void))
{
    //Load Tick to Load Register
	SYSTICK->LOAD = copy_u32Ticks;

    //Save CallBack 
    SYSTICK_CallBack = Copy_ptrFunc;

    //Set Mode of Timer 
    G_u8SetMode = STK_SINGLE;

    //Enable SYSTICK Interrupt
    SET_BIT(SYSTICK->CTRL,TICK_INT);

    //Start Timer
    SET_BIT(SYSTICK->CTRL,ENABLE_BIT); 	
	
}



void MSTK_voidStopIntervel(void)
{
	//Disable SYSTICK Interrupt
    CLR_BIT(SYSTICK->CTRL,TICK_INT);
	
	//Disable SYSTICK Timer
	CLR_BIT(SYSTICK->CTRL,ENABLE_BIT);
	SYSTICK->LOAD = 0U;
	SYSTICK->VAL  = 0U;
}



//ISR of SYSTICK
void SysTick_Handler(void)
{
	u8 Local_u8Temporary = 0U;
	
	if(G_u8SetMode == STK_SINGLE)
	{
		//Disable SYSTICK Timer
		CLR_BIT(SYSTICK->CTRL,ENABLE_BIT);
		SYSTICK->LOAD = 0U;
		SYSTICK->VAL  = 0U;
	    
        //Disable SYSTICK Interrupt
		CLR_BIT(SYSTICK->CTRL,TICK_INT);		
	}
	
	//CallBack Notification
	SYSTICK_CallBack();
	
	Local_u8Temporary = GET_BIT(SYSTICK->CTRL, COUNT_FLAG);
	
	
	
}
