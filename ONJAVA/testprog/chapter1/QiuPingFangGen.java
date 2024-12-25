package chapter1;

import java.util.Scanner;

public class QiuPingFangGen{

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int i,x = scan.nextInt();

		for(i = 1;i*i <= x;i ++) {
			;
		}

		i = i - 1;	

		System.out.println("i = " + (i));
	}
}
