/*******************************************************************************
* File Name: Stepper1_MS2.h  
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

#if !defined(CY_PINS_Stepper1_MS2_H) /* Pins Stepper1_MS2_H */
#define CY_PINS_Stepper1_MS2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Stepper1_MS2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Stepper1_MS2__PORT == 15 && ((Stepper1_MS2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Stepper1_MS2_Write(uint8 value) ;
void    Stepper1_MS2_SetDriveMode(uint8 mode) ;
uint8   Stepper1_MS2_ReadDataReg(void) ;
uint8   Stepper1_MS2_Read(void) ;
uint8   Stepper1_MS2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Stepper1_MS2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Stepper1_MS2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Stepper1_MS2_DM_RES_UP          PIN_DM_RES_UP
#define Stepper1_MS2_DM_RES_DWN         PIN_DM_RES_DWN
#define Stepper1_MS2_DM_OD_LO           PIN_DM_OD_LO
#define Stepper1_MS2_DM_OD_HI           PIN_DM_OD_HI
#define Stepper1_MS2_DM_STRONG          PIN_DM_STRONG
#define Stepper1_MS2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Stepper1_MS2_MASK               Stepper1_MS2__MASK
#define Stepper1_MS2_SHIFT              Stepper1_MS2__SHIFT
#define Stepper1_MS2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Stepper1_MS2_PS                     (* (reg8 *) Stepper1_MS2__PS)
/* Data Register */
#define Stepper1_MS2_DR                     (* (reg8 *) Stepper1_MS2__DR)
/* Port Number */
#define Stepper1_MS2_PRT_NUM                (* (reg8 *) Stepper1_MS2__PRT) 
/* Connect to Analog Globals */                                                  
#define Stepper1_MS2_AG                     (* (reg8 *) Stepper1_MS2__AG)                       
/* Analog MUX bux enable */
#define Stepper1_MS2_AMUX                   (* (reg8 *) Stepper1_MS2__AMUX) 
/* Bidirectional Enable */                                                        
#define Stepper1_MS2_BIE                    (* (reg8 *) Stepper1_MS2__BIE)
/* Bit-mask for Aliased Register Access */
#define Stepper1_MS2_BIT_MASK               (* (reg8 *) Stepper1_MS2__BIT_MASK)
/* Bypass Enable */
#define Stepper1_MS2_BYP                    (* (reg8 *) Stepper1_MS2__BYP)
/* Port wide control signals */                                                   
#define Stepper1_MS2_CTL                    (* (reg8 *) Stepper1_MS2__CTL)
/* Drive Modes */
#define Stepper1_MS2_DM0                    (* (reg8 *) Stepper1_MS2__DM0) 
#define Stepper1_MS2_DM1                    (* (reg8 *) Stepper1_MS2__DM1)
#define Stepper1_MS2_DM2                    (* (reg8 *) Stepper1_MS2__DM2) 
/* Input Buffer Disable Override */
#define Stepper1_MS2_INP_DIS                (* (reg8 *) Stepper1_MS2__INP_DIS)
/* LCD Common or Segment Drive */
#define Stepper1_MS2_LCD_COM_SEG            (* (reg8 *) Stepper1_MS2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Stepper1_MS2_LCD_EN                 (* (reg8 *) Stepper1_MS2__LCD_EN)
/* Slew Rate Control */
#define Stepper1_MS2_SLW                    (* (reg8 *) Stepper1_MS2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Stepper1_MS2_PRTDSI__CAPS_SEL       (* (reg8 *) Stepper1_MS2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Stepper1_MS2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Stepper1_MS2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Stepper1_MS2_PRTDSI__OE_SEL0        (* (reg8 *) Stepper1_MS2__PRTDSI__OE_SEL0) 
#define Stepper1_MS2_PRTDSI__OE_SEL1        (* (reg8 *) Stepper1_MS2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Stepper1_MS2_PRTDSI__OUT_SEL0       (* (reg8 *) Stepper1_MS2__PRTDSI__OUT_SEL0) 
#define Stepper1_MS2_PRTDSI__OUT_SEL1       (* (reg8 *) Stepper1_MS2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Stepper1_MS2_PRTDSI__SYNC_OUT       (* (reg8 *) Stepper1_MS2__PRTDSI__SYNC_OUT) 


#if defined(Stepper1_MS2__INTSTAT)  /* Interrupt Registers */

    #define Stepper1_MS2_INTSTAT                (* (reg8 *) Stepper1_MS2__INTSTAT)
    #define Stepper1_MS2_SNAP                   (* (reg8 *) Stepper1_MS2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Stepper1_MS2_H */


/* [] END OF FILE */
