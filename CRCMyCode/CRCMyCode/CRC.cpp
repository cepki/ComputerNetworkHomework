#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "converter.h"
#include "tester.h"
#include "divide.h"
#include "AddMistake.h"

int main()
{
	int dataAsNumber = 0;
	int lengthOfExtendedData = 0;
	printf("Insert your data\n");
	scanf(" %d", &dataAsNumber);
	int *dataAsArray = ConvertNumberIntoArray(dataAsNumber);
	int lengthOfData = GetLengthOfNumber(dataAsNumber);

	if (!AreAllNumbersBinary(dataAsArray, lengthOfData))
	{
		printf("Moraju svi brojevi bit binarni");
		return -1;
	}

	int divisorAsNumber = 0;
	printf("Inser divisor\n");
	scanf(" %d", &divisorAsNumber);
	int *divisorAsArray = ConvertNumberIntoArray(divisorAsNumber);
	int lengthOfDivisor = GetLengthOfNumber(divisorAsNumber);

	if (!AreAllNumbersBinary(divisorAsArray, lengthOfDivisor))
	{
		printf("Moraju svi brojevi bit binarni\n");
		return -1;
	}

	lengthOfExtendedData = lengthOfData + lengthOfDivisor - 1;

	int *extendedData = (int *)malloc(sizeof(int) * lengthOfExtendedData);
	int *secondExtendedData = (int *)malloc(sizeof(int) * lengthOfExtendedData);

	int j = 0;
	for (int i = 0; i < lengthOfExtendedData; i++)
	{
		if (i < lengthOfDivisor)
		{
			extendedData[i] = 0;
			secondExtendedData[i] = 0;
			
		}
		else
		{
			j++;
			extendedData[i] = dataAsArray[j];
			secondExtendedData[i] = dataAsArray[j];
		}
	}


	int firstRemainder = GetRemainder(extendedData, lengthOfExtendedData, divisorAsArray, lengthOfDivisor, lengthOfExtendedData - lengthOfDivisor);

	for (int j = 0; j < lengthOfDivisor; j++)
	{
		secondExtendedData[j] = extendedData[j];
	}

	int ubaciGresku = 0;
	printf("Da li zelis ubacit gresku? 1 - da || 2 - ne\n");
	scanf(" %d", &ubaciGresku);

	if (ubaciGresku == 1)
	{
		AddMistake(secondExtendedData, lengthOfData);
	}


	int test = GetRemainder(secondExtendedData, lengthOfExtendedData, divisorAsArray, lengthOfDivisor, lengthOfExtendedData - lengthOfDivisor);
	printf("\n");

	test = 0;
	for (int i = lengthOfDivisor; i >= 0; i--)
	{
		if (secondExtendedData[i] != 0)
		{
			printf("Dogodila se greska u prijenosu sustavom\n");
			test = 1;
		}
	}

	if (test == 0)
	{
		printf("Nije bilo greske u prijenosu podataka\n");
	}
}	