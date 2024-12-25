package operators;

import java.util.Random;

public class TernaryIfElse{

	public static void main(String[] args) {
		Random rand = new Random(47);
		int a = rand.nextInt(100);

		System.out.println("ternary(" + "(" + a + ")");
		System.out.println(ternary(a));
		System.out.printf("ifElse(%d)%n%d%n",a,ifElse(a));		
	}

	static int ternary(int i){
		return (i < 10)?(i * 100):(i * 10);
	}

	static int ifElse(int i){
		int re;

		if(i < 10) {
			re = i * 100;
		} else {
			re = i * 10;
		}

		return re;
	}
}
