#include "math.h"
#include "stdio.h"
#include "stdlib.h"

#include "lib/common.h"
#include "lib/linkedlist.h"

#define max 10000

int generateDivisors(int n);
int sumAmicables(int *arr, int size);
int *getAmicables(int *arr, int size);

int main()
{
	int *allDivisors = calloc(max, sizeof(int));
	int *amicables = NULL;

	for(int i = 1; i < max; i++)
	{
		allDivisors[i] = generateDivisors(i);
		//printf("%d - %d\n", i, allDivisors[i]);
	}
	amicables = getAmicables(allDivisors, max);

	printf("Result: %d\n", sumAmicables(amicables, max));
	return 0;
}

int sumAmicables(int *arr, int size)
{
	int sum = 0;
	for(int i = 1; i < size; i++)
	{
		if(arr[i])
		{
			sum += i;
		}
	}

	return sum;
}

int *getAmicables(int *arr, int size)
{
	int *result = calloc((unsigned long)size, sizeof(int));
	for(int i = 1; i < size; i++)
	{
		if(!result[i])
		{
			for(int j = i + 1; j < size; j++)
			{
				if(arr[i] < size &&  arr[j] < size && arr[i] == j && arr[j] == i)
				{
					result[i] = result[j] = 1;
					continue;
				}
			}
		}
	}

	return result;
}

int generateDivisors(int n)
{
	int sum = 0;
	int top = (int) ceil(n/2) + 1;
	for(int i = 1; i < top; i++)
	{
		if(n % i == 0)
		{
			sum += i;
		} 
	}
	return sum;
}
