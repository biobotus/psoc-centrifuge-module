/*******************************************************************************
* File Name: Door_Step_Dist.c  
* Version 3.0
*
*  Description:
*     The Counter component consists of a 8, 16, 24 or 32-bit counter with
*     a selectable period between 2 and 2^Width - 1.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Door_Step_Dist.h"

uint8 Door_Step_Dist_initVar = 0u;


/*******************************************************************************
* Function Name: Door_Step_Dist_Init
********************************************************************************
* Summary:
*     Initialize to the schematic state
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void Door_Step_Dist_Init(void) 
{
        #if (!Door_Step_Dist_UsingFixedFunction && !Door_Step_Dist_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!Door_Step_Dist_UsingFixedFunction && !Door_Step_Dist_ControlRegRemoved) */
        
        #if(!Door_Step_Dist_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 Door_Step_Dist_interruptState;
        #endif /* (!Door_Step_Dist_UsingFixedFunction) */
        
        #if (Door_Step_Dist_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            Door_Step_Dist_CONTROL &= Door_Step_Dist_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                Door_Step_Dist_CONTROL2 &= ((uint8)(~Door_Step_Dist_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                Door_Step_Dist_CONTROL3 &= ((uint8)(~Door_Step_Dist_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (Door_Step_Dist_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                Door_Step_Dist_CONTROL |= Door_Step_Dist_ONESHOT;
            #endif /* (Door_Step_Dist_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            Door_Step_Dist_CONTROL2 |= Door_Step_Dist_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            Door_Step_Dist_RT1 &= ((uint8)(~Door_Step_Dist_RT1_MASK));
            Door_Step_Dist_RT1 |= Door_Step_Dist_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            Door_Step_Dist_RT1 &= ((uint8)(~Door_Step_Dist_SYNCDSI_MASK));
            Door_Step_Dist_RT1 |= Door_Step_Dist_SYNCDSI_EN;

        #else
            #if(!Door_Step_Dist_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = Door_Step_Dist_CONTROL & ((uint8)(~Door_Step_Dist_CTRL_CMPMODE_MASK));
            Door_Step_Dist_CONTROL = ctrl | Door_Step_Dist_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = Door_Step_Dist_CONTROL & ((uint8)(~Door_Step_Dist_CTRL_CAPMODE_MASK));
            
            #if( 0 != Door_Step_Dist_CAPTURE_MODE_CONF)
                Door_Step_Dist_CONTROL = ctrl | Door_Step_Dist_DEFAULT_CAPTURE_MODE;
            #else
                Door_Step_Dist_CONTROL = ctrl;
            #endif /* 0 != Door_Step_Dist_CAPTURE_MODE */ 
            
            #endif /* (!Door_Step_Dist_ControlRegRemoved) */
        #endif /* (Door_Step_Dist_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!Door_Step_Dist_UsingFixedFunction)
            Door_Step_Dist_ClearFIFO();
        #endif /* (!Door_Step_Dist_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        Door_Step_Dist_WritePeriod(Door_Step_Dist_INIT_PERIOD_VALUE);
        #if (!(Door_Step_Dist_UsingFixedFunction && (CY_PSOC5A)))
            Door_Step_Dist_WriteCounter(Door_Step_Dist_INIT_COUNTER_VALUE);
        #endif /* (!(Door_Step_Dist_UsingFixedFunction && (CY_PSOC5A))) */
        Door_Step_Dist_SetInterruptMode(Door_Step_Dist_INIT_INTERRUPTS_MASK);
        
        #if (!Door_Step_Dist_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)Door_Step_Dist_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            Door_Step_Dist_WriteCompare(Door_Step_Dist_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            Door_Step_Dist_interruptState = CyEnterCriticalSection();
            
            Door_Step_Dist_STATUS_AUX_CTRL |= Door_Step_Dist_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(Door_Step_Dist_interruptState);
            
        #endif /* (!Door_Step_Dist_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Door_Step_Dist_Enable
********************************************************************************
* Summary:
*     Enable the Counter
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: 
*   If the Enable mode is set to Hardware only then this function has no effect 
*   on the operation of the counter.
*
*******************************************************************************/
void Door_Step_Dist_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (Door_Step_Dist_UsingFixedFunction)
        Door_Step_Dist_GLOBAL_ENABLE |= Door_Step_Dist_BLOCK_EN_MASK;
        Door_Step_Dist_GLOBAL_STBY_ENABLE |= Door_Step_Dist_BLOCK_STBY_EN_MASK;
    #endif /* (Door_Step_Dist_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!Door_Step_Dist_ControlRegRemoved || Door_Step_Dist_UsingFixedFunction)
        Door_Step_Dist_CONTROL |= Door_Step_Dist_CTRL_ENABLE;                
    #endif /* (!Door_Step_Dist_ControlRegRemoved || Door_Step_Dist_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: Door_Step_Dist_Start
********************************************************************************
* Summary:
*  Enables the counter for operation 
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Global variables:
*  Door_Step_Dist_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void Door_Step_Dist_Start(void) 
{
    if(Door_Step_Dist_initVar == 0u)
    {
        Door_Step_Dist_Init();
        
        Door_Step_Dist_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    Door_Step_Dist_Enable();        
}


/*******************************************************************************
* Function Name: Door_Step_Dist_Stop
********************************************************************************
* Summary:
* Halts the counter, but does not change any modes or disable interrupts.
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: If the Enable mode is set to Hardware only then this function
*               has no effect on the operation of the counter.
*
*******************************************************************************/
void Door_Step_Dist_Stop(void) 
{
    /* Disable Counter */
    #if(!Door_Step_Dist_ControlRegRemoved || Door_Step_Dist_UsingFixedFunction)
        Door_Step_Dist_CONTROL &= ((uint8)(~Door_Step_Dist_CTRL_ENABLE));        
    #endif /* (!Door_Step_Dist_ControlRegRemoved || Door_Step_Dist_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (Door_Step_Dist_UsingFixedFunction)
        Door_Step_Dist_GLOBAL_ENABLE &= ((uint8)(~Door_Step_Dist_BLOCK_EN_MASK));
        Door_Step_Dist_GLOBAL_STBY_ENABLE &= ((uint8)(~Door_Step_Dist_BLOCK_STBY_EN_MASK));
    #endif /* (Door_Step_Dist_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Door_Step_Dist_SetInterruptMode
********************************************************************************
* Summary:
* Configures which interrupt sources are enabled to generate the final interrupt
*
* Parameters:  
*  InterruptsMask: This parameter is an or'd collection of the status bits
*                   which will be allowed to generate the counters interrupt.   
*
* Return: 
*  void
*
*******************************************************************************/
void Door_Step_Dist_SetInterruptMode(uint8 interruptsMask) 
{
    Door_Step_Dist_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: Door_Step_Dist_ReadStatusRegister
********************************************************************************
* Summary:
*   Reads the status register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the status register
*
* Side Effects:
*   Status register bits may be clear on read. 
*
*******************************************************************************/
uint8   Door_Step_Dist_ReadStatusRegister(void) 
{
    return Door_Step_Dist_STATUS;
}


#if(!Door_Step_Dist_ControlRegRemoved)
/*******************************************************************************
* Function Name: Door_Step_Dist_ReadControlRegister
********************************************************************************
* Summary:
*   Reads the control register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
uint8   Door_Step_Dist_ReadControlRegister(void) 
{
    return Door_Step_Dist_CONTROL;
}


/*******************************************************************************
* Function Name: Door_Step_Dist_WriteControlRegister
********************************************************************************
* Summary:
*   Sets the bit-field of the control register.  This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
void    Door_Step_Dist_WriteControlRegister(uint8 control) 
{
    Door_Step_Dist_CONTROL = control;
}

#endif  /* (!Door_Step_Dist_ControlRegRemoved) */


#if (!(Door_Step_Dist_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: Door_Step_Dist_WriteCounter
********************************************************************************
* Summary:
*   This funtion is used to set the counter to a specific value
*
* Parameters:  
*  counter:  New counter value. 
*
* Return: 
*  void 
*
*******************************************************************************/
void Door_Step_Dist_WriteCounter(uint32 counter) \
                                   
{
    #if(Door_Step_Dist_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (Door_Step_Dist_GLOBAL_ENABLE & Door_Step_Dist_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        Door_Step_Dist_GLOBAL_ENABLE |= Door_Step_Dist_BLOCK_EN_MASK;
        CY_SET_REG16(Door_Step_Dist_COUNTER_LSB_PTR, (uint16)counter);
        Door_Step_Dist_GLOBAL_ENABLE &= ((uint8)(~Door_Step_Dist_BLOCK_EN_MASK));
    #else
        CY_SET_REG32(Door_Step_Dist_COUNTER_LSB_PTR, counter);
    #endif /* (Door_Step_Dist_UsingFixedFunction) */
}
#endif /* (!(Door_Step_Dist_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: Door_Step_Dist_ReadCounter
********************************************************************************
* Summary:
* Returns the current value of the counter.  It doesn't matter
* if the counter is enabled or running.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint32) The present value of the counter.
*
*******************************************************************************/
uint32 Door_Step_Dist_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(Door_Step_Dist_UsingFixedFunction)
		(void)CY_GET_REG16(Door_Step_Dist_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(Door_Step_Dist_COUNTER_LSB_PTR_8BIT);
	#endif/* (Door_Step_Dist_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(Door_Step_Dist_UsingFixedFunction)
        return ((uint32)CY_GET_REG16(Door_Step_Dist_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG32(Door_Step_Dist_STATICCOUNT_LSB_PTR));
    #endif /* (Door_Step_Dist_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Door_Step_Dist_ReadCapture
********************************************************************************
* Summary:
*   This function returns the last value captured.
*
* Parameters:  
*  void
*
* Return: 
*  (uint32) Present Capture value.
*
*******************************************************************************/
uint32 Door_Step_Dist_ReadCapture(void) 
{
    #if(Door_Step_Dist_UsingFixedFunction)
        return ((uint32)CY_GET_REG16(Door_Step_Dist_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG32(Door_Step_Dist_STATICCOUNT_LSB_PTR));
    #endif /* (Door_Step_Dist_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Door_Step_Dist_WritePeriod
********************************************************************************
* Summary:
* Changes the period of the counter.  The new period 
* will be loaded the next time terminal count is detected.
*
* Parameters:  
*  period: (uint32) A value of 0 will result in
*         the counter remaining at zero.  
*
* Return: 
*  void
*
*******************************************************************************/
void Door_Step_Dist_WritePeriod(uint32 period) 
{
    #if(Door_Step_Dist_UsingFixedFunction)
        CY_SET_REG16(Door_Step_Dist_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG32(Door_Step_Dist_PERIOD_LSB_PTR, period);
    #endif /* (Door_Step_Dist_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Door_Step_Dist_ReadPeriod
********************************************************************************
* Summary:
* Reads the current period value without affecting counter operation.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint32) Present period value.
*
*******************************************************************************/
uint32 Door_Step_Dist_ReadPeriod(void) 
{
    #if(Door_Step_Dist_UsingFixedFunction)
        return ((uint32)CY_GET_REG16(Door_Step_Dist_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG32(Door_Step_Dist_PERIOD_LSB_PTR));
    #endif /* (Door_Step_Dist_UsingFixedFunction) */
}


#if (!Door_Step_Dist_UsingFixedFunction)
/*******************************************************************************
* Function Name: Door_Step_Dist_WriteCompare
********************************************************************************
* Summary:
* Changes the compare value.  The compare output will 
* reflect the new value on the next UDB clock.  The compare output will be 
* driven high when the present counter value compares true based on the 
* configured compare mode setting. 
*
* Parameters:  
*  Compare:  New compare value. 
*
* Return: 
*  void
*
*******************************************************************************/
void Door_Step_Dist_WriteCompare(uint32 compare) \
                                   
{
    #if(Door_Step_Dist_UsingFixedFunction)
        CY_SET_REG16(Door_Step_Dist_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG32(Door_Step_Dist_COMPARE_LSB_PTR, compare);
    #endif /* (Door_Step_Dist_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Door_Step_Dist_ReadCompare
********************************************************************************
* Summary:
* Returns the compare value.
*
* Parameters:  
*  void:
*
* Return: 
*  (uint32) Present compare value.
*
*******************************************************************************/
uint32 Door_Step_Dist_ReadCompare(void) 
{
    return (CY_GET_REG32(Door_Step_Dist_COMPARE_LSB_PTR));
}


#if (Door_Step_Dist_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: Door_Step_Dist_SetCompareMode
********************************************************************************
* Summary:
*  Sets the software controlled Compare Mode.
*
* Parameters:
*  compareMode:  Compare Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void Door_Step_Dist_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    Door_Step_Dist_CONTROL &= ((uint8)(~Door_Step_Dist_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    Door_Step_Dist_CONTROL |= compareMode;
}
#endif  /* (Door_Step_Dist_COMPARE_MODE_SOFTWARE) */


#if (Door_Step_Dist_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: Door_Step_Dist_SetCaptureMode
********************************************************************************
* Summary:
*  Sets the software controlled Capture Mode.
*
* Parameters:
*  captureMode:  Capture Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void Door_Step_Dist_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    Door_Step_Dist_CONTROL &= ((uint8)(~Door_Step_Dist_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    Door_Step_Dist_CONTROL |= ((uint8)((uint8)captureMode << Door_Step_Dist_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (Door_Step_Dist_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: Door_Step_Dist_ClearFIFO
********************************************************************************
* Summary:
*   This function clears all capture data from the capture FIFO
*
* Parameters:  
*  void:
*
* Return: 
*  None
*
*******************************************************************************/
void Door_Step_Dist_ClearFIFO(void) 
{

    while(0u != (Door_Step_Dist_ReadStatusRegister() & Door_Step_Dist_STATUS_FIFONEMP))
    {
        (void)Door_Step_Dist_ReadCapture();
    }

}
#endif  /* (!Door_Step_Dist_UsingFixedFunction) */


/* [] END OF FILE */

