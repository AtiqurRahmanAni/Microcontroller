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
#define RS RD2
#define EN RD3
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7
#define s1 RC5
#define s2 RC6
#define TWELVE RA0
#define ONE RB2
#define TWO RB3
#define THREE RB4
#define FOUR RB5
#define FIVE RB6
#define SIX RB7
#define SEVEN RA5
#define EIGHT RC1
#define NINE RA3
#define TEN RA2
#define ELEVEN RA1
int sec = 05;
int min = 55;
int hour = 10;
int date = 06;
int month = 05;
int year = 18;
int sec1,sec2;
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
    TRISA=0x00;
    PORTA=0x00;
    TRISC=0x00;
    PORTC=0x00;
    TRISB=0x00;
    PORTB=0x00;
    TRISD=0x00;
    PORTD=0x00;
    I2C_Initialize(100);
    while (1) 
    {
        Update_Current_Date_Time();
        sec1=sec%10;
        sec2=sec/10;
        PORTD=seg[sec1];
        s1=0;
        s2=1;
        __delay_ms(5);
        PORTD=seg[sec2];
        s2=0;
        s1=1;
        __delay_ms(5);
        //one
        if(hour==1 || hour==13)
        {
            PORTA=0x00;
            ONE=1;
            TWO=0;
            THREE=0;
            FOUR=0;
            FIVE=0;
            SIX=0;
            EIGHT=0;
        }
        //two
        else if(hour==2 || hour==14)
        {
            
            PORTA=0x00;
            ONE=0;
            TWO=1;
            THREE=0;
            FOUR=0;
            FIVE=0;
            SIX=0;
            EIGHT=0;
        }
        //three
        else if(hour==3 || hour==15)
        {
            
            PORTA=0x00;
            ONE=0;
            TWO=0;
            THREE=1;
            FOUR=0;
            FIVE=0;
            SIX=0;
            EIGHT=0;
        }
        //four
        else if(hour==4 || hour==16)
        {
            
            PORTA=0x00;
            ONE=0;
            TWO=0;
            THREE=0;
            FOUR=1;
            FIVE=0;
            SIX=0;
            EIGHT=0;
            
        }
        //five
        else if(hour==5 || hour==17)
        {
            
            //PORTA=0x00;
            ONE=0;
            TWO=0;
            THREE=0;
            FOUR=0;
            FIVE=1;
            SIX=0;
            EIGHT=0;
        }
        //six
        else if(hour==6 || hour==18)
        {
            
            PORTA=0x00;
            ONE=0;
            TWO=0;
            THREE=0;
            FOUR=0;
            FIVE=0;
            SIX=1;
            EIGHT=0;
        }
        //seven
        else if(hour==7 || hour==19)
        {
            
            PORTA=0x20;
            ONE=0;
            TWO=0;
            THREE=0;
            FOUR=0;
            FIVE=0;
            SIX=0;
            EIGHT=0;
        }
        //eight
        else if(hour==8 || hour==20)
        {
            PORTA=0x00;
            ONE=0;
            TWO=0;
            THREE=0;
            FOUR=0;
            FIVE=0;
            SIX=0;
            EIGHT=1;
        }
        //nine
        else if(hour==9 || hour==21)
        {
            PORTA=0x08;
            ONE=0;
            TWO=0;
            THREE=0;
            FOUR=0;
            FIVE=0;
            SIX=0;
            EIGHT=0;
        }
        //ten
        else if(hour==10 || hour==22)
        {
            PORTA=0x04;
            ONE=0;
            TWO=0;
            THREE=0;
            FOUR=0;
            FIVE=0;
            SIX=0;
            EIGHT=0;
        }
        //eleven
        else if(hour==11 || hour==23)
        {
            PORTA=0x02;
            ONE=0;
            TWO=0;
            THREE=0;
            FOUR=0;
            FIVE=0;
            SIX=0;
            EIGHT=0;
        }
        //twelve
        else if(hour==12 || hour==0)
        {
            PORTA=0x01;
            ONE=0;
            TWO=0;
            THREE=0;
            FOUR=0;
            FIVE=0;
            SIX=0;
            EIGHT=0;
        }
        
    }
    return 0;
}
