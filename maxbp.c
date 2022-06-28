#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define M 6
#define N 6
bool bpGraph[M][N]; 
bool bpMax(int u, bool visited[], int a[]) {
   for (int v = 0; v < N; v++) {
      if (bpGraph[u][v] && !visited[v]) {
         visited[v] = true;
         if (a[v] < 0 || bpMax(a[v], visited, a)) {
            a[v] = u;
            return true;
         }
      }
   }
   return false;
}
int maxmatches() {
   int a[N];
   for(int i = 0; i<N; i++)
      a[i] = -1;
   int Count = 0;
   for (int u = 0; u < M; u++) {
      bool visited[N];
      for(int i = 0; i<N; i++)
         visited[i] = false;
      if (bpMax(u, visited, a))
         Count++;
   }
   return Count;
}
int main() {
    printf("Enter the matrix: ");
    int i,j;
    int g[M][N];
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
        scanf("%d",&g[i][j]);
        bpGraph[i][j]=g[i][j];
        }
    }
    printf("Maximum number of matches for the graph are: %d ",maxmatches());
}
