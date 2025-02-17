
long sum(long *start,int n) {
	if(n <= 0) {
		return 0;
	} else {
		return *start + sum(start+1,n-1);
	}
}
