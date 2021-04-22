#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o, time.o, date.o, and calendar.o to executable main
main: main.o time.o date.o calendar.o
	g++ -std=c++11 -g -o main main.o time.o date.o calendar.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -std=c++11 -g -c main.cpp

#compile the time.cpp to time.o
time.o: time.cpp
	g++ -std=c++11 -g -c time.cpp

#compile the date.cpp to date.o
date.o: date.cpp
	g++ -std=c++11 -g -c date.cpp
	
#compile the calendar.cpp to calendar.o
calendar.o: calendar.cpp
	g++ -std=c++11 -g -c calendar.cpp

#remove built files
clean:
	rm -rf main main.o time.o date.o calendar.o *~
