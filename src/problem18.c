#include "stdio.h"
#include "assert.h"
#include "stdlib.h"

#include "lib/common.h"
#include "lib/linkedlist.h"

#define totalLevels 15

int findMax(int* arr, int levels);
int getNumber(int level, int position, int* arr);
int firstLevelEntry(int n);
void printTriangularArray(int *arr, int levels);


int main()
{
	int data[] = {75,95,64,17,47,82,18,35,87,10,20,4,82,47,65,19,1,23,75,3,34,88,2,77,73,7,63,67,99,65,4,28,6,16,70,92,41,41,26,56,83,40,80,70,33,41,48,72,33,47,32,37,16,94,29,53,71,44,65,25,43,91,52,97,51,14,70,11,33,28,77,73,17,78,39,68,17,57,91,71,52,38,17,14,91,43,58,50,27,29,48,63,66,4,68,89,53,67,30,73,16,69,87,40,31,4,62,98,27,23,9,70,98,73,93,38,53,60,4,23};
	
	findMax((int *)data, totalLevels);
	printf("\nResult: %d\n", data[0]);
	return 0;
}

void printTriangularArray(int *arr, int levels)
{
	for(int i = 0; i < levels; i++)
	{
		int currentLevel = firstLevelEntry(i);
		int nextLevel = currentLevel + i + 1;
		for(int j = currentLevel; j < nextLevel; j++)
		{
			printf("%3d ", arr[j]);
		}
		printf("\n");
	}
}

int findMax(int* arr, int levels)
{
	assert(levels > 0);
	for(int i = totalLevels - 2; i >= 0; i--)
	{
		int first = firstLevelEntry(i);
		for(int j = 0; j < i + 1; j++)
		{
			int right = getNumber(i + 1, j, arr);
			int left = getNumber(i + 1, j + 1, arr);
			arr[first + j] += maxInt(right, left);
		}
	}

	return arr[0];
}

int getNumber(int level, int position, int* arr)
{
	if((position < 0) || (position > level))
	{
		return 0;
	}
	int s = firstLevelEntry(level); 

	return arr[s + position];
}

int firstLevelEntry(int n)
{
	return (n * (n + 1)) / 2;	
}
