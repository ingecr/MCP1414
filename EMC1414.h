/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:  EMC1414
 * Author: Juan de Dios Duran
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef EMC1414_H
#define	EMC1414_H



#include <xc.h> // include processor files - each processor file is guarded.  
#include "TYPE_DEF.h"
    /*I2C Call Address*/
#define MCP1414_Addr_Write 0x98
#define MCP1414_Addr_Read  0x99

        /*Registers*/
    /*Temperature data Registers*/
#define MCP1414_Addr_Int_Temp_HB    0x00
#define MCP1414_Addr_Int_Temp_LB    0x29
#define MCP1414_Addr_Ext_Temp_1_HB  0x01
#define MCP1414_Addr_Ext_Temp_1_LB  0x10
#define MCP1414_Addr_Ext_Temp_2_HB  0x23
#define MCP1414_Addr_Ext_Temp_2_LB  0x24
#define MCP1414_Addr_Ext_Temp_3_HB  0x2A
#define MCP1414_Addr_Ext_Temp_3_LB  0x2B

    /*Status Register*/
#define MCP1414_Addr_Status           0x02
    /*Configuration Register*/
#define MCP1414_Addr_Configuration    0x03
    /*Conversion Rate Register*/
#define MCP1414_Addr_Conv_Rate        0x04
    
    /*Temperature limit Registers*/
#define MCP1414_Addr_Int_Temp_H_Limit        0x05
#define MCP1414_Addr_Int_Temp_L_Limit        0x06

#define MCP1414_Addr_Ext_Temp_1_H_Limit_HB   0x07
#define MCP1414_Addr_Ext_Temp_1_H_Limit_LB   0x13
#define MCP1414_Addr_Ext_Temp_1_L_Limit_HB   0x08
#define MCP1414_Addr_Ext_Temp_1_L_Limit_LB   0x14

#define MCP1414_Addr_Ext_Temp_2_H_Limit_HB   0x15
#define MCP1414_Addr_Ext_Temp_2_H_Limit_LB   0x17
#define MCP1414_Addr_Ext_Temp_2_L_Limit_HB   0x16
#define MCP1414_Addr_Ext_Temp_2_L_Limit_LB   0x18

#define MCP1414_Addr_Ext_Temp_3_H_Limit_HB   0x2C
#define MCP1414_Addr_Ext_Temp_3_H_Limit_LB   0x2E
#define MCP1414_Addr_Ext_Temp_3_L_Limit_HB   0x2D
#define MCP1414_Addr_Ext_Temp_3_L_Limit_LB   0x2F

    /*Scratchpad*/
#define MCP1414_Addr_Scratchpad_1     0x11
#define MCP1414_Addr_Scratchpad_2     0x12
    /*One shot Register*/
#define MCP1414_Addr_One_Shot         0x0F

    /*Therm Limit Register*/
#define MCP1414_Addr_Therm_Hysteresis    0x21
#define MCP1414_Addr_Int_Therm_limit     0x20
#define MCP1414_Addr_Ext_Therm_limit_1   0x19
#define MCP1414_Addr_Ext_Therm_limit_2   0x1A
#define MCP1414_Addr_Ext_Therm_limit_3   0x30

    /*External Diode Fault Register*/
#define MCP1414_Addr_Ext_Fault   0x1B

    /*Channel Mask Register*/
#define MCP1414_Addr_Channel_Mask   0x1F

    /*Consecutive Alert Register*/
#define MCP1414_Addr_Consec_Alert   0x22

    /*Beta Configuration Registers*/
#define MCP1414_Addr_Ext_Beta_Config_1   0x25
#define MCP1414_Addr_Ext_Beta_Config_2   0x26

    /*External Ideality Factor Registers*/
#define MCP1414_Addr_Ext_Ideality_Factor_1   0x27
#define MCP1414_Addr_Ext_Ideality_Factor_2   0x28
#define MCP1414_Addr_Ext_Ideality_Factor_3   0x31

    /*Limit Status Registers*/
#define MCP1414_Addr_Limit_Status_H       0x35
#define MCP1414_Addr_Limit_Status_L       0x36
#define MCP1414_Addr_Limit_Status_Therm   0x37

    /*Filter Control Register*/
#define MCP1414_Addr_Filter_Control   0x40

    /*ID*/
#define MCP1414_Addr_Product_ID     0xFD
#define MCP1414_Addr_Microchip_ID   0xFD
#define MCP1414_Addr_Revision       0xFF

    


            /*DATA*/
#define MCP1414_Data_Config     0b00000100
#define MCP1414_Data_Conv_Rate  0b00000111

#define MCP1414_Data_Temp_Limit_Int_H  0b11111111
#define MCP1414_Data_Temp_Limit_Int_L  0b00000000
#define MCP1414_Data_Temp_Limit_1_H    0b11111111
#define MCP1414_Data_Temp_Limit_1_L    0b00000000
#define MCP1414_Data_Temp_Limit_2_H    0b11111111
#define MCP1414_Data_Temp_Limit_2_L    0b00000000
#define MCP1414_Data_Temp_Limit_3_H    0b11111111
#define MCP1414_Data_Temp_Limit_3_L    0b00000000

#define MCP1414_Data_Therm_Limit_Int     0b11111111
#define MCP1414_Data_Therm_Limit_Ext_1   0b11111111
#define MCP1414_Data_Therm_Limit_Ext_2   0b11111111
#define MCP1414_Data_Therm_Limit_Ext_3   0b11111111
#define MCP1414_Data_Therm_Hysteresis    0b11111111

#define MCP1414_Data_Channel_Mask        0b00000111

#define MCP1414_Data_Consec_Alert        0b01110000

#define MCP1414_Data_Beta_Config_1       0b00001000
#define MCP1414_Data_Beta_Config_2       0b00000111

#define MCP1414_Data_Ext_Ideality_Factor_1  0b00010010
#define MCP1414_Data_Ext_Ideality_Factor_2  0b00010010
#define MCP1414_Data_Ext_Ideality_Factor_3  0b00010010

#define MCP1414_Data_Filter_Config          0b00000011


    


void   MCP1414_writeByte            (u8 wrAddr, u8 wrData);
u8     MCP1414_readByte             (u8 rdAddr); 
void   MCP1414_writeConfig          (u8 wrData); 
void   MCP1414_setConversRate       (u8 ConversRate); 
void   MCP1414_setFilterRate        (u8 filterDecodeRate); 
void   MCP1414_setDiode1BetaConfig  (u8 enable); 
void   MCP1414_setDiode2BetaConfig  (u8 enable); 
void   MCP1414_setTemeratureLimit   (u8 LimitInt_H ,u8 Limit1_H, u8 Limit2_H, u8 Limit3_H , u8 LimitInt_L ,u8 Limit1_L, u8 Limit2_L, u8 Limit3_L);
void   MCP1414_setThermLimit        (u8 IntLimit, u8 ExtLimit1, u8 ExtLimit2, u8 ExtLimit3, u8 Hysteresis);
void   MCP1414_setChannelMask       (u8 ChannelMask);
void   MCP1414_setConsecAlert       (u8 ConsecAlert);
void   MCP1414_setExtIdealityFactor (u8 Factor1 , u8 Factor2 , u8 Factor3 );
int    MCP1414_readInterTemp        (void);
int    MCP1414_readExtern1Temp      (void);
int    MCP1414_readExtern2Temp      (void);
int    MCP1414_readExtern3Temp      (void);
u8     MCP1414_readProductID        (void);
u8     MCP1414_readManufacturerID   (void); 
u8     MCP1414_readRevisionRegister (void);
u8     MCP1414_getInterruptState    (void);
u8     MCP1414_readStatReg          (void); 
u8     MCP1414_readThermLimitStat   (void);
u8     MCP1414_readExterDiodeFault  (void);
u8     MCP1414_readLowLimitStat     (void);
u8     MCP1414_readHighLimitStat    (void);
u8     MCP1414_readConfig           (void);
u8     MCP1414_readFilterRate       (void);
u8     MCP1414_readDiode1BetaConfig (void); 
u8     MCP1414_readDiode2BetaConfig (void); 


#endif	/* EMC1414_H */

