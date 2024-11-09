#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALU.h"
#include "decoder.h"
#include "execute.h"
#include "processor.h" 



// user mode selection function
 char get_mode() {
          char mode;
          printf("Select one of the following mode\n");
          printf("R - Run in continuous mode\n");
          printf("S - Run step-by-step\n");
         printf("Select mode:");
          scanf(" %c", &mode);
return mode; 
 }

int main()
{
    char mode=get_mode();
    int instruction_count=0;
    unsigned char buffer[8]; //before it was 9
    unsigned char IM[16];
//    load binary file;
    FILE* file = fopen("fibonacci.bin", "rb");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (instruction_count < 16 && fread(buffer, sizeof(unsigned char),8, file) == 8) {
        
        unsigned char instruction=0x00;
    
    for(int i = 0; i<9; i++){
    instruction>>=1;
    
    if (buffer[i] =='1') {  //& 0x80) != 0){
            instruction = instruction | 0x80;
              }
       else if (buffer[i] == '0') { 
         } else { continue;}     
            }

    IM[instruction_count] = instruction;
     instruction_count++;

//     control_flags_t flags = check_control_flags(instruction);
//        printf("Flags: j=%d, c=%d, d1=%d, d0=%d, Sreg=%d, s=%d, imm1=%d, imm2=%d\n",
//               flags.j, flags.c, flags.d1, flags.d0, flags.Sreg, flags.s, flags.imm1, flags.imm2);
}

fclose(file);

// executing function unless its a jump condition
int PC = 0;
//control_flags_t flags;
Processor proc = {0};


if(mode == 'R'){
while (PC < instruction_count){
    control_flags_t flags = check_control_flags(IM[PC]);
    proc.imm = flags.imm1 + (flags.imm2 << 1) + (flags.s << 2);
    
    
    printf("\nExecuting instruction at PC=%d\n", PC);
    printf("Immediate value: %d\n", proc.imm);
    // previous register values
    int prev_Ra = proc.Ra;
    int prev_Rb = proc.Rb;
    int prev_R0 = proc.R0;

    printf("Register values from previous round RA %d RB %d and R0 %d\n", prev_Ra, prev_Rb, prev_R0);

    if(flags.j == 0){
    proc=execute(proc,flags);
    printf("Result Ra =%d, Rb=%d, R0=%d, Carry =%d\n",proc.Ra,proc.Rb, proc.R0, proc.carry);
    PC++;
    }
    else if(flags.j == 1 && flags.c==1 && proc.carry){
            PC=proc.imm;
            flags = check_control_flags(IM[PC]); //QUESTION How do i pass the immediate value ? 
	        proc=execute(proc,flags);
    printf("Result Ra =%d, Rb=%d, R0=%d, Carry =%d\n",proc.Ra,proc.Rb, proc.R0, proc.carry);
            
        } else if (flags.j==1 && flags.c==0){
            PC = proc.imm;
            flags = check_control_flags(IM[PC]);
	    proc=execute(proc,flags);
    printf("Result Ra =%d, Rb=%d, R0=%d, Carry =%d\n",proc.Ra,proc.Rb, proc.R0, proc.carry);
	}
		}
			}

else if (mode == 'S'){
        char step;
        while (PC < instruction_count) {
            printf("\nPress ENTER to execute next instruction:\n");
            step = getchar();
            
            control_flags_t flags = check_control_flags(IM[PC]);
            proc.imm = flags.imm1 + (flags.imm2 << 1) + (flags.s << 2);
            
            //printf("PC=%d, Instruction=%02X\n", PC, IM[PC]);
	    int prev_Ra = proc.Ra;      
	    int prev_Rb = proc.Rb;      
	    int prev_R0 = proc.R0;   
	    printf("Register values from previous round RA %d RB %d and R0 %d\n", prev_Ra, prev_Rb, prev_R0);        
            if (!flags.j) {
                proc = execute(proc, flags);
                PC++;
            }
               else if(flags.j == 1 && flags.c==1 && proc.carry){
              PC=proc.imm; 
              flags = check_control_flags(IM[PC]); //QUESTION How do i pass the immediate value ? 
                  proc=execute(proc,flags);
      printf("Result Ra =%d, Rb=%d, R0=%d, Carry =%d\n",proc.Ra,proc.Rb, proc.R0, proc.carry);
              
          } else if (flags.j==1 && flags.c==0){
              PC = proc.imm;
             flags = check_control_flags(IM[PC]);
              proc=execute(proc,flags);
      printf("Result Ra =%d, Rb=%d, R0=%d, Carry =%d\n",proc.Ra,proc.Rb, proc.R0, proc.carry);
          } 
	}}
	else {
printf("No value");
}


return 0;
}

