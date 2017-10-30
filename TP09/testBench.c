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

  char array [TAMANOPUERTO_16_T];
  bienvenida();             //Explico la simulacion del puerto al usuario

  aux1 = getch();          // Busco la tecla

      if (!is_Between_0_And_7(aux1))      //Chequeo que me hayan pasado un numero de bit
          input = aux1;                     //si no lo recibi le asigno el valor a input


      else{
          aux2 = (aux2*10) + aux1-'0';    //Acomodo mi input en caso de haber recibido mas de un numero
          flagRecibi = 1;           //Prendo el flag para saber que recibi un numero
      }
      aux1 = -1;              //Vuelvo a settear en su valor original



  while(input != EXIT)                //Chequeo que no haya terminado
  {

    printf("%c",'0'+puertoD.bitPort.b15);         //Imprimo los bits del puerto
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
    sleep(0.01);

    if(error)
      while(!kbhit()){            //Mientras no se oprima una tecla asigno el valor obtenido a mi variable
        aux1 = getch();
        if (!is_Between_0_And_7(aux1))        //Chequeo si recibo un numero de bit del puerto
            input = aux1;                   //De no ser asi igualo input a lo recibido

        else{
            aux2 = (aux2*10) + aux1-'0';      //Acomodo mi input en caso de haber recibido mas de un numero
            flagRecibi = 1;                 //Si recibi un numero prendo el flag
        }
        }
        aux1 = -1;                  //Vuelvo a su valor original
        error = 0;                    //Borro error
        break;
      }

    if(kbhit()){              //Espero a que se presione una tecla
      aux1 = getch();                   //Busco la tecla oprimida
      if (!is_Between_0_And_7(aux1))          //Chequeo que sea un numero de bit del puerto
            input = aux1;                   //De no ser asi igualo input a lo recibido



      else{
          aux2 = (aux2*10) + aux1-'0';        //Acomodo mi input en caso de haber recibido mas de un numero
          flagRecibi = 1;               //Si recibi un numero prendo el flag

      }
      aux1 = -1;
    }

    else{
      switch (input)            //Chequeo en que caso estoy
      {
        case BLINK:             //Chequeo si estoy en el caso de parpadear
          error = blinkAll_On_Leds(&puertoD.port, TAMANOPUERTO_16_T, array);
          break;

        case OFF:             //Chequeo si estoy en el caso de apagar los leds
          error = apagarLeds(&puertoD.port, TAMANOPUERTO_16_T);
          break;

        case ON:              //Chequeo si estoy en el caso de prender los leds
          error = PrenderLeds(&puertoD.port, TAMANOPUERTO_16_T);
          break;

        case '\n':            //Chequeo si estoy en el caso de enter para la funcion bitSet
          if(flagRecibi){
          input = aux2;         //Si recibi un numero igualo el input a mi segunda variable auxiliar
          error = prenderLed(&puertoD.port, TAMANOPUERTO_16_T, input);
          flagRecibi = 0;       //Reseteo el flag
          }
          aux2 = 0;             //Reseteo mi variable auxiliar
          break;

        case EXIT:            //Chequeo si estoy en el caso de terminado
          break;

        default:              //Si no recibo nada
            if(primeraVuelta){          //Chequeo si es la primer vuelta
                primeraVuelta = 0;      //Reseteo el valor
                error =1;
            }
      }
    }

  }

  return 0;

}
