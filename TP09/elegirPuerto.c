#include "termlib.h"
#include "elegirPuerto.h"
#include "display.h"

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
