#include "logic.h"

void koch(unsigned int orderN, unsigned int side_Length){
    
    draw_Base_Triangle(side_Length);
    
    segment_t base;
    segment_t costado_Derecho;
    segment_t costado_Izquierdo;
    if(orderN > 0){
        recursive_koch(orderN-1, side_Length/3);        
        recursive_koch(orderN-1, side_Length/3);
        recursive_koch(orderN-1, side_Length/3);
    }
    else 
        close_Base_Triangle();
}
void recursive_koch(unsigned int orderN, unsigned int side_Length,int rotation1, int rotation2, segment_t seg){
    
    segment_t nuevoSeg1;
    segment_t nuevoSeg2;
    
    if(orderN == 0){
        draw_No_Split_Triangle(rotation1, rotation2, seg, side_Length);
    }
    else {
        draw_Split_Triangle(rotation1, rotation2, seg, &nuevoSeg1, &nuevoSeg2, side_Length/3);
        //falta cambiar el angulo de rotacion 1 y el angulo de rotacion 2.
        recursive_koch(orderN-1, side_Length/3, rotation1, rotation2, nuevoSeg1);
        recursive_koch(orderN-1, side_Length/3, rotation1, rotation2, nuevoSeg2);
    }
    
}

