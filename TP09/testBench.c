#include <stdio.h>
#include <stdlib.h>
#include "testBench.h"
#include "display.h"
#include "termlib.h"
#include "registers.h"
#include "deff.h"
#include "logic.h"
#include "led.h"

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


int testBench(void)
{

  changemode(BUFFERED_OFF); // Turns terminal line buffering off
  clrscr();

  int error = 0;
  unsigned char input;
  char aux1 = -1 ;
  char aux2 = 0;
  unsigned int flagRecibi = 0;
  puerto_16_t puertoD;
  puertoD.port = 0;           //inicializo el puerto, todos los leds apagados
  input = getch(); 
  bienvenida();


  while(input != EXIT)
  {
    //printf("Puerto> %d",BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(puertoA.port));
    if(error)
      while(!kbhit()){
        input = getch();        // Get the Key
        error = 0;
        break;
      }

    if(kbhit()){              // wait for a key to be pressed
      aux1 = getch();          // Get the Key
      if (!is_Between_0_And_7(aux1))
          input = aux1;
    
    
      else{
          aux2 = (aux2*10) + aux1;
          flagRecibi = 1;
      }
      aux1 = -1;
    }
 
    else{
      switch (input)
      {
        case BLINK:
          error = blinkAll_On_Leds(&puertoD.port, TAMANOPUERTO_16_T);
          break;

        case OFF:
          error = apagarLeds(&puertoD.port, TAMANOPUERTO_16_T);
          break;

        case ON:
          error = PrenderLeds(&puertoD.port, TAMANOPUERTO_16_T);
          break;

        case '\n':
          input = aux2;
          error = prenderLed(&puertoD.port, TAMANOPUERTO_16_T, input-'0');
          flagRecibi = 0;
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