#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "assert.h"

#include "common.h"
#include "linkedlist.h"

int maxInt(int a, int b)
{
	if(a > b)
	{
		return a;
	}
	return b;
}


long isMultiple(long n,long m)
{
	return n % m == 0;
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

void aggregateList(list *lst, int arr[])
{
	listNode* current = lst->head;
	while(current != NULL)
	{
		long prime = getLongData(current->data);
		arr[prime]++;
		current = current->next;
	}
}

char *sum(char *a, char *b)
{
	int max = getMaxLength(a, b);
	char *result = createAndInitialize(max + 2);
	char reminder = 0;

	for(int i = 0; i < max + 1; i++)
	{
		char digit = getValue(a, i) + getValue(b, i) + reminder;
		if(digit >= 10)
		{
			reminder = 1;
			result[max - i] = digit - 10 + '0';
		}
		else
		{
			reminder = 0;
			result[max - i] = digit + '0';
		}
	}
	result[max + 1] = '\0';
	return trimLeadingZeroes(result);
}

char* scalarProduct(char *a, int n)
{
	assert(n > 0);
	char *result = zeroString();

	for(int i = 0; i < n; i++)
	{
		result = sum(result, a);
	}

	return result;
}

char* factorial(int n)
{
	assert(n > 0);
	char *result = zeroString();
	result[0] = '1';

	for(int i = 1; i <= n; i++)
	{
		result = scalarProduct(result, i);
	}
	return result;
}

char *zeroString()
{
	char *result = createAndInitialize(2);
	result[0] = '0';
	return result;
}

char *trimLeadingZeroes(char *str)
{
	if(str == NULL)
	{
		return NULL;
	}

	int i = 0;
	for(; i < (int)strlen(str) && str[i] == '0'; i++);
	if(i >= (int)strlen(str))
	{
		return NULL;
	}
	return str + i;
}

int getMaxLength(char *a, char *b)
{
	int strlenA = (int)strlen(a);
	int strlenB = (int)strlen(b);
	return strlenA > strlenB? strlenA : strlenB;
}

char *createAndInitialize(int n)
{
	char *result = calloc((unsigned long)n, sizeof(char));
	for(int i = 0; i < n; i++)
	{
		result[i] = '\0';
	}
	return result;
}

char getValue(char *str, int n)
{
	int len = (int)strlen(str);
	if(len <= n)
	{
		return 0;
	}

	return str[len - n - 1] - '0';
}
