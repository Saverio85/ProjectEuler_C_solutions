#include "stdio.h"
#include "stdlib.h"

#include "lib/common.h"
#include "lib/linkedlist.h"

#define max 1000000

long computeFlight(long n, long *arr);
long collatz(long n);

int main()
{
	long *arr = calloc(max, sizeof(long));
	arr[1] = 1;
	for(int i = 1; i < max; i++)
	{
		computeFlight(i, arr);
	}

	int result = maxLongArray(arr, max);
	printf("Result: %d\n", result);
	return 0;
}

long computeFlight(long n, long *arr)
{
	if(n == 1)
	{
		return 1;
	}

	if(n < max && arr[n] > 0)
	{
		return arr[n];
	}

	long flight = 1 + computeFlight(collatz(n), arr);
	if(n < max)
	{
		arr[n] = flight;
	}
	return flight;
}

long collatz(long n)
{
	return (n % 2 == 0)? n/2 : 3 * n + 1;
}
