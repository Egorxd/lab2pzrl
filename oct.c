#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "oct.h"

int oct_to_dec(const char* n)
{
	int summ = 0;
	int i = 0;

	if (n[0] == '-')
		i += 1;
	else
		i += 1;

	for (i; i < strlen(n) - 1; i++)
	{
		if (isdigit(n[i]) != 0 && (int)(n[i] - '0') < 8)
			summ += (int)(n[i] - '0') * pow(8, strlen(n) - 2 - i);
		else
		{
			printf("ERROR\n");
			exit(1);
		}
	}
	
	if (n[0] == '-')
		return -summ;
	return summ;
}

char* dec_to_oct(int n)
{
	int len	= 15;
	char* VIII = (char*)malloc(len * sizeof(char));

	if (n >= 0)
		sprintf(VIII, "0%o", abs(n));
	else
		sprintf(VIII, "-0%o", abs(n));

	return VIII;
}
