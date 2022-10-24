BankAccount: main.o BankAccount.o
	g++ -g main.o BankAccount.o -o BankAccount

main.o: main.cpp BankAccount.h
	g++ -g -c main.cpp

BankAccount.o: BankAccount.cpp BankAccount.h
	g++ -g -c functions.cpp

clean: 
	rm *.o BankAccount