#include "assert.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "lib/common.h"
#include "lib/linkedlist.h"

#define N 20

void getMaxExp(list* list, int* arr);
long getData(void* data);

int main()
{
	int numbers[N] = {0};
	long result = 1;

	for(int i = 2; i < N; i++)
	{
		list *facts = factors(i);
		getMaxExp(facts, numbers);
	}

	for(int i = 2; i < N; i++)
	{
		result *= pow(i, numbers[i]); 
	}

	printf("Result: %ld\n", result);
	return 0;
}

void getMaxExp(list* list, int* arr)
{
	int tmp[N] = {0};
	listNode *node = list->head;

	while(node != NULL)
	{
		int value = (int)getLongData(node->data);
		tmp[value]++;
		node = node->next;
	}

	for(int i = 0; i < N; i++)
	{
		if(tmp[i] > arr[i])
		{
			arr[i] = tmp[i];
		}
	}
}
