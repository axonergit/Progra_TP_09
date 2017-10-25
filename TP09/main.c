
#include <stdio.h>
#include <stdlib.h>
#include "registers.h"


int main(void) {
    puerto_8_t puertoA;
    puertoA.port = 0;           //inicializo el puerto, todos los leds apagados
    unsigned int a_prender = 0;//debo recibir por input
    int error = prenderLed(&puertoA, sizeof(puertoA), a_prender);
    
}

