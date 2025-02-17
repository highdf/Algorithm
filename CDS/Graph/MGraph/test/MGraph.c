#include "MGraph_in.h"
#include "MGraph_out.h"

MGraph* MakeMGraph(int VertexNum) {
	MGraph *MG = (MGraph*) malloc (sizeof(MGraph));
	Vertex *V = (Vertex*) malloc (sizeof(Vertex)*VertexNum);
	Edge *E = (Edge*) malloc (sizeof(Edge) * (VertexNum*VertexNum));

	if(MG && V && E) {
		MG->V = V;
		MG->E = E;

		MG->VertexNum = 0;
		MG->EdgeNum = 0;
		MG->MaxVertexNum = VertexNum;

		for(int i = 0;i < VertexNum;i ++) {
			MG->V[i].Data = NULL;
		}

		for(int i = 0;i < (VertexNum*VertexNum);i++) {
			MG->E[i].Flag = NO;
		}

	} else {
		printf("error:In the makeMGraph:");
		printf("Malloc is false\n");
	}

	return MG;
}
status IsFullVertex(MGraph *G) {
	return (G->VertexNum == G->MaxVertexNum)?(TRUE):(FALSE);
}
status IsFullEdge(MGraph *G) {
	int MaxEdgeNum = G->MaxVertexNum*G->MaxVertexNum - G->MaxVertexNum;

	return (G->EdgeNum == MaxEdgeNum)?(TRUE):(FALSE);
}
status IsConect(MGraph *G,int Num1,int Num2) {
	int Index = EdgeIndex(G,Num1,Num2);

	return ((G->E[Index].Flag) == NO)?(FALSE):(TRUE);
}
int EdgeIndex(MGraph *G,int Num1,int Num2) {
	return (Num1*G->MaxVertexNum + Num2);
}
void AddEdge(MGraph *G,int Num0,int Num1,int Wight) {
	int Index = EdgeIndex(G,Num0,Num1);

	if(IsFullEdge(G) != TRUE && FLAG == DI) {
		G->E[Index].Flag = YES;
		G->E[Index].Wight = Wight;
		G->EdgeNum ++;
	} else if(IsFullEdge(G) != TRUE && FLAG == UNDI){
		G->E[Index].Flag = YES;
		G->E[Index].Wight = Wight;
		Index = EdgeIndex(G,Num1,Num0);
		G->E[Index].Flag = YES;
		G->E[Index].Wight = Wight;
		G->EdgeNum += 2;
	}
	else {
		printf("error:In the AddEdge:");
		printf("The MGraph->E is Full\n");
	}
}
void AddVertex(MGraph *G,ElementTypeMGraph *Data) {
	if(IsFullVertex(G) != TRUE) {
		G->V[G->VertexNum++].Data = Data;
	} else {
		printf("error:In the AddVertex:");
		printf("The MGraph->V is Full\n");
	}
}
void StatusMGraph(MGraph *G) {
	printf("MGraph's status\n");
	printf("\tMGraph->VertexNum %d\n\tMGraph->EdgeNum %d\n",G->VertexNum,G->EdgeNum);
	printf("\tMaxVertexNum is %d\n",G->MaxVertexNum);

}
Edge* GetEdge(MGraph *G,int i,int j) {
	int Index = EdgeIndex(G,i,j);

	return &G->E[Index];
}
void DFS(MGraph *G,int n) {
	if(n >= 0 && n < G->MaxVertexNum) {
		Se_Stack0 *stack = MakeSe_Stack0(G->VertexNum);
		ElementTypeSe_Stack0 *Data;

		status Visited[G->VertexNum];

		for(int i = 0;i < G->VertexNum;i ++) {
			Visited[i] = FALSE;
		}

		Data = ElementSe_Stack0(n);
		PushSe_Stack0(stack,Data);
		Visited[n] = TRUE;

		do{
			Data = PopSe_Stack0(stack);
			Visit(&(G->V[Data->Value]));

			for(int i = 0;i < G->MaxVertexNum;i++) {
				Edge* E = GetEdge(G,Data->Value,i);
				if(E->Flag == YES && Visited[i] == FALSE) {
					ElementTypeSe_Stack0* Data0;
					Data0 = ElementSe_Stack0(i);
					PushSe_Stack0(stack,Data0);
					Visited[i] = TRUE;
				}
			}
			free(Data);
		} while(IsEmptySe_Stack0(stack) != TRUE);
	} else {
		printf("error:In the DFS:");
		printf("Vertex number is error\n");
	}
}

void BFS(MGraph *G,int n) {
	if(n >= 0 && n < G->MaxVertexNum) {
		status Visited[G->MaxVertexNum];
		Ch_Queue0* Q = MakeCh_Queue0();
		ElementTypeCh_Queue0 *Data;
		
		for(int i = 0;i < G->MaxVertexNum;i ++) {
			Visited[i] = FALSE;
		}

		Data = ElementCh_Queue0(n);
		AddCh_Queue0(Q,Data);
		Visited[n] = TRUE;
		
		do{
			Data = DeleteCh_Queue0(Q);
			Visit(&(G->V[Data->Value]));

			for(int i = 0;i < G->MaxVertexNum;i ++) {
				Edge* E = GetEdge(G,Data->Value,i);
				if(E->Flag == YES && Visited[i] == FALSE) {
					ElementTypeCh_Queue0 *Data0;
					Data0 = ElementCh_Queue0(i);
					AddCh_Queue0(Q,Data0);
					Visited[i] = TRUE;
				}
			}
			free(Data);
		} while((IsEmptyCh_Queue0(Q)) != TRUE);
	} else {
		printf("error:In the BFS:");
		printf("Vertex number is error\n");
	}
		
}

ElementTypeCh_Queue0* ElementCh_Queue0(int val) {
	ElementTypeCh_Queue0 *Data=(ElementTypeCh_Queue0*)malloc(sizeof(ElementTypeCh_Queue0));
	Data->Value = val;

	return Data;
}

ElementTypeSe_Stack0* ElementSe_Stack0(int Value) {
	ElementTypeSe_Stack0* Data = (ElementTypeSe_Stack0*) malloc (sizeof(ElementTypeSe_Stack0));
	Data->Value = Value;

	return Data;
}
//自定义函数
void Visit(Vertex *V) {
	printf("V->Data->Value = %d\n",V->Data->Value);
}

