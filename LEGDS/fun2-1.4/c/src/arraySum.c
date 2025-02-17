#include "arraySum_in.h"
#include "arraySum_out.h"

double arraySum(double x,int n) {
	int sign = 1;
	double A = x;
	double re = 0;

	for(int i = 0;i < n;i ++) {
		re += A * sign;
		sign *= -1;
		A *= x;
	}

	return re;
}

double arraySum0(double x,int n) {
	double re = 0;

	if(n == 1) {
		re = x;
	} else {
		re = x * (1 - arraySum0(x, n-1));
	}

	return re;
}
