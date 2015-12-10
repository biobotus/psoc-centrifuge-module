/*******************************************************************************
* File Name: Pin_Stepper1_Dir.h  
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

#if !defined(CY_PINS_Pin_Stepper1_Dir_H) /* Pins Pin_Stepper1_Dir_H */
#define CY_PINS_Pin_Stepper1_Dir_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pin_Stepper1_Dir_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pin_Stepper1_Dir__PORT == 15 && ((Pin_Stepper1_Dir__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Pin_Stepper1_Dir_Write(uint8 value) ;
void    Pin_Stepper1_Dir_SetDriveMode(uint8 mode) ;
uint8   Pin_Stepper1_Dir_ReadDataReg(void) ;
uint8   Pin_Stepper1_Dir_Read(void) ;
uint8   Pin_Stepper1_Dir_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pin_Stepper1_Dir_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Pin_Stepper1_Dir_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Pin_Stepper1_Dir_DM_RES_UP          PIN_DM_RES_UP
#define Pin_Stepper1_Dir_DM_RES_DWN         PIN_DM_RES_DWN
#define Pin_Stepper1_Dir_DM_OD_LO           PIN_DM_OD_LO
#define Pin_Stepper1_Dir_DM_OD_HI           PIN_DM_OD_HI
#define Pin_Stepper1_Dir_DM_STRONG          PIN_DM_STRONG
#define Pin_Stepper1_Dir_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Pin_Stepper1_Dir_MASK               Pin_Stepper1_Dir__MASK
#define Pin_Stepper1_Dir_SHIFT              Pin_Stepper1_Dir__SHIFT
#define Pin_Stepper1_Dir_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_Stepper1_Dir_PS                     (* (reg8 *) Pin_Stepper1_Dir__PS)
/* Data Register */
#define Pin_Stepper1_Dir_DR                     (* (reg8 *) Pin_Stepper1_Dir__DR)
/* Port Number */
#define Pin_Stepper1_Dir_PRT_NUM                (* (reg8 *) Pin_Stepper1_Dir__PRT) 
/* Connect to Analog Globals */                                                  
#define Pin_Stepper1_Dir_AG                     (* (reg8 *) Pin_Stepper1_Dir__AG)                       
/* Analog MUX bux enable */
#define Pin_Stepper1_Dir_AMUX                   (* (reg8 *) Pin_Stepper1_Dir__AMUX) 
/* Bidirectional Enable */                                                        
#define Pin_Stepper1_Dir_BIE                    (* (reg8 *) Pin_Stepper1_Dir__BIE)
/* Bit-mask for Aliased Register Access */
#define Pin_Stepper1_Dir_BIT_MASK               (* (reg8 *) Pin_Stepper1_Dir__BIT_MASK)
/* Bypass Enable */
#define Pin_Stepper1_Dir_BYP                    (* (reg8 *) Pin_Stepper1_Dir__BYP)
/* Port wide control signals */                                                   
#define Pin_Stepper1_Dir_CTL                    (* (reg8 *) Pin_Stepper1_Dir__CTL)
/* Drive Modes */
#define Pin_Stepper1_Dir_DM0                    (* (reg8 *) Pin_Stepper1_Dir__DM0) 
#define Pin_Stepper1_Dir_DM1                    (* (reg8 *) Pin_Stepper1_Dir__DM1)
#define Pin_Stepper1_Dir_DM2                    (* (reg8 *) Pin_Stepper1_Dir__DM2) 
/* Input Buffer Disable Override */
#define Pin_Stepper1_Dir_INP_DIS                (* (reg8 *) Pin_Stepper1_Dir__INP_DIS)
/* LCD Common or Segment Drive */
#define Pin_Stepper1_Dir_LCD_COM_SEG            (* (reg8 *) Pin_Stepper1_Dir__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pin_Stepper1_Dir_LCD_EN                 (* (reg8 *) Pin_Stepper1_Dir__LCD_EN)
/* Slew Rate Control */
#define Pin_Stepper1_Dir_SLW                    (* (reg8 *) Pin_Stepper1_Dir__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pin_Stepper1_Dir_PRTDSI__CAPS_SEL       (* (reg8 *) Pin_Stepper1_Dir__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pin_Stepper1_Dir_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pin_Stepper1_Dir__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pin_Stepper1_Dir_PRTDSI__OE_SEL0        (* (reg8 *) Pin_Stepper1_Dir__PRTDSI__OE_SEL0) 
#define Pin_Stepper1_Dir_PRTDSI__OE_SEL1        (* (reg8 *) Pin_Stepper1_Dir__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pin_Stepper1_Dir_PRTDSI__OUT_SEL0       (* (reg8 *) Pin_Stepper1_Dir__PRTDSI__OUT_SEL0) 
#define Pin_Stepper1_Dir_PRTDSI__OUT_SEL1       (* (reg8 *) Pin_Stepper1_Dir__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pin_Stepper1_Dir_PRTDSI__SYNC_OUT       (* (reg8 *) Pin_Stepper1_Dir__PRTDSI__SYNC_OUT) 


#if defined(Pin_Stepper1_Dir__INTSTAT)  /* Interrupt Registers */

    #define Pin_Stepper1_Dir_INTSTAT                (* (reg8 *) Pin_Stepper1_Dir__INTSTAT)
    #define Pin_Stepper1_Dir_SNAP                   (* (reg8 *) Pin_Stepper1_Dir__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pin_Stepper1_Dir_H */


/* [] END OF FILE */
