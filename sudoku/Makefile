#name of the executable file
output: ./src/main.o 
	g++ ./src/main.o -o ./bin/sudoku

#creating object files , well it's one file over here
main.o: ./src/main.cpp
	g++ -c ./src/main.cpp

#actions

clean:
	rm *.o

install:
	cp ./bin/sudoku /usr/bin

