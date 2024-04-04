/**
 * HAW Hamburg
 * IE4-MC: Microcontrollers
 * Lab Project
 *
 * TODOs Backlog:
 * TODO Update UART FIFO Interrupt level
 * TODO Interrupt priorities (done, test?)
 * TODO Debug timer interrupt configuration (Match and Interval load values)
 *
 * Date:
 * Authors: Mostafa Salman, Mohamed ElGhamrawy, Kieran Edgeworth
 * */

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h> // required for printf
#include "inc/tm4c1294ncpdt.h" // register name for TIVA macros
#include "inc/hw_types.h" // required for sysctl.h
#include "driverlib/sysctl.h" // required for SysCtlClockFreqSet

/* INCLUDES */
#include "src/config.h"
/* END INCLUDES */

/* MAIN FUNCTION */
void main(void) {
    configSys();
    configPortA();
    configPortL();
    configPortM();
    configUart0();
    configTimer1A();

    while (1) {}
}
/* END MAIN FUNCTION */

