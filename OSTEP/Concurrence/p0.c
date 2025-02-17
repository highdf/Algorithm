#include <stdio.h>
#include <pthread.h> 

void* mythread(void *c);

int counter = 0;

int main() {
	pthread_t p1, p2;
	printf("main begin (counter = %d)\n", counter);

	pthread_create(&p1, NULL, mythread, "A");
	pthread_create(&p2, NULL, mythread, "B");

	pthread_join(p1, NULL);
	pthread_join(p2, NULL);

	printf("main done (counter = %d)\n", counter);

	return 0;
}

void* mythread(void *c) {
	printf("%c thread begin\n", *(char *)c);
	for(int i = 0;i < 1e7;i ++) {
		counter ++;
	}

	return NULL;
}
