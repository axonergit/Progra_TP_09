#include <registers.h>
int bitSet(void * posPuerto, unsigned int tamanoPuerto , unsigned int numBit){
    
    int error =0;
    int numByte;
    char byte ,* p;
    
    if((tamanoPuerto * 8) < numBit ){
        printf("error.");
        error = 1;
    }
    else{
        p = (char *) posPuerto;
        numByte = numBit/8;
        p = p + numByte;
        
        byte = (*p);
        numBit = numBit % 8;
        byte = ( byte | (1 << numBit) );
        *p = byte;
    }
    return error;
}
int bitClr(void * posPuerto, unsigned int tamanoPuerto , unsigned int numBit){
    int error =0;
    int numByte;
    char byte ,* p;
    
    if((tamanoPuerto * 8) < numBit ){
        printf("error.");
        error = 1;
    }
    else{
        p = (char *) posPuerto;
        numByte = numBit/8;
        p = p + numByte;
        
        byte = (*p);
        numBit = numBit % 8;
        byte = ( byte & (~(1 << numBit)) );
        *p = byte;
    }
    return error;
}

int bitGet(void * posPuerto, unsigned int tamanoPuerto , unsigned int numBit){
    int error =0;
    int numByte;
    char byte ,* p;
    
    if((tamanoPuerto * 8) < numBit ){
        printf("error.");
        error = 2;
    }
    else{
        p = (char *) posPuerto;
        numByte = numBit/8;
        p = p + numByte;
        
        byte = (*p);
        numBit = numBit % 8;
        byte = ( byte & (1 << numBit) );
        
        error = (byte == 0) ? 0 : 1;
        
    }
    return error;
    
} 
int maskOn(void * posPuerto, unsigned int tamanoPuerto, char * mascara[]){
    int error;
    char * p;
    //falta chequear el error.
    p = (char *) posPuerto;
    int i;
    for(i = 0; i <tamanoPuerto ;i++){
        *(p+i) = (*(p+i)) | (*(mascara+i));
    }
    return error;
}

int maskOff(void * posPuerto, unsigned int tamanoPuerto, char * mascara[]){
    int error;
    char * p;
    //falta chequear el error.
    p = (char *) posPuerto;
    int i;
    for(i = 0; i <tamanoPuerto ;i++){
        *(p+i) = (*(p+i)) & (~(*(mascara+i)));
    }
    return error;
} 
