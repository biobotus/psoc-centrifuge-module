/*******************************************************************************
* File Name: HB2_En.h  
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

#if !defined(CY_PINS_HB2_En_H) /* Pins HB2_En_H */
#define CY_PINS_HB2_En_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HB2_En_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 HB2_En__PORT == 15 && ((HB2_En__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    HB2_En_Write(uint8 value) ;
void    HB2_En_SetDriveMode(uint8 mode) ;
uint8   HB2_En_ReadDataReg(void) ;
uint8   HB2_En_Read(void) ;
uint8   HB2_En_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define HB2_En_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define HB2_En_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define HB2_En_DM_RES_UP          PIN_DM_RES_UP
#define HB2_En_DM_RES_DWN         PIN_DM_RES_DWN
#define HB2_En_DM_OD_LO           PIN_DM_OD_LO
#define HB2_En_DM_OD_HI           PIN_DM_OD_HI
#define HB2_En_DM_STRONG          PIN_DM_STRONG
#define HB2_En_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define HB2_En_MASK               HB2_En__MASK
#define HB2_En_SHIFT              HB2_En__SHIFT
#define HB2_En_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HB2_En_PS                     (* (reg8 *) HB2_En__PS)
/* Data Register */
#define HB2_En_DR                     (* (reg8 *) HB2_En__DR)
/* Port Number */
#define HB2_En_PRT_NUM                (* (reg8 *) HB2_En__PRT) 
/* Connect to Analog Globals */                                                  
#define HB2_En_AG                     (* (reg8 *) HB2_En__AG)                       
/* Analog MUX bux enable */
#define HB2_En_AMUX                   (* (reg8 *) HB2_En__AMUX) 
/* Bidirectional Enable */                                                        
#define HB2_En_BIE                    (* (reg8 *) HB2_En__BIE)
/* Bit-mask for Aliased Register Access */
#define HB2_En_BIT_MASK               (* (reg8 *) HB2_En__BIT_MASK)
/* Bypass Enable */
#define HB2_En_BYP                    (* (reg8 *) HB2_En__BYP)
/* Port wide control signals */                                                   
#define HB2_En_CTL                    (* (reg8 *) HB2_En__CTL)
/* Drive Modes */
#define HB2_En_DM0                    (* (reg8 *) HB2_En__DM0) 
#define HB2_En_DM1                    (* (reg8 *) HB2_En__DM1)
#define HB2_En_DM2                    (* (reg8 *) HB2_En__DM2) 
/* Input Buffer Disable Override */
#define HB2_En_INP_DIS                (* (reg8 *) HB2_En__INP_DIS)
/* LCD Common or Segment Drive */
#define HB2_En_LCD_COM_SEG            (* (reg8 *) HB2_En__LCD_COM_SEG)
/* Enable Segment LCD */
#define HB2_En_LCD_EN                 (* (reg8 *) HB2_En__LCD_EN)
/* Slew Rate Control */
#define HB2_En_SLW                    (* (reg8 *) HB2_En__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HB2_En_PRTDSI__CAPS_SEL       (* (reg8 *) HB2_En__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HB2_En_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HB2_En__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HB2_En_PRTDSI__OE_SEL0        (* (reg8 *) HB2_En__PRTDSI__OE_SEL0) 
#define HB2_En_PRTDSI__OE_SEL1        (* (reg8 *) HB2_En__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HB2_En_PRTDSI__OUT_SEL0       (* (reg8 *) HB2_En__PRTDSI__OUT_SEL0) 
#define HB2_En_PRTDSI__OUT_SEL1       (* (reg8 *) HB2_En__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HB2_En_PRTDSI__SYNC_OUT       (* (reg8 *) HB2_En__PRTDSI__SYNC_OUT) 


#if defined(HB2_En__INTSTAT)  /* Interrupt Registers */

    #define HB2_En_INTSTAT                (* (reg8 *) HB2_En__INTSTAT)
    #define HB2_En_SNAP                   (* (reg8 *) HB2_En__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_HB2_En_H */


/* [] END OF FILE */
