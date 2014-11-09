#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "assert.h"

#include "common.h"
#include "linkedlist.h"

typedef struct 
{
	long base;
 	long exponent;
} factor;

typedef struct factorization
{
	factor *factor;
	struct factorization *next;
} factorization;

typedef struct divisors
{
	long value;
	struct divisors *next;
} divisors;

divisors *createDivisor(long n)
{
	divisors *el = malloc(sizeof(divisors));
	el->next = NULL;
	el->value = n;

	return el;
}

void addDivisor(divisors *dvs, long n)
{
	divisors *current = dvs;
	for(; current->next != NULL; current = current->next);
	divisors *el = createDivisor(n);
	current->next = el;
}

long *divisorsToArray(divisors *divs)
{
	divisors *current = divs;
	long count = 0;
	long *result = NULL;

	while(current)
	{
		current = current->next;
		count++;
	}

	current = divs;
	result = calloc((unsigned long)count, sizeof(long));
	for(long i = 0; i < count; i++)
	{
		result[i] = current->value;
		current = current->next;
	}

	return result;
}

factor *createFactor(long n)
{
	factor *fact = malloc(sizeof(factor));
	fact->base = n;
	fact->exponent = 1;

	return fact;
}

factorization *createFactorization(long n)
{
	factorization *facts = malloc(sizeof(factorization));
	facts->factor = createFactor(n);
	facts->next = NULL;

	return facts;
}

void addFactor(factorization **facts, long n)
{
	assert(n > 1);
	if(*facts == NULL)
	{
		*facts = createFactorization(n);
	}
	else
	{
		factorization *tail = NULL;
		factorization *current = *facts;
		while(current)
		{
			if((current->factor)->base == n)
			{
				(current->factor)->exponent++;
				return;	
			}
			tail = current;
			current = current->next;
		}
		tail->next = createFactorization(n);
	}
}

long ceilSqrt(long n)
{
	return (long)(ceil(sqrt(n)));
}

factorization *factorize(long n)
{
	long m = 3;
	factorization *fact = NULL;

	while(n % 2 == 0)
	{
		addFactor(&fact, 2);
		n /= 2;
	}
	long max = ceilSqrt(n) + 1;
	while((n > 1) && (m <= max))
	{
		if(n % m == 0)
		{
			addFactor(&fact, m);
			n /= m;
			m = 3;
			max = ceilSqrt(n) + 1;
		}
		else
		{
			m += 2;
		}
	}
	if(n > 1)
	{
		addFactor(&fact, n);
	}
	return fact;
}

void printFactors(factorization *fac)
{
	factorization *current = fac;
	while(current)
	{
		printf("%ld^%ld ", current->factor->base, current->factor->exponent);
		current = current->next;
	}
	printf("\n");
}

void printLongs(long *arr)
{
	printf("Printing long array\n");
	long size = sizeof(arr) / sizeof(arr[0]);
	printf("Elements in array: %ld\n", size);
	for(long i = 0; i < size; i++)
	{
		printf("%ld ", arr[i]);
	}
	printf("\n");
}

void createRecDivisors(long a, factorization *fact, divisors *divs)
{
	if(fact == NULL)
	{
		addDivisor(divs, a);
	}
	else
	{
		for(int i = 0; i <= fact->factor->exponent; i++)
		{
			createRecDivisors(a * (long)pow(fact->factor->base, i), fact->next, divs);
		}
	}
}

divisors *createDivisors(factorization *fact)
{
	divisors *divs = createDivisor(1);
	createRecDivisors(1, fact, divs);

	return divs->next;
}
