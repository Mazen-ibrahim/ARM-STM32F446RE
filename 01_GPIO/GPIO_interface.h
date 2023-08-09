/***********************************************************
    
		NAME: GPIO_interface.h
		Create: 17/6/2023     
		Author: Mazen Ibrahim
		Version: _V1_
	
***********************************************************/


#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*Define Modes of Pin*/
typedef enum
{
	INPUT  = 0 ,
	OUTPUT = 1 ,
	ALT_F  = 2 ,
	ANALOG = 3   
	
}PIN_MODE;


/*Define Name of Ports*/
typedef enum
{
	PORTA  = 0 ,
	PORTB  = 1 ,
	PORTC  = 2 ,
	PORTD  = 3 ,
    PORTE  = 4 ,
    PORTH  = 5  	
	
}PORT_NAME;

/*Define Number of Pin*/
typedef enum
{
	PIN_0  = 0 ,
	PIN_1  = 1 ,
	PIN_2  = 2 ,
	PIN_3  = 3 ,
	PIN_4  = 4 ,
	PIN_5  = 5 ,
	PIN_6  = 6 ,
	PIN_7  = 7 ,
	PIN_8  = 8 ,
	PIN_9  = 9 ,
	PIN_10 = 10,
	PIN_11 = 11,
	PIN_12 = 12,
	PIN_13 = 13,
	PIN_14 = 14,
	PIN_15 = 15,
	
}PIN_NUM;

/*Define Types of Output*/
typedef enum 
{
	PUSH_PULL  = 0U,
  	OPEN_DRAIN = 1U,
	
}OUTPUT_TYPE;


/*Define Speed levels of Pin*/
typedef enum
{
	LOW_SPEED    = 0U,
	MEDIUM_SPEED = 1U,
  	FAST_SPEED   = 2U,
	HIGH_SPEED   = 3U,
	
}SPEED_LEVEL;


/*Define Types of Input*/
typedef enum
{
	NO_PULL   = 0U,
	PULL_UP   = 1U,
	PULL_DOWN = 2U,
}INPUT_TYPE;


/*Define Types of Pin State*/
typedef enum 
{
	HIGH = 0U,
	LOW  = 1U,
}PIN_STATE;

typedef enum 
{
	SET   = 0U,
	RESET = 1U,
}ENABLE_PIN;


typedef enum 
{
	AF0   = 0U,
	AF1   = 1U,
	AF2   = 2U,
	AF3   = 3U,
	AF4   = 4U,
	AF5   = 5U,
	AF6   = 6U,
	AF7   = 7U,
	AF8   = 8U,
	AF9   = 9U,
	AF10  = 10U,
	AF11  = 11U,
	AF12  = 12U,
	AF13  = 13U,
	AF14  = 14U,
	AF15  = 15U
	
}ALTERNATE_MODE;



/*
 Fucntion to enable GPIO Pin
  Parameters :  
    1- PortName (PORTA,PORTB,PORTC,PORTD,PORTE,PORTH) 
    2- PinNumber   (PIN_0...PIN_15)
	3- Mode of Pin (INPUT,OUTPUT,ALT_F,ANALOG)
  
  Return: void
*/
void MGPIO_vSetPinMode( PORT_NAME copy_ePortName , PIN_NUM copy_ePinNum , PIN_MODE copy_eMode );

/*
 Fucntion to Define Type  of Output Pin
  Parameters :  
    1- PortName (PORTA,PORTB,PORTC,PORTD,PORTE,PORTH) 
    2- PinNumber (PIN_0...PIN_15)
	3- Type of Output (PUSH_PULL , OPEN_DRAIN)
 
  Return: void
*/
void MGPIO_vSetPinOutputType( PORT_NAME copy_ePortName , PIN_NUM copy_ePinNum , OUTPUT_TYPE copy_eType );


/*
 Fucntion to Define Speed Level of Output Pin
  Parameters :  
   1- PortName  (PORTA,PORTB,PORTC,PORTD,PORTE,PORTH) 
   2- PinNumber  (PIN_0...PIN_15)
   3- Type of Output (LOW_SPEED ,MEDIUM_SPEED, FAST_SPEED, HIGH_SPEED)
  
  Return: void
*/
void MGPIO_vSetPinSpeedLevel( PORT_NAME copy_ePortName , PIN_NUM copy_ePinNum , SPEED_LEVEL copy_eLevel );


/*
 Fucntion to Define Type  of Input Pin
  Parameters :  
    1- PortName (PORTA,PORTB,PORTC,PORTD,PORTE,PORTH) 
    2- PinNumber (PIN_0...PIN_15)
	3- Type of Input_type (NO_PULL, PULL_UP, PULL_DOWN,)

  Return: void
*/
void MGPIO_vSetPinInputType( PORT_NAME copy_ePortName , PIN_NUM copy_ePinNum , INPUT_TYPE copy_eType );



/*
 Fucntion to Get State of Input Pin
  Parameters :  
    1- PortName (PORTA,PORTB,PORTC,PORTD,PORTE,PORTH) 
    2- PinNumber (PIN_0...PIN_15)

  Return : 
    1- State of Pin ( HIGH , LOW)
*/
u8 MGPIO_vGetPinState( PORT_NAME copy_ePortName , PIN_NUM copy_ePinNum );



/*
 Fucntion to Define Output Pin
  Parameters :  
    1- PortName  (PORTA,PORTB,PORTC,PORTD,PORTE,PORTH) 
    2- PinNumber (PIN_0...PIN_15)
	3- Type of Output (HIGH,LOW)
  
  Return: void
*/
void MGPIO_vSetPinOutputState( PORT_NAME copy_ePortName , PIN_NUM copy_ePinNum , PIN_STATE state );


/*
 Fucntion to Set or Reset Pin
  Parameters :  
    1- PortName (PORTA,PORTB,PORTC,PORTD,PORTE,PORTH) 
    2- PinNumber (PIN_0...PIN_15)
    3- Type of Output (SET,RESET)

  Return: void
*/
void MGPIO_vEnablePin( PORT_NAME copy_ePortName , PIN_NUM copy_ePinNum , ENABLE_PIN state );




/*
 Fucntion to Lock Pin
  Parameters :  
    1- PortName  (PORTA,PORTB,PORTC,PORTD,PORTE,PORTH) 
    2- PinNumber (PIN_0...PIN_15)
	
  Return: void
*/
void MGPIO_vPinLock( PORT_NAME copy_ePortName , PIN_NUM copy_ePinNum );


/*
 Fucntion to Set Alternate Fucntion mode for Pin
  Parameters :  
    1- PortName  (PORTA,PORTB,PORTC,PORTD,PORTE,PORTH) 
    2- PinNumber   (AF0...AF15)
  
  Return: void
*/
void MGPIO_vSetAltPin( PORT_NAME copy_ePortName , PIN_NUM copy_ePinNum , ALTERNATE_MODE mode );

#endif
