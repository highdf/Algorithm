package chapter1;

import java.util.Scanner;

public class ZhiShu{
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int i,x = scan.nextInt();

		for(i = 2;i < x && x % i != 0;i ++){
			;
		}

		if(i < x) {
			System.out.println("NO");
		} else {
			System.out.println("YES");
		}
	}
}
