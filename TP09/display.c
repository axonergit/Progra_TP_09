#include "display.h"
#include <stdio.h>
void bienvenida(void){

    printf("Bienvenido a la simulacion de puertos.\n");
    printf("Se disponen de 8 LEDs conectados al Puerto A.\n");
    printf("Se debera ingresar el numero correspondiente al LED\n");
    printf("que se desee prender o apagar (del 0 al 7).\n");
    printf("Para poder realizar acciones con los LEDs se dispone de las opciones:\n");
    printf("Presionando la tecla 'b', los LEDs que se encuentren prendidos parpadearan\n");
    printf("Presionando la tecla 'c', los LEDs se apagaran (todos)\n");
    printf("Presionando la tecla 's', los LEDs se prenderan (todos)\n");

}


void imprimirString(char * string){
    printf("%s", string);
}
