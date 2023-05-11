#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define sV 4
#define INF 99999

void printQ2(int weight[][sV]);

void floydWarshallAlgo(int graph[][sV])
{
	int weight[sV][sV], i, j, k;

	for (i = 0; i < sV; i++)
	{
		for (j = 0; j < sV; j++)
			weight[i][j] = graph[i][j];
	}
	
	for (k = 0; k < sV; k++) 
	{
		for (i = 0; i < sV; i++) 
		{
			for (j = 0; j < sV; j++) 
			{
				if (weight[i][k] + weight[k][j] < weight[i][j])
					weight[i][j] = weight[i][k] + weight[k][j];
			}
		}
	}
	printQ2(weight);
}
void printQ2(int weight[][sV])
{
    printf("Using Floyd Warshall Algorithm, \n");
	printf("The shortest distances between every pair of vertices in the Graph \n");
	for (int i = 0; i < sV; i++) 
	{
		for (int j = 0; j < sV; j++) 
		{
			if (weight[i][j] == INF)
				printf("%7s", "INF");
			else
				printf("%7d", weight[i][j]);
		}
		printf("\n");
	}
}

void fillArr(int *arr, int k, int arrlen)
{
    for(int i =0;i < arrlen;i++){
        arr[i] = k;
    }
}
int minval(int a, int b)
{
    return a>b?b:a;
}
int maxval(int a, int b) 
{ 
	return (a > b) ? a : b; 
}
int coinChange(int coins[], int amt, int arrlen) //Dynamic programming - Bottom up
{
    int max = amt + 1;
    int *dyArr = (int*)malloc(sizeof(int)*(amt+1));
	
    fillArr(dyArr, max, amt+1);
    dyArr[0] = 0;
	
    for (int i = 1; i <= amt; i++) 
	{
        for (int j = 0; j < arrlen; j++) 
        {
            if (coins[j] <= i) {
                dyArr[i] = minval(dyArr[i], dyArr[i - coins[j]] + 1);
            }
        }
    }
	
    return dyArr[amt] > amt ? -1 : dyArr[amt];
}
int knapSackAlgo(int W, int wt[], int val[], int sizeVal)
{
	if (sizeVal == 0 || W == 0)
		return 0;

	if (wt[sizeVal - 1] > W)
		return knapSackAlgo(W, wt, val, sizeVal - 1);
	else
		return maxval(val[sizeVal - 1] + knapSackAlgo(W - wt[sizeVal - 1], wt, val, sizeVal - 1),knapSackAlgo(W, wt, val, sizeVal - 1));
}
void q2()
{
	int graph[sV][sV] = { { 0, 8, INF, 1 },
						{ INF, 0, 1, INF },
						{ 4, INF, 0, INF },
						{ INF, 2, 9, 0 } };
	
	floydWarshallAlgo(graph);
}
void printarr(int *arr, int len)
{
    printf("{ %d",arr[0]);
    for(int i=1;i<len;i++) {
        printf(", %d",arr[i]);
    }
    printf(" }\n");
}
int main()
{
    printf("\n\n---------------------PROGRAM 1---------------------\n");
    int val[] = { 3, 4, 5,6 };
    int sizeVal = 4;

	int wt[] = { 2, 3, 4,5};
    
	int W = 5;

    printf("Number of items = %d\n",sizeVal);
    printf("Weight of items = ");
    printarr(wt,sizeVal);
    printf("Value of items = ");
    printarr(val,sizeVal);
    printf("Capacity of Knapsack = %d\n",W);
    printf("Number of items = %d\n",sizeVal);
    
	printf("\nMaximum attainable value of items = %d", knapSackAlgo(W, wt, val, sizeVal));
    printf("\n");

    printf("\n---------------------PROGRAM 2---------------------\n");
    q2();
    printf("\n");

    printf("\n---------------------PROGRAM 3---------------------\n");
    int arr[] = {1,2,5};
    int arrlen = 3;
    int amount = 11;

    int few = coinChange(arr , amount, arrlen);

    printf("Coins = ");
    printarr(arr,arrlen);
    printf("Amount = Rs. %d\n",amount);

    printf("\nFewest no. of coins that is needed to make up the amount = %d\n",few);
    printf("\n");
    
    return 0;
}