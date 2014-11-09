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

factor *createFactor(long n);

factorization *createFactorization(long n);

void addFactor(factorization **facts, long n);

factorization *factorize(long n);

divisors *createDivisors(factorization *fact);

void printFactors(factorization *fac);

