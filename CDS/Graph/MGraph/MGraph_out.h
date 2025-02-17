
MGraph* MakeMGraph(int VertexNum);
status IsConect(MGraph *G,int Num1,int Num2);

void AddEdge(MGraph *G,int Num0,int Num1,int Wight);
void AddVertex(MGraph *G,ElementTypeMGraph *Data);
void StatusMGraph(MGraph *G);

void DFS(MGraph *G,int n);
void BFS(MGraph *G,int n);
int* Dijkstra(MGraph *G,int N);
