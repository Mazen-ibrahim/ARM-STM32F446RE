/***********************************************************
    
		NAME: NVIC_interface.h
		Create: 12/7/2023     
		Author: Mazen Ibrahim
		Verison: _V1_
	
***********************************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_
#include "STD_TYPES.h"

//Define Enum to Hold Return Status of Fucntion
typedef enum
{
	NVIC_OK,
	NVIC_NOK
}NVIC_TYPE_STATUS;




/*
Description: Function used to Enable Interrupt or Exception Based on Interrupt Number
Paramaters: Interrupt Number
return: 
    1-NVIC_OK:Interrupt Enabled 
	2-NVIC_NOK: Error Happend
*/

u8 MNVIC_EnableIRQ(u8 Interrupt_Number);



/*
Description: Function used to Disable Interrupt or Exception Based on Interrupt Number
Paramaters: Interrupt Number
return: 
    1-NVIC_OK:Interrupt Disabled 
	2-NVIC_NOK: Error Happend
*/

u8 MNVIC_DisableIRQ(u8 Interrupt_Number);


/*
Description: Function used to Enable Pending State of Interrupt Based on Interrupt Number
Paramaters: Interrupt Number
return: 
    1-NVIC_OK 
	2-NVIC_NOK
*/
u8 MNVIC_EnablePendingIRQ(u8 Interrupt_Number);



/*
Description: Function used to Disable Pending State of Interrupt Based on Interrupt Number
Paramaters: Interrupt Number
return: 
    1-NVIC_OK 
	2-NVIC_NOK
*/
u8 MNVIC_DisablePendingIRQ(u8 Interrupt_Number);



/*
Description: Function used to Get Pending State of Interrupt Based on Interrupt Number
Paramaters: Interrupt Number
return: 
    1-NVIC_OK
	2-NVIC_NOK
*/


u8 MNVIC_GetPendingIRQ(u8 Interrupt_Number , u8 *Interrupt_Status);


/*
Description: Fucntion to Read Status of Interrupt Based on Interuppt number
Paramaters: Interrupt Number , Pointer to Hold Status  (1:Mean Active  , 0:Mean Not Active)
return:  
    1-NVIC_OK 
	2-NVIC_NOK
*/
u8 MNVIC_ReadInterruptStatus(u8 Interrupt_Number , u8 *Interrupt_Status);



/*
Description: Fucntion to Set Priority of Interrupt Based on Interuppt number
Paramaters: Interrupt Number ,New Priority_Number
return:  
    1-NVIC_OK
	2-NVIC_NOK
*/

u8 MNVIC_SetPriority(u8 Interrupt_Number, u8 Priority_Number);



/*
Description: Fucntion to Get Priority of Interrupt Based on Interuppt number
Paramaters: Interrupt Number , pointer to variable to Hold Priority of Interrupt
return:  
    1-NVIC_OK
	2-NVIC_NOK
*/

u8 MNVIC_GetPriority(u8 Interrupt_Number, u32 *Priority_Number);


/*
Description: Fucntion to Trigger Interuppt Based on Interrupt Number
Paramaters: Interrupt Number , pointer to variable to Hold Priority of Interrupt
return:  
    1-NVIC_OK
	2-NVIC_NOK
*/
u8 MNVIC_TriggerInterrupt(u8 Interrupt_Number);


#endif  //NVIC_INTERFACE_H_
