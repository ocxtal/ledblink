/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "CyLib.h"
#include "`$INSTANCE_NAME`_LED_Blinker.h"

/**
 * (global) pattern container
*/
uint16 `$INSTANCE_NAME`_pattern;
uint8 `$INSTANCE_NAME`_period;

void `$INSTANCE_NAME`_Start(void)
{
	/* enable counter */
	uint8 enableInterrupts = 0u;    
	enableInterrupts = CyEnterCriticalSection();
	`$INSTANCE_NAME`_CNT4_CONTROL_REG |= `$INSTANCE_NAME`_CNTR_ENABLE;
	CyExitCriticalSection(enableInterrupts);

	/* clear pattern */
	`$INSTANCE_NAME`_SetPeriod(20);
	`$INSTANCE_NAME`_SetPattern(0xffff);
	return;
}

void `$INSTANCE_NAME`_SetPeriod(uint8 period)
{
	if(period > 127) { period = 127; }
	`$INSTANCE_NAME`_period = period;
	`$INSTANCE_NAME`_CNT4_PERIOD_REG = period;
	return;
}

uint8 `$INSTANCE_NAME`_GetPeriod(void)
{
	return(`$INSTANCE_NAME`_period);
}

void `$INSTANCE_NAME`_SetPattern(uint16 pattern)
{
	uint8 i;
	uint8 d0 = 0, d1 = 0;
	`$INSTANCE_NAME`_pattern = pattern;
	
	for(i = 0; i < 8; i++) {
		d0 = (d0<<1) | (pattern & 0x01); pattern >>= 1;
		d1 = (d1<<1) | (pattern & 0x01); pattern >>= 1;
	}
	`$INSTANCE_NAME`_D0_REG = ~d0;
	`$INSTANCE_NAME`_D1_REG = ~d1;
	return;
}

uint16 `$INSTANCE_NAME`_GetPattern(void)
{
	return(`$INSTANCE_NAME`_pattern);
}

void `$INSTANCE_NAME`_Stop(void)
{
	/* nothing to do */
	return;
}
/* [] END OF FILE */
