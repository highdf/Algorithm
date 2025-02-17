#include "annotation_in.h"
#include "annotation_out.h"

//funcation
void annotation(char *str,int Len) {
	char text[Len];
	Mode mode = GENERAL;
	//指向ti和si的索引
	int ti,si;
	//记录遍历过程中的前一个字符
	char front = ' ';


	for(ti = 0,si = 0;str[si] != EOF;si ++) {
		//更新模式
		if(mode == GENERAL && str[si] == '\'') {
			mode = CHAR;	
		} else if(mode == GENERAL && str[si] == '"') {
			mode = STRING;
		} else if(mode == CHAR && str[si] == '\'') {
			mode = GENERAL;
		} else if(mode == STRING && str[si] == '"') {
			mode = GENERAL;
		}

		if(mode == GENERAL) {
			//printf("si = %d,ti = %d\n",si,ti);
			if(front == '/') {
				switch(str[si]) {
					case '/':si += F0(&(str[si]));ti --;break;
					case '*':si += F1(&(str[si+1]));ti --;break;
					default :text[ti++] = str[si];
				}	

			} else {
				if(str[si] == '\\') {
					text[ti++] = str[si++];
				}
				text[ti] = str[si];
				ti ++;
			}	
		} else {
			text[ti] = str[si];
			ti ++;
		}

		front = str[si];
	}

	text[ti] = EOF;

	for(ti = 0;text[ti] != EOF;ti++) {
		str[ti] = text[ti];
	}
	str[ti] = EOF;

}

int GetText(FILE *fp,char *str,int n) {
	int i;
	char c;

	for(i = 0;(c = fgetc(fp) ) != EOF && i < n;i ++) {
		str[i] = c;
	}

	if(i < n) {
		str[i] = EOF;
	} else {
		i = -1;
	}

	return i;
}

void Print(char *str) {
	for(int i = 0;str[i] != EOF;i++) {
		printf("%c",str[i]);
	}
}
status Ischar(char c) {
	return ((c=='\'') || (c=='\"'))?(TRUE):(FALSE);
}

int F0(char *str) {
	int i;

	for(i = 0;str[i] != '\n' && str[i] != EOF;i ++) {
		;
	}

	return i - 1;
}

int F1(char *str) {
	int i;
	int re;
	char front = ' ';
	status Label = FALSE;

	for( i = 0;str[i] != EOF && Label == FALSE;i ++) {
		if(front == '*' && str[i] == '/') {
			Label = TRUE;
		}	

		front = str[i];
	}

	(str[i] == EOF)?(re = i-1):(re = i);

	return re;
}
