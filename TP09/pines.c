#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pines.h"
FILE * handle;
int nWritten;

char *const pin27 = "/sys/class/gpio/gpio27/value";
char *const pin22 = "/sys/class/gpio/gpio22/value";
char *const pin25 = "/sys/class/gpio/gpio25/value";
char *const pin24 = "/sys/class/gpio/gpio24/value";
char *const pin23 = "/sys/class/gpio/gpio23/value";
char *const pin18 = "/sys/class/gpio/gpio18/value";
char *const pin4 =  "/sys/class/gpio/gpio4/value";
char *const pin17 = "/sys/class/gpio/gpio17/value";


void setPin(unsigned int numPin, unsigned int value){
    
    char * pointer_2_Pin;
    
    switch(value){
        case 0:
            pointer_2_Pin = pin27;
            break;
        case 1:
            pointer_2_Pin = pin22;
            break;  
        case 2:
            pointer_2_Pin = pin25;
            break;
        case 3:
            pointer_2_Pin = pin24;
            break; 
        case 4:
            pointer_2_Pin = pin23;
            break;
        case 5:
            pointer_2_Pin = pin18;
            break; 
        case 6:
            pointer_2_Pin = pin4;
            break;
        case 7:
            pointer_2_Pin = pin17;
            break; 
    }
    
    if ((handle = fopen(pointer_2_Pin, "w")) == NULL)
    {
        printf("Cannot open device. Try again later.\n");
    	exit(1);
    }
    else
    {
	printf("Device successfully opened\n");
    }
    
    if(value == 1){
        if(fputc('1' ,handle)==-1) // Set pin low
        {
            printf("Clr_Pin: Cannot write to file. Try again later.\n");
            exit(1);
        }
    }
    else if(value == 0){
        if(fputc('0' ,handle)==-1) // Set pin low
        {
            printf("Clr_Pin: Cannot write to file. Try again later.\n");
            exit(1);
        }
    }

fclose(handle);

}

// Notes : command line as non root user
// echo "1" | sudo tee /sys/class/gpio/gpio22/value 
// echo "0" | sudo tee /sys/class/gpio/gpio22/value 

