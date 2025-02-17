
//Data Declaration
typedef struct ElementSe_Stack_Num{
	int Value;
}ElementTypeSe_Stack_Num;
typedef ElementTypeSe_Stack_Num* PtrToElementSe_Stack_Num;

//Type Declaration
typedef struct {
	PtrToElementSe_Stack_Num *Data;
	int Top;
	int Size;
}Se_Stack_Num;

//General Declaration
typedef int Number;
typedef Se_Stack_Num* PtrToSe_Stack_Num;
