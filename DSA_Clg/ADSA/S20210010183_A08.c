#include <stdio.h>
#include<stdlib.h>

int N, M;

void creatingadjacencyMatrix(int Adj[][N + 1], int arr[][2])
{


	for (int i = 0; i < N + 1; i++) {

		for (int j = 0; j < N + 1; j++) {
			Adj[i][j] = 0;
		}
	}


	for (int i = 0; i < M; i++) {


		int x = arr[i][0];
		int y = arr[i][1];


		Adj[x][y] = 1;
		Adj[y][x] = 1;
	}
}


void printadjacencyMatrix(int Adj[][N + 1])
{


	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {


			printf("%d ", Adj[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
}

void Graph1()
{
    	N = 5;


	int arr[][2]
		= { { 1, 2 }, { 1, 3 },
			{ 1, 4 }, { 2, 4 }, {3,4} };


	M = sizeof(arr) / sizeof(arr[0]);


	int Adj[N + 1][N + 1];


	creatingadjacencyMatrix(Adj, arr);


	printadjacencyMatrix(Adj);

}
void Graph2()
{
    	N = 5;


	int arr[][2]
		= { { 1, 2 }, { 1, 3 },
			{ 1, 4 }, { 2, 4 }, {3,4}, {2,5},{4,5}};


	M = sizeof(arr) / sizeof(arr[0]);


	int Adj[N + 1][N + 1];


	creatingadjacencyMatrix(Adj, arr);


	printadjacencyMatrix(Adj);

}

void Graph_connectivitydfs()
{
    int a[20][20], reach[20], n;
    void dfs(int v) 
    {
        int i;
        reach[v] = 1;
        for (i = 1; i <= n; i++)
            if (a[v][i] && !reach[i]) {
                printf("\n %d->%d", v, i);
                dfs(i);
            }
    }
    printf("Graph1 Is Not Conneceted\n Graph 2 Is Connected\n ");
}

//Question1
void Implementing_Hashing()
{

    printf("\nQuestion No 01\n");
    int arr[] = {7, 12, 17, 14 };
    int Array_size = sizeof(arr) / sizeof(arr[0]);
    int size = 5;
    int *hashing = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        hashing[i] = -1;
    }

    int index, cnt = 0;
    for (int i = 0; i < size; i++)
    {
        index = arr[i] % size;
        if (hashing[index] == -1)
        {
            hashing[index] = arr[i];
            cnt++;
        }
        else
        {
            while (hashing[(++index % size)] != -1);

            hashing[index % size] = arr[i];
            cnt++;
        }

        if (cnt == (0.8 * size))
        {
            int temp = size;
            size *= 2;
            hashing = (int *)realloc(hashing, size * sizeof(int));
            for (int j = temp; j < size; j++)
                hashing[j] = -1;
        }
        if (cnt == Array_size)
            break;
    }
    printf("-1 denotes no of insertion  \n");
    for (int i = 0; i < size; i++)
    {
        printf("  %d no index gives : %d\n", i, hashing[i]);
    }
}
 //Question 3 Function

 struct Adjacencynode_out {
    int dest;
    struct Adjacencynode_out* next;
};

struct AdjList {
    struct Adjacencynode_out *head;
};

struct Graph {
    int V;
    struct AdjList* array;
};


struct Adjacencynode_out* newAdjacencynode_out(int dest) {
    struct Adjacencynode_out* newNode = (struct Adjacencynode_out*) malloc(
            sizeof(struct Adjacencynode_out));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;


    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));


    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

void edgesAddition(struct Graph* graph, int src, int dest) {

    struct Adjacencynode_out* newNode = newAdjacencynode_out(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;


    newNode = newAdjacencynode_out(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void graphPrinting(struct Graph* graph) {
    int v;
    for (v = 0; v < graph->V; ++v) {
        struct Adjacencynode_out* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
 void Adjacency_for_Graph2 ()
 {

    printf("\nFor Graph 2\n");
 int V = 7;
    struct Graph* graph = createGraph(V);
    edgesAddition(graph, 1, 2);
    edgesAddition(graph, 1, 3);
    edgesAddition(graph, 1, 4);
    edgesAddition(graph, 3, 4);
    edgesAddition(graph, 2, 4);
    edgesAddition(graph, 2, 5);
    edgesAddition(graph, 4, 5);


    graphPrinting(graph);


 }

 void Adjacency_for_Graph1()
 {
      printf("\n \nQuestion No 03\n\n For Graph 1");
      int V = 5;
    struct Graph* graph = createGraph(V);
    edgesAddition(graph, 1, 2);
    edgesAddition(graph, 1, 3);
    edgesAddition(graph, 1, 4);
    edgesAddition(graph, 2, 4);
    edgesAddition(graph, 3, 4);

     graphPrinting(graph);
 }

 void Question1()
 {
     Implementing_Hashing();
 }
 void Question3()
 {
     Adjacency_for_Graph1();
     Adjacency_for_Graph2();

 }

 void Question2()
 {
      printf("Question No 02\n\n The Adjacency Matrix for Graph 1\n\n");
   Graph1();
   printf("The Adjacency Matrix for Graph 2\n\n");
   Graph2();
  Graph_connectivitydfs();
 }

 void Solutions()
 {
     Question1();
     Question2();
     Question3();
 }


int main()
{
    Solutions();



	return 0;
}
