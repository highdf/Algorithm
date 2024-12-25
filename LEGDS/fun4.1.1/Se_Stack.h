#include "status.h"
#include <stdio.h>
#include <stdlib.h>

/**********************************Line Btween**********************************/
//Data Declaration
typedef struct {
	int Start[2];
	int n;
}fun;
typedef fun ElementTypeSe_Stack0;

/**********************************Line Btween**********************************/
//Type Declaration
typedef int Length;
typedef int Position;
typedef struct {
	ElementTypeSe_Stack0 *Data;
	Position Top;
	Length SIZE;
}Se_Stack0;

/**********************************Line Btween**********************************/
//General Declaration
typedef ElementTypeSe_Stack0* PtrToEl_Ty_Se_S0;
typedef int Number;
typedef Se_Stack0* PtrToSe_Stack0;

/**********************************Line Btween**********************************/
//funcation
PtrToSe_Stack0 MakeSe_Stack0(Length n);

status IsEmptySe_Stack0(PtrToSe_Stack0 s);

status IsFullSe_Stack0(PtrToSe_Stack0 a);

void StatusSe_Stack0(PtrToSe_Stack0 a,Number n);

ElementTypeSe_Stack0 PopSe_Stack0(PtrToSe_Stack0 a);

status PushSe_Stack0(PtrToSe_Stack0 a,PtrToEl_Ty_Se_S0 p);
