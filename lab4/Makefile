#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o, time.o, date.o, and calendar.o to executable main
main: main.o Stack.o
	g++ -std=c++11 -g -o main main.o Stack.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -std=c++11 -g -c main.cpp

#compile the time.cpp to time.o
Stack.o: Stack.cpp
	g++ -std=c++11 -g -c Stack.cpp

#remove built files
clean:
	rm -rf main main.o Stack.o *~
