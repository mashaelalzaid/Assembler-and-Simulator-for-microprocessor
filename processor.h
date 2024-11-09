#ifndef PROCESSOR_H
#define PROCESSOR_H


typedef struct {
    int Ra;      
    int Rb;      
    int R0;      
    int PC;    
    int carry;
    int imm;
} Processor;

#endif
