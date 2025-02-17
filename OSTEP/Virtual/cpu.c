#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
//#include "common.h"

int main(int argc,char **args) {
	
	if(argc != 2) {
		fprintf(stderr,"usage:cpu <string> \n");
		exit(1);
	}

	char *str = args[1];

	while(1) {
		//Spin(1);
		for(int i = 0;i < 100000;i ++) {
			;
		}
		printf("%s\n",str);
	}

	return 0;
}
