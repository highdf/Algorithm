
//Data Declaration
typedef struct ElementLMraph{
	int Value;
}ElementTypeLGraph;

//Type Declaration
typedef struct Vertex{
	ElementTypeLGraph *Data;
}Vertex;

typedef struct EdgeNode {
	int Number;
	struct EdgeNode *Next;
}EdgeNode;
typedef EdgeNode* Edge;
typedef struct LGraph{
	Vertex *V;
	Edge *E;

	int VertexNum;
	int EdgeNum;
	int MaxVertexNum;
}LGraph;


