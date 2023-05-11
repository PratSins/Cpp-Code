#include<stdio.h>
#include<string.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
#define INF INT_MAX
#define NIL -1
#define V 6

bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
   
    int queue[V];  
    int q_end = 0;
 
   
    queue[q_end++] = s;
    visited[s] = true;
    parent[s] = -1;
 
    while (q_end)
    {
        int u = queue[--q_end];
 
       for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                queue[q_end++] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
   
    return (visited[t] == true);
}
int fordFulkerson(int graph[V][V], int s, int t)
{
   
    int u, v;
 
    int rGraph[V][V];  
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];
 
    int parent[V];  
    int max_flow = 0;  
 
   
    while (bfs(rGraph, s, t, parent))
    {
       
        int path_flow = INF;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        max_flow += path_flow;
    }
    return max_flow;
}

int longestStr( char *s1, char *s2, int m, int n )
{
   int L[m+1][n+1];
   int i, j;
   
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (s1[i-1] == s2[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   return L[m][n];
}
void executeQ1()
{
    printf("\n\n---------------------PROGRAM 1---------------------\n");
     char s1[] = "TTCTACGGGGGGAGACCTTTACGAATCACACCGGTCTTCTTTGTTCTAGCCGCTCTTTTTCATCAGTTGCAGCTAGTGCATAATTGCTCACAAACGTATC";
     char s2[] = "TCTACGGGGGGCGTCATTACGGAATCCACACAGGTCGTTATGTTCATCTGTCTCTTTTCACAGTTGCGGCTTGTGCATAATGCTCACGAACGTATC";
     int m = strlen(s1);
     int n = strlen(s2);
     printf("\n\nThe Length Of Longest String Is: %d\n\n", longestStr( s1, s2, m, n ) );
    printf("\n");
}
void Q2()
{
    printf("\n\n---------------------PROGRAM 2---------------------\n");
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };
 
    printf("The maximum possible flow is %d \n",
           fordFulkerson(graph, 0, 5));
    printf("\n");
}
int main()
{
    executeQ1();
    Q2();
    return 0;
}