/* Experimentacon 1*/


#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_uart.h"
#include "inc/hw_memmap.h"
#include "driverlib/pin_map.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "inc/hw_timer.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h"

int estado = 0;
int estado_R = 0;
int estado_G = 0;
int estado_B = 0;

int enable_R = 1;
int enable_G = 1;
int enable_B = 1;
int variable = 0;


void Int_Conf_UART0 (void){
    IntEnable(INT_UART0);
    UARTIntEnable(UART0_BASE,UART_INT_RX|UART_INT_RT);}

void Int_Conf_TMR(void){
    IntEnable(INT_TIMER0A);
    TimerIntEnable(TIMER0_BASE,TIMER_TIMA_TIMEOUT);
    IntMasterEnable();}

void IntTimer (void){
    TimerIntClear(TIMER0_BASE,TIMER_TIMA_TIMEOUT);
    if (estado == 0){estado = 1;}
    else{estado = 0;}

}


void IntUART0 (void){
    uint32_t ui32Status;
    ui32Status = UARTIntStatus(UART0_BASE,true);
    UARTIntClear(UART0_BASE,ui32Status);
    while(UARTCharsAvail(UART0_BASE)){
        variable = UARTCharGetNonBlocking(UART0_BASE);
        UARTCharPutNonBlocking(UART0_BASE,0x0A);
        UARTCharPutNonBlocking(UART0_BASE,0x0D);
        UARTCharPutNonBlocking(UART0_BASE,'R');
        UARTCharPutNonBlocking(UART0_BASE,'E');
        UARTCharPutNonBlocking(UART0_BASE,'C');
        UARTCharPutNonBlocking(UART0_BASE,'I');
        UARTCharPutNonBlocking(UART0_BASE,'B');
        UARTCharPutNonBlocking(UART0_BASE,'I');
        UARTCharPutNonBlocking(UART0_BASE,':');
        UARTCharPutNonBlocking(UART0_BASE,' ');
        UARTCharPutNonBlocking(UART0_BASE,variable);
        }
    if (variable == 'R' || variable == 'r'){
        enable_R = !enable_R;}
    else if (variable == 'G' || variable == 'g'){
        enable_G = !enable_G;}
    else if (variable == 'B' || variable == 'b'){
        enable_B = !enable_B;}
}





int main(){
    SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    TimerConfigure(TIMER0_BASE,TIMER_CFG_PERIODIC);
    TimerLoadSet(TIMER0_BASE,TIMER_A,19999999);
    TimerEnable(TIMER0_BASE,TIMER_A);
    Int_Conf_TMR();
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    GPIOPinTypeUART(GPIO_PORTA_BASE,GPIO_PIN_0 | GPIO_PIN_1);
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    UARTConfigSetExpClk(UART0_BASE,SysCtlClockGet(),115200,(UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE));


    UARTCharPut(UART0_BASE,0x0A);
    UARTCharPut(UART0_BASE,0x0D);
    UARTCharPut(UART0_BASE,'B');
    UARTCharPut(UART0_BASE,'I');
    UARTCharPut(UART0_BASE,'E');
    UARTCharPut(UART0_BASE,'N');
    UARTCharPut(UART0_BASE,'V');
    UARTCharPut(UART0_BASE,'E');
    UARTCharPut(UART0_BASE,'N');
    UARTCharPut(UART0_BASE,'I');
    UARTCharPut(UART0_BASE,'D');
    UARTCharPut(UART0_BASE,'O');
    UARTCharPut(UART0_BASE,' ');
    UARTCharPut(UART0_BASE,'P');
    UARTCharPut(UART0_BASE,'R');
    UARTCharPut(UART0_BASE,'E');
    UARTCharPut(UART0_BASE,'S');
    UARTCharPut(UART0_BASE,'I');
    UARTCharPut(UART0_BASE,'O');
    UARTCharPut(UART0_BASE,'N');
    UARTCharPut(UART0_BASE,'E');
    UARTCharPut(UART0_BASE,' ');
    UARTCharPut(UART0_BASE,'R');
    UARTCharPut(UART0_BASE,' ');
    UARTCharPut(UART0_BASE,'G');
    UARTCharPut(UART0_BASE,' ');
    UARTCharPut(UART0_BASE,'o');
    UARTCharPut(UART0_BASE,' ');
    UARTCharPut(UART0_BASE,'B');
    UARTCharPut(UART0_BASE,' ');
    UARTCharPut(UART0_BASE,'P');
    UARTCharPut(UART0_BASE,'A');
    UARTCharPut(UART0_BASE,'R');
    UARTCharPut(UART0_BASE,'A');
    UARTCharPut(UART0_BASE,' ');
    UARTCharPut(UART0_BASE,'E');
    UARTCharPut(UART0_BASE,'L');
    UARTCharPut(UART0_BASE,' ');
    UARTCharPut(UART0_BASE,'T');
    UARTCharPut(UART0_BASE,'O');
    UARTCharPut(UART0_BASE,'G');
    UARTCharPut(UART0_BASE,'G');
    UARTCharPut(UART0_BASE,'L');
    UARTCharPut(UART0_BASE,'E');
    UARTCharPut(UART0_BASE,' ');
    UARTCharPut(UART0_BASE,'D');
    UARTCharPut(UART0_BASE,'E');
    UARTCharPut(UART0_BASE,' ');
    UARTCharPut(UART0_BASE,'L');
    UARTCharPut(UART0_BASE,'E');
    UARTCharPut(UART0_BASE,'D');
    UARTCharPut(UART0_BASE,'S');
    Int_Conf_UART0();

    while(true){
        if (estado == 1){
                if (enable_R){GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,2);}
                if (enable_B){GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,4); }
                if (enable_G){GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,8); }
        }

        else{GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0);}


       /* if (enable_R){
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,4);
            enable_R = 0;
        }
        if (enable_G){
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,4);
                }
        if (enable_B){
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,8);
                }*/
    }

}
