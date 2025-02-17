package operators;

public class ShortCircuit{

	public static void main(String[] args) {
		System.out.printf("Result: %b%n",(test0(1)&&test1(2)&&test2(2)));
	}

	static boolean test0(int val) {
		System.out.printf("in the test0%n");
		System.out.printf("val = %d%n",val);
		System.out.printf("val<2 = %b%n",val<2);
		return val < 2;
	}
	static boolean test1(int val) {
		System.out.printf("in the test1%n");
		System.out.printf("val = %d%n",val);
		System.out.printf("val<2 = %b%n",val<2);
		return val < 2;
	}
	static boolean test2(int val) {
		System.out.printf("in the test2%n");
		System.out.printf("val = %d%n",val);
		System.out.printf("val<2 = %b%n",val<2);
		return val < 2;
	}
}
