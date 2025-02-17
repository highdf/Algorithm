#include "1.23_in.h"
#include "1.23_out.h"

//funcation
void Operat(char *str,int Len) {
	char text[Len];
	//临时存放更新后的文本
	int Lable1 = OUT,Lable0 = OUT,Lable2 = OUT;
	//前者用于标记是否处理注释，后者用于标记匹配注释前缀符
	int ti,si;
	//text的索引，str的索引

	for(ti = 0,si = 0;str[si] != EOF;si ++) {
		if(Lable2 == OUT && str[si] == '\'') {
			(Lable1 == OUT)?(Lable1 = IN):(Lable1 = OUT);
		} else if(Lable1 == OUT && str[si] == '"') {
			(Lable2 == OUT)?(Lable2 = IN):(Lable2 = OUT);
		}

		if(Lable1 == OUT && Lable2 == OUT) {
			if(Lable0 == OUT && str[si] == '/') {
				//判断是否匹配注释前缀符
				Lable0 = IN;
			}

			if(Lable0 == IN) {
				switch(str[si]) {
					case '/':si += F0(&(str[si+1]));break;
					case '*':si += F1(&(str[si+1]));break;
					default :text[ti++] = '/';text[ti++] = str[si];
				}	
				Lable0 = OUT;

			} else {
				text[ti] = str[si];
				ti ++;
			}	
		} else {
			text[ti] = str[si];
			ti ++;
		}
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

	for(i = 0;str[i] != '\n' && str[i] != EOF; i++) {
		;
	}

	return i;
}

int F1(char *str) {
	int i;
	status Lable = FALSE;
	int Lable0 = OUT;

	for(i = 0;Lable != TRUE;i ++) {
		if(str[i] == '*') {
			Lable0 = IN;
		}

		if(Lable0 == IN) {
			switch(str[i]) {
				case '*':break;
				case '/':Lable = TRUE;break;
				default :Lable0 = OUT;
			}
		}
	}	

	return i;
}
