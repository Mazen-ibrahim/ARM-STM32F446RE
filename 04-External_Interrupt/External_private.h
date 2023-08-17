/***********************************************************
    
		NAME: External_private.h
		Create: 14/8/2023     
		Author: Mazen Ibrahim
		Verison: _V1_
	
***********************************************************/


#ifndef EXTERNAL_PRIVATE_H_
#define EXTERNAL_PRIVATE_H_

/******************* SYSCFG registers *******************/
#define SYSCFG_BASE_ADDRESS       0x40013800

//Define Struct To Hold Register of SYSCFG
typedef struct
{
  volatile u32 MEMRMP;	
  volatile u32 PMC;
  volatile u32 EXTICR1;
  volatile u32 EXTICR2;   
  volatile u32 EXTICR3;
  volatile u32 EXTICR4;
  volatile u32 CMPCR;  
	
}SYSCFG;

#define SYSCFG_REG    ((SYSCFG*)(SYSCFG_BASE_ADDRESS))

/********************************************************/



/*************** EXTERNAL_INTERRUPT *********************/

#define  EXTERNAL_BASE_ADDRESS    0x40013C00

//Define Struct To Hold Registers of External Interrupt
typedef struct
{
  volatile u32 IMR;	
  volatile u32 EMR;
  volatile u32 RSTR;
  volatile u32 FTSR;
  volatile u32 SWIER;
  volatile u32 PR;
    
	
}EXTI;

#define EXTERNEL_REG    ((EXTI*)( EXTERNAL_BASE_ADDRESS )) 

/**********************************************************/


#endif