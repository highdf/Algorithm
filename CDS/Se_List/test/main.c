#include "main.h"

ElementTypeSe_List_Num* ElementSe_List_Num(int i);
int main() {
	Se_List_Num *List = MakeSe_List_Num(10);
	ElementTypeSe_List_Num *Data;

	for(int i = 0;i < 10;i ++ ) {
		Data = ElementSe_List_Num(i);
		InsertSe_List_Num(List,Data,0);
	}
	StatusSe_List_Num(List,0);

	for(int i = 9;i >= 0;i -- ) {
		Data = DeleteSe_List_Num(List,i);
		free(Data);
	}
	StatusSe_List_Num(List,0);

	for(int i = 0;i < 10;i ++ ) {
		Data = ElementSe_List_Num(i);
		InsertSe_List_Num(List,Data,0);
	}

	for(int i = 9;i >= 0;i -- ) {
		Data = DeleteSe_List_Num(List,i);
		free(Data);
	}
	StatusSe_List_Num(List,0);
	StatusSe_List_Num(List,0);
	return 0;
}
ElementTypeSe_List_Num* ElementSe_List_Num(int i) {
	ElementTypeSe_List_Num *Data = (ElementTypeSe_List_Num*) malloc (sizeof(ElementTypeSe_List_Num));

	Data->Value = i;

	return Data;
}
