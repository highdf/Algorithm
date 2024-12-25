package chapter1;

import java.util.Scanner;

public class QiuZhiShu{

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		System.out.println("Please enter range of prime number");
		int front = scan.nextInt();
		int last = scan.nextInt();

		rangePrime(front,last);
	}

	public static void rangePrime(int front,int last) {
		int count = 0;

		for(int i = front;i <= last;i ++ ) {
			if(isPrime(i)) {
				count ++;
				System.out.printf("%d ",i);
			}
		}

		System.out.println();
	}

	private static boolean isPrime(int number) {
		boolean re;
		int i;

		for(i = 2;i < number && number % i != 0;i ++) {
			;
		}

		if(i < number) {
			re = false;
		} else {
			re = true;
		}	

		return re;
	}
}
