#include <stdio.h>
#include <stdlib.h>
#include "testBench.h"
#include "display.h"
#include "termlib.h"
#include "registers.h"
#include "deff.h"
#include "logic.h"
#include "led.h"
#include "elegirPuerto.h"
#include <unistd.h>


int main(void)
{
  changemode(BUFFERED_OFF); // Turns terminal line buffering off
  clrscr();
  int error = 0, primeraVuelta =1;
  unsigned char input = 0;
  char aux1 = -1 ;
  char aux2 = 0;
  unsigned int flagRecibi = 0;
  unsigned int sleepTime;
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
  
      aux1 = getch();          // Get the Key       //recibo el primer input por usuario. Obligatorio asi qeu es bloqueante.
      
      //chequeo si el usuario ingreso un numero valido o un caracter especial.
      if (!is_Between_0_And_7(aux1))            
          input = aux1;             //caracter especial, direcatmente pasa a ser el input y tendra una accion inmediata.
      else{
          aux2 = (aux2*10) + aux1-'0';  //numero, convierto e indico que recibi un numero, no tendra accionar el numero hasta recibir un enter.
          flagRecibi = 1;
      }
      aux1 = -1;                //reseteo la variable auxiliar para recibir input.



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
    sleepTime = sleep(0.5);            //retardo entre estados.
    
    if(error)               //si hubo error se solicita input obligatorio, bloqueante.
      while(!kbhit()){
        // mismo criterio que antes para discernir en cuanto al input
        aux1 = getch();
        if (!is_Between_0_And_7(aux1))
            input = aux1;
    
        else{
            aux2 = (aux2*10) + aux1-'0';
            flagRecibi = 1;
        }
        aux1 = -1;
        error = 0;
        break;
      }
    // chequeo cada vez que corra el while si el usuario presiono el keyboard y acciono en caso que lo haya hecho.
    //esto permite no interrumpir el programa y que el estado de los leds se siga actualizando
    if(kbhit()){              // check if a key was pressed
      aux1 = getch();          // Get the Key
      if (!is_Between_0_And_7(aux1))        
            input = aux1;
      else{
          aux2 = (aux2*10) + aux1-'0';
          flagRecibi = 1;
      }
      aux1 = -1;
    }
 
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
