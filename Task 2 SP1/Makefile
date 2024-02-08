# Command 
CC = gcc
# For make static library
AR = ar 

# Flags setup

# Triggers many warnings for problems in the source code, helps identify possible errors
# and adds debug information when compiling, useful for running a debugger to find faults in the code.
 CFLAGS = -Wall -g
#defines to create a dynamic library (shared library) instead of an executable file.
LFLAGS = -shared
#definition of an archiver (archiver) for make a static library.
SFLAGS = rcs
#adds instructions to PIC, which allows the dynamic library to be loaded anywhere in memory regardless of position and avoid from used same memory in different librarys.
FP = -fPIC


# File names
GRAPH = my_graph.c
HEADER = my_mat.h
SRC = my_mat.c
PARTWO = my_Knapsnap.c

# Phony tag for non-targeted commands
.PHONY: all clean 

# Build everything 
all: my_graph my_Knapsnap

my_graph: my_graph.o my_mat.o
	$(CC) my_graph.o my_mat.o -o my_graph 

my_Knapsnap: my_Knapsnap.o 
	$(CC) my_Knapsnap.o -o my_Knapsnap

my_Knapsnap.o: $(PARTWO)
	$(CC) $(CFLAGS) -c $(PARTWO)
# The main program
my_graph.o: $(GRAPH) $(HEADER)  
	$(CC) $(CFLAGS) -c my_graph.c

# The additional source file
my_mat.o: $(SRC) $(HEADER)
	$(CC) $(CFLAGS) -c $(SRC)



# Clean command to cleanup all the compiled files (*.o, *.a, *.so, *.gch)
clean:
	rm -f mains  *.o *.a *.so *.gch