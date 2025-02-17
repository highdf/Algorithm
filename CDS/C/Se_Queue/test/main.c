#include "main.h"

ElementTypeSe_Queue_Num* ElementSe_Queue(int i);

int main() {
	Se_Queue_Num *Queue = MakeSe_Queue_Num(10);
	ElementTypeSe_Queue_Num *Data;

	for(int i = 0;i < 10;i ++) {
		Data = ElementSe_Queue(i);
		AddSe_Queue_Num(Queue,Data);
	}
	StatusSe_Queue_Num(Queue,0);

	for(int i = 0;i < 10;i ++) {
		Data = DeleteSe_Queue_Num(Queue);
		free(Data);
	}
	StatusSe_Queue_Num(Queue,0);

	for(int i = 0;i < 10;i ++) {
		Data = ElementSe_Queue(i);
		AddSe_Queue_Num(Queue,Data);
	}
	StatusSe_Queue_Num(Queue,0);

	for(int i = 0;i < 10;i ++) {
		Data = DeleteSe_Queue_Num(Queue);
		free(Data);
	}
	StatusSe_Queue_Num(Queue,0);
	return 0;
}
ElementTypeSe_Queue_Num* ElementSe_Queue(int i) {
	ElementTypeSe_Queue_Num *Data = (ElementTypeSe_Queue_Num*) malloc (sizeof(ElementTypeSe_Queue_Num));
	Data->Value = i;

	return Data;

}
