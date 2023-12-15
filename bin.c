#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "bin.h"

int bin_to_dec(const char* n)
{
	int summ = 0;

	if (strlen(n) == 2 && n[0] == '0')
		return 0;
	
	int i = 0;
	if (n[0] == '-')
		i++;
	
	for (i; i < strlen(n) - 1; i++)
	{
		if (n[i] == '1')
			summ += pow(2, strlen(n) - 2 - i);
		else if (n[i] != '1' && n[i] != '0')
		{
			printf("Input error(or num sys error)\n");
			exit(1);
		}
	}	
	
	if (n[0] == '-')
		return -summ;
	return summ;
}

char* dec_to_bin(int n)
{
	int flag = 0; // флаг = 0 - положительное, 1 - отриц
	
	if (n < 0)
	{
		flag = 1;
		n = abs(n);
	}

	else if (n == 0)
		return "0";
	
	int len = 32; // Длина max инта
	char* bin = (char*)malloc(len * sizeof(char));
	if (bin == NULL)
		exit(1);
	
	int ind = 0; // Индекс числа
	while (n > 0 && ind < len - 1)
	{
		bin[ind++] = (char)(n % 2 + '0');
		n /= 2;
	}
	
	if (flag == 1)
	{
		bin[ind] = '-';
		bin[ind + 1] = '\0';
		ind++;
	}
	else
		bin[ind] = '\0';

	int beginning = 0;
	int end = ind - 1;
	while (beginning < end)
	{
		char kostyl = bin[beginning];
		bin[beginning] = bin[end];
		bin[end] = kostyl;
		beginning++;
		end--;
	}

	return bin;

}
