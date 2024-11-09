#ifndef DECODER_H
#define DECODER_H

typedef struct {
       int j;
    int c;
    int d1;
    int d0;
    int Sreg;
    int s;
    int imm1;
    int imm2;

} control_flags_t;

control_flags_t check_control_flags(unsigned char byte); 

#endif
