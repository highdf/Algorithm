#include "main.h"

int main() {
	Ch_Queue_Num *p = MakeCh_Queue_Num();
	ElementTypeCh_Queue_Num k;
	int a = 1;
	k.Value = a;

	AddCh_Queue_Num(p,&k);
	AddCh_Queue_Num(p,&k);
	AddCh_Queue_Num(p,&k);
	AddCh_Queue_Num(p,&k);
	StatusCh_Queue_Num(p,1);
	
	DeleteCh_Queue_Num(p);
	StatusCh_Queue_Num(p,1);
	DeleteCh_Queue_Num(p);
	DeleteCh_Queue_Num(p);
	DeleteCh_Queue_Num(p);
	return 0;
}
