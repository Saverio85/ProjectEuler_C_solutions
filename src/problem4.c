#include "stdio.h"
#include "lib/common.h"
#include "lib/linkedlist.h"
#include "math.h"
#include "assert.h"
#include "string.h"
#include "stdlib.h"

#define DMIN 100
#define DMAX 1000

char* longToString(long n);
long digits(long n);
bool palindrome(char* str);

int main()
{
	long result = 0;
	for(int i = DMIN; i < DMAX; i++)
	{
		for(int j = i; j < DMAX; j++)
		{
			long product = i * j;
			char *str = longToString(product);
			if((product > result) && (palindrome(str)))
			{
				result = product;
			}
		}
	}
	printf("Max palindrome product of 2 three digits numbers: %ld\n", result);
	return 0;
}

bool palindrome(char* str)
{
	long n = (long)strlen(str);
	long middle = (long) n/2;
	for(long i = 0; i <= middle; i++)
	{
		if(str[i] != str[n-i-1])
		{
			return false;
		}
	}
	return true;
}

char* longToString(long n)
{
	long length = digits(n);
	assert(length > 0);
	char* str = calloc((unsigned long)length, sizeof(char));
	snprintf(str, length, "%ld", n);
	assert(str[length] == '\0');
	return str;
}

long digits(long n)
{
	return (long)ceil(log10(n)) + 1;
}
