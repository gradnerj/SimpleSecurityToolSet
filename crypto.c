/*!
 *    \file  crypto.c
 *   \brief  
 *
 *  \author  Jeff Gradner, jeffreygradner@mail.weber.edu
 *  \internal
 *       Created:  01/14/2020
 *      Revision:  none
 *      Compiler:  gcc
 *  Organization:  
 *     Copyright:  Copyright (c) 2020, Jeff Gradner
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "crypto.h"
#include <string.h>

void Encrypt(void);
void Decrypt(void);
int getSize(char* s);
extern int errno;

void Encrypt(void){
    
    char key;; 
    int size = 0;
    int i = 0;
    int errnum;
    FILE* file = NULL;
    char* inFile = NULL;
    char* outFile = NULL;
    char* pText = NULL;
    char* eText = NULL;

    while(1){
        printf("Please enter an encryption key: ");
        //while((getchar()) != '\n');
        scanf(" %c", &key);
        //key = getchar();
        getchar();
        //printf("%c is the key.......", key);
        if (key < 'a' || key > 'z'){ //Might be uppercase
            if(key < 'A' || key > 'Z'){
                printf("Sorry that is an invalid key...try again.\n");
                continue;
            }else{
                break;
            }
        }
        else{
            break;
        }
    }
    //printf("\nThe key you've entered is: %c\n", key);
    key = key - 'A';
    //while((getchar()) != '\n');
    while(true){
        //while((getchar()) != '\n');
        printf("Please enter the file you'd like to encrypt: ");

        inFile = malloc(25);
        scanf("%24s", inFile);
        //printf("The file you've selected is: %s\n", inFile);
        pText = malloc(255);
    
        file = fopen(inFile, "r");
        if(file == NULL){
            errnum = errno;
            //fprintf(stderr, "Value of error: %d\n", errno);
            //perror("Error printed by perror");
            fprintf(stderr, "Error opening file: %s\n", strerror(errnum));
            while((getchar()) != '\n');
            continue;
        }
        else{
            fscanf(file, "%s", pText);
            printf("%s Is the contents of the file...\n", pText);
            fclose(file);
            break;
        }
    }
    size = getSize(pText);
    eText = malloc(size);

    for(i = 0; i < size; i++){
        eText[i] = pText[i] + key;
        if(eText[i] > 90){
            eText[i] -= 26;
        }
    }
     
    printf("Please enter an output file name: ");
    outFile = malloc(25);
    scanf("%24s", outFile);
    printf("The file you've selected is: %s\n", outFile);
    file = fopen(outFile, "w");
    fprintf(file, "%s", eText);
    fclose(file);
   // while((getchar()) != '\n');
    getchar();


    }

void Decrypt(void){
    char key;; 
    int size = 0;
    int i = 0;
    FILE* file = NULL;
    char* inFile = NULL;
    char* outFile = NULL;
    char* eText = NULL;
    char* dText = NULL;
     while(1){
        printf("Please enter a decryption key: ");
        //while((getchar()) != '\n');
        scanf(" %c", &key);
        //key = getchar();
        getchar();
        //printf("%c is the key.......", key);
        if (key < 'a' || key > 'z'){ //Might be uppercase
            if(key < 'A' || key > 'Z'){
                printf("Sorry that is an invalid key...try again.\n");
                continue;
            }else{
                break;
            }
        }
        else{
            break;
        }
    }
    //printf("\nThe key you've entered is: %c\n", key);
    key = key - 'A';

    printf("Please enter the file you'd like to decrypt: ");

    inFile = malloc(25);
    scanf("%24s", inFile);
    printf("The file you've selected is: %s\n", inFile);
    eText = malloc(255);
    file = fopen(inFile, "r");
    fscanf(file, "%s", eText);
    //printf("%s Is the contents of the encrypted file...\n", eText);
    fclose(file);
    
    size = getSize(eText);
    dText = malloc(size);

    for(i = 0; i < size; i++){
        dText[i] = eText[i] - key;
        if(dText[i] < 65){
            dText[i] += 26;
        }
    }

    printf("Please enter an output file name: ");
    outFile = malloc(25);
    scanf("%24s", outFile);
    printf("The file you've selected is: %s\n", outFile);
    file = fopen(outFile, "w");
    fprintf(file, "%s", dText);
    fclose(file);
   // while((getchar()) != '\n');
    getchar();


}

void CryptoMenu(void){
    
    while(true){
        printf("\nCrypto Toolkit\n1. Encrypt\n2. Decrypt\n3. Main Menu\n");
        int input = 0;	
        scanf(" %d", &input);
        while((getchar()) != '\n');
	    //while((getchar()) != '\n');
        //input = getchar();
      
        if(input == 1){
            //return 1;
            Encrypt();
            //return;
        }
        else if(input == 2){
            //printf("Decrypt Selected...\n");
            Decrypt();
           // return;
        }
        else if(input == 3){
           break;
        }
        else{
            printf("Invalid selection, please try again\n");
            continue;
        }
    }
    
}

int getSize(char* s){
    char* t;
    for(t = s; *t != '\0'; t++);
    return t - s;
}
