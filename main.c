/*
 * File:   main.c
 * Author: juand
 *
 * Created on July 1, 2019, 4:55 PM
 */


#include <xc.h>
#include "EMC1414.h"
#include "TYPE_DEF.h"
#include "I2C_MASTER.h"
#include "LCD.h"
#include "pic18f45k50.h"

#pragma config MCLRE = OFF      // MCLR Pin Enable bit (Disabled)
#pragma config FOSC = HSH       // Oscillator Selection (HS oscillator, high power 16MHz to 25MHz)

#define LED_OP PORTDbits.RD1



int Temp_Int    = 0;
int Temp_Ext_1  = 0;
int Temp_Ext_2  = 0;
int Temp_Ext_3  = 0;
unsigned int ErrorStatus;


void main(void) {
    ANSELD = 0x0;
    ANSELB = 0x0;
    TRISDbits.RD1 = 0;
    LED_OP = 0;
    
    LCD_INIT();
    I2C_Master_Init();
    MSdelay(150);
    //MCP1414_writeConfig(MCP1414_Data_Config);
    MCP1414_setConversRate(MCP1414_Data_Conv_Rate);
    MCP1414_setTemeratureLimit(MCP1414_Data_Temp_Limit_Int_H , MCP1414_Data_Temp_Limit_1_H , MCP1414_Data_Temp_Limit_2_H , MCP1414_Data_Temp_Limit_3_H, 
                               MCP1414_Data_Temp_Limit_Int_L , MCP1414_Data_Temp_Limit_1_L , MCP1414_Data_Temp_Limit_2_L , MCP1414_Data_Temp_Limit_3_L);
    MCP1414_setThermLimit(MCP1414_Data_Therm_Limit_Int , MCP1414_Data_Therm_Limit_Ext_1 , 
                          MCP1414_Data_Therm_Limit_Ext_2 , MCP1414_Data_Therm_Limit_Ext_3 , MCP1414_Data_Therm_Hysteresis);
    MCP1414_setChannelMask(MCP1414_Data_Channel_Mask);
    MCP1414_setConsecAlert(MCP1414_Data_Consec_Alert);
    MCP1414_setDiode1BetaConfig(MCP1414_Data_Beta_Config_1);
    MCP1414_setDiode2BetaConfig(MCP1414_Data_Beta_Config_2);
    MCP1414_setExtIdealityFactor(MCP1414_Data_Ext_Ideality_Factor_1 , MCP1414_Data_Ext_Ideality_Factor_2 , MCP1414_Data_Ext_Ideality_Factor_3);
    MCP1414_setFilterRate(MCP1414_Data_Filter_Config);
    MCP1414_writeConfig(MCP1414_Data_Config);
    
    SSP1CON1bits.SSPEN = 0;
    while (1){
        SSP1CON1bits.SSPEN = 1;
        Temp_Int = MCP1414_readInterTemp();
        Temp_Ext_1 = MCP1414_readExtern1Temp();
        Temp_Ext_2 = MCP1414_readExtern2Temp();
        Temp_Ext_3 = MCP1414_readExtern3Temp();
        //ErrorStatus = MCP1414_readExterDiodeFault();
        ErrorStatus = MCP1414_readLowLimitStat();

        LCD_PRINT(0," 0: &  1: &",Temp_Int,Temp_Ext_1,0);
        LCD_PRINT(1," 2: &  3: &",Temp_Ext_2,Temp_Ext_3,0);
        LED_OP = ~LED_OP;
        SSP1CON1bits.SSPEN = 0;
        
    }
}