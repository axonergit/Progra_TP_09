
#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include "termlib.h"
#include "registers.h"
#include "deff.h"
#include "logic.h"
#include "led.h"


int main(void)
{

  changemode(BUFFERED_OFF); // Turns terminal line buffering off
  clrscr();

  int error = 0;
  unsigned char input;
  puerto_8_t puertoA;
  puertoA.port = 0;           //inicializo el puerto, todos los leds apagados
  input=getch(); 

  while(input != EXIT)
  {
    if(error)
      while(!kbhit())
        input=getch();        // Get the Key


    if(kbhit())              // wait for a key to be pressed
      input=getch();          // Get the Key

    if (is_Between_0_And_7(input))
      error = prenderLed(&puertoA.port, TAMANOPUERTO_8_T, input-'0');
    else{
      switch (input)
      {
        case BLINK:
          error = blinkAll_On_Leds(&puertoA.port, TAMANOPUERTO_8_T);
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

  return 0;

}
