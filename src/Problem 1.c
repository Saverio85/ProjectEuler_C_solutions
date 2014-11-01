#include "stdio.h"
#include "lib/common.h"

#define max 1000

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
