/***********************************************************
    
		NAME: NVIC_private.h
		Create: 12/7/2023     
		Author: Mazen Ibrahim
		Verison: _V1_
	
***********************************************************/

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_
#include "STD_TYPES.h"

//Base Addresses of NVIC Registers

#define NVIC_ISER_BASE_ADDRESS     0xE000E100    
#define NVIC_ICER_BASE_ADDRESS     0XE000E180
#define NVIC_ISPR_BASE_ADDRESS     0XE000E200
#define NVIC_ICPR_BASE_ADDRESS     0XE000E280
#define NVIC_IABR_BASE_ADDRESS     0XE000E300
#define NVIC_STIR_BASE_ADDRESS     0xE000EF00
#define NVIC_IPR_BASE_ADDRESS      0xE000E400

//********************************************


//Struct To Hold NVIC Enable Regsiters
typedef struct
{
	u32   NVIC_ISER0;
	u32   NVIC_ISER1;
	u32   NVIC_ISER2;
	u32   NVIC_ISER3;
	u32   NVIC_ISER4;
	u32   NVIC_ISER5;
	u32   NVIC_ISER6;
	u32   NVIC_ISER7;
}NVIC_ISER;

#define  NVIC_ISEN     ((NVIC_ISER*) NVIC_ISER_BASE_ADDRESS)      

//*************************************************


//Struct To Hold NVIC Disable Regsiters
typedef struct
{
	u32   NVIC_ICER0;
	u32   NVIC_ICER1;
	u32   NVIC_ICER2;
	u32   NVIC_ICER3;
	u32   NVIC_ICER4;
	u32   NVIC_ICER5;
	u32   NVIC_ICER6;
	u32   NVIC_ICER7;
}NVIC_ICER;

#define  NVIC_ICEN    ((NVIC_ICER*) NVIC_ICER_BASE_ADDRESS)      

//*************************************************



//Struct To Hold NVIC Pending Enable Registers
typedef struct
{
  u32   NVIC_ISPR0;
  u32   NVIC_ISPR1;
  u32   NVIC_ISPR2;
  u32   NVIC_ISPR3;
  u32   NVIC_ISPR4;
  u32   NVIC_ISPR5;
  u32   NVIC_ISPR6;
  u32   NVIC_ISPR7;
}NVIC_ISPR;

#define NVIC_ISPRN     ((NVIC_ISPR*) NVIC_ISPR_BASE_ADDRESS)

//*************************************************



//Struct To Hold NVIC Pending Disable Registers
typedef struct
{
  u32   NVIC_ICPR0;
  u32   NVIC_ICPR1;
  u32   NVIC_ICPR2;
  u32   NVIC_ICPR3;
  u32   NVIC_ICPR4;
  u32   NVIC_ICPR5;
  u32   NVIC_ICPR6;
  u32   NVIC_ICPR7;
}NVIC_ICPR;

#define NVIC_ICPRN     ((NVIC_ICPR*) NVIC_ICPR_BASE_ADDRESS)

//*************************************************


//Struct To Hold NVIC Status Registers of Interrupts
typedef struct
{
 	
 u32  NVIC_IABR0;
 u32  NVIC_IABR1;
 u32  NVIC_IABR2;	
 u32  NVIC_IABR3;
 u32  NVIC_IABR4; 
 u32  NVIC_IABR5;	
 u32  NVIC_IABR6;
 u32  NVIC_IABR7; 
	
}NVIC_IABR;


#define NVIC_IABRN    ((NVIC_IABR*) NVIC_IABR_BASE_ADDRESS)
//*************************************************



//Software trigger interrupt Registers

#define NVIC_STIRN    (*((volatile u32*)(NVIC_STIR_BASE_ADDRESS)))

//*************************************************


#endif  //NVIC_PRIVATE_H_