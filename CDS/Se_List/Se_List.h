//Data Declaration
typedef struct ElementSe_List{
	int Value;
}ElementTypeSe_List_Num;
typedef ElementTypeSe_List_Num* PtrToElementSe_List_Num;

//Type Declaration
typedef struct Se_List_Num {
		PtrToElementSe_List_Num *Data;
		int Last;
		int Size;
}Se_List_Num;

//General Declaration
typedef Se_List_Num* PtrToSe_List_Num;
