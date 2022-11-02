MyArray: test.o MyArray.o
	g++ -g test.o MyArray.o -o MyArray

test.o: test.cpp MyArray.h
	g++ -g -c test.cpp

MyArray.o: MyArray.cpp MyArray.h
	g++ -g -c MyArray.cpp

clean: 
	rm *.o MyArray