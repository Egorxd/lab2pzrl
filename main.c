#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "operations.h"
#include "bin.h"
#include "oct.h"
#include "hex.h"

int main(int argc, char** argv)
{
	char* input = NULL; // Строка для ввода чисел и операции
	size_t len = 0;
	getline(&input, &len, stdin); // Ввод строки

	char* num1 = NULL; // Первое число из строки
	char* num2 = NULL; // Второе число из строки
	char* operation = NULL; // Операция между числами

	char* bin;
	char* oct;
	char* hex;

	if (strchr(input, '~') != NULL)
	{
		num1 = input + 1;
		if (sys(num1) == 2) // 2 СС
		{
			bin = dec_to_bin(bit_not(bin_to_dec(num1)));
			printf("%s \t (%i)\n", bin, bit_not(bin_to_dec(num1)));
			if (bin[0] != '0')
				free(bin);
		}

		else if (sys(num1) == 1) // 8 СС
		{

		}

		else // 16 СС
		{
			
		}

		free(input);
		return 0;
	}
	
	char num1_buff[35];
	char num2_buff[35];
	char operator_buff[2];
	sscanf(input, "%35s %1s %35s", num1_buff, operator_buff, num2_buff);
	
	num1 = strdup(num1_buff);
	num2 = strdup(num2_buff);
	operation = strdup(operator_buff);

	return 0;
}
