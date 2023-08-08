/***********************************************************
    
		NAME: RCC_private.h
		Create: 3/6/2023     
		Author: Mazen Ibrahim
		Verison: _V1_
	
***********************************************************/


/*********************************************************
******** Guard of file will call on time in .c ***********
*********************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

//Base Address of RCC_Periheral
#define MRCC_BASE_ADDRESS       0x40023800


/************************RCC REGISTERS******************************/
#define RCC_CR           (*((volatile u32*)(MRCC_BASE_ADDRESS+0x00)))
#define RCC_PLLCFGR      (*((volatile u32*)(MRCC_BASE_ADDRESS+0x04)))
#define RCC_CFGR         (*((volatile u32*)(MRCC_BASE_ADDRESS+0x08)))
#define RCC_CIR          (*((volatile u32*)(MRCC_BASE_ADDRESS+0x0C)))
#define RCC_AHB1RSTR     (*((volatile u32*)(MRCC_BASE_ADDRESS+0x10)))
#define RCC_AHB2RSTR     (*((volatile u32*)(MRCC_BASE_ADDRESS+0x14)))
#define RCC_APB1RSTR     (*((volatile u32*)(MRCC_BASE_ADDRESS+0x20)))
#define RCC_APB2RSTR     (*((volatile u32*)(MRCC_BASE_ADDRESS+0x24)))
#define RCC_AHB1ENR      (*((volatile u32*)(MRCC_BASE_ADDRESS+0x30)))
#define RCC_AHB2ENR      (*((volatile u32*)(MRCC_BASE_ADDRESS+0x34)))
#define RCC_APB1ENR      (*((volatile u32*)(MRCC_BASE_ADDRESS+0x40)))
#define RCC_APB2ENR      (*((volatile u32*)(MRCC_BASE_ADDRESS+0x44)))
#define RCC_AHB1LPENR    (*((volatile u32*)(MRCC_BASE_ADDRESS+0x50)))
#define RCC_AHB2LPENR    (*((volatile u32*)(MRCC_BASE_ADDRESS+0x54)))
#define RCC_APB1LPENR    (*((volatile u32*)(MRCC_BASE_ADDRESS+0x60)))
#define RCC_APB2LPENR    (*((volatile u32*)(MRCC_BASE_ADDRESS+0x64)))
#define RCC_BDCR         (*((volatile u32*)(MRCC_BASE_ADDRESS+0x70)))
#define RCC_CSR          (*((volatile u32*)(MRCC_BASE_ADDRESS+0x74)))
#define RCC_SSCGR        (*((volatile u32*)(MRCC_BASE_ADDRESS+0x80)))
#define RCC_PLLI2SCFGR   (*((volatile u32*)(MRCC_BASE_ADDRESS+0x84)))
#define RCC_DCKCFGR      (*((volatile u32*)(MRCC_BASE_ADDRESS+0x8C)))
/*******************************************************************/


/*************************RCC REGSITERS PINS************************/
#define CSSON     19U


/*******************************************************************/


/*************************Struct Method*****************************/
typedef struct
{   
	volatile u32 CR            ;
	volatile u32 PLLCFGR       ;
	volatile u32 CFGR          ;
	volatile u32 CIR           ;
	volatile u32 AHB1RSTR      ;
	volatile u32 AHB2RSTR      ;
	volatile u32 RESERVED_1[2] ;
	volatile u32 APB1RSTR      ;
	volatile u32 APB2RSTR      ;
	volatile u32 RESERVED_2[2] ;
	volatile u32 AHB1ENR       ;
	volatile u32 AHB2ENR       ;
    volatile u32 RESERVED_3[2] ;
	volatile u32 APB1ENR       ;
	volatile u32 APB2ENR       ;
	volatile u32 RESERVED_4[2] ;
	volatile u32 AHB1LPENR     ;
	volatile u32 AHB2LPENR     ;
	volatile u32 RESERVED_5[2] ;
	volatile u32 APB1LPENR     ;
	volatile u32 APB2LPENR     ;
	volatile u32 RESERVED_6[2] ;
	volatile u32 BDCR          ;
	volatile u32 CSR           ;
	volatile u32 RESERVED_7[2] ;
	volatile u32 SSCGR         ;
	volatile u32 PLLI2SCFGR    ;
	volatile u32 RESERVED_8    ;
	volatile u32 DCKCFGR       ;
	
}RCC_Registers;

#define MRCC        ((RCC_Registers*) MRCC_BASE_ADDRESS)

/*******************************************************************/




#endif // RCC_PRIVATE_H
