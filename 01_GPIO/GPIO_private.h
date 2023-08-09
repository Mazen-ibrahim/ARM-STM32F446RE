/***********************************************************
    
		NAME: GPIO_private.h
		Create: 17/6/2023     
		Author: Mazen Ibrahim
		Verison: _V1_
	
***********************************************************/


#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


/*************** This is Method of #define  *******************************/
#define GPIOA_BASE_ADDRESS     0x40020000  
#define GPIOB_BASE_ADDRESS     0x40020400
#define GPIOC_BASE_ADDRESS     0x40020800  
#define GPIOD_BASE_ADDRESS     0x40020C00
#define GPIOE_BASE_ADDRESS     0x40021000
#define GPIOH_BASE_ADDRESS     0x40021C00

#define GPIOA_MODER            (*((volatile u32*)(GPIOA_BASE_ADDRESS+0x00)))
#define GPIOB_MODER            (*((volatile u32*)(GPIOB_BASE_ADDRESS+0x00)))
#define GPIOC_MODER            (*((volatile u32*)(GPIOC_BASE_ADDRESS+0x00)))
#define GPIOD_MODER            (*((volatile u32*)(GPIOR_BASE_ADDRESS+0x00)))
#define GPIOE_MODER            (*((volatile u32*)(GPIOE_BASE_ADDRESS+0x00)))
#define GPIOH_MODER            (*((volatile u32*)(GPIOH_BASE_ADDRESS+0x00)))
							   
#define GPIOA_OTYPER           (*((volatile u32*)(GPIOA_BASE_ADDRESS+0x04)))
#define GPIOB_OTYPER           (*((volatile u32*)(GPIOB_BASE_ADDRESS+0x04)))
#define GPIOC_OTYPER           (*((volatile u32*)(GPIOC_BASE_ADDRESS+0x04)))
#define GPIOD_OTYPER           (*((volatile u32*)(GPIOR_BASE_ADDRESS+0x04)))
#define GPIOE_OTYPER           (*((volatile u32*)(GPIOE_BASE_ADDRESS+0x04)))
#define GPIOH_OTYPER           (*((volatile u32*)(GPIOH_BASE_ADDRESS+0x04)))
							   
#define GPIOA_OSPEEDER         (*((volatile u32*)(GPIOA_BASE_ADDRESS+0x08)))
#define GPIOB_OSPEEDER         (*((volatile u32*)(GPIOB_BASE_ADDRESS+0x08)))
#define GPIOC_OSPEEDER         (*((volatile u32*)(GPIOC_BASE_ADDRESS+0x08)))
#define GPIOD_OSPEEDER         (*((volatile u32*)(GPIOR_BASE_ADDRESS+0x08)))
#define GPIOE_OSPEEDER         (*((volatile u32*)(GPIOE_BASE_ADDRESS+0x08)))
#define GPIOH_OSPEEDER         (*((volatile u32*)(GPIOH_BASE_ADDRESS+0x08)))

#define GPIOA_PUPDR            (*((volatile u32*)(GPIOA_BASE_ADDRESS+0x0C)))
#define GPIOB_PUPDR            (*((volatile u32*)(GPIOB_BASE_ADDRESS+0x0C)))
#define GPIOC_PUPDR            (*((volatile u32*)(GPIOC_BASE_ADDRESS+0x0C)))
#define GPIOD_PUPDR            (*((volatile u32*)(GPIOR_BASE_ADDRESS+0x0C)))
#define GPIOE_PUPDR            (*((volatile u32*)(GPIOE_BASE_ADDRESS+0x0C)))
#define GPIOH_PUPDR            (*((volatile u32*)(GPIOH_BASE_ADDRESS+0x0C)))
							   
#define GPIOA_IDR              (*((volatile u32*)(GPIOA_BASE_ADDRESS+0x10)))
#define GPIOB_IDR              (*((volatile u32*)(GPIOB_BASE_ADDRESS+0x10)))
#define GPIOC_IDR              (*((volatile u32*)(GPIOC_BASE_ADDRESS+0x10)))
#define GPIOD_IDR              (*((volatile u32*)(GPIOR_BASE_ADDRESS+0x10)))
#define GPIOE_IDR              (*((volatile u32*)(GPIOE_BASE_ADDRESS+0x10)))
#define GPIOH_IDR              (*((volatile u32*)(GPIOH_BASE_ADDRESS+0x10)))
							   
							   
#define GPIOA_ODR              (*((volatile u32*)(GPIOA_BASE_ADDRESS+0x14)))
#define GPIOB_ODR              (*((volatile u32*)(GPIOB_BASE_ADDRESS+0x14)))
#define GPIOC_ODR              (*((volatile u32*)(GPIOC_BASE_ADDRESS+0x14)))
#define GPIOD_ODR              (*((volatile u32*)(GPIOR_BASE_ADDRESS+0x14)))
#define GPIOE_ODR              (*((volatile u32*)(GPIOE_BASE_ADDRESS+0x14)))
#define GPIOH_ODR              (*((volatile u32*)(GPIOH_BASE_ADDRESS+0x14)))
							   
#define GPIOA_ODR              (*((volatile u32*)(GPIOA_BASE_ADDRESS+0x14)))
#define GPIOB_ODR              (*((volatile u32*)(GPIOB_BASE_ADDRESS+0x14)))
#define GPIOC_ODR              (*((volatile u32*)(GPIOC_BASE_ADDRESS+0x14)))
#define GPIOD_ODR              (*((volatile u32*)(GPIOR_BASE_ADDRESS+0x14)))
#define GPIOE_ODR              (*((volatile u32*)(GPIOE_BASE_ADDRESS+0x14)))
#define GPIOH_ODR              (*((volatile u32*)(GPIOH_BASE_ADDRESS+0x14)))


#define GPIOA_BSRR             (*((volatile u32*)(GPIOA_BASE_ADDRESS+0x18)))
#define GPIOB_BSRR             (*((volatile u32*)(GPIOB_BASE_ADDRESS+0x18)))
#define GPIOC_BSRR             (*((volatile u32*)(GPIOC_BASE_ADDRESS+0x18)))
#define GPIOD_BSRR             (*((volatile u32*)(GPIOR_BASE_ADDRESS+0x18)))
#define GPIOE_BSRR             (*((volatile u32*)(GPIOE_BASE_ADDRESS+0x18)))
#define GPIOH_BSRR             (*((volatile u32*)(GPIOH_BASE_ADDRESS+0x18)))



#define GPIOA_LCKR             (*((volatile u32*)(GPIOA_BASE_ADDRESS+0x1C)))
#define GPIOB_LCKR             (*((volatile u32*)(GPIOB_BASE_ADDRESS+0x1C)))
#define GPIOC_LCKR             (*((volatile u32*)(GPIOC_BASE_ADDRESS+0x1C)))
#define GPIOD_LCKR             (*((volatile u32*)(GPIOR_BASE_ADDRESS+0x1C)))
#define GPIOE_LCKR             (*((volatile u32*)(GPIOE_BASE_ADDRESS+0x1C)))
#define GPIOH_LCKR             (*((volatile u32*)(GPIOH_BASE_ADDRESS+0x1C)))


#define GPIOA_AFRL             (*((volatile u32*)(GPIOA_BASE_ADDRESS+0x20)))
#define GPIOB_AFRL             (*((volatile u32*)(GPIOB_BASE_ADDRESS+0x20)))
#define GPIOC_AFRL             (*((volatile u32*)(GPIOC_BASE_ADDRESS+0x20)))
#define GPIOD_AFRL             (*((volatile u32*)(GPIOR_BASE_ADDRESS+0x20)))
#define GPIOE_AFRL             (*((volatile u32*)(GPIOE_BASE_ADDRESS+0x20)))
#define GPIOH_AFRL             (*((volatile u32*)(GPIOH_BASE_ADDRESS+0x20)))


#define GPIOA_AFRH             (*((volatile u32*)(GPIOA_BASE_ADDRESS+0x24)))
#define GPIOB_AFRH             (*((volatile u32*)(GPIOB_BASE_ADDRESS+0x24)))
#define GPIOC_AFRH             (*((volatile u32*)(GPIOC_BASE_ADDRESS+0x24)))
#define GPIOD_AFRH             (*((volatile u32*)(GPIOR_BASE_ADDRESS+0x24)))
#define GPIOE_AFRH             (*((volatile u32*)(GPIOE_BASE_ADDRESS+0x24)))
#define GPIOH_AFRH             (*((volatile u32*)(GPIOH_BASE_ADDRESS+0x24)))
/***************************************************************************/


/**************************This is Struct Method***************************/
typedef struct 
{
    volatile u32  MODER    ;
    volatile u32  OTYPER   ;
	volatile u32  OSPEEDER ;
	volatile u32  PUPDR    ;
	volatile u32  IDR      ;
	volatile u32  ODR      ;
	volatile u32  BSRR     ;
	volatile u32  LCKR     ;
	volatile u32  AFRL     ;
	volatile u32  AFRH     ;
	
}GPIO_REGISTERS;

#define GPIOA  (( GPIO_REGISTERS*)(GPIOA_BASE_ADDRESS))
#define GPIOB  (( GPIO_REGISTERS*)(GPIOB_BASE_ADDRESS))
#define GPIOC  (( GPIO_REGISTERS*)(GPIOC_BASE_ADDRESS))
#define GPIOD  (( GPIO_REGISTERS*)(GPIOD_BASE_ADDRESS))
#define GPIOE  (( GPIO_REGISTERS*)(GPIOE_BASE_ADDRESS))
#define GPIOH  (( GPIO_REGISTERS*)(GPIOH_BASE_ADDRESS))

/****************************************************************************/



#endif
