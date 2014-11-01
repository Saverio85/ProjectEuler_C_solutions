#include "stdio.h"
#define max 1000

int isMultiple(int n, int m);

int main()
{
	int sum = 0;
	for(int i = 0; i < max; i++)
	{
		if(isMultiple(i, 3) || isMultiple(i, 5))
		{
			sum += i;
		}
	}

	printf("%d\n", sum);
	return 0;
}

int isMultiple(int n,int m)
{
	return n % m == 0;
}
