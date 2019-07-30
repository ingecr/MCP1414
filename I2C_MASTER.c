/*
 * File:   I2C_Master.c
 * Author: hectorcruz
 *
 * Created on April 17, 2019, 10:15 AM
 */

#include <pic18f45k50.h>
#include "I2C_MASTER.h"

void I2C_Master_Init()
{
    TRISBbits.RB0 = 1;                //SDA     /* Set up I2C lines by setting as input */
	TRISBbits.RB1 = 1;                //SCL
	SSP1STAT = 0xC0;  /*80*/          /* Slew rate disabled, other bits are cleared */
    SSP1CON1 = 0x28;			      /* Enable SSP port for I2C Master mode, clock = FOSC / (4 * (SSPADD+1))*/ 
	SSP1CON2 = 0;
    SSP1ADD = BITRATE;                /* Set clock frequency */  
    SSPIE = 0;                        /* Enable SSPIF interrupt */
    SSPIF = 0;
}

char I2C_Master_Start(char slave_write_address)
{   
    SSP1CON2bits.SEN = 1;            /* Send START condition */
    while(SSP1CON2bits.SEN);         /* Wait for completion of START */
    SSPIF=0;
    if(!SSP1STATbits.S)              /* Return 0 if START is failed */
    return 0;
    return (I2C_Master_Write(slave_write_address)); /* Write slave device address with write to communicate */
}

void I2C_Master_Start_Wait(char slave_write_address)
{
  while(1)
  {   
    SSP1CON2bits.SEN = 1;            /* Send START condition */
    while(SSP1CON2bits.SEN);         /* Wait for completion of START */
    SSPIF = 0;
    if(!SSP1STATbits.S)              /* Continue if START is failed */
        if(SSP1CON1bits.WCOL || SSP1CON1bits.SSPOV){
            SSP1CON1bits.WCOL   = 0;
            SSP1CON1bits.SSPOV  = 0;
            continue;
        }
        
    I2C_Master_Write(slave_write_address); /* Write slave device address with write to communicate */
    if(ACKSTAT)                     /* Check whether Acknowledgment received or not */
    {
        I2C_Master_Stop();                 /* If not then initiate STOP and continue */
        continue;
    }    
    break;                          /* If yes then break loop */
  }
}

char I2C_Master_Repeated_Start(char slave_read_address)
{
    RSEN = 1;                       /* Send REPEATED START condition */
    while(SSP1CON2bits.RSEN);        /* Wait for completion of REPEATED START condition */
    SSPIF = 0;
    if(!SSP1STATbits.S) return 0;              /* Return 0 if REPEATED START is failed */
    
    I2C_Master_Write(slave_read_address);  /* Write slave device address with read to communicate */
    if (ACKSTAT)                    /* Return 2 if acknowledgment received else 1 */
     return 1;
    else
     return 2;
}

char I2C_Master_Write(unsigned char data)
{
      SSPBUF = data;                /* Write data to SSPBUF */
      I2C_Master_Ready();
      if (ACKSTAT)                  /* Return 2 if acknowledgment received else 1 */
        return 1;
      else
        return 2;
}

void I2C_Master_Ack()
{
    ACKDT = 0;  					/* Acknowledge data 1:NACK,0:ACK */
	ACKEN = 1;        				/* Enable ACK to send */
    while(ACKEN);
}

void I2C_Master_Nack()
{
    ACKDT = 1;          			/* Not Acknowledge data 1:NACK,0:ACK */
	ACKEN = 1;              		/* Enable ACK to send */	          
    while(ACKEN);
}
char I2C_Master_Read(char flag)            /* Read data from slave devices with 0=Ack & 1=Nack */
{
    char buffer;
    RCEN = 1;                       /* Enable receive */
    while(!SSP1STATbits.BF);         /* Wait for buffer full flag which set after complete byte receive */
    buffer = SSPBUF;                /* Copy SSPBUF to buffer */
    if(flag==0)
        I2C_Master_Ack();                  /* Send acknowledgment */
    else
        I2C_Master_Nack();                 /* Send negative acknowledgment */
    //I2C_Master_Ready();
    return(buffer);
}

char I2C_Master_Stop()
{
    PEN = 1;                        /* Initiate STOP condition */
    while(PEN);                     /* Wait for end of STOP condition */
    SSPIF = 0;
    if(!SSP1STATbits.P){             /* Return 0 if STOP failed */
        return 0;
    }
    return 1;
}

void I2C_Master_Ready()
{
    //while(!SSPIF);                  /* Wait for operation complete */
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
    SSPIF=0;                        /*clear SSPIF interrupt flag*/
}


