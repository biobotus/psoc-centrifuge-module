/*******************************************************************************
* File Name: Thermistor_5.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Thermistor_5_H) /* Pins Thermistor_5_H */
#define CY_PINS_Thermistor_5_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Thermistor_5_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Thermistor_5__PORT == 15 && ((Thermistor_5__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Thermistor_5_Write(uint8 value) ;
void    Thermistor_5_SetDriveMode(uint8 mode) ;
uint8   Thermistor_5_ReadDataReg(void) ;
uint8   Thermistor_5_Read(void) ;
uint8   Thermistor_5_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Thermistor_5_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Thermistor_5_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Thermistor_5_DM_RES_UP          PIN_DM_RES_UP
#define Thermistor_5_DM_RES_DWN         PIN_DM_RES_DWN
#define Thermistor_5_DM_OD_LO           PIN_DM_OD_LO
#define Thermistor_5_DM_OD_HI           PIN_DM_OD_HI
#define Thermistor_5_DM_STRONG          PIN_DM_STRONG
#define Thermistor_5_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Thermistor_5_MASK               Thermistor_5__MASK
#define Thermistor_5_SHIFT              Thermistor_5__SHIFT
#define Thermistor_5_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Thermistor_5_PS                     (* (reg8 *) Thermistor_5__PS)
/* Data Register */
#define Thermistor_5_DR                     (* (reg8 *) Thermistor_5__DR)
/* Port Number */
#define Thermistor_5_PRT_NUM                (* (reg8 *) Thermistor_5__PRT) 
/* Connect to Analog Globals */                                                  
#define Thermistor_5_AG                     (* (reg8 *) Thermistor_5__AG)                       
/* Analog MUX bux enable */
#define Thermistor_5_AMUX                   (* (reg8 *) Thermistor_5__AMUX) 
/* Bidirectional Enable */                                                        
#define Thermistor_5_BIE                    (* (reg8 *) Thermistor_5__BIE)
/* Bit-mask for Aliased Register Access */
#define Thermistor_5_BIT_MASK               (* (reg8 *) Thermistor_5__BIT_MASK)
/* Bypass Enable */
#define Thermistor_5_BYP                    (* (reg8 *) Thermistor_5__BYP)
/* Port wide control signals */                                                   
#define Thermistor_5_CTL                    (* (reg8 *) Thermistor_5__CTL)
/* Drive Modes */
#define Thermistor_5_DM0                    (* (reg8 *) Thermistor_5__DM0) 
#define Thermistor_5_DM1                    (* (reg8 *) Thermistor_5__DM1)
#define Thermistor_5_DM2                    (* (reg8 *) Thermistor_5__DM2) 
/* Input Buffer Disable Override */
#define Thermistor_5_INP_DIS                (* (reg8 *) Thermistor_5__INP_DIS)
/* LCD Common or Segment Drive */
#define Thermistor_5_LCD_COM_SEG            (* (reg8 *) Thermistor_5__LCD_COM_SEG)
/* Enable Segment LCD */
#define Thermistor_5_LCD_EN                 (* (reg8 *) Thermistor_5__LCD_EN)
/* Slew Rate Control */
#define Thermistor_5_SLW                    (* (reg8 *) Thermistor_5__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Thermistor_5_PRTDSI__CAPS_SEL       (* (reg8 *) Thermistor_5__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Thermistor_5_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Thermistor_5__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Thermistor_5_PRTDSI__OE_SEL0        (* (reg8 *) Thermistor_5__PRTDSI__OE_SEL0) 
#define Thermistor_5_PRTDSI__OE_SEL1        (* (reg8 *) Thermistor_5__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Thermistor_5_PRTDSI__OUT_SEL0       (* (reg8 *) Thermistor_5__PRTDSI__OUT_SEL0) 
#define Thermistor_5_PRTDSI__OUT_SEL1       (* (reg8 *) Thermistor_5__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Thermistor_5_PRTDSI__SYNC_OUT       (* (reg8 *) Thermistor_5__PRTDSI__SYNC_OUT) 


#if defined(Thermistor_5__INTSTAT)  /* Interrupt Registers */

    #define Thermistor_5_INTSTAT                (* (reg8 *) Thermistor_5__INTSTAT)
    #define Thermistor_5_SNAP                   (* (reg8 *) Thermistor_5__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Thermistor_5_H */


/* [] END OF FILE */
