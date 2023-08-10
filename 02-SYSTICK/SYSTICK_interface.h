/***********************************************************
    
		NAME: SYSTICK_interface.h
		Create: 28/6/2023     
		Author: Mazen Ibrahim
		Verison: _V1_
	
***********************************************************/

#define SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_


/*
 Description:Fucntion to Apply Clock Configuration of SYSTICK Timer
 Parameters: void
 Return: void
*/
void MSTK_voidInit(void);


/*
 Description:Fucntion to set load Resigter Ticks of SYSTICK Timer
 Parameters : copy_u32Ticks : Number of Ticks
 Return : void
*/
void MSTK_voidSetBusyWait(u32 copy_u32Ticks);

/*
  Description: Fucntion to Know Current Value of SYSTICK 
  Parameters : void
  Return : Current Value of SYSTICK Timer
*/
u32 MSTK_u32CurrentValue(void);


/*
 Description: Fucntion to Know Elapsed Value of SYSTICK 
 Parameters : void
 Return : Elapsed Value of SYSTICK Timer
*/
u32 MSTK_u32ElapsedValue(void);



/*
 Description: Fucntion to Stop Systick timer 
 Parameters : void
 Return : void
*/
void MSTK_voidStopIntervel(void);




/*
 Description: Function Set Periodic time call of Callback fucntion when SYSTICK counter Flag is raised
 Parameters : 
  1- copy_u32Ticks : Number of Ticks
  2- void(*Copy_ptrFunc)(void): pointer to callback function
 Return: void
*/
void MSTK_voidSetIntervelPeriodic(u32 copy_u32Ticks, void(*Copy_ptrFunc)(void));


/*
 Descritpion: Fucntion Set Single time call of Callback fucntion when SYSTICK counter Flag is raised
 Parameters : 
 1- copy_u32Ticks : Number of Ticks
 2- void(*Copy_ptrFunc)(void): pointer to callback function
 Return: void
*/
void MSTK_voidSetIntervelSingle(u32 copy_u32Ticks, void(*Copy_ptrFunc)(void));



#endif