Bank: main.o Bank.o
	g++ -g main.o Bank.o -o Bank

main.o: main.cpp Bank.h
	g++ -g -c main.cpp

Bank.o: Bank.cpp Bank.h
	g++ -g -c functions.cpp

clean: 
	rm *.o Bank