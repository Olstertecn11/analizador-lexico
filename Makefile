all: main


main: main.o func.o
	g++ -std=c++17 -o main main.o func.o

main.o: main.cpp
	g++ -c main.cpp

func.o: func.cpp func.h
	g++ -c func.cpp

clean:
	rm *.o main
