#include "MGraph_in.h"

int* Dijkstra(MGraph *G,int N) {
	int *path;

	if(N >= 0 && N < (G->VertexNum)) {
		int dis[G->VertexNum];
		status visited[G->VertexNum];
		int visitct = 0;
		path = (int*)malloc(sizeof(int) * (G->VertexNum));
			
		for(int i = 0;i < G->VertexNum;i ++) {
			visited[i] = FALSE;
			(i == N)?(dis[i] = 0):(dis[i] = (unsigned)(~0) >>1);
			(i == N)?(path[i] = N):(path[i] = 0);
		}

		do{
			for(int i = 0;i < (G->VertexNum);i ++) {
				Edge* E = GetEdge(G,N,i);
				if(E->Flag == YES && visited[i] == FALSE) {
					int d = dis[N] + E->Wight;
					(dis[i] > d)?(dis[i] = d,path[i] = N):(0);
				}
			}

			visited[N] = TRUE;
			N = FindMin(dis,visited,G->VertexNum);
			//printf("N = %d\n",N);
		} while(N > 0);
	} else {
		path = NULL;
		printf("Error;In the Dijkstra:");
		printf("Vertex number is error\n");
	}
	

	return path;
}
int FindMin(int *dis,status *visited,int num) {
	int min = -1,value = (unsigned) (~0) >> 1;

	for(int i = 1;i < num;i ++) {
		//printf("dis[%d] = %d ",i,dis[i]);
		if(value > dis[i] && visited[i] == FALSE) {
			value = dis[i];
			min = i;
		}
	}

	return min;
}
