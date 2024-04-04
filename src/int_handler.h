/*
 * int_handler.h
 *
 *  Created on: 28 May 2022
 *      Author: mohamedelghamrawy
 */

#ifndef SRC_INT_HANDLER_H_
#define SRC_INT_HANDLER_H_

#include <stdint.h>
#include "inc/tm4c1294ncpdt.h" // register name for TIVA macros

/* MACROS */
#define BUFFERLENGTH 16
#define PENDULUMWIDTH 50
/* END MACROS */

void IntPortLHandler(void);
void IntHandlerUART0(void);
void IntHandlerTimer1A(void);
void updatePendulumArray(void);

#endif /* SRC_INT_HANDLER_H_ */
