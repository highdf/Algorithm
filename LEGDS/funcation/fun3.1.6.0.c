#include <stdio.h>
#include "status.h"

int main()
{
	char w;
	int a = 0;
	int m;

	status Leap = TRUE;
	printf("Please enter \n");
	scanf("%d",&m);
	status t[m];

	printf("Please enter \n");

	while(i < m) {
		while( (w = getchar()) != '\n') {
			(w == 'S')?(a ++):(a --);
			if( a < 0) {
				Leap = FALSE;
				break;
			}
		}
		t[i] = Leap;		
		i ++;
	}
		

	if(Leap == TRUE) {
		(a == 0)?(printf("yes\n")):(printf("no\n"));
	} else {
	       printf("No\n");
	}	       
			
	return 0;
}
