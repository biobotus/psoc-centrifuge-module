/*******************************************************************************
* File Name: Door_CurrentRef.h  
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

#if !defined(CY_PINS_Door_CurrentRef_H) /* Pins Door_CurrentRef_H */
#define CY_PINS_Door_CurrentRef_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Door_CurrentRef_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Door_CurrentRef__PORT == 15 && ((Door_CurrentRef__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Door_CurrentRef_Write(uint8 value) ;
void    Door_CurrentRef_SetDriveMode(uint8 mode) ;
uint8   Door_CurrentRef_ReadDataReg(void) ;
uint8   Door_CurrentRef_Read(void) ;
uint8   Door_CurrentRef_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Door_CurrentRef_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Door_CurrentRef_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Door_CurrentRef_DM_RES_UP          PIN_DM_RES_UP
#define Door_CurrentRef_DM_RES_DWN         PIN_DM_RES_DWN
#define Door_CurrentRef_DM_OD_LO           PIN_DM_OD_LO
#define Door_CurrentRef_DM_OD_HI           PIN_DM_OD_HI
#define Door_CurrentRef_DM_STRONG          PIN_DM_STRONG
#define Door_CurrentRef_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Door_CurrentRef_MASK               Door_CurrentRef__MASK
#define Door_CurrentRef_SHIFT              Door_CurrentRef__SHIFT
#define Door_CurrentRef_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Door_CurrentRef_PS                     (* (reg8 *) Door_CurrentRef__PS)
/* Data Register */
#define Door_CurrentRef_DR                     (* (reg8 *) Door_CurrentRef__DR)
/* Port Number */
#define Door_CurrentRef_PRT_NUM                (* (reg8 *) Door_CurrentRef__PRT) 
/* Connect to Analog Globals */                                                  
#define Door_CurrentRef_AG                     (* (reg8 *) Door_CurrentRef__AG)                       
/* Analog MUX bux enable */
#define Door_CurrentRef_AMUX                   (* (reg8 *) Door_CurrentRef__AMUX) 
/* Bidirectional Enable */                                                        
#define Door_CurrentRef_BIE                    (* (reg8 *) Door_CurrentRef__BIE)
/* Bit-mask for Aliased Register Access */
#define Door_CurrentRef_BIT_MASK               (* (reg8 *) Door_CurrentRef__BIT_MASK)
/* Bypass Enable */
#define Door_CurrentRef_BYP                    (* (reg8 *) Door_CurrentRef__BYP)
/* Port wide control signals */                                                   
#define Door_CurrentRef_CTL                    (* (reg8 *) Door_CurrentRef__CTL)
/* Drive Modes */
#define Door_CurrentRef_DM0                    (* (reg8 *) Door_CurrentRef__DM0) 
#define Door_CurrentRef_DM1                    (* (reg8 *) Door_CurrentRef__DM1)
#define Door_CurrentRef_DM2                    (* (reg8 *) Door_CurrentRef__DM2) 
/* Input Buffer Disable Override */
#define Door_CurrentRef_INP_DIS                (* (reg8 *) Door_CurrentRef__INP_DIS)
/* LCD Common or Segment Drive */
#define Door_CurrentRef_LCD_COM_SEG            (* (reg8 *) Door_CurrentRef__LCD_COM_SEG)
/* Enable Segment LCD */
#define Door_CurrentRef_LCD_EN                 (* (reg8 *) Door_CurrentRef__LCD_EN)
/* Slew Rate Control */
#define Door_CurrentRef_SLW                    (* (reg8 *) Door_CurrentRef__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Door_CurrentRef_PRTDSI__CAPS_SEL       (* (reg8 *) Door_CurrentRef__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Door_CurrentRef_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Door_CurrentRef__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Door_CurrentRef_PRTDSI__OE_SEL0        (* (reg8 *) Door_CurrentRef__PRTDSI__OE_SEL0) 
#define Door_CurrentRef_PRTDSI__OE_SEL1        (* (reg8 *) Door_CurrentRef__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Door_CurrentRef_PRTDSI__OUT_SEL0       (* (reg8 *) Door_CurrentRef__PRTDSI__OUT_SEL0) 
#define Door_CurrentRef_PRTDSI__OUT_SEL1       (* (reg8 *) Door_CurrentRef__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Door_CurrentRef_PRTDSI__SYNC_OUT       (* (reg8 *) Door_CurrentRef__PRTDSI__SYNC_OUT) 


#if defined(Door_CurrentRef__INTSTAT)  /* Interrupt Registers */

    #define Door_CurrentRef_INTSTAT                (* (reg8 *) Door_CurrentRef__INTSTAT)
    #define Door_CurrentRef_SNAP                   (* (reg8 *) Door_CurrentRef__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Door_CurrentRef_H */


/* [] END OF FILE */
