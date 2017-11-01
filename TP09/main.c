#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include "termlib.h"
#include "registers.h"
#include "deff.h"
#include "led.h"
#include <unistd.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/display.h>
#include <allegro5/allegro_ttf.h>


int elegirPuerto(void);
int is_Between_0_And_7 (unsigned char input);
void recibir(char * aux1, char * aux2, char *input, int * flagRecibi);

int main(void)
{
  
  changemode(BUFFERED_OFF); // Turns terminal line buffering off
  clrscr();
  int error = 0, primeraVuelta =1;
  unsigned char input = 0;
  char aux1 = -1 ;
  char aux2 = 0;
  unsigned int flagRecibi = 0;
  unsigned int puerto_A_Elegir = 0;
  unsigned int portSize=0;
  puerto_8_t puertoA;
  puerto_16_t puertoD;

  puertoD.port = 0;           //inicializo el puerto, todos los leds apagados
  puertoA.port = 0;           //inicializo el puerto, todos los leds apagados

  puerto_A_Elegir = elegirPuerto();             //le pido al usuario que elija trabajar con puerto de 2 bytes o de 1 byte.

  if(puerto_A_Elegir == 2){
      portSize = TAMANOPUERTO_16_T;             //indico el tamano del puerto.
  }
  else if(puerto_A_Elegir == 1){
      portSize =TAMANOPUERTO_8_T;               //indico el tamano del puerto.
  }
  else
      imprimirString("Error\nIngrese nuevamente");


  char array [TAMANOPUERTO_16_T];                        //creo un arreglo que necesitara la funcion blinkAllOnLeds
  bienvenida();                                  //bienvenida al programa e instrucciones.

  recibir(&aux1, &aux2, &input, &flagRecibi);

  while(input != EXIT)          //salgo del while cuando el usuario lo indique y asi termina el programa
  {
    //imprimire el puerto que corresponda actualizando su estado cada vez qeu entre al while
    if(portSize == 1)
        byte_to_2(puertoA.port);
    else if (portSize == 2){
        byte_to_2(puertoD.puertos.puertoA.port);
        byte_to_2(puertoD.puertos.puertoB.port);
    }
    printf("\n");
    sleep(1);            //retardo entre estados.

    if(error)               //si hubo error se solicita input obligatorio, bloqueante.
      while(!kbhit()){
        // mismo criterio que antes para discernir en cuanto al input
        recibir(&aux1, &aux2, &input, &flagRecibi);

        error = 0;
        break;
      }
    // chequeo cada vez que corra el while si el usuario presiono el keyboard y acciono en caso que lo haya hecho.
    //esto permite no interrumpir el programa y que el estado de los leds se siga actualizando
    if(kbhit())              // check if a key was pressed
      recibir(&aux1, &aux2, &input, &flagRecibi);
    

    else{
      switch (input)
      {
        case BLINK:         //hace blinkear a los leds UNA SOLA VEZ PR WHILE
          if(portSize == 2)
            error = blinkAll_On_Leds(&puertoD.port, portSize, array);
          else
            error = blinkAll_On_Leds(&puertoA.port, portSize, array);

          break;


        case OFF:       //apaga todos los leds
          if(portSize == 2)
            error = apagarLeds(&puertoD.port, portSize);
          else
            error = apagarLeds(&puertoA.port, portSize);

          break;

        case ON:        // prende a todos los leds
          if(portSize == 2)
            error = PrenderLeds(&puertoD.port, portSize);
          else
            error = PrenderLeds(&puertoA.port, portSize);

          break;

        case '\n':
          if(portSize == 2){
            if(flagRecibi){
                input = aux2;
                error = prenderLed(&puertoD.port, portSize, input);
                flagRecibi = 0;
            }
            aux2 = 0;
          }
          else{
            if(flagRecibi){
               input = aux2;
               error = prenderLed(&puertoA.port, portSize, input);
               flagRecibi = 0;
            }
          aux2 = 0;
          }

          break;

        case EXIT:
          break;
        default:
          if(primeraVuelta){          // chequeo si es la primera vez que corre el while
            primeraVuelta = 0;
            error =1;               //si es la 1ra vez entonces se;anlo que necesito un input extra obligatorio en caso de haber recibido un numero.
          }
        break;

      }
    }

  }

  changemode(BUFFERED_ON);
  return 0;

}

int elegirPuerto(void){
    unsigned int opcionElegida = 0;
    unsigned int flagError = 0;
    do{                 //Pido al usuario que elija tamaño de puerto que desee simular
        imprimirString("La siguiente simulacion puede realizarse en un puerto");
        imprimirString("de 8-bits o 16-bits.");
        imprimirString("Por favor elija el puerto deseado presionando un '1' para 8-bits");
        imprimirString("o un '2' para 16-bits:\n");
        while(!kbhit()){
            opcionElegida = getch();       //Pido si o si un input, por eso uso getchar, para esperar al enter.
            break;
        }

        if((opcionElegida != '1') && (opcionElegida != '2')){     //Chequeo si se uso un input valido
            flagError = 1;          //Prendo mi flag de error
            imprimirString("No se ha ingresado un valor correcto.");   //Pido que se ingrese un input valido
            imprimirString("Vuelva a ingresar un valor, pero esta vez correcto.");
        }
        else
            flagError = 0;        //Reseteo el flag de error
    }
    while(flagError);       //Pido al usuario input hasta que elija una opcion valida
    return (opcionElegida -'0');
}

int is_Between_0_And_7 (unsigned char input){

	int flagNotError;
	if( (input >= '0') && (input <= '7') )				//Chequeo si se ha ingresado un numero entre 0 y 7
		flagNotError = 1;								//Dee ser asi prendo mi flag de no error
	else
		flagNotError = 0;							//Sino hubo error

	return flagNotError;					//Devuelvo si hay error
}

void recibir(char * aux1, char * aux2, char *input, int * flagRecibi){
    *aux1 = getch();         
        if (!is_Between_0_And_7(*aux1))
            *input = *aux1;
        
        else{
            *aux2 = (*aux2)*10 + (*aux1)-'0';
            *flagRecibi = 1;
        }
        *aux1 = -1;
}
