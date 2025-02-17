package operators;

public class AutoInc {

	public static void main(String[] args) {
		int a = 2;

		System.out.println("a = " + (a));
		System.out.println("a ++ = " + (a++));
		System.out.println("a = " + (a));

		System.out.println("-----------");
		a = 2;
		System.out.println("a = " + (a));
		System.out.println("++ a = " + (++a));
		System.out.println("a = " + (a));
	}
}
