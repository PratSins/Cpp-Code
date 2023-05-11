#include <stdio.h>
#include <stdlib.h>
//LAB 9
int vis[100];
struct Graph {
	int V;
	int E;
	int** Adj;
};

struct Graph* read_GRAPH(int n)
{
	struct Graph* G = (struct Graph*)malloc(sizeof(struct Graph));
	if (!G) {
		printf("Memory Error\n");
		return NULL;
	}
	G->V = n;
	G->E = n;

	G->Adj = (int**)malloc((G->V) * sizeof(int*));
	for (int k = 0; k < G->V; k++) {
		G->Adj[k] = (int*)malloc((G->V) * sizeof(int));
	}
	for (int u = 0; u < G->V; u++) {
		for (int v = 0; v < G->V; v++) {
			G->Adj[u][v] = 0;
		}
	}

    printf("Enter vertices:\n");
    int k, l;
    do
    {
        scanf("%d %d",&k,&l);
        G->Adj[k][l] = G->Adj[l][k] = 1;
    } while (k!=0 || l!=0);

	return G;
}

void DFS(struct Graph* G, int u,int f)
{
	vis[u] = 1;
    if(f==1)
	    printf("%d ", u);
	for (int v = 0; v < G->V; v++) {
		if (!vis[v] && G->Adj[u][v]) {
			DFS(G, v,f);
		}
	}
}

void DFStraversal(struct Graph* G,int f)
{
	for (int i = 0; i < 100; i++) {
		vis[i] = 0;
	}
	for (int i = 0; i < G->V; i++) {
		if (!vis[i]) {
			DFS(G, i,f);
		}
	}
}
void isConnected(struct Graph* G,int n)
{
    DFStraversal(G,0);
    int check = 0;
    for(int i=1;i<n;i++){
        if(vis[i]!=1){
            check = 1;
            break;
        }
    }
    printf("\n");
    if(check==1)
        printf("Graph is not connected \n"); 
    else
           printf("Graph is connected \n"); 
}
void main()
{
	struct Graph* G;
    printf("Enter the number of nodes:\n ->");
    int n;
    scanf("%d",&n);
	G = read_GRAPH(n);
	DFStraversal(G,1);
    isConnected(G,n);
}
