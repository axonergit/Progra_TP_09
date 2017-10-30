#include "led.h"
#include "registers.h"
#include <unistd.h>
#include "display.h"

int prenderLed(void * posPuerto, unsigned int tamanoPuerto, unsigned int numLed){
    return bitSet(posPuerto, tamanoPuerto , numLed);    //Pongo un bit prendido en el puerto en donde corresponde
}
int blinkAll_On_Leds(void * posPuerto, unsigned int tamanoPuerto ,char array[]){

    //Creo mis variables
    char * puerto = (char *) posPuerto;
    int error;
    int i =0;
    for(i =0; i < tamanoPuerto;i++){
        array[i] =  *((char *)posPuerto+i);              //Copio el puerto entero como mascara
    }
    error = apagarLeds(posPuerto, tamanoPuerto);        //Apago todos los leds

    for(i =0; i < (tamanoPuerto);i++){
        byte_to_2(0);
    }
    imprimirString("");
    sleep(1);                                           //Dejo pasar un segundo
    if(!error)
        error = maskOn(posPuerto, tamanoPuerto, array);    //Vuelvo a prenderlos con lo mismo que tenian antes

    return error;
}
int apagarLeds(void * posPuerto, unsigned int tamanoPuerto){
    int led,error;

    for(led=0 ;led < (tamanoPuerto*8); led++){            //Recorro cada uno de los leds y los voy apagando
        error = bitClr(posPuerto, tamanoPuerto , led);
        if(error)
            break;
    }
    return error;

}
int PrenderLeds(void * posPuerto, unsigned int tamanoPuerto){
    int led,error;

    for(led=0 ;led < (tamanoPuerto*8); led++){            //Recorro cada uno de los leds y los voy prendiendo
        error = bitSet(posPuerto, tamanoPuerto , led);
        if(error)
            break;
    }
    return error;

}
