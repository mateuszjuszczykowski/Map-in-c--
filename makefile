# List your *.h files here:
headers = Employee.h Map.h BookInfo.h

# List your *.c files here:
sources = Test.cpp

program: $(headers) $(sources)
	g++ -g -Wall -pedantic $(sources) -o program

.PHONY: clean check debug

clean:
	-rm program

check: program
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./program

debug: program
	gdb program
