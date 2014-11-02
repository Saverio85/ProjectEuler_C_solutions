#include "stdio.h"
#include "math.h"

#include "lib/common.h"
#include "lib/linkedlist.h"

#define target 1000

bool checkTarget(int a, int b, int c);
int square(int n);


int main()
{
	for(int i = 1; i <= target; i++)
	{ 
		for(int j = i; j <= target; j++)
		{
			int k = target - i - j;
			if(checkTarget(i, j, k))
			{
				printf("Result: %d\n", i * j * k);
				return 0;
			}
		}
	}

	printf("FAIL\n");
	return 0;
}

bool checkTarget(int a, int b, int c)
{
	return square(a) + square(b) == square(c);
}

int square(int n)
{
	return (int)pow(n, 2.0);
}
