
#include <stdio.h>
#include <stdlib.h>
#include "registers.h"
/*
 * 
 */
int main(int argc, char** argv) {
    puerto_8_t puertoA;
    puertoA.port = 6;
    printf("%d",puertoA.port);
    return 0;
}

