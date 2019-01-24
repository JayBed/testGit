
# default command, builds an executable called "newton".
# executable can be called with ./newton 49 4
all: newton

# link the object files into the executable.
# the -lm option is to tell the linker to include math libraries.
newton: newton.o comparison.o main.o  
	gcc -o $@ $^ -lm

# compile the newton.c file into the newton.o object file.
newton.o: newton.c newton.h
	gcc -o $@ -c $<

# compile the comparison.c file into the comparison.o object file.
comparison.o: comparison.c comparison.h
	gcc -o $@ -c $<

# compile the main.c file into the main.o object file.
main.o: main.c newton.h comparison.h
	gcc -o $@ -c $<

# remove the executable and intermediary object files.
clean:
	rm -rf newton main.o newton.o comparison.o

