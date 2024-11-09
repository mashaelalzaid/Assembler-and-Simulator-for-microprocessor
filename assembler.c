#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for strcmp


typedef struct {
    const char *instruction;
    const char *binary_code;
    } instructionMapping;

int main(int argc, char *argv[]) {
char *inputfile=argv[1];

char line[256];

// take assmb file open it and read it line by line
FILE *fptr = fopen(inputfile,"r");
    //fopen("fibonacci.asm", "r");
FILE *optr = fopen("fibonacci.bin","wb");

instructionMapping instr[9] = {
{"RA = RA + RB","00000000"},
{"RB = RA + RB","00010000"},
{"RA = RA - RB","00000100"},
{"RB = RA - RB","00010100"},
{"RO = RA","00100000"},
{"RA = imm","00001000"},
{"RB = imm","00011000"},
{"JC = imm","01110000"},
{"J = imm","10110000"}
};

while(fgets(line, sizeof(line), fptr)){
    line[strcspn(line, "\n")] = '\0';
  //  printf("%s", line);
    int found=0;
    for (int i=0; i<9; i++){

        if(strcmp(line, instr[i].instruction) == 0){
// create a new bin file to store the results inside it
           fwrite(instr[i].binary_code, 8,1, optr);
           fputc('\n', optr);
            found=1;
            break;
           } //else{
              // printf("Unrecognized instruction %s\n", line);
    
}            
  
    
    if(!found) {printf("Unrecognized %s\n", line);}
}


  
fclose(fptr);
fclose(optr);
printf("The file is now closed.");
return 0;}
