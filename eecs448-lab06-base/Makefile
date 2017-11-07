#	Author: John Gibbons
#	Date: 2016.10.26


#Add needed Test.o
prog: main.o tests.o LinkedListOfInts.o
	g++ -g -Wall -std=c++11 main.o tests.o LinkedListOfInts.o -o prog


main.o: main.cpp tests.cpp tests.h
	g++ -g -Wall -std=c++11 -c main.cpp

#Add needed Test.o recipe and compiler command
tests.o: tests.cpp tests.h
		g++ -g -Wall -std=c++11 -c tests.cpp

#DON'T delete LinkedList.o!
clean:
	rm main.o *.*~ prog
