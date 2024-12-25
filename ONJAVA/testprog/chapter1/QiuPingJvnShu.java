package chapter1;

import java.util.Scanner;

public class QiuPingJvnShu{

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int Max = 0,Min = 100,sum = 0;

		System.out.println("Please enter grade");
		for(int i = 0;i < 4;) {
			int num = scan.nextInt();
			if(num >= 0 && num <= 100) {
				sum += num;
				Max = (num > Max)?(num):(Max);
				Min = (num < Min)?(num):(Min);
				i ++;
			} else {
				System.out.println("number is over grade");
			}
		}

		sum -= (Max + Min);

		System.out.println("result is " + (sum/4.0));
	}
}
