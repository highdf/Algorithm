//Data Declaration
typedef struct Ch_ListElement_Num{
	int Value;
}ElementTypeCh_List_Num;

//Type Declaration
typedef struct Ch_ListNode_Num {
	ElementTypeCh_List_Num *Data;
	struct Ch_ListNode_Num *Next;
}Ch_ListNode_Num;

//General Declaration
typedef Ch_ListNode_Num* PtrToCh_ListNode_Num;
typedef Ch_ListNode_Num* PtrToCh_ListHead_Num;
typedef int Length;
