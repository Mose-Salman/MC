/*
 * config.h
 *
 *  Created on: 29 May 2022
 *      Author: mohamedelghamrawy
 */

#ifndef SRC_CONFIG_H_
#define SRC_CONFIG_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h> // required for printf
#include "inc/tm4c1294ncpdt.h" // register name for TIVA macros
#include "inc/hw_types.h" // required for sysctl.h
#include "driverlib/sysctl.h" // required for SysCtlClockFreqSet

/* MACROS */
#define SYS_FREQUENCY 120000000
/* END MACROS */

/* FUNCTION PROTOTYPES */
void configSys(void);
void configPortA(void);
void configPortL(void);
void configPortM(void);
void configUart0(void);
void configTimer1A(void);
/* END FUNCTION PROTOTYPES */

#endif /* SRC_CONFIG_H_ */
