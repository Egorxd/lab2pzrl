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
			oct = dec_to_oct(bit_not(oct_to_dec(num1)));
			printf("%s \t (%d)\n", oct, bit_not(oct_to_dec(num1)));
			free(oct);
		}

		else // 16 СС
		{
			hex = dec_to_hex(bit_not(hex_to_dec(num1)));
			printf("%s \t (%d)\n", hex, bit_not(hex_to_dec(num1)));
			free(hex);
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

	size_t len1 = strlen(num1);
	size_t len2 = strlen(num2);

	char* string1 = (char*)malloc(len1 * sizeof(char) + 1);
	char* string2 = (char*)malloc(len2 * sizeof(char) + 1);
	strcpy(string1, num1);
	strcpy(string2, num2);
	string1[len1] = '0';
	string2[len2] = '0';
	free(num1);
	free(num2);
	num1 = string1;
	num2 = string2;
	
	if (sys(num1) != sys(num2))
	{
		printf("SYS ERROR\n");
		free(input);
		free(num1);
		free(num2);
		free(operation);
		return 1;
	}

	return 0;
}
