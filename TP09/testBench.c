#include <stdio.h>
#include <stdlib.h>
#include "testBench.h"
#include "display.h"
#include "termlib.h"
#include "registers.h"
#include "deff.h"
#include "logic.h"
#include "led.h"




int testBench(void)
{

  changemode(BUFFERED_OFF); // Turns terminal line buffering off
  clrscr();

  int error = 0, primeraVuelta =1;
  unsigned char input = 0;
  char aux1 = -1 ;
  char aux2 = 0;
  unsigned int flagRecibi = 0;
  puerto_16_t puertoD;
  puertoD.port = 0;           //inicializo el puerto, todos los leds apagados
  
  bienvenida();
  
  aux1 = getch();          // Get the Key
  
      if (!is_Between_0_And_7(aux1))
          input = aux1-'0';
    
    
      else{
          aux2 = (aux2*10) + aux1-'0';
          flagRecibi = 1;
      }
      aux1 = -1;



  while(input != EXIT)
  {
    
    printf("%c",'0'+puertoD.bitPort.b15);
    printf("%c",'0'+puertoD.bitPort.b14);
    printf("%c",'0'+puertoD.bitPort.b13);
    printf("%c",'0'+puertoD.bitPort.b12);
    printf("%c",'0'+puertoD.bitPort.b11);
    printf("%c",'0'+puertoD.bitPort.b10);
    printf("%c",'0'+puertoD.bitPort.b9);
    printf("%c",'0'+puertoD.bitPort.b8);
    printf("%c",'0'+puertoD.bitPort.b7);
    printf("%c",'0'+puertoD.bitPort.b6);
    printf("%c",'0'+puertoD.bitPort.b5);
    printf("%c",'0'+puertoD.bitPort.b4);
    printf("%c",'0'+puertoD.bitPort.b3);
    printf("%c",'0'+puertoD.bitPort.b2);
    printf("%c",'0'+puertoD.bitPort.b1);
    printf("%c",'0'+puertoD.bitPort.b0);
    printf("\n");
    sleep(0.1);
    
    if(error)
      while(!kbhit()){
        aux1 = getch();
        if (!is_Between_0_And_7(aux1)){
          if(aux1 == EXIT || aux1 == '\n')
            input = aux1;
          else 
              input = aux1-'0';
        }
    
        else{
            aux2 = (aux2*10) + aux1-'0';
            flagRecibi = 1;
        }
        aux1 = -1;
        error = 0;
        break;
      }

    if(kbhit()){              // wait for a key to be pressed
      aux1 = getch();          // Get the Key
      if (!is_Between_0_And_7(aux1)){
        if(aux1 == EXIT || aux1 == '\n')
            input = aux1;
        else 
            input = aux1-'0';
        }
    
    
    
      else{
          aux2 = (aux2*10) + aux1-'0';
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
          error = prenderLed(&puertoD.port, TAMANOPUERTO_16_T, input);
          flagRecibi = 0;
          
          break;
        
        case EXIT:
          break;
        
        default:
            if(primeraVuelta){
                primeraVuelta = 0;
                error =1;
            }
      }
    }

  }

  return 0;

}
