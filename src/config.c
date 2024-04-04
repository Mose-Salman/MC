#include "config.h"

/**
 * Configure system clock to 120MHz and set interrupt priorities.
 *
 * */
void configSys(void) {
    // Set system clock frequency to 120MHz
    SysCtlClockFreqSet(SYSCTL_XTAL_25MHZ |
                       SYSCTL_OSC_MAIN |
                       SYSCTL_USE_PLL |
                       SYSCTL_CFG_VCO_480,
                       SYS_FREQUENCY);

    NVIC_PRI13_R = 0x00; // set GPIO interrupt priority to 0
    NVIC_PRI5_R = 0x00; //0x2000; // set Timer 1A interrupt priority to 1
    NVIC_PRI5_R = 0xE0; // set UART interrupt priority to 7

}

/**
 * Configure PA(1:0) for UART (alternate function)
 *
 * */
void configPortA(void) {
    // initialize Port A
    SYSCTL_RCGCGPIO_R |= (1 << 0); // switch on clock for Port A
    while ((SYSCTL_PRGPIO_R & (1 << 0)) == 0); // wait for stable clock
    GPIO_PORTA_AHB_DEN_R |= 0x03; // digital I/O enable for pin PA(1:0)
    GPIO_PORTA_AHB_AFSEL_R |= 0x03; // PA(1:0) set to alternate func
    GPIO_PORTA_AHB_PCTL_R |= 0x00000011; // alternate func is U0Rx+Tx
}

void configUart0(void) {
    // initialize UART0
    SYSCTL_RCGCUART_R |= (1 << 0); // switch on clock for UART0
    while ((SYSCTL_PRUART_R & (1 << 0)) == 0); // wait for stable clock

    UART0_CTL_R &= ~(1 << 0); // disable UART0 for config
    // initialize bitrate of 9600 bit per second
    UART0_IBRD_R = 781; // set DIVINT of BRD floor(120MHz/16/9600Hz)
    UART0_FBRD_R = 10; // set DIVFRAC of BRD
    UART0_LCRH_R = 0x00000050; // serial format 7N1 & UART Enable FIFOs
    UART0_CTL_R |= 0x0301; // re-enable UART0

    //interrupt config uart0 RX interrupt
    UART0_ICR_R = 0xE7FF; //clear all interrupts
    UART0_IM_R = (1 << 4); // | (1 << 5);  //set UART0 Rx interrupt
    NVIC_EN0_R |= 1 << 5; //enable UART0 interrupt in NVIC IRQ #5

}

void configPortL(void){
    SYSCTL_RCGCGPIO_R |= 0x00000700 ; // =>0000 0100 0000 0000 Enable and provide a clock to GPIO Port M & L in Run mode
    while(!(SYSCTL_PRGPIO_R & 0x00000700));// Wait until GPIO Port M Peripheral Ready, i.e. i++;
    GPIO_PORTL_DEN_R |= 0x0001; // enable pin 0
    GPIO_PORTL_DIR_R &= ~0x01 ; // PortL(0) input

    GPIO_PORTL_IS_R &= ~0x01; // sense to "edge-sensitive"
    GPIO_PORTL_IBE_R &= ~0x01; // trigger set to "single edge"
    GPIO_PORTL_IEV_R |= 0x01; // interrupt event to rising edge
    GPIO_PORTL_ICR_R |= 0x01; // clear interrupt PORTL(0)
    GPIO_PORTL_IM_R |= 0x01; // unmask PORTL(0) = S1
    NVIC_EN1_R |= (1<<21); // enable PortL interrupt (Int#53/Vec#69) in NVIC
}

void configPortM(void){
    SYSCTL_RCGCGPIO_R |= 0x00000800 ; // =>0000 1000 0000 0000 Enable and provide a clock to GPIO Port M & L in Run mode
    while(!(SYSCTL_PRGPIO_R & 0x00000800));// Wait until GPIO Port M Peripheral Ready, i.e. i++;
    GPIO_PORTM_DEN_R = 0xFF; // => Enable GPIO Port M pins 0 to  7
    GPIO_PORTM_DIR_R = 0xFF; // => Set GPIO Port M pins 0 to 7 to Output
}
/**
 * Configure timer 1A interrupt periodic every
 * 0.6ms.
 * */
void configTimer1A(void) {
    SYSCTL_RCGCTIMER_R |= (1 << 1); // clock timer 1
    while (!(SYSCTL_PRTIMER_R & 0x02)); // wait for timer to be ready

    TIMER1_CTL_R &= ~0x0001; // disable timer 1
    TIMER1_CFG_R = 0x04; // 16 bit mode chosen
    TIMER1_TAMR_R = 0x32; // match enabled, count up, periodic.
    TIMER1_TAPR_R = 2 - 1; // pre-scalar // TODO check for bugs
    TIMER1_TAILR_R = 0; // interval load value
    TIMER1_TAMATCHR_R = 36000 - 1; // match value
    TIMER1_CTL_R |= 0x0001; //enable timer 1

    //setting up timer interrupt
    TIMER1_ICR_R = 0x2F3F; //clear all timer interrupts, see p1002
    TIMER1_IMR_R = (1 << 4); // masking timer 1A match interrupt
    NVIC_EN0_R |= 1 << 21; // enable timer 1a in NVIC IRQ #21
}


