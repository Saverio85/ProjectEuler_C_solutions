#include "math.h"
#include "stdio.h"
#include "lib/common.h"
#include "lib/linkedlist.h"

#define max 120000
#define target 10001

int main()
{
	int counter = 0;
	short sieve[max] = {0};

	for(int i = 2; i < max; i++)
	{
		if(sieve[i] == 0)
		{
			counter++;
			if(counter == target)
			{
				printf("%d\n", i);
				break;
			}
			else
			{
				for(int j = i; j < max; j += i)
				{
					sieve[j] = 1;
				}
			}
		}
	}
	return 0;
}
