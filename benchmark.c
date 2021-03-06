#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <time.h>

int loopFib(int);
int recFib(int);
void * recursiveThread(void *);

int n, threads, val;

int main()
{
	clock_t start, end;
	double cpu_time_used;

	printf("Please enter the number of fibbonaci sequence numbers> ");
	scanf("%d", &n);
	printf("Please enter the number of parallel threads> ");
	scanf("%d", &threads);
	
	pthread_t threadArray[threads];
	
	//create thread attribute and initalize it
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	start = clock();
	for(int i = 0; i < threads; i++) {
		pthread_create(&threadArray[i], &attr, recursiveThread, NULL);
	}

	for(int i = 0; i < threads; i++) {
		pthread_join(threadArray[i], NULL);
	}
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
	printf("Without optimization\n");
	printf("Input size: %d\n", n);
	printf("Final Value: %d\n", n);
	printf("------------------------------------\n");
	printf("Fibbonaci recursive algorithm, total time: %f seconds\n", cpu_time_used);
	
	start = clock();
	for(int i = 0; i < threads; i++) {
		pthread_create(&threadArray[i], &attr, recursiveThread, NULL);
	}

	for(int i = 0; i < threads; i++) {
		pthread_join(threadArray[i], NULL);
	}
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	
	printf("Fibbonaci loop algoirthm, total time: %f seconds\n", cpu_time_used);	
	
	return 0;
}

void *recursiveThread(void *param)
{
	val = recFib(n);
	pthread_exit(NULL);
}

void *loopThread(void *param)
{
	val = loopFib(n);
	pthread_exit(NULL);
}

int recFib(int n)
{
	if(n <= 1)
		return n;
	else
		return recFib(n - 1) + recFib(n - 2);
}

int loopFib(int n)
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
