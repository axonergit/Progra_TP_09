

#ifndef REGISTERS_H
#define REGISTERS_H


typedef struct{
    unsigned char b0 :1;
    unsigned char b1 :1;
    unsigned char b2 :1;
    unsigned char b3 :1;
    unsigned char b4 :1;
    unsigned char b5 :1;
    unsigned char b6 :1;
    unsigned char b7 :1;
}bitfield_8_t;

typedef struct{
    unsigned char b0 :1;
    unsigned char b1 :1;
    unsigned char b2 :1;
    unsigned char b3 :1;
    unsigned char b4 :1;
    unsigned char b5 :1;
    unsigned char b6 :1;
    unsigned char b7 :1;
    unsigned char b8 :1;
    unsigned char b9 :1;
    unsigned char b10 :1;
    unsigned char b11 :1;
    unsigned char b12 :1;
    unsigned char b13 :1;
    unsigned char b14 :1;
    unsigned char b15 :1;
}bitfield_16_t;

typedef union{
    
    bitfield_8_t bitPort;
    unsigned char port;
    
}puerto_8_t;

typedef struct{
    
    puerto_8_t puertoB;
    puerto_8_t puertoA;
    
}puerto_16_Dividido_t;

typedef union{
    
    bitfield_16_t port;
    unsigned short int;
    puerto_16_Dividido_t puertos;
    
}puerto_16_t;

#endif /* REGISTERS_H */

