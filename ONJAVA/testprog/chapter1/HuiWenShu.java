package chapter1;

import java.util.Scanner;

public class HuiWenShu{

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int i = in.nextInt();
		int a = i;
		int sum = 0;

		while(a > 0) {
			sum = sum * 10 + a % 10;
			a /= 10;
		}

		//System.out.println("sum = " + (sum));
		System.out.println(sum == i);
	}
}
