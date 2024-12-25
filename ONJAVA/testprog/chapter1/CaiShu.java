package chapter1;

import java.util.Scanner;
import java.util.Random;

public class CaiShu{

	public static void main(String[] args) {
		Random rand = new Random();
		Scanner scan = new Scanner(System.in);

		int a;
		int x = rand.nextInt(100) + 1;

		System.out.println("Please enter a intege");

		do {
			a = scan.nextInt();
			
			if(x > a) {
				System.out.println("小了");
			} else if(x < a) {
				System.out.println("大了");
			} else {
				System.out.println("恭喜，猜中了");
			}	
		} while(x != a);
	}
}
