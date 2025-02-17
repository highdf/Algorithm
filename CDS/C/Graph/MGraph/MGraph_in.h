#include <stdio.h>
#include <stdlib.h>

#include "/home/luky/Algorithm/Include/status.h"
#include "MGraph.h"
#include "Ch_Queue/Ch_Queue.h"
#include "Se_Stack/Se_Stack.h"

#include "Ch_Queue/Ch_Queue_out.h"
#include "Se_Stack/Se_Stack_out.h"

#define NO 1
#define YES 2

#define UNDI 0
#define DI 1
#define FLAG UNDI
//无向图/有向图标记

int EdgeIndex(MGraph *G,int Num1,int Num2);
status IsFullVertex(MGraph *G);
status IsFullEdge(MGraph *G);
ElementTypeCh_Queue0* ElementCh_Queue0(int val);
Edge* GetEdge(MGraph *G,int i,int j);
int FindMin(int *dis,status *visited,int num);
void Visit(Vertex *V);
ElementTypeSe_Stack0* ElementSe_Stack0(int Value);
