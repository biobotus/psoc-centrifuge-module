/*******************************************************************************
* File Name: RotarySensor_Step.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "RotarySensor_Step.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 RotarySensor_Step__PORT == 15 && ((RotarySensor_Step__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: RotarySensor_Step_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void RotarySensor_Step_Write(uint8 value) 
{
    uint8 staticBits = (RotarySensor_Step_DR & (uint8)(~RotarySensor_Step_MASK));
    RotarySensor_Step_DR = staticBits | ((uint8)(value << RotarySensor_Step_SHIFT) & RotarySensor_Step_MASK);
}


/*******************************************************************************
* Function Name: RotarySensor_Step_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  RotarySensor_Step_DM_STRONG     Strong Drive 
*  RotarySensor_Step_DM_OD_HI      Open Drain, Drives High 
*  RotarySensor_Step_DM_OD_LO      Open Drain, Drives Low 
*  RotarySensor_Step_DM_RES_UP     Resistive Pull Up 
*  RotarySensor_Step_DM_RES_DWN    Resistive Pull Down 
*  RotarySensor_Step_DM_RES_UPDWN  Resistive Pull Up/Down 
*  RotarySensor_Step_DM_DIG_HIZ    High Impedance Digital 
*  RotarySensor_Step_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void RotarySensor_Step_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(RotarySensor_Step_0, mode);
}


/*******************************************************************************
* Function Name: RotarySensor_Step_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro RotarySensor_Step_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 RotarySensor_Step_Read(void) 
{
    return (RotarySensor_Step_PS & RotarySensor_Step_MASK) >> RotarySensor_Step_SHIFT;
}


/*******************************************************************************
* Function Name: RotarySensor_Step_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 RotarySensor_Step_ReadDataReg(void) 
{
    return (RotarySensor_Step_DR & RotarySensor_Step_MASK) >> RotarySensor_Step_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(RotarySensor_Step_INTSTAT) 

    /*******************************************************************************
    * Function Name: RotarySensor_Step_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 RotarySensor_Step_ClearInterrupt(void) 
    {
        return (RotarySensor_Step_INTSTAT & RotarySensor_Step_MASK) >> RotarySensor_Step_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
