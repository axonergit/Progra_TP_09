#include "display.h"
#include <stdio.h>
#include "pines.h"



void bienvenida(void){


    imprimirString("Bienvenido a la simulacion de puertos.");
    imprimirString("Luego, se debera ingresar durante ejecucion el numero correspondiente al LED ");
    imprimirString("que se desee prender o apagar (del 0 al 15 en caso de haber elegido el puerto de 16 bits,");
    imprimirString("del 0 al 7 en caso de haber elegido el puerto de 8 bits)");
    imprimirString("Luego se presionara enter para prender al LED inidicado.");
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
  
  setPin( 0 ,((byte & 0x80) ? 1 : 0));
  setPin( 1 ,((byte & 0x80) ? 1 : 0));
  setPin( 2 ,((byte & 0x80) ? 1 : 0));
  setPin( 3 ,((byte & 0x80) ? 1 : 0));
  setPin( 4 ,((byte & 0x80) ? 1 : 0));
  setPin( 5 ,((byte & 0x80) ? 1 : 0));
  setPin( 6 ,((byte & 0x80) ? 1 : 0));
  setPin( 7 ,((byte & 0x80) ? 1 : 0));
}

