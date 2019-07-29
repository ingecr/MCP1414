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
 * File: Types_Var.h   
 * Author: Juan de Dios Duran
 * Comments: 
 * Revision history: 
 */

#ifndef TYPE_DEF_H
#define	TYPE_DEF_H

#include <xc.h>                         /* Include processor files - each processor file is guarded. */

typedef unsigned char        u8;
typedef unsigned int         u16;
typedef unsigned long        u32;
typedef unsigned long long   u64;

typedef signed char         s8;
typedef signed int          s16;
typedef signed long         s32;
typedef signed long long    s64;

#define ON              1
#define OFF             0
#define INPUT           1
#define OUTPUT          0
#define ANALOG_PIN      1
#define DIGITAL_PIN     0
#define ANALOG_PORT     0xFF
#define DIGITAL_PORT    0
#define HIGH            1
#define LOW             0


#endif	/* TYPE_DEF_H */
