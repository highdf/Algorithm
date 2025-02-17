
//Data Declaration
typedef struct ElementMGraph{
	int Value;
}ElementTypeMGraph;

//Type Declaration
typedef struct Vertex{
	ElementTypeMGraph *Data;
}Vertex;
typedef struct EdgeNode{
	char Flag;
	int Wight;
}Edge;
typedef struct MGraph{
	Vertex *V;
	Edge *E;

	int VertexNum;
	int EdgeNum;
	int MaxVertexNum;
}MGraph;

//General Declaration

