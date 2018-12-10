.SUFFIXES: .c .h .o

.PHONY: run clean

a16: textfun.o main.o
	cc -o a16 textfun.o main.o
	
textfun.o: textfun.c
	gcc -c -ansi -pedantic -Wall textfun.c -o textfun.o

main.o: main.c
	gcc -c -g -ansi -pedantic -Wall main.c -o main.o
			

run:a16
	valgrind ./a16 kunft=yo Haus=Unterkunft


clean: 
	rm textfun.o
	rm main.o
	rm a16
