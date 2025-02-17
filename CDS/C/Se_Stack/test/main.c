#include "main.h"

ElementTypeSe_Stack_Num* ElementSe_Stack(int i);

int main() {
	Se_Stack_Num *Stack = MakeSe_Stack_Num(10);
	ElementTypeSe_Stack_Num *Data;

	for(int i = 0;i < 10;i ++) {
		Data = ElementSe_Stack(i);
		PushSe_Stack_Num(Stack,Data);
	}
	StatusSe_Stack_Num(Stack,0);

	for(int i = 0;i < 10;i ++) {
		Data = PopSe_Stack_Num(Stack);
		free(Data);
	}
	StatusSe_Stack_Num(Stack,0);

	for(int i = 0;i < 10;i ++) {
		Data = ElementSe_Stack(i);
		PushSe_Stack_Num(Stack,Data);
	}
	StatusSe_Stack_Num(Stack,0);

	for(int i = 0;i < 10;i ++) {
		Data = PopSe_Stack_Num(Stack);
		free(Data);
	}
	StatusSe_Stack_Num(Stack,0);
	return 0;
}
ElementTypeSe_Stack_Num* ElementSe_Stack(int i) {
	ElementTypeSe_Stack_Num *Data = (ElementTypeSe_Stack_Num*) malloc (sizeof(ElementTypeSe_Stack_Num));
	Data->Value = i;

	return Data;

}
