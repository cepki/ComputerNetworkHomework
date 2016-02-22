#pragma once


bool AreAllNumbersBinary(int *polynomialToCheck, int sizeOfPolynomial)
{
	for (int i = 0; i < sizeOfPolynomial; i++)
	{
		if (polynomialToCheck[i] != 0 && polynomialToCheck[i] != 1)
		{
			return false;
		}
	}
	return true;
}
