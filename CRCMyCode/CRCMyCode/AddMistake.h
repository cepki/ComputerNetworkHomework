#pragma once
#pragma once
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

void AddMistake(int *data, int sizeOfData)
{
	int pozicija = 0;
	printf("Na koju poziciju?\n");
	scanf(" %d", &pozicija);

	if (pozicija < sizeOfData)
	{
		data[pozicija] = data[pozicija] == 1 ? 0 : 1;
	}
	else
	{
		printf("Greska pri pristupu podatcima");
	}
}