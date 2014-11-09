#include "stdio.h"

#include "lib/numerics.h"
#include "lib/common.h"
#include "lib/linkedlist.h"

#define max 28123

bool isAbundant(long n);
long sumDivisors(divisors *divs);
bool *generateAbundants(long n);
bool *sumOfAbundants(long n);


int main()
{
	long sum = 0;
	bool *res = sumOfAbundants(max);
	for(int i = 0; i < max; i++)
	{
		if(!res[i])
		{
			sum += i;
		}
	}
	printf("%ld\n", sum);
	return 0;
}

bool *sumOfAbundants(long n)
{
	bool* res = calloc((unsigned long) n, sizeof(bool));
	bool* abuntants = generateAbundants(n);

	for(long i = 1; i < n; i++)
	{
		res[i] = false;
		for(long j = 0; j < i; j++)
		{
			if(abuntants[j] && abuntants[i - j])
			{
				res[i] = true;
				break;
			}
		}
	}

	return res;
}

long sumDivisors(divisors *divs)
{
	long sum = 0;
	while(divs->next)
	{
		sum += divs->value;
		divs = divs->next;
	}
	return sum;
}

bool isAbundant(long n)
{
	factorization *f = factorize(n);
	divisors *divs = createDivisors(f);
	long sum = sumDivisors(divs);

	return sum > n;	
}

bool *generateAbundants(long n)
{
	bool *res = calloc((unsigned long) n, sizeof(bool));
	for(long i = 1; i < n; i++)
	{
		res[i] = isAbundant(i);
	}
	return res;
}
