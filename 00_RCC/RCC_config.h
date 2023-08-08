/***********************************************************
    
		NAME: RCC_config.h
		Create: 6/6/2023     
		Author: Mazen Ibrahim
		Verison: _V1_
	
***********************************************************/


/*********************************************************
******** Guard of file will call on time in .c ***********
*********************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

#define HSI             0U
#define HSE             1U
#define PLL             2U
#define HSECrystal      3U
#define HSERC           4U
#define PLLHSE          5U
#define PLLHSI          6U


/****************
 CLK_SRC Options: 
 1-HSI
 2-HSE
 3-PLL
****************/
#define CLK_SRC         HSI


/****************
 HSE_TYPE Options: 
 1-HSECrystal
 2-HSERC 
****************/
#define HSE_TYPE        HSECrystal


/****************
 HSE_TYPE Options: 
 1-PLLHSI
 2-PLLHSE
****************/
#define PLL_TYPE        PLLHSE



#endif
