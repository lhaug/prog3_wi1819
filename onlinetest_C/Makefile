DATA = rechner
.PHONY: run clean

rechner: $(DATA).c
	cc -g -ansi -pedantic -Wall $(DATA).c -o $(DATA)
			

run: $(DATA)
	./$(DATA)
	
test: $(DATA)
	valgrind ./$(DATA)
	
bug: $(DATA)
	nemiver ./$(DATA)

clean: 
	rm $(DATA)
