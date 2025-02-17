#include "main.h"

int main() {
	int length;

	printf("Please enter length of array\n");
	scanf("%d",&length);
	List *list = MakeList(length);

	printf("Please enter you want enter's number of element\n");
	int last;
	scanf("%d",&last);

	printf("Please enter value of array\n");
	for(int i = 0;i < last;i ++) {
		scanf("%d",&list->arr[i]);
		list->last ++;	
	}

	int insert_value;
	printf("Please enter value of insert\n");
	scanf("%d",&insert_value);

	int re = Insert(list,insert_value);
	if(re > 0) {
		printf("After insertion\n");
		for(int i = 0;i <= list->last;i ++) {
			int c = (i == (list->last))?('\n'):(' ');
			printf("%d%c",list->arr[i],c);
		}
	}

	return 0;
}
