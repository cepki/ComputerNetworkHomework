#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 6
#define INF 1000

void _bellmanFord(int matrix[N][N], int startEdge)
{
	int pathCost[N] = { 0 };
	for (int i = 0; i < N; i++) // loop n times
	{
		pathCost[i] = INF;
	}
	pathCost[startEdge] = 0;

	for (int i = 0; i < N - 1; i++) // loop n-1 times
	{
		for (int j = 0; j < N; j++) //loop through all edges
		{
			if (pathCost[j] != INF) //if it is visited alteleast once
				for (int k = 0; k < N; k++) //loop again through that row of matrix
				{
					if ((matrix[j][k] != INF && matrix[j][k] != 0) && pathCost[k] > pathCost[j] + matrix[j][k]) //if current edge is connected to k-edge
					{
						pathCost[k] = pathCost[j] + matrix[j][k];
					}
				}
		}
	}
	printf("RESULT:\n");
	for (int i = 0; i < N; i++)
	{
		printf("%d ", pathCost[i]);
	}
	printf("KRAJ\n");
}

int main()
{
	int startEdge = 0, endEdge = 0;

	//test matrix
	//int matrix[N][N] = { { 0, INF, 2, INF, INF, INF },{ 1, 0, INF, INF, INF, INF },{ INF, 5, 0, INF, INF, INF },
	//{ 5, INF, 5, 0, INF, INF },{ INF, INF, INF, 1, 0, INF },{ 10, INF, INF, INF, 8, 0 } };

	int matrix[N][N] = { {0, 1, INF, INF, INF, INF}, {INF, 0, 2, 7, INF, 3}, {2, 3, 0, INF, INF, INF}, {INF, INF, INF, 0, INF, 10},
	{ 5, INF, -2, INF, 0, INF}, {INF, INF, INF, INF, INF, 0} };

	for(int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	} //print matrix for test

	printf("What is start edge\n");
	scanf(" %d", &startEdge);

	printf("\n\n");
	startEdge -= 1;

	_bellmanFord(matrix, startEdge);

	return 0;
}