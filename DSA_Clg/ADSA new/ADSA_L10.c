#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 9

int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX, min_pos;
	for (int i = 0; i < V; i++){
		if (mstSet[i] == false && key[i] < min)
			min = key[i], min_pos = i;
    }
	return min_pos;
}
int printMST(int parent_arr[], int graph[V][V])
{
	printf("Edge \tWeight\n");
	for (int i = 1; i < V; i++){
		printf("%d - %d \t%d \n", parent_arr[i], i,	graph[i][parent_arr[i]]);
    }
}
void primMST(int graph[V][V])
{
	int parent_arr[V];
	int key[V];
	bool mstSet[V];
	for (int i = 0; i < V; i++){
		key[i] = INT_MAX, mstSet[i] = false;
    }
	key[0] = 0;
	parent_arr[0] = -1; 

	for (int count = 0; count < V - 1; count++)
    {
		int u = minKey(key, mstSet);
		mstSet[u] = true;

		for (int v = 0; v < V; v++)
        {
			if ( graph[u][v] && mstSet[v] == false && graph[u][v] < key[v] )
				parent_arr[v] = u, key[v] = graph[u][v];
        }
	}
	printMST(parent_arr, graph);
}

int parent_arr[V];
int find(int i)
{
    while (parent_arr[i] != i)
        i = parent_arr[i];
    return i;
}
void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent_arr[a] = b;
}
void kruskalMST(int cost[][V])
{
    int mincost = 0;
    for (int i = 0; i < V; i++){
            parent_arr[i] = i;
    }
    int edge_count = 0;
    while (edge_count < V - 1) 
    {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) 
        {
            for (int j = 0; j < V; j++) 
            {
                if (find(i) != find(j) && cost[i][j] < min) 
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
 
        union1(a, b);
        printf("Edge %d:(%d, %d) cost:%d \n",
               edge_count++, a, b, min);
        mincost += min;
    }
    printf("\n Minimum cost= %d \n", mincost);
}


int main()
{
    printf("\n---------------------PROGRAM 1---------------------\n");
    //                    A  B  C  D  E  F  G  H  I
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },   // A
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },  // B
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },   // C
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },  // D
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },  // E
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, // F
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },   // G
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },  // H
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }    // I
                      };
    // ------------------- Arr ends
	primMST(graph);
    printf("\n");

    printf("\n---------------------PROGRAM 2---------------------\n");
    // INT_MAX ---> 0 in this Adjacency Matrix
    int cost[][V] = {
                        { INT_MAX, 4, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 8, INT_MAX },
						{ 4, INT_MAX, 8, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 11, INT_MAX },
						{ INT_MAX, 8, INT_MAX, 7, INT_MAX, 4, INT_MAX, INT_MAX, 2 },
						{ INT_MAX, INT_MAX, 7, INT_MAX, 9, 14, INT_MAX, INT_MAX, INT_MAX },
						{ INT_MAX, INT_MAX, INT_MAX, 9, INT_MAX, 10, INT_MAX, INT_MAX, INT_MAX },
                        { INT_MAX, INT_MAX, 4, 14, 10, INT_MAX, 2, INT_MAX, INT_MAX },
                        { INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 2, INT_MAX, 1, 6 },  
                        { 8, 11, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 1, INT_MAX, 7 },  
                        { INT_MAX, INT_MAX, 2, INT_MAX, INT_MAX, INT_MAX, 6, 7, INT_MAX } 
                    };
    // ------------------- Arr ends
    kruskalMST(cost);
    printf("\n");


    
	return 0;
}