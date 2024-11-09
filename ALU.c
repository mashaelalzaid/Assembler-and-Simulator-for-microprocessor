#include "ALU.h"


ALU alu(int Ra, int Rb, int control) {
    ALU ALU;

    switch (control) {
        case 0:
        ALU.result = Ra + Rb;
        ALU.carry = (Ra&Rb)? 1:0;
        break;
        case 1: 
        ALU.result=Ra - Rb;
        ALU.carry=0;
        break;
    }

    return ALU;

}

