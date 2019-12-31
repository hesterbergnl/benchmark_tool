#include <stdio.h>
#include <math.h>

int fib(int);

int main()
{
	int n = 35;
	int val = fib(n);
	printf("Fibbonaci with O2 optimization and recursion, %d input: %d\n", n, val);	
	
	return 0;
}

int fib(int n)
{
	if(n <= 1)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}
