#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "assert.h"

#include "common.h"
#include "linkedlist.h"

long isMultiple(long n,long m)
{
	return n % m == 0;
}

long ceilSqrt(long n)
{
	return (long)(ceil(sqrt(n)));
}

int maxIntArray(int* arr, int size)
{
	assert(arr != NULL);
	assert(size > 0);

	int tmp = arr[0];
	for(int i = 1; i < size; i++)
	{
		tmp = (arr[i] > tmp)? arr[i] : tmp;
	}
	return tmp;
}

void printIntArray(int* arr, int size)
{
	assert(arr != NULL);
	assert(size > 0);

	for(int i = 0; i < size; i++)
	{
		printf("a[%d] = %d \n", i, arr[i]);
	}
}

int maxLongArray(long* arr, int size)
{
	assert(arr != NULL);
	assert(size > 0);

	int tmp = 0;
	for(int i = 1; i < size; i++)
	{
		tmp = (arr[i] > arr[tmp])? i : tmp;
	}
	return tmp;
}

void printLongArray(long* arr, int size)
{
	assert(arr != NULL);
	assert(size > 0);

	for(int i = 0; i < size; i++)
	{
		printf("a[%d] = %ld \n", i, arr[i]);
	}
}

long getLongData(void *data)
{
	long *target = malloc(sizeof(long));
	memcpy(target, data, sizeof(long));
	return *target;
}

list* factors(long n)
{
	long m = 3;
	list *lst = malloc(sizeof(list));
	list_new(lst, sizeof(long), NULL);

	while(n % 2 == 0)
	{
		long factor = 2;
		list_append(lst, &factor);
		n /= 2;
	}
	long max = ceilSqrt(n);
	while((n > 1) && (m <= max))
	{
		if(n % m == 0)
		{
			long factor = m;
			list_append(lst, &factor);
			n /= m;
			m = 3;
			max = ceilSqrt(n);
		}
		else
		{
			m += 2;
		}
	}
	if(n > 1)
	{
		long cpn = n;
		list_append(lst, &cpn);
	}
	return lst;
}
