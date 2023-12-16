#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "operations.h"
#include "hex.h"

int hex_to_dec(const char* n)
{
	int summ = 0;
	int i = 0;
	if (n[0] == '-')
		i += 3;
	else
		i += 2;

	for (i; i < strlen(n) - 1; i++)
	{
		if (n[i] == 'a')
			summ += 10 * pow(16, strlen(n) - 2 - i);
		else if (n[i] == 'b')
			summ += 11 * pow(16, strlen(n) - 2 - i);
		else if (n[i] == 'c')
			summ += 12 * pow(16, strlen(n) - 2 - i);
		else if (n[i] == 'd')
			summ += 13 * pow(16, strlen(n) - 2 - i);
		else if (n[i] == 'e')
			summ += 14 * pow(16, strlen(n) - 2 - i);
		else if (n[i] == 'f')
			summ += 15 * pow(16, strlen(n) - 2 - i);
		else
		{
			if (isdigit(n[i]) != 0)
				summ += (int)(n[i] - '0') * pow(16, strlen(n) - 2 - i);
			else
			{
				printf("ERROR\n");
				exit(1);
			}
		}
	}
	if (n[0] == '-')
		return -summ;
	return summ;
}

char* dec_to_hex(int n)
{
	int len = 10;
	char* VXI = (char*)malloc(len * sizeof(char));

	if (n >= 0)
		sprintf(VXI, "0x%x", abs(n));
	else
		sprintf(VXI, "-0x%x", abs(n));

	return VXI;
}
