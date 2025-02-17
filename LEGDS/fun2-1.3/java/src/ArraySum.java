package src;

public class ArraySum{
	public static int araySum(int a,int n) {
		int sum = 0;
		int A = a;

		for(int i = 0;i < n;i ++) {
			sum += A;
			A = A * 10 + a;
		}

		return sum;
	}
	public static int[] arraySum0(int a,int n) {
		int[] re = new int[n+1];
		int[] A = new int[n];

		for(int i = 0;i < re.length;i ++) {
			re[i] = 0;
			if(i < ( re.length - 1 )) {
				A[i] = 0;
			}
		}
		
		for(int i = 0;i < A.length;i ++) {
			int carry = 0;
			int j = 0;
			A[i] = a;

			for(;j <= i;j ++) {
				int current = (A[j] + re[j] + carry) % 10;
				carry = (A[j] + re[j] + carry) / 10;
				re[j] = current;
			}
			re[j] = carry;
		}

		return re;
	}
	public static int[] arraySum1(int a,int n) {
		int[] re = new int[n+1];
		int[] A = new int[n];

		int carry = 0;
		for(int i = 0;i < A.length;i ++) {
			int current = ( (A.length - i) * a + carry ) % 10;
			carry = ( (A.length - i) * a + carry) / 10;
			re[i] = current;
		}
		re[re.length - 1] = carry;

		return re;
	}
}
