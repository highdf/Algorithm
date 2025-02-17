#include <stdio.h>
#include "/home/luky/Algorithm/Include/status.h"

typedef enum Mode{
	CHAR,
	STRING,
	GENERAL,
}Mode;

#define OUT 2
#define IN 1

status Ischar(char c);
int F0(char *str);
int F1(char *str);
