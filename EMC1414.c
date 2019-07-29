/*
 * File:   EMC1414.c
 * Author: juand
 *
 * Created on July 1, 2019, 5:16 PM
 */


#include <xc.h>
#include <pic18f45k50.h>
#include "EMC1414.h"
#include "TYPE_DEF.h"
#include "I2C_MASTER.h"

void   MCP1414_writeByte (u8 wrAddr, u8 wrData){
    I2C_Master_Start_Wait(MCP1414_Addr_Write);	 /* Start with device write address */
	I2C_Master_Write(wrAddr);	 
	I2C_Master_Write(wrData);	    
	I2C_Master_Stop();
}
u8     MCP1414_readByte (u8 rdAddr){
    u8 data;
    I2C_Master_Start_Wait(MCP1414_Addr_Write);								/* I2C start with device write address */
	I2C_Master_Write(rdAddr);							/* Write start location address from where to read */ 
	I2C_Master_Repeated_Start(MCP1414_Addr_Read);							/* I2C start with device read address */
    data = I2C_Master_Read(1);
    I2C_Master_Stop();
    return data;
}
int  MCP1414_readInterTemp (void){
    int data;
    u8 dataMSB;
    u8 dataLSB;
    dataMSB = MCP1414_readByte(MCP1414_Addr_Int_Temp_HB);
    dataLSB = MCP1414_readByte(MCP1414_Addr_Int_Temp_LB);
    //data = (dataMSB + (float)((dataLSB&(0b10000000))*(float)0.5) + (float)((dataLSB&(0b01000000))*(float)0.25) + (float)((dataLSB&(0b00100000))*(float)0.125) ) - 64;
    
    return (dataMSB - 64);
}
int  MCP1414_readExtern1Temp (void){
    int data;
    u8 dataMSB;
    u8 dataLSB;
    dataMSB = MCP1414_readByte(MCP1414_Addr_Ext_Temp_1_HB);
    dataLSB = MCP1414_readByte(MCP1414_Addr_Ext_Temp_1_LB);
    //data = (data + (float)((datatemp & 0b10000000)*(float)0.5) + (float)((datatemp&0b01000000)*(float)0.25) + (float)((datatemp&0b00100000)*(float)0.125)) - 64;
    return (dataMSB - 64);
}
int  MCP1414_readExtern2Temp (void){
    int data;
    u8 dataMSB;
    u8 dataLSB;
    dataMSB = MCP1414_readByte(MCP1414_Addr_Ext_Temp_2_HB);
    dataLSB = MCP1414_readByte(MCP1414_Addr_Ext_Temp_2_LB);
    //data = (data + (float)((datatemp&(0b10000000))*(float)0.5) + (float)((datatemp&(0b01000000))*(float)0.25) + (float)((datatemp&(0b00100000))*(float)0.125)) - 64;
    return (dataMSB - 64);
}
int  MCP1414_readExtern3Temp (void){
    int data;
    u8 dataMSB;
    u8 dataLSB;
    dataMSB = MCP1414_readByte(MCP1414_Addr_Ext_Temp_3_HB);
    dataLSB = MCP1414_readByte(MCP1414_Addr_Ext_Temp_3_LB);
    //data = (data + (float)((datatemp&(0b10000000))*(float)0.5) + (float)((datatemp&(0b01000000))*(float)0.25) + (float)((datatemp&(0b00100000))*(float)0.125)) - 64;
    return (dataMSB - 64);
}
u8     MCP1414_readStatReg          (void){
    u8 data;
    data = MCP1414_readByte(MCP1414_Addr_Status);
    return data;
} 
void   MCP1414_writeConfig (u8 wrData){
    MCP1414_writeByte(MCP1414_Addr_Configuration,wrData);
}
void   MCP1414_setConversRate (u8 ConversRate){
    MCP1414_writeByte(MCP1414_Addr_Configuration , ConversRate);
}
void   MCP1414_setTemeratureLimit (u8 LimitInt_H ,u8 Limit1_H, u8 Limit2_H, u8 Limit3_H , u8 LimitInt_L ,u8 Limit1_L, u8 Limit2_L, u8 Limit3_L){
    MCP1414_writeByte(MCP1414_Addr_Int_Temp_H_Limit      , LimitInt_H);
    MCP1414_writeByte(MCP1414_Addr_Int_Temp_L_Limit      , LimitInt_L);
    MCP1414_writeByte(MCP1414_Addr_Ext_Temp_1_H_Limit_HB , Limit1_H);
    MCP1414_writeByte(MCP1414_Addr_Ext_Temp_1_L_Limit_HB , Limit1_L);
    MCP1414_writeByte(MCP1414_Addr_Ext_Temp_2_H_Limit_HB , Limit2_H);
    MCP1414_writeByte(MCP1414_Addr_Ext_Temp_2_L_Limit_HB , Limit2_L);
    MCP1414_writeByte(MCP1414_Addr_Ext_Temp_3_H_Limit_HB , Limit3_H);
    MCP1414_writeByte(MCP1414_Addr_Ext_Temp_3_L_Limit_HB , Limit3_L);
}
void   MCP1414_setThermLimit(u8 IntLimit, u8 ExtLimit1, u8 ExtLimit2, u8 ExtLimit3, u8 Hysteresis){
    MCP1414_writeByte(MCP1414_Addr_Therm_Hysteresis  , Hysteresis);
    MCP1414_writeByte(MCP1414_Addr_Int_Therm_limit   , IntLimit);
    MCP1414_writeByte(MCP1414_Addr_Ext_Therm_limit_1 , ExtLimit1);
    MCP1414_writeByte(MCP1414_Addr_Ext_Therm_limit_2 , ExtLimit2);
    MCP1414_writeByte(MCP1414_Addr_Ext_Therm_limit_3 , ExtLimit3);
}
void   MCP1414_setChannelMask (u8 ChannelMask){
    MCP1414_writeByte(MCP1414_Addr_Channel_Mask , ChannelMask);
}
void   MCP1414_setConsecAlert (u8 ConsecAlert){
    MCP1414_writeByte(MCP1414_Addr_Consec_Alert , ConsecAlert);
}
void   MCP1414_setDiode1BetaConfig (u8 enable){
    MCP1414_writeByte(MCP1414_Addr_Ext_Beta_Config_1 , enable);
} 
void   MCP1414_setDiode2BetaConfig (u8 enable){
    MCP1414_writeByte(MCP1414_Addr_Ext_Beta_Config_2 , enable);
}
void   MCP1414_setExtIdealityFactor (u8 Factor1 , u8 Factor2 , u8 Factor3 ){
    MCP1414_writeByte(MCP1414_Addr_Ext_Ideality_Factor_1 , Factor1);
    MCP1414_writeByte(MCP1414_Addr_Ext_Ideality_Factor_2 , Factor2);
    MCP1414_writeByte(MCP1414_Addr_Ext_Ideality_Factor_3 , Factor3);
}
void   MCP1414_setFilterRate (u8 filterDecodeRate){
    MCP1414_writeByte(MCP1414_Addr_Filter_Control , filterDecodeRate);
}
u8     MCP1414_readProductID        (){
    u8 data;
    data = MCP1414_readByte(MCP1414_Addr_Product_ID);
    return data;
}
u8     MCP1414_readManufacturerID   (){
    u8 data;
    data = MCP1414_readByte(MCP1414_Addr_Microchip_ID);
    return data;
} 
u8     MCP1414_readRevisionRegister (){
    u8 data;
    data = MCP1414_readByte(MCP1414_Addr_Revision);
    return data;
}
u8     MCP1414_getInterruptState    (void){
    return 0;
}
u8     MCP1414_readThermLimitStat   (){
    u8 data;
    data = MCP1414_readByte(MCP1414_Addr_Limit_Status_Therm);
    return data;
}
u8     MCP1414_readExterDiodeFault  (){
    u8 data;
    data = MCP1414_readByte(MCP1414_Addr_Ext_Fault);
    return data;
}
u8     MCP1414_readLowLimitStat     (){
    u8 data;
    data = MCP1414_readByte(MCP1414_Addr_Limit_Status_L);
    return data;
}
u8     MCP1414_readHighLimitStat    (){
    u8 data;
    data = MCP1414_readByte(MCP1414_Addr_Limit_Status_H);
    return data;
}
u8     MCP1414_readConfig           (){
    u8 data;
    data = MCP1414_readByte(MCP1414_Addr_Configuration);
    return data;
}
u8     MCP1414_readFilterRate       (){
    u8 data;
    data = MCP1414_readByte(MCP1414_Addr_Filter_Control);
    return data;
}
u8     MCP1414_readDiode1BetaConfig (){
    u8 data;
    data = MCP1414_readByte(MCP1414_Addr_Ext_Beta_Config_1);
    return data;
} 
u8     MCP1414_readDiode2BetaConfig (){
    u8 data;
    data = MCP1414_readByte(MCP1414_Addr_Ext_Beta_Config_2);
    return data;
} 
