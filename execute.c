#include "execute.h"
#include "ALU.h"
#include "decoder.h"
#include "processor.h"
#include <stdio.h>

Processor execute(Processor proc,control_flags_t flags){

//int Ra=0, Rb=0, R0=0;
//first ALU 
ALU alu_result = alu(proc.Ra, proc.Rb, flags.s);
//second the result of ALU will go to two places DFF and back to mux 
proc.carry = (alu_result.carry!=0)? 1:0;

//decoder implementation
int decoder_eA=0;
int decoder_eB=0; 
int decoder_e0=0;

if(flags.d0 == 0 && flags.d1 == 0){
    decoder_eA=1;
    }
    else if (flags.d0==1 && flags.d1 ==0){
	decoder_eB=1;
        }
    else if (flags.d0 == 0 && flags.d1 ==1){
	decoder_e0=1;
        }

// Mux implementation
int mux;

if(flags.Sreg == 1){
	mux = (flags.Sreg==1)? alu_result.result : proc.imm;
    }
proc.Ra = (decoder_eA==1)? mux:0; // QUESTION if i need to keep the last stored value should i use the long if format?
printf("Ra= %d\n", proc.Ra);
proc.Rb = (decoder_eB==1)? mux:0;
//QUESTION how can i send these values back to ALU ?
printf("Rb= %d\n", proc.Rb);
if(decoder_e0==1){
proc.R0=proc.Ra;
printf("RO= %d\n", proc.R0);
    }


return proc;}
