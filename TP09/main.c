#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include "termlib.h"
#include "registers.h"
#include "deff.h"
#include "logic.h"
#include "led.h"
#include "testBench.h"
#include "elegirPuerto.h"

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 


int main(void)
{

  changemode(BUFFERED_OFF); // Turns terminal line buffering off
  clrscr();
  unsigned int puerto = 0;
  puerto = elegirPuerto();
  if(puerto == 2)
      testBench();
  
  else{
    int error = 0 ;
    unsigned char input;
    puerto_8_t puertoA;
    puertoA.port = 0;           //inicializo el puerto, todos los leds apagados

    char array [TAMANOPUERTO_8_T];
    
    bienvenida();

    input=getch(); 
    while(input != EXIT)
    {
      //printf("Puerto> %d",BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(puertoA.port));
      if(error)
        while(!kbhit()){
          input=getch();        // Get the Key
          error =0;
          break;
        }

      if(kbhit())              // wait for a key to be pressed
        input=getch();          // Get the Key

      if (is_Between_0_And_7(input))
        error = prenderLed(&puertoA.port, TAMANOPUERTO_8_T, input-'0');
      else{
        switch (input)
        {
          case BLINK:
            error = blinkAll_On_Leds(&puertoA.port, TAMANOPUERTO_8_T, array);

            break;

          case OFF:
            error = apagarLeds(&puertoA.port, TAMANOPUERTO_8_T);
            break;

          case ON:
            error = PrenderLeds(&puertoA.port, TAMANOPUERTO_8_T);
            break;

          case EXIT:
            break;

          default:
              imprimirString("Hubo un error");
              error = 1;
        }
      }
    }
  }

  return 0;

}
