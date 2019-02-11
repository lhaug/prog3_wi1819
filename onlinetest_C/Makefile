.PHONY: run clean

rechner: rechner.c
	cc -g -ansi -pedantic -Wall rechner.c -o rechner
			

run: rechner
	./rechner
	
test: rechner
	valgrind ./rechner
	
bug: rechner
	nemiver ./rechner

clean: 
	rm rechner
