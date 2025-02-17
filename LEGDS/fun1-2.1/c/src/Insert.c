#include "Insert_in.h"
#include "Insert_out.h"

int Insert(List *list,int insert_value) {
	int re = -1;

	if( (list->last + 1) == list->length) {
		printf("The arr is full\n");
		printf("Insert failed\n");
	} else {
		int index = BinSearch(list->arr, list->last+1, insert_value);

		for(int i = list->last;i >= index;i --) {
			list->arr[i+1] = list->arr[i];
		}

		list->arr[index] = insert_value;
		list->last ++;
		re = 1;
	}

	return re;
}

List* MakeList(int length) {
	List *re = NULL;

	List *list = (List*)malloc(sizeof(List));
	list -> arr = (int *) malloc(length * sizeof(length));

	if (list != NULL && list -> arr != NULL) {
		list -> length = length;
		list -> last = -1;
		re = list;
	} else {
		printf("Error:In the Insert\n");
		printf("Malloc is failed\n");
	}

	return re;
}
