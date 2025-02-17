package src;

public class ArraySum{

	public static double arraySum(double x , int n) {
		int sign = 1;
		double re = 0;
		double A = x;

		for(int i = 0;i < n;i ++) {
			re = re + sign * A;
			sign *= -1;
			A *= x;
		}

		return re;
	}

	public static double arraySum0(double x,int n) {
		double re = 0;

		if(n == 1) {
			re = x;
		} else {
			re = x * (1 - arraySum0(x,n-1));
		}

		return re;
	}
}
