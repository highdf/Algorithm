package operators;

import java.util.Random;

public class MathOps{

	public static void main(String[] args) {
		Random rand = new Random(47);
		int a = rand.nextInt(100) + 1;
		int b = rand.nextInt(100) + 1;
		float c = rand.nextFloat();
		float d = rand.nextFloat();

		System.out.println("a = " + (a));
		System.out.println("b = " + (b));
		System.out.println("a + b = " + (a+b));
		System.out.println("a - b = " + (a-b));
		System.out.println("a * b = " + (a*b));
		System.out.println("a / b = " + (a/b));
		System.out.println("a % b = " + (a%b));

		System.out.println("c = " + (c));
		System.out.println("d = " + (d));
		System.out.println("c + d = " + (c+d));
		System.out.println("c - d = " + (c-d));
		System.out.println("c * d = " + (c*d));
		System.out.println("c / d = " + (c/d));
		System.out.println("c % d = " + (c%d));
		
	}
}
