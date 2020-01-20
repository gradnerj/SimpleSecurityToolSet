/*!
 *    \file  main.c
 *   \brief  
 *
 *  \author  Jeffrey Gradner, jeffreygradner@mail.weber.edu
 *
 *  \internal
 *       Created:  01/14/2020
 *      Revision:  none
 *      Compiler:  gcc
 *  Organization:  
 *     Copyright:  Copyright (c) 2020, Hugo Valle
 *
 *  This source code is released for free distribution under the terms of the
 *  GNU General Public License as published by the Free Software Foundation.
 */
#include "crypto.h"
#include <stdlib.h>
#include <stdio.h>

/* Function Prototypes */

/* Main Function */
int main(void)
{
    int selection = 0;
    printf("Welcome to Jeff's CS-5740 Toolkit\n");

    while(true){
        
        printf("\nMain Menu:\n");
        printf("1. Simple Crypto\n");
        printf("2. Exit\n");
        


        scanf(" %d", &selection);
        while((getchar()) != '\n');

        if(selection == 1){
           // printf("Simple Crypto Selected...\n");
          CryptoMenu();
        }
        else if(selection == 2){
            printf("Goodbye...\n");
            break;
        }
        else{
            printf("Invalid Selection! Try Again.\n");

        }
    }
    /*printf("Starting tests...");
    char a = 'A';
    char z = 'Z';
    //printf("%c\n", a);

    char b = 'B';
    char* abc = "ABC";
    int key =  b - 'A';
    printf("%d is the key\n", key);
    int size = getSize(abc);
    char* encrypted = NULL;
    encrypted = malloc(size);
    printf("%d is the size\n", size);
    printf("%s is the string\n", abc);
    int i;
    for(i =0; i < size; i++){
        encrypted[i] = abc[i] + key;
    }
    printf( "%s", encrypted);

    a = a + 1;
    
    printf("%c\n", a);
    z = z+1;
    z = z % 66;

    printf("%c", z);*/

    

    
    return 0;
}
/* Function Defenitions */

