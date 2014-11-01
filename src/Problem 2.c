#include "stdio.h"
#include "lib/common.h"

#define max 4000000

int main()
{
	long a = 1, b = 1, evenFibonacciSum;

	while(a < max)
	{
		if(isMultiple(a, 2))
		{
			evenFibonacciSum += a;
		}

		long tmp = a;
		a = a + b;
		b = tmp;
	}

	printf("%ld\n", evenFibonacciSum);
	return 0;
}