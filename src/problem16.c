#include "stdio.h"
#include "string.h"

#include "lib/common.h"
#include "lib/linkedlist.h"

#define max 1000

int main()
{
	char *value = createAndInitialize(2);
	value[0] = '1';

	for(int i = 0; i < max; i++)
	{
		value = sum(value, value);
	}

	long result = 0;
	int len = (int)strlen(value);
	for(int i = 0; i < len; i++)
	{
		result += value[i] - '0';
	}
	printf("%ld\n", result);
	return 0;
}
