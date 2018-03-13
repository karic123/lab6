#ifndef TESTS_h
#define TESTS_h
#include<iostream>
#include "Node.h"
#include <vector>
#include "LinkedListOfInts.h"

class tests
{
public:
tests();
//constructor of test suite
void RunTests();
//runs tests in main.cpp

bool test1();
//this test checks is the linkedlist is empty upon creation
// T if empty, F otherwise

bool test2();
//this test checks if size=0 when a new list is created
//T if size = 0, F otherwise

bool test3();
//checks addFront function by adding 3 and checking if 3 nodes were added using size()
//T if size returns 3, F otherwise

bool test4();
//adds 3 nodes using addBack fuction. Checks if size returns 3.
//T is size returns 3, F otherwise

bool test5();
//adds 3 nodes, removes 1 using removeFront
//T if size = 2, F otherwise

bool test6();
//adds 3 nodes, removes 1 using removeBack
//T if size = 2, F otherwise

bool test7();
//makes linkedlist with values 5,6,7 and uses search to see if 6 is in the list
//T if 6 is in the list, F otherwise

bool test8();
//makes linkedlist with values 5,6,7 and uses search to see if 9 is in the list
//T if 9 is in the list, F otherwise

bool test9();
//checks to see if first value is correct after addFront(3).
//T is correct, F otherwise

bool test10();
//checks to see if last value is 9 after addBack(9).
//T if correct, F otherwise

bool test11();
//checks to see if 6 is in the list when we add it using addBack
//T if 6 is there, F otherwise

bool test12();
//Checks to see if 9 is not in the list when we don't add it using addBack
//T if not in list, F otherwise

bool test13();
//checks if the "last" element is correct after removeBack
//T if correct, F otherwise

bool test14();
//checks if the new front is correct after using removeFront
//T if correct, F otherwise

bool test15();
//removes back and checks if value is still in linked list
// T if value is not there, F otherwise

bool test16();
//removes front and checks if value is still in linked list
// T if value is not there, F otherwise
};
#endif
