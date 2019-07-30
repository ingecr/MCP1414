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
 * File: I2C_Master.h   
 * Author: Hector Cruz
 * Comments: 
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef I2C_MASTER_H
#define	I2C_MASTER_H



//#include <xc.h>                           /* Include processor files - each processor file is guarded. */
#define F_OSC 16000000                    /* Define F_OSC, here it's 16 MHz */
#define I2C_CLOCK 100000                  /* I2C clock frequency is 100 kHz*/
#define BITRATE ((F_OSC/(4*I2C_CLOCK))-1) /* find bit rate to assign this value to SSPADD register*/

 

void I2C_Master_Ready(void);                   /* Check weather I2C is ready/idle or not */
void I2C_Master_Init(void);                    /* Initialize I2C configuration*/
char I2C_Master_Start(char);                   /* Send START pulse with slave device write address */
void I2C_Master_Start_Wait(char);              /* Send START pulse with slave device write address until acknowledgement */
char I2C_Master_Repeated_Start(char);          /* Send REPEATED START pulse with slave device read address*/
char I2C_Master_Stop(void);                    /* Send STOP pulse*/
char I2C_Master_Write(unsigned char);          /* Write data/address to slave device */
void I2C_Master_Ack(void);                     /* Send acknowledge to slave for continue read */
void I2C_Master_Nack(void);                    /* Send negative acknowledge to slave for stop current communication */
char I2C_Master_Read(char);                    /* Read data from slave devices with 0=Ack & 1=Nack */


#endif	/* I2C_Master_H */


