#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENT ME: Declare your functions here */
int add (int a, int b);
int sub (int a, int b);
int mult (int a, int b);
int divi (int a, int b);

int (*pointers[4])(int a, int b);

int main (void)
{
	int a = 6;
	int b = 3;
	int operation;


	pointers[0]=add;
	pointers[1]=sub;
	pointers[2]=mult;
	pointers[3]=divi;


	printf("choose an operation: 0: add | 1: subtract | 2: multiply |3:divide\n");
	scanf("%d", &operation);

	int result = (*pointers[operation])(a,b);
	printf("result: %d\n", result);

	return 0;
}

/* IMPLEMENT ME: Define your functions here */
int add (int a, int b) { printf ("Adding %d and %d\n", a, b); return a + b; }
int sub (int a, int b) { printf ("Subtracting %d from %d\n", b, a); return a-b;}
int mult (int a, int b) { printf ("Multiplying %d and %d\n", a, b); return a*b;}
int divi (int a, int b) { printf ("Dividing %d by %d\n", a, b); return a/b;}
