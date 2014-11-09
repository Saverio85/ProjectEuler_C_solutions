#include "stdio.h"
#include "string.h"

#include "lib/common.h"
#include "lib/linkedlist.h"

#define n 100

int main()
{
	char* factorialResult = factorial(n);
	long sum = 0;

	for(int i = 0; i < (int)strlen(factorialResult); i++)
	{
		sum += factorialResult[i] - '0';
	}
	printf("%s\n", factorialResult);
	printf("%ld\n", sum);
	return 0;
}
