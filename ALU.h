// alu.h
#ifndef ALU_H
#define ALU_H

typedef struct {
    int result;
    int carry;
    } ALU;

ALU alu(int Ra, int Rb, int control);

#endif

