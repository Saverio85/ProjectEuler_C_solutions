#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "lib/common.h"
#include "lib/linkedlist.h"

#define max 1000

int* factorsProduct(int n, int size);
long long binomial(int n, int m);

int main()
{
	long long result = binomial(40, 20);
	printf("result : %llu\n", result);
	return 0;
}

long long binomial(int n, int m)
{
	int* nfactors = factorsProduct(n, n);
	int* mfactors = factorsProduct(m, n);
	int* nmfactors = factorsProduct(n - m, n);

	long long result = 1;
	for(int i = 1; i < n; i++)
	{
		result *= pow(i, nfactors[i] - mfactors[i] - nmfactors[i]);
	}
	return result;
}

int* factorsProduct(int n, int size)
{
	int* result = calloc((unsigned long)size, sizeof(int));
	for(int i = 1; i <= n; i++)
	{
		list *lst = factors(i);
		aggregateList(lst, result);
	}	
	return result;
}
