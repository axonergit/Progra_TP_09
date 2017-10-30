#include "display.h"
#include <stdio.h>

void bienvenida(void){

    imprimirString("\nBienvenido a la simulacion de puertos.");
    imprimirString("Se disponen de 8 LEDs conectados al Puerto A.");
    imprimirString("Se debera ingresar el numero correspondiente al LED");
    imprimirString("que se desee prender o apagar (del 0 al 7).");
    imprimirString("Para poder realizar acciones con los LEDs se dispone de las opciones:");
    imprimirString("Presionando la tecla 'b', los LEDs que se encuentren prendidos parpadearan");
    imprimirString("Presionando la tecla 'c', los LEDs se apagaran (todos)");
    imprimirString("Presionando la tecla 's', los LEDs se prenderan (todos)\n");

}


void imprimirString(char * string){
    printf("%s\n", string);
}


void byte_to_2(char  byte){  
  printf("%c",(byte & 0x80) ? '1' : '0');
  printf("%c",(byte & 0x40) ? '1' : '0');
  printf("%c",(byte & 0x20) ? '1' : '0');
  printf("%c",(byte & 0x10) ? '1' : '0');
  printf("%c",(byte & 0x08) ? '1' : '0');
  printf("%c",(byte & 0x04) ? '1' : '0');
  printf("%c",(byte & 0x02) ? '1' : '0');
  printf("%c",(byte & 0x01) ? '1' : '0');
}
