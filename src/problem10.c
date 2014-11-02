#include "math.h"
#include "stdio.h"
#include "lib/common.h"
#include "lib/linkedlist.h"

#define max 2000000

int main()
{
	long long sum = 0;
	short sieve[max] = {0};

	for(int i = 2; i < max; i++)
	{
		if(sieve[i] == 0)
		{
			sum += i;
			for(int j = i; j < max; j += i)
			{
				sieve[j] = 1;
			}
		}
	}
	printf("Result: %llu\n", sum);
	return 0;
}
