/* 
 * File:   LCD.h
 * Author: Juan Carlos Lomelí, David Amezcua y Alejandra Iberri.
 *
 * Created on 23 de octubre de 2014, 07:07 PM
 */

#ifndef LCD_H
#define	LCD_H

#define SS PORTAbits.RA0
#define SCK PORTAbits.RA1
#define SDO PORTAbits.RA2



void LCD_INIT (void);

void LCD_PRINT (short int dir, unsigned char a[],unsigned long int var1, unsigned long int var2, unsigned long int var3);

void LCD_TRANSMIT(unsigned char dato);

#endif	/* LCD_H */

