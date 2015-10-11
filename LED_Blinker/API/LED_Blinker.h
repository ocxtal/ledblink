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
#ifndef `$INSTANCE_NAME`_H_INCLUDED
#define `$INSTANCE_NAME`_H_INCLUDED

#include <cytypes.h>
#include <cyfitter.h>

/* constants */
#define `$INSTANCE_NAME`_CNTR_ENABLE			(0x20u)   

/* registers */
#define `$INSTANCE_NAME`_D0_REG					(* (reg8 *) `$INSTANCE_NAME`_dp_u0__D0_REG )
#define `$INSTANCE_NAME`_D1_REG					(* (reg8 *) `$INSTANCE_NAME`_dp_u0__D1_REG )
#define `$INSTANCE_NAME`_CNT4_CONTROL_REG 		(* (reg8 *) `$INSTANCE_NAME`_cnt4__CONTROL_AUX_CTL_REG )
#define `$INSTANCE_NAME`_CNT4_PERIOD_REG 		(* (reg8 *) `$INSTANCE_NAME`_cnt4__PERIOD_REG )

/* functions */
void `$INSTANCE_NAME`_Start(void);
void `$INSTANCE_NAME`_SetPeriod(uint8 period);
uint8 `$INSTANCE_NAME`_GetPeriod(void);
void `$INSTANCE_NAME`_SetPattern(uint16 pattern);
uint16 `$INSTANCE_NAME`_GetPattern(void);
void `$INSTANCE_NAME`_Stop(void);

/* macros */
#define `$INSTANCE_NAME`_REPEAT(n)				( 0x5555>>(16-((n)<<1)) )

#endif
/* [] END OF FILE */
