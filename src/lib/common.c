#include "common.h"
#include "linkedlist.h"
#include "stdlib.h"
#include "math.h"
#include "stdio.h"

long isMultiple(long n,long m)
{
	return n % m == 0;
}

long ceilSqrt(long n)
{
	return (long)(ceil(sqrt(n)));
}

list* factors(long n)
{
	long m = 3;
	list *lst = malloc(sizeof(list));
	list_new(lst, sizeof(long), NULL);

	while(n % 2 == 0)
	{
		long factor = 2;
		list_append(lst, &factor);
		n /= 2;
	}
	long max = ceilSqrt(n);
	while((n > 1) && (m <= max))
	{
		if(n % m == 0)
		{
			long factor = m;
			list_append(lst, &factor);
			n /= m;
			m = 3;
			max = ceilSqrt(n);
		}
		else
		{
			m += 2;
		}
	}
	if(n > 1)
	{
		long cpn = n;
		list_append(lst, &cpn);
	}
	return lst;
}
