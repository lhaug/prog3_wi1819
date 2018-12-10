.PHONY: run clean

a19: a19.c
	cc -g -ansi -pedantic -Wall a19.c -o a19
			

run: a19
	./a19
	
test: a19
	valgrind ./a19
	
bug: a19
	nemiver ./a19

clean: 
	rm a19
