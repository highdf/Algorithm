#include "main.h"

ElementTypeMGraph* ElementMGraph(int n);

int main() {
	MGraph *G;
	int VNum,ENum;
	char fname[10];
	FILE *fp;
	int *path;

	printf("Please enter file name\n");
	scanf("%s",fname);

	fp = fopen(fname,"r");
	//printf("Please enter VNum and ENum\n");
	fscanf(fp,"%d %d",&VNum,&ENum);

	G = MakeMGraph(VNum);

	for(int i = 0;i < VNum;i ++) {
		ElementTypeMGraph *Data = ElementMGraph(i);
		AddVertex(G,Data);
	}

	//printf("Please enter Edge info\n");
	for(int i = 0;i < ENum;i ++) {
		int N0,N1,Weight;
		fscanf(fp,"%d %d %d",&N0,&N1,&Weight);
		AddEdge(G,N0,N1,Weight);
	}

	printf("BFS\n");
	BFS(G,0);
	printf("DFS\n");
	DFS(G,0);

	printf("Optimal Path\n");
	path = Dijkstra(G,0);	

	for(int i = 0;i < G->VertexNum;i ++) {
		printf("path[%d] = %d\n",i,path[i]);
	}

	return 0;
}
//funcation
ElementTypeMGraph* ElementMGraph(int n){
	ElementTypeMGraph *Data =(ElementTypeMGraph*) malloc (sizeof(ElementTypeMGraph));
	Data->Value = n;

	return Data;
}
