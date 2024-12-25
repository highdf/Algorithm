package chapter1;

import java.util.Scanner;

public class ChuShu{

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		int b = scan.nextInt();
		int q = 0,r = 0;

		while(a >= b) {
			a = a - b;
			q ++;	
		}

		r = a;
		System.out.println("q = " + (q));
		System.out.println("r = " + (r));
	}
}
