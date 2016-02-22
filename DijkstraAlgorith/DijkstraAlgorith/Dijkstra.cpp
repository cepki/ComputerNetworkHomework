#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void _resolveDijkstra(int [5][5], int , int);

void _resolveDijkstra(int matrix[5][5], int startEdge, int endEdge)
{
	int arrayOfEdges[5];
	int pathCost[5];
	int currentEdge;
	int minimum = 0, m = 0;
	int status = 0;

	for (int i = 0; i < 5; i++)
	{
		arrayOfEdges[i] = -1;
		pathCost[i] = 1000;
	}

	currentEdge = startEdge;
	arrayOfEdges[startEdge] = 0;
	pathCost[currentEdge] = 0;


	while (arrayOfEdges[endEdge] != 2) //until target edge is not visited
	{
		minimum = 1000;
		m = 0; //reset variables
		status = 0;

		//loop through all edges and check which one is not checked and check ho,
		for (int i = 0; i < 5; i++)
		{
			if ((arrayOfEdges[i] == -1 || arrayOfEdges[i] == 1) && matrix[currentEdge][i] != 1000 && matrix[currentEdge][i] != 0)
			{
				if (pathCost[i] > matrix[currentEdge][i] + pathCost[currentEdge])
				{
					pathCost[i] = matrix[currentEdge][i] + pathCost[currentEdge];
				}

				if (arrayOfEdges[i] == -1)
				{
					arrayOfEdges[i] = 1;
				}
			}
		}
		arrayOfEdges[currentEdge] = 2;
		//mark currentEdge finished


		//decide which one to do next
		for (int i = 0; i < 5; i++)
		{
			if (matrix[currentEdge][i] != 1000 && matrix[currentEdge][i] != 0)
			{
				if (arrayOfEdges[i] == 1)
				{
					if (status != 0 && pathCost[i] < pathCost[m])
					{
						m = i;
					}
					if (status == 0)
					{
						m = i;
						status++;
					}
				}
			}
		}
		currentEdge = m; //decide which edge to do next
		arrayOfEdges[currentEdge] = 0; //mark that that edge is in process now
	}
	printf("Path cost between %d and %d is: %d\n", startEdge + 1, endEdge + 1, pathCost[endEdge]);
}

int main()
{
	int startEdge = 0, endEdge = 0;
	

	int matrix[5][5] = { { 0, 4, 1000, 8, 1000 },{ 4, 0, 3, 1000, 1000 },{ 1000, 3, 0, 4, 1000 },{ 8, 1000, 4, 0, 7 },{ 1000, 1000, 1000, 7, 0 } };
	//test matrix
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	} //print matrix for test

	  //0 = inProgress || -1 = not touched and nonVisited || 1-touched but not visieted || 2 -done
	
	printf("What is start edge\n");
	scanf(" %d", &startEdge);
	printf("\n");

	//get target edge and start edge

	printf("What is end edge\n");
	scanf(" %d", &endEdge);
	printf("\n");

	

	if (startEdge == endEdge)
	{
		printf("Nema smisla, to je isti vrh\n");
		return -2;
	}

	if (startEdge > 5 || endEdge > 5) //check does that edge exist
	{
		printf("Nema tog vrha u mrezi\n");
		return -2;
	}

	startEdge -= 1;
	endEdge -= 1;
	//matrix starts with 0, so we have to use decrement here


	//temp variables
	_resolveDijkstra(matrix, startEdge, endEdge);
}