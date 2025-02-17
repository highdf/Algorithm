package operators;

public class DoubleEquivalence{

	public static void main(String[] args) {
		double a = Double.MIN_VALUE;
		double b = Double.MAX_VALUE;

		System.out.printf("(0 == %e) = %b%n",a,(0 == a));
		System.out.printf("(%e == %e) = %b%n",b,(b - a),(b == (b-a)));
	}
}
