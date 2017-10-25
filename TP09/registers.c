#include <stdio.h>
#include <stdlib.h>

    typedef unsigned char uint8_t;
    typedef struct
    {
        uint8_t bit_7 : 1;
        uint8_t bit_6 : 1;
        uint8_t bit_5 : 1;
        uint8_t bit_4 : 1;
        uint8_t bit_3 : 1;
        uint8_t bit_2 : 1;
        uint8_t bit_1 : 1;
        uint8_t bit_0 : 1;
    }BITFIELD_PORT8;

    typedef struct
    {
        uint8_t bit_15 : 1;
        uint8_t bit_14 : 1;
        uint8_t bit_13 : 1;
        uint8_t bit_12 : 1;
        uint8_t bit_11 : 1;
        uint8_t bit_10 : 1;
        uint8_t bit_9 : 1;
        uint8_t bit_8 : 1;
        uint8_t bit_7 : 1;
        uint8_t bit_6 : 1;
        uint8_t bit_5 : 1;
        uint8_t bit_4 : 1;
        uint8_t bit_3 : 1;
        uint8_t bit_2 : 1;
        uint8_t bit_1 : 1;
        uint8_t bit_0 : 1;
    }BITFIELD_PORT16;

    typedef struct
    {
            BITFIELD_PORT8 port_B;
            BITFIELD_PORT8 port_A;
    }PUERTOS_AB_BITS;

    typedef struct
    {
            unsigned char port_B;
            unsigned char  port_A;
    }PUERTOS_AB;


    typedef union
    {
        /* BIT ACCESO */
        PUERTOS_AB_BITS ports_AB_bit;
        BITFIELD_PORT16 port_D_bit;

        /* PUERTA ACCESO */
        PUERTOS_AB ports_AB;
        unsigned short int port_D;

    }PORT;


void print_port_bin(PORT d);

int main(void)
{


    printf("%d - %d - %d \n", sizeof(unsigned char), sizeof(short int), sizeof(unsigned int));

    PORT compu;
    printf("%d \n",sizeof(compu) );

    compu.ports_AB_bit.port_A.bit_0 = 1;
    compu.ports_AB_bit.port_B.bit_1 = 1;

    print_port_bin(compu);

    compu.port_D_bit.bit_2 = 1;
    print_port_bin(compu);

    compu.ports_AB.port_A = 0b11001100;
    compu.ports_AB.port_B = 0b11110000;

    print_port_bin(compu);
    compu.port_D = 0b1111111111111111;
    print_port_bin(compu);

}

/*
    Print the value of the PORT (16 bits) in a binomial format
*/
void print_port_bin(PORT d)
{
    printf("%d%d%d%d ",d.port_D_bit.bit_0, d.port_D_bit.bit_1, d.port_D_bit.bit_2, d.port_D_bit.bit_3);
    printf("%d%d%d%d ",d.port_D_bit.bit_4, d.port_D_bit.bit_5, d.port_D_bit.bit_6, d.port_D_bit.bit_7);
    printf("%d%d%d%d ",d.port_D_bit.bit_8, d.port_D_bit.bit_9, d.port_D_bit.bit_10, d.port_D_bit.bit_11);
    printf("%d%d%d%d\n",d.port_D_bit.bit_12, d.port_D_bit.bit_13, d.port_D_bit.bit_14, d.port_D_bit.bit_15);
}


