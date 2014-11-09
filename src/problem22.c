#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#include "lib/common.h"
#include "lib/linkedlist.h"

#define names 5163

void quickSortString(char **strings, int start, int end);
void printStringArray(char **arr, int n);
void swapString(char **a, char **b);
int partition(char **strings, int start, int end);
char *loadData(char *name);
void cleanString(char *str, char *token);
char **splitString(char *str, char *token, int max);
int strValue(char *str);


int main()
{
	char *dat = loadData((char *)"p022_names.txt");
	char **arr = NULL;
	long long result = 0;
	cleanString(dat, (char *)"\"");
	arr = splitString(dat, (char *)",", names);
	quickSortString(arr, 0, names - 1);
	for(int i = 0; i < names; i++)
	{
		result += (i + 1) * strValue(arr[i]);
	}
	printf("Result: %lld\n", result);
	return 0;
}

int strValue(char *str)
{
	int len = (int)strlen(str);
	int sum = 0;

	for(int i = 0; i < len; i++)
	{
		sum += str[i] - 'A' + 1;
	}

	return sum;
}

void cleanString(char *str, char *token)
{
	char *pos = NULL;
	int tokenLen = (int)strlen(token);
	while ((pos = strstr(str, token)))
	{
		memmove(pos, pos + tokenLen, 1 + strlen(pos + tokenLen));
	}
}

char **splitString(char *str, char *token, int max)
{
	char **result = calloc((unsigned long)max, sizeof(char *));
	char *currentPosition = str;
	int counter = 0;
	int tokenLength = (int)strlen(token);
	char *tokenPosition = NULL;
	while((tokenPosition = strstr(currentPosition, token)))
	{
		int nameLength = (int)(tokenPosition - currentPosition);
		result[counter] = createAndInitialize(nameLength + 1);
		memmove(result[counter], currentPosition, nameLength);
		result[counter][nameLength] = '\0';
		currentPosition = tokenPosition + tokenLength;
		counter++;
	}
	int leftStringLen = (int)strlen(currentPosition);
	result[counter] = createAndInitialize(leftStringLen + 1);
	memmove(result[counter], currentPosition, leftStringLen);
	result[counter][leftStringLen] = '\0';
	return result;
}

char *loadData(char *name)
{
	char *line = createAndInitialize(names * 20);
	FILE *file = fopen(name, "r");
	if(!feof(file))
	{
		fscanf(file, "%s", line);
	}
	return line;
}

void printStringArray(char **arr, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d. %s\n", i, arr[i]);
	}
}

void swapString(char **a, char **b)
{
	char *tmp = *a;
	*a = *b;
	*b = tmp;
}

void quickSortString(char **strings, int start, int end)
{
	if(start < end)
	{
		int pivotId = partition(strings, start, end);
		quickSortString(strings, start, pivotId - 1);
		quickSortString(strings, pivotId + 1, end);
	}
}

int partition(char **strings, int start, int end)
{
	char *pivot = strings[start];
	int left = start;
	for(int i = start + 1; i <= end; i++)
	{
		if(strcmp(strings[i], pivot) < 0)
		{
			left++;
			swapString(&strings[i], &strings[left]);
		}
	}

	swapString(&strings[start], &strings[left]);
	return left;
}
