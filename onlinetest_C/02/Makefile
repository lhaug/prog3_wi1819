DATA = a2

.PHONY: run clean

$(DATA): $(DATA).c
	cc -g -ansi -pedantic -Wall $(DATA).c -o $(DATA)
			

run: $(DATA)
	./$(DATA)
	
test: $(DATA)
	valgrind ./$(DATA)
	
bug: $(DATA)
	nemiver ./$(DATA)

clean: 
	rm $(DATA)
