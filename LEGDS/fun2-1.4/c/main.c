#include "main.h"

int main() {
	int n;
	double x;

	printf("Please enter a double value\n");
	scanf("%lf",&x);
	printf("Please enter number of sum\n");
	scanf("%d",&n);

	printf("Result of sum is %.2lf\n",arraySum(x, n));
	printf("Recursion is %.2lf \n",arraySum0(x,n));
	return 0;
}
