package operators;

import java.util.Random;

public class Bool{

	public static void main(String[] args) {
		Random rand = new Random(47);
		int i = rand.nextInt(100);
		int j = rand.nextInt(100);

		System.out.println("i = " + (i));
		System.out.println("j = " + (j));
		System.out.println("i < 10 = " + (i<10));
		System.out.println("j < 10 = " + (j<10));
		System.out.println("(i<10) && (j<10) = " + ((i<10)&&(j<10)));
		System.out.println("(i<10) || (j<10) = " + ((i<10)||(j<10)));
	}
}
