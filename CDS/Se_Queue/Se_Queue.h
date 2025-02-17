//Data Declaration
typedef struct ElementSe_Queue_Num{
	int Value;
}ElementTypeSe_Queue_Num;
typedef ElementTypeSe_Queue_Num* PtrToElementSe_Queue_Num;

//Type Declaration
typedef struct Queue{
	PtrToElementSe_Queue_Num *Data;
	int Front;
	int Count;
	int MaxSize;
}Se_Queue_Num;

//General Declaration
typedef Se_Queue_Num* PtrToSe_Queue_Num;
