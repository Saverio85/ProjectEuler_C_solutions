#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "lib/common.h"
#include "lib/linkedlist.h"

#define target 600851475143

long getData(void *data);

int main()
{
	//long target = 600851475143;
	list *primes = factors(target);
	long result = getData(primes->tail->data);
	printf("The maximum factor in %ld is %ld\n", target, result);
	return 0;
}

long getData(void *data)
{
	long *l = malloc(sizeof(long));
	memcpy(l, data, sizeof(long));
	return *l;
}
