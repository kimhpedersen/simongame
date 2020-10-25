/* 
 * File:   main.c
 * Author: khpe
 *
 * Created on August 5, 2020, 11:20 AM
 */
#include "configuration_bits.c"
#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */
#include <stdio.h>
#include <stdlib.h>
#include <pic16f18345.h>
#include <pic.h>
#include <xc.h>
#include <stdbool.h>


/**
 * Display a color
 * @param char color 0-3
 */
void displayColor(char c) {
    if (c==0) {
        PORTC=Green; //31
    }
    if (c==1) {
        PORTC=Blue; // 47
    }
    if (c==2) {
        PORTC=Red; //59
    }
    if (c==3) {
        PORTC=Yellow; // 61
    }
    __delay_ms(10);
    PORTC=AllOff;
}

/**
 * Add a random color to the current sequence
 */
void addToColorSequence() {
    colorSequence[seqenceLength]=r;
    seqenceLength++;
}

/**
 * Display current color sequence
 */
void displayColorSequence() {
    char position = 0;
    while (position<seqenceLength) {
        displayColor(colorSequence[position++]);
        __delay_ms(1000);
    }
}

/**
 * Wait for user to enter a color
 * @return char color 0-3
 */
char waitForUserColor() {
    while (true) {
        r=(r+1)%4;
        if (RB6==0b0) {
            return 0;
        }
        if (RB7==0b0) {
            return 1;
        }
        if (RB5==0b0) {
            return 2;
        }
        if (RB4==0b0) {
            return 3;
        }
        _delay(10);
    }
}

/**
 * Wait for user to enter complete color Sequence
 */
void waitForUserSequence(){
    char position = 0;
    while (position<seqenceLength) {
        char userColor = waitForUserColor();
        if (userColor==colorSequence[position]) {
            position++;
           __delay_ms(500);
        } else {
            PORTC=ErrColor;
            __delay_ms(200);
            seqenceLength=0;
            PORTC=AllOff;
            __delay_ms(2000);
        }
    }
}

/*
 * Main loop
 */
int main(int argc, char** argv) {
    ConfigureOscillator();
    InitApp();
    while (1) {
        addToColorSequence();
        displayColorSequence();
        waitForUserSequence();
        //__delay_ms(200);
    }
    return (EXIT_SUCCESS);
}