#pragma once
#include<math.h>

int * ConvertNumberIntoArray(unsigned int number) {
	int length = (int)floor(log10((float)number)) + 1;
	int * arr = new int[length];
	int i = 0;
	do {
		arr[i] = number % 10;
		number /= 10;
		i++;
	} while (number != 0);
	return arr;
}

int GetLengthOfNumber(int number)
{
	return (int)floor(log10((float)number)) + 1;
}