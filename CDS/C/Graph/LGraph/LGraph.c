#include "LGraph_in.h"
#include "LGraph_out.h"

LGraph* MakeLGraph(int VertexNum) {
	LGraph* G = (LGraph*) malloc (sizeof(LGraph));
	Vertex *V = (Vertex*) malloc (sizeof(Vertex)*VertexNum);
	Edge *E = (Edge*) malloc (sizeof(Edge) * VertexNum);

	if(G && V && E) {
		G -> V = V;
		G -> E = E;

		for(int i = 0;i < VertexNum;i ++) {
			G -> V[i] = NULL;
			G -> E[i] = NULL;
		}

		G -> VertexNum = 0;
		G -> EdgeNum = 0;
		G -> MaxVertexNum = VertexNum;
	} else {
		printf("Error:In the MakeLGraph:");
		printf("Malloc is false\n");
	}
}
status IsFullVertex(LGraph *G) {
	return (G->MaxVertexNum == G->VertexNum)?(TRUE):(FALSE);
}

