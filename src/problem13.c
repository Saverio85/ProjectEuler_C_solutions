#include "string.h"
#include "stdio.h"
#include "stdlib.h"

#include "lib/common.h"
#include "lib/linkedlist.h"

#define num 100

char getValue(char *str, int n);
char *sum(char *a, char *b);
int getMaxLength(char *a, char *b);
char *trimLeadingZeroes(char *str);
char *createAndInitialize(int n);
char *unsafeSubstring(char *str, int n);

int main()
{
	char *result = createAndInitialize(2);
	result[0] = '0';

	FILE *fp = fopen("problem13.dat","r");
	while (!feof(fp)) 
	{
		char *line = calloc(num, sizeof(char));		
        fscanf(fp, "%s\r\n", line);
        if(line != NULL)
        {
    		result = sum(result, line);
        }
	}

	printf("Result: %s\n", unsafeSubstring(result, 10));
	return 0;
}

char *unsafeSubstring(char *str, int n)
{
	char *result = createAndInitialize(n);
	strncpy(result, str, n);
	return result;
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
