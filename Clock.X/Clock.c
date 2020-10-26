/*
 * File:   Clock.c
 * Author: Atiqur Rahman
 *
 * Created on June 8, 2020, 2:31 PM
 */
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 16000000
#define ss1 RB0
#define ss2 RB1
#define mm1 RB2
#define mm2 RB3
#define hh1 RB4
#define hh2 RB5


int sec = 05;
int min = 55;
int hour = 10;
int date = 06;
int month = 05;
int year = 18;

int s1,s2,m1,m2,h1,h2,dly=2;;

unsigned int seg[]={0X3F, //Hex value to display the number 0
                    0X06, //Hex value to display the number 1
                    0X5B, //Hex value to display the number 2
                    0X4F, //Hex value to display the number 3
                    0X66, //Hex value to display the number 4
                    0X6D, //Hex value to display the number 5
                    0X7D, //Hex value to display the number 6
                    0X07, //Hex value to display the number 7
                    0X7F, //Hex value to display the number 8
                    0X6F  //Hex value to display the number 9
                   }; //End of Array for displaying numbers from 0 to 9
#include <xc.h>
#include "PIC16F877a_I2C.h" // Header for using I2C protocal
#include "PIC16F877a_DS3231.h" //Header for using DS3231 RTC module

int main() 
{
    
    TRISB=0x00;
    PORTB=0x00;
    TRISD=0x00;
    PORTD=0x00;
    I2C_Initialize(100);
    while (1) 
    {
        Update_Current_Date_Time();
        s1=sec%10;
        s2=sec/10;
        m1=min%10;
        m2=min/10;
        if(hour==1 || hour==13)
        {
            h1=1;
            h2=0;
        }
        else if(hour==2 || hour==14)
        {
            h1=2;
            h2=0;
        }
        else if(hour==3 || hour==15)
        {
            h1=3;
            h2=0;
        }
        else if(hour==4 || hour==16)
        {
            h1=4;
            h2=0;
        }
        else if(hour==5 || hour==17)
        {
            h1=5;
            h2=0;
        }
        else if(hour==6 || hour==18)
        {
           h1=6;
           h2=0;
        }
        else if(hour==7 || hour==19)
        {
            h1=7;
            h2=0;
        }
        else if(hour==8 || hour==20)
        {
            h1=8;
            h2=0;
        }
        else if(hour==9 || hour==21)
        {
            h1=9;
            h2=0;
        }
        else if(hour==10 || hour==22)
        {
            h1=0;
            h2=1;
        }
        else if(hour==11 || hour==23)
        {
            h1=1;
            h2=1;
        }
        else if(hour==12 || hour==0)
        {
            h1=2;
            h2=1;
        }
        PORTD=seg[h2];
        hh2=1;
        __delay_ms(dly);
        hh2=0;
        PORTD=seg[h1];
        hh1=1;
        __delay_ms(dly);
        hh1=0;
        PORTD=seg[m2];
        mm2=1;
        __delay_ms(dly);
        mm2=0;
        PORTD=seg[m1];
        mm1=1;
        __delay_ms(dly);
        mm1=0;
        PORTD=seg[s2];
        ss2=1;
        __delay_ms(dly);
        ss2=0;
        PORTD=seg[s1];
        ss1=1;
        __delay_ms(dly);
        ss1=0;
    }
    return 0;
}
