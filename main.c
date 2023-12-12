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
	getline(&input, &len, stdin);

	char* num1 = NULL; // Первое число из строки
	char* num2 = NULL; // Второе число из строки
	char* operation = NULL; // Операция между числами

	return 0;
}
