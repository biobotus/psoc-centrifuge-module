/*******************************************************************************
* File Name: SSI_Enable.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_SSI_Enable_H) /* CY_CONTROL_REG_SSI_Enable_H */
#define CY_CONTROL_REG_SSI_Enable_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} SSI_Enable_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    SSI_Enable_Write(uint8 control) ;
uint8   SSI_Enable_Read(void) ;

void SSI_Enable_SaveConfig(void) ;
void SSI_Enable_RestoreConfig(void) ;
void SSI_Enable_Sleep(void) ; 
void SSI_Enable_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define SSI_Enable_Control        (* (reg8 *) SSI_Enable_Sync_ctrl_reg__CONTROL_REG )
#define SSI_Enable_Control_PTR    (  (reg8 *) SSI_Enable_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_SSI_Enable_H */


/* [] END OF FILE */
