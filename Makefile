CC=gcc

CFLAGS=-Wall -g

OBJ=simulator.o ALU.o decoder.o execute.o

simulator: $(OBJ)
	$(CC) $(CFLAGS) -o simulator $(OBJ)

simulator.o: simulator.c ALU.h decoder.h execute.h processor.h
	$(CC) $(CFLAGS) -c simulator.c

execute.o: execute.c execute.h ALU.h decoder.h processor.h
	$(CC) $(CFLAGS) -c execute.c

decoder.o: decoder.c decoder.h
	$(CC) $(CFLAGS) -c decoder.c

ALU.o: ALU.c ALU.h
	$(CC) $(CFLAGS) -c ALU.c

clean:
	rm -f *.o simulator
