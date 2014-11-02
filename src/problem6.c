#include "math.h"
#include "stdio.h"
#include "lib/common.h"
#include "lib/linkedlist.h"

#define max 100

int main()
{
	long long sumSquare = 0;
	long long squareSum = 0;

	for(int i = 0; i <= max; i++)
	{
		squareSum += pow(i, 2.0);
		sumSquare += (long long)i;
	}

	sumSquare = (long long)pow(sumSquare, 2.0);

	printf("%llu\n", sumSquare - squareSum);
	return 0;
}
