/***********************************************************
    
		NAME: SYSTICK_private.h
		Create: 28/6/2023     
		Author: Mazen Ibrahim
		Verison: _V1_
	
***********************************************************/

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

#define SYSTICK_BASE_ADDRESS     0xE000E010


/*************** SYSTICK_CTRL REGSITER *****************/
#define ENABLE_BIT     0U
#define TICK_INT       1U
#define CLK_SOURCE     2U
#define COUNT_FLAG     16U
/******************************************************/





typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
	
}SYSTICK_REG;

#define  ENABLE           0U
#define  DISABLE          1U
#define  AHB_8            0U
#define  PRO_CLK          1U 
#define  ENABLE_BIT       0U
#define  TICKINT_BIT      1U
#define  CLK_SRC_BIT      2U
#define  COUNTER_FLAG     16U
#define  STK_SINGLE       0U
#define  STK_PERODIC      1U


#define SYSTICK   ((SYSTICK_REG*       )(SYSTICK_BASE_ADDRESS))

#endif
