#include "termlib.h"
#include "elegirPuerto.h"
#include "display.h"

int elegirPuerto(void){
    unsigned int opcionElegida = 0;
    unsigned int flagError = 0;
    do{
        imprimirString("La siguiente simulacion puede realizarse en un puerto");
        imprimirString("de 8-bits o 16-bits.");
        imprimirString("Por favor elija el puerto deseado presionando un '1' para 8-bits");
        imprimirString("o un '2' para 16-bits:\n");
        if(kbhit())
            opcionElegida = getch();
        if((opcionElegida != 1) || (opcionElegida != 2)){
            flagError = 1;
            imprimirString("No se ha ingresado un valor correcto");         
        }
        flagError = 0;
    }
    while(flagError);
    return opcionElegida;
}
