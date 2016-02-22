#pragma once
#include<math.h>
#include<stdlib.h>

int GetRemainder(int *extendedData, int lengthOfExtendedData, int *divisor, int lengthOfDivisor, int sizeOfResult)
{
	int *result = (int *)malloc(sizeof(int) * sizeOfResult);

	int currentPositionOfDividendPolynomial = lengthOfExtendedData;
	int currentPositionOfResultPolynomial = sizeOfResult;


	for (int j = 0; j < sizeOfResult; j++)
	{
		result[currentPositionOfResultPolynomial - 1] = extendedData[currentPositionOfDividendPolynomial - 1] & divisor[lengthOfDivisor - 1];

		for (int i = 0; i < lengthOfDivisor; i++)
		{
			extendedData[currentPositionOfDividendPolynomial - 1 - i] ^=
				(divisor[lengthOfDivisor - 1 - i] * result[currentPositionOfResultPolynomial - 1]);
		}

		currentPositionOfDividendPolynomial -= 1;
		currentPositionOfResultPolynomial -= 1;
	}

	return 5;
}