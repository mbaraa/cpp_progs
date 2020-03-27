#name of the output file
#this compiles the object files into an executable file
output: main.o message.o
	g++ main.o message.o -o output

#creating object file of the main.cpp
main.o: main.cpp
	g++ -c main.cpp

#creating object file of the message.cpp
main.o: message.cpp
	g++ -c message.cpp

#Note that the (-c) option in gcc compiles the ".cpp"
#file into an object file i.e ".o" file

#the action clean clears the directory as seen
clean:
		rm *.o
