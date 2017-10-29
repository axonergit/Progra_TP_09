
#include <stdio.h>
#include <stdlib.h>
#include "registers.h"
#include "display.h"

int main(void)
{

  changemode(BUFFERED_OFF); // Turns terminal line buffering off
  clrscr();

  unsigned char input;
  puerto_8_t puertoA;
  puertoA.port = 0;           //inicializo el puerto, todos los leds apagados

  while(input != EXIT)
  {
    if(kbhit());              // wait for a key to be pressed
      input=getch();        // Get the Key

    if (is_Between_0_And_7 (input))
    {

    }
    else
      switch (input)
      {
        case BLINK:

        case OFF:

        case ON:

        case EXIT:

        case default:

      }




      unsigned int a_prender = 0;//debo recibir por input
      int error = prenderLed(&puertoA, sizeof(puertoA), a_prender);
    }






}
