/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "system.h"
#include "user.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */



void InitApp(void) {
    WPUA=255;
    WPUB=255;
    WPUC=255;
    ADIE=0;
    ADON=0;
    ANSELA=0;
    ANSELB=0;
    ANSELC=0;
    powerOnSelfTest();
}

void powerOnSelfTest() {

}
