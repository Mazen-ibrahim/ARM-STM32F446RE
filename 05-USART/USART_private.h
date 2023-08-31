/***********************************************************
    
		NAME: USART_private.h
		Create: 22/8/2023     
		Author: Mazen Ibrahim
		Verison: _V1_
	
***********************************************************/

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

//Define Base Address for All USART in System
#define USART1_BASE_ADDRESS          0x40011000
#define USART2_BASE_ADDRESS          0x40004400
#define USART6_BASE_ADDRESS          0x40011400



//Define Struct to Hold Registers of USART
typedef struct 
{
  volatile u32 SR;	
  volatile u32 DR;
  volatile u32 BRP;
  volatile u32 CR1;
  volatile u32 CR2; 
  volatile u32 CR3;  
  volatile u32 GTPR;	
	
}USART_REG;



#define MUSART_1    ((USART_REG*)(USART1_BASE_ADDRESS))   
#define MUSART_2    ((USART_REG*)(USART2_BASE_ADDRESS))
#define MUSART_6    ((USART_REG*)(USART6_BASE_ADDRESS))



//Define USART STATES
#define IDLE      0
#define Busy_RX   1
#define Busy_TX   2





#endif  //USART_PRIVATE_H_