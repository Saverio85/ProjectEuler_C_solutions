#include "math.h"
#include "stdio.h"
#include "stdlib.h"

#include "lib/common.h"
#include "lib/linkedlist.h"

#define mindiv 500

long long triangular(int n);
int triangularDivisors(int n);
int* groupFactors(list *a, list *b, int n);
void aggregateList(list *lst, int arr[]);

int main()
{
	int n = 1;
	for(;triangularDivisors(n) < mindiv; n++ );
	printf("Result: %d - %llu\n", n, triangular(n));
	return 0;
}

long long triangular(int n)
{
	return (long long)trunc((n * (n+1)) / 2);
}

int triangularDivisors(int n)
{
	list *factorsN = factors(n);
	list *factorsN_1 = factors(n + 1);
	int *grp = groupFactors(factorsN, factorsN_1, n + 1);
	int total = 1;

	for(int i = 0; i <= n; i++)
	{
		total *= (grp[i] + 1);
	}

	return total;
}

int* groupFactors(list *a, list *b, int n)
{
	int *result = (int *)calloc((unsigned long)n, sizeof(int));
	aggregateList(a, result);
	aggregateList(b, result);
	result[2]--;
	return result;
}

