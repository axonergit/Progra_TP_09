#include "draw.h"
#include "logic.h"
#include <math.h>

void draw_Base_Triangle(unsigned int side_Length){
    //draw_Split_Triangle();
}
void close_Base_Triangle(){
    
}
void draw_Split_Triangle(int rotation1,int rotation2, segment_t seg, segment_t * nuevoSeg1, segment_t * nuevoSeg2, unsigned int side_Length){
    
    
    unsigned int destino_final_x;
    unsigned int destino_final_y;
    /*
     * proyecto los verctices finales para trazar la linea.
     */
    
    nuevoSeg1->initial_Point.x = proyect_x(rotation1, side_Length, seg.initial_Point.x); 
    nuevoSeg1->initial_Point.y = proyect_y(rotation1, side_Length, seg.initial_Point.y);
    
    nuevoSeg2->initial_Point.x = proyect_x(rotation2, side_Length, seg.final_Point.x );
    nuevoSeg2->initial_Point.y = proyect_y(rotation2, side_Length, seg.final_Point.y);
    
    //dibujo las lineas.
    al_draw_line(seg.initial_Point.x, seg.initial_Point.y, nuevoSeg1->initial_Point.x , nuevoSeg1->initial_Point.y, al_color_name("papayawhip") , 40.0 );
    al_draw_line(seg.final_Point.x, seg.final_Point.y, nuevoSeg2->initial_Point.x , nuevoSeg2->initial_Point.y, al_color_name("papayawhip") , 40.0 );
    
    nuevoSeg1->final_Point.x = proyect_x(rotation1, side_Length, nuevoSeg1->initial_Point.x); 
    nuevoSeg1->final_Point.y = proyect_y(rotation1, side_Length, nuevoSeg1->initial_Point.y); 
    
    nuevoSeg2->final_Point.x = proyect_x(rotation1, side_Length, nuevoSeg2->initial_Point.x); 
    nuevoSeg2->final_Point.y = proyect_y(rotation1, side_Length, nuevoSeg2->initial_Point.y); 
    
    destino_final_x = proyect_x(rotation1, side_Length, nuevoSeg1->final_Point.x);
    destino_final_y = proyect_x(rotation1, side_Length, nuevoSeg1->final_Point.y);
    
    al_draw_line(nuevoSeg1->final_Point.x , nuevoSeg1->final_Point.y, destino_final_x, destino_final_y, al_color_name("papayawhip") , 40.0 );
    
    destino_final_x = proyect_x(rotation1, side_Length, nuevoSeg2->final_Point.x);
    destino_final_y = proyect_x(rotation1, side_Length, nuevoSeg2->final_Point.y);
    
    al_draw_line(nuevoSeg2->final_Point.x , nuevoSeg2->final_Point.y, destino_final_x, destino_final_y, al_color_name("papayawhip") , 40.0 );
    
}
void draw_No_Split_Triangle(int rotation1,int rotation2, segment_t seg, unsigned int side_Length){
    unsigned int destino_final_x;
    unsigned int destino_final_y;
    
    destino_final_x = proyect_x(rotation1, side_Length, seg.initial_Point.x);
    destino_final_y = proyect_y(rotation1, side_Length, seg.initial_Point.y);
    
    al_draw_line(seg.initial_Point.x, seg.initial_Point.y, destino_final_x, destino_final_y, al_color_name("papayawhip") , 40.0 );
    
    destino_final_x = proyect_x(rotation2, side_Length, seg.final_Point.x);
    destino_final_y = proyect_y(rotation2, side_Length, seg.final_Point.y);
    
    al_draw_line(seg.final_Point.x , seg.final_Point.y, destino_final_x, destino_final_y, al_color_name("papayawhip") , 40.0 );
    
}
double proyect_x(int rotation, unsigned int side_Length, unsigned int coordinate){
    
    return (coordinate + cos((rotation/180.0)*M_PI)*side_Length);
}
double proyect_y(int rotation, unsigned int side_Length, unsigned int coordinate){
    return (coordinate + sin((rotation/180.0)*M_PI)*side_Length);
}
