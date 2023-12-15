#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "operations.h"

int sys(char* n)
{
	if (n[0] == '-')
		n += 1;

	if (n[0] == '0' && n[1] == 'x')
	{
		return 0; // Возвращает 16 СС
	}
	
	else if (n[0] == '0')
	{
		if (strlen(n) == 2)
			return 2; // Возвращает 2 СС, тк стрлен считает и \0
		
		return 1; // Возвращает 8 СС
	}

	else
		return 2;
}

int mult(int n1, int n2)
{
	return n1 * n2;
}

int sum(int n1, int n2)
{
	return n1 + n2;
}

int subst(int n1, int n2)
{
	return n1 - n2;
}

int percent(int n1, int n2)
{
	return n1 % n2;
}

int bit_and(int n1, int n2)
{
	return n1 & n2;
}

int bit_or(int n1, int n2)
{
	return n1 | n2;
}

int bxor(int n1, int n2)
{
	return n1 ^ n2;
}

int bit_not(const int n)
{
	if (n == 0)
		return 0;
	else
		return -(n + 1);
}

