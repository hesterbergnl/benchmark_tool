#include <stdio.h>

int fib(int);

int main()
{
	int n = 35;
	int val = fib(n);
	printf("Fibbonaci with optimization, %d input: %d\n", n, val);

	return 0;
}

int fib(int n)
{
	int val1 = 0;
	int val2 = 1;
	int nextVal;

	for(int i = 0; i < n; i++){
		nextVal = val1 + val2;
		val1 = val2;
		val2 = nextVal;
	}

	return val1;
}
