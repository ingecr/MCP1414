#include <xc.h>
#include <pic18f45k50.h>
#include"LCD.h"

#define _XTAL_FREQ  16000000


short unsigned int digitos[9];
short unsigned int call;



void LCD_ENABLE();
void LCD_CONVERTER(int a);
void LCD_TRANSMIT(unsigned char dato);
short int LCD_ITOA(unsigned long int a);                //Convierte un número en dígitos y después los convierte a ascii.



void LCD_INIT (void){

    SS = 1;
    SCK = 1;
    SDO = 1;
    TRISAbits.RA0 = 0;
    TRISAbits.RA1 = 0;
    TRISAbits.RA2 = 0;
    ANSELAbits.ANSA0 = 0;
    ANSELAbits.ANSA1 = 0;
    ANSELAbits.ANSA2 = 0;
    
    
    __delay_ms(50);
    __delay_ms(50);
    __delay_ms(50);
    LCD_TRANSMIT(0xFE);
    LCD_TRANSMIT(0x53);
    LCD_TRANSMIT(0x08);
}



void LCD_PRINT (short int dir, unsigned char a[],unsigned long int var1, unsigned long int var2,unsigned long int var3){
    short int numerodigitos = 0;
    short int var = 0;


    if(dir == 0){
        LCD_TRANSMIT(0xFE);
        LCD_TRANSMIT(0x45);
        LCD_TRANSMIT(0x00);
    }
    else{
        LCD_TRANSMIT(0xFE);
        LCD_TRANSMIT(0x45);
        LCD_TRANSMIT(0x40);
    }

    call = 0;
    for(short int i=0; call <16; i++){
        if(a[i] == 0){
            while(call<16){
                  LCD_TRANSMIT(0x10);
            }
        }
        else if(a[i] == '&'){
            if(var == 0){
                  numerodigitos = LCD_ITOA(var1);
                  var = var + 1;
            }
            else if(var == 1){
                  numerodigitos = LCD_ITOA(var2);
                  var = var + 1;
            }
            else if(var == 2){
                  numerodigitos = LCD_ITOA(var3);
            }
            for(short int j = 1; j<= numerodigitos && call < 16; j++){
                  LCD_TRANSMIT(digitos[numerodigitos-j]);
            }
                }
        else{
            LCD_TRANSMIT(a[i]);
        }
    }
}



 
void LCD_TRANSMIT(unsigned char dato){
    unsigned char temp = 0x00;
    
    for(int i = 0; i<8; i++){
        temp = temp << 1;
        temp = (dato & 0x01) + temp;
        dato = dato >> 1;
        
    }
    dato = temp;    
    
    
    SS = 0;
    __delay_us(10);
    SCK = 1;
    for(unsigned char i = 0; i < 8;i++){
        SCK = 0;
        __delay_us(5);
        SDO = (dato & 0x01);
        __delay_us(5);
        SCK = 1;
        __delay_us(10);
        dato = dato >> 1;
    }
    
    SS = 1;
    call = call + 1;
       
}


short int LCD_ITOA(unsigned long int a){
      short int i = 0;
      int temp;

      if(a == 0){
          digitos[0] = 48;
           i = 1;}

      while(a != 0){
          temp = a%10;
          temp = temp + 48;
          digitos[i] = temp;
          a = a / 10;
          i = i + 1;}
      return i;
}


