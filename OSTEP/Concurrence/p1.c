#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int get ();
void put (int i);
void* server (void* arg);
void* client (void* arg);

int buf = 0;
int count = 0;
int data_ready = 0;
int server_i = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; pthread_cond_t server_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t client_cond = PTHREAD_COND_INITIALIZER;

int main(int argc, char **argv)
{
	pthread_t th1, th2, th3, th4, th5;
	
	if (pthread_create(&th1, NULL, server, NULL) != 0)  {
		printf("Create thread %lu failed\n", th1);
		exit(1);
	}
	if (pthread_create(&th5, NULL, server, NULL) != 0)  {
		printf("Create thread %lu failed\n", th1);
		exit(1);
	}
	if (pthread_create(&th2, NULL, client, "client 0") != 0)  {
		printf("Create thread %lu failed\n", th2);
		exit(1);
	}
	// if (pthread_create(&th3, NULL, client, "client 1") != 0)  { printf("Create thread %lu failed\n", th3);
	// 	printf("Create thread %lu failed\n", th2);
	// 	exit(1);
	// }
	// if (pthread_create(&th4, NULL, client, "client 1") != 0)  { printf("Create thread %lu failed\n", th4);
	// 	printf("Create thread %lu failed\n", th2);
	// 	exit(1);
	// }

	pthread_join(th1, NULL);
	pthread_join(th5, NULL);
	pthread_join(th2, NULL);
	// pthread_join(th3, NULL);
	// pthread_join(th4, NULL);

	return 0;
}
//function
int get ()  {
	int re = 0;

	// while (data_ready == 0)  {
	// 	;
	re = buf;

	return re;
}
void put (int i)  {
	pthread_mutex_lock(&mutex);
	while (data_ready == 1)  {
		pthread_cond_wait(&server_cond, &mutex);
	}
	// while (data_ready == 1)  {
	// 	;
	// }
	buf = i;
	data_ready = 1;
	pthread_cond_signal(&client_cond);
	pthread_mutex_unlock(&mutex);
}

void* server (void* arg)  {
	while (1)  {
		put(server_i ++);
	}

	return NULL;
}
void* client (void* arg)  {
	char c = ' ';
	char *str = "";

	for (int i = 0; i < 1000000; i ++)  {
		pthread_mutex_lock(&mutex);
		while (data_ready == 0)  {
			pthread_cond_wait(&client_cond, &mutex);
		}
		int value = get();
		count ++;
		c = (count % 5 == 0)?('\n'): (' ');
		// printf("i = %d: %s%c", value, (char*)arg, c);
		printf("i = %d%c", value, c);
		data_ready = 0;
		pthread_cond_signal(&server_cond);
		pthread_mutex_unlock(&mutex);
	}

	return NULL;
}
