/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

/* TODO Application specific user parameters used in user.c may go here */

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here */

void InitApp(void);         /* I/O and Peripheral Initialization */

void powerOnSelfTest();

#define AllOff 63
#define ErrColor 55
#define Green 31
#define Blue 47
#define Red 59
#define Yellow 61
char colorSequence[60];
char seqenceLength = 0;
char r=0;

