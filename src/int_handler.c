#include "int_handler.h"
#include "src/bitmaps.h"

/* GLOBAL VARIABLES */
// TODO update and document interrupt priorities
unsigned char cmdLineUart[BUFFERLENGTH]; // command received via UART (updated by UART Interrupt)
unsigned int pendulumArray[100]; // array to be displayed by pendulum
unsigned int pendulumArrayCursor = 0; // position of pendulum array cursor (updated by Timer 0A Interrupt)
int pendulumDirection = 0; // direction of pendulum (updated by GPIO Port L Interrupt)
/* END GLOBAL VARIABLES */
int timerInterrupts = 0; // TODO delete after debugging

/**
 * Interrupt Handler for IRQ 53, vector 69
 *
 * A function to set the oscillation direction - left turning
 * point at falling edge and right turning point at raising edge.
 *
 * */
void IntPortLHandler(void) {
    if((GPIO_PORTL_DATA_R & 0x01) == 0x00) {
        // detect left turning point
        pendulumDirection = 1;
        pendulumArrayCursor =0;


    }
    else {
        // detect right turning point
        pendulumDirection = -1;
    }
}

void IntHandlerUART0(void) {
    //check for UART2 Rx interrupt
    if (UART0_MIS_R & (1 << 4)) {
        UART0_ICR_R |= (1 << 4); //clear interrupt
        int i = 0;

        // clear remaining cmdLineUart array
        for(i = 0; i < BUFFERLENGTH; i++) {
            cmdLineUart[i] = 0x00;
        }
        i = 0;

        // while Rx FIFO is not empty, read chars from FIFO
        while (!(UART0_FR_R & (1 << 4))){
            cmdLineUart[i] = (char) (UART0_DR_R & 0xFF); //read data from uart0 data register
            if (cmdLineUart[i] == 0x0D || cmdLineUart[i] == 0x0A) {
                cmdLineUart[i] = 0x00;
            }
            i++;
        }
        updatePendulumArray();
    }
}

void IntHandlerTimer1A(void) {
    TIMER1_ICR_R |= (1 << 4); //clear interrupt

    if (pendulumDirection){
    pendulumArrayCursor ++;
    GPIO_PORTM_DATA_R = pendulumArray[pendulumArrayCursor];
    // timerInterrupts++;
    }
}

/**
 * A helper function for IntHandlerUART0 to update pendulumArray
 * to match the UART input.
 * */
void updatePendulumArray(void) {
    int cursor = 20;

    // loop through cmdLineUart array elements
    int i; for(i = 0; i < 8; i++) {
        char pendulumChar = cmdLineUart[i];
        int j; for(j = 0; j < 8; j++) {
            pendulumArray[cursor] = bitmaps[pendulumChar][j];
            cursor++;
        }
        cursor ++; // space between character
    }

    int ecursor; for(ecursor = cursor; ecursor < PENDULUMWIDTH; ecursor++) {
        pendulumArray[ecursor] = 0x00;
    }
}
