
//Funcation Declaration
PtrToHeap MakeHeap (int Size);
status IsEmptyHeap(PtrToHeap p);
status IsFullHeap(PtrToHeap p);
status InsertHeap(PtrToHeap p,ElementTypeHeap *Data);
ElementTypeHeap DeleteHeap(PtrToHeap p);
void StatusHeap(PtrToHeap p,int n);