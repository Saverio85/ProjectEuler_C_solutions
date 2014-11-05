#include "string.h"
#include "stdio.h"
#include "stdlib.h"

#include "lib/common.h"
#include "lib/linkedlist.h"

#define num 100

char *unsafeSubstring(char *str, int n);

int main()
{
	char *result = createAndInitialize(2);
	result[0] = '0';

	FILE *fp = fopen("problem13.dat","r");
	while (!feof(fp)) 
	{
		char *line = calloc(num, sizeof(char));		
        fscanf(fp, "%s\r\n", line);
        if(line != NULL)
        {
    		result = sum(result, line);
        }
	}

	printf("Result: %s\n", unsafeSubstring(result, 10));
	return 0;
}

char *unsafeSubstring(char *str, int n)
{
	char *result = createAndInitialize(n);
	strncpy(result, str, n);
	return result;
}
