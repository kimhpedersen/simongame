/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "system.h"

void ConfigureOscillator(void)
{
    INTCONbits.GIE = 0;
    INTCONbits.PEIE = 0;
    TRISC=0;
    TRISA=255;
    TRISB=255;
    WPUA=255;
    WPUB=255;
}
