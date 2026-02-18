/*
================================================================================
Project 1: ASCII Art Train Generator
Author: Lloyd Dela Cruz
Start Date: 2026-02-01
Completion Date: 2026-02-18 
Course: IPC144
================================================================================
Description:
This program generates an ASCII art train based on user input. The train
always includes an engine and a variable number of cars (0–5). The user 
selects the number of cars and the direction (Left or Right). Input is 
validated. Smoke is added as a customization to the engine.

Engine and car ASCII art are taken and adapted from:
https://www.asciiart.eu/vehicles/trains

How to compile: gcc -o train train.c    then    ./train
================================================================================
*/

#include <stdio.h>
#include <ctype.h>

void printRight(int cars);
void printLeft(int cars);

int main(void)
{
    int cars;
    char dir;

    do {
        printf("Enter number of train cars (0-5): ");
        scanf("%d", &cars);

        if (cars < 0 || cars > 5)
            printf("Invalid number. Must be between 0 and 5.\n");

    } while (cars < 0 || cars > 5);

    do {
        printf("Enter direction (L or R): ");
        scanf(" %c", &dir);
        dir = toupper(dir);

        if (dir != 'L' && dir != 'R')
            printf("Invalid direction. Enter L or R.\n");

    } while (dir != 'L' && dir != 'R');

    printf("\n");

    if (dir == 'R')
        printRight(cars);
    else
        printLeft(cars);

    return 0;
}

/* Improved RIGHT FACING TRAIN with precise spacing */
void printRight(int cars)
{
    int i;

    /* Each car width = 11 chars for alignment */

    /* Row 1 */
    printf("   o O___ ");
    for (i = 0; i < cars; i++)
        printf("___________ ");  // 11 underscores + 1 space = 12 width
    printf("\n");

    /* Row 2 */
    printf(" _][__|o|_|");
    for (i = 0; i < cars; i++)
        printf("|O O O O | ");  // added space inside box for width
    printf("\n");

    /* Row 3 */
    printf("<_______|-|");
    for (i = 0; i < cars; i++)
        printf("|________| "); // 10 underscores + pipes + space
    printf("\n");

    /* Row 4 */
    printf(" /O-O-O   ");
    for (i = 0; i < cars; i++)
        printf("  o     o  "); // spacing around wheels
    printf("\n");

    /* Row 5 */
    printf("   ~~~    ");
    for (i = 0; i < cars; i++)
        printf("           "); // spaces for alignment under cars
    printf("\n");
}

/* LEFT FACING TRAIN - same spacing principle */
void printLeft(int cars)
{
    int i;

    /* Row 1 */
    for (i = 0; i < cars; i++)
        printf("__________ ");  // 11 underscores + space
    printf(" ___O o\n");

    /* Row 2 */
    for (i = 0; i < cars; i++)
        printf("|O O O O | ");  // space inside box for width
    printf("|_|o|__][_ \n");

    /* Row 3 */
    for (i = 0; i < cars; i++)
        printf("|________| "); // box width
    printf("-|_______>\n");

    /* Row 4 */
    for (i = 0; i < cars; i++)
        printf(" o     o   "); // wheels spacing
    printf("   O-O-O\\\n");

    /* Row 5 */
    for (i = 0; i < cars + 1; i++)
        printf("           "); // alignment line
    printf("   ~~~\n");
}