package chapter1;

import java.util.Scanner;

public class FeiJiPiao{

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("Please enter price");
		double price = scan.nextDouble();
		System.out.println("Please enter month");
		int month = scan.nextInt();
		System.out.println("Please enter seat");
		String seat = scan.next();

		System.out.println("Price is " + (prefprice(price,month,seat)));
	}

	public static double prefprice(double price,int month,String seat) {
		if(month >= 5 && month <= 10) {
			price = (seat == "First Class")?(price * 0.9):(price * 0.86);
		} else {
			price = (seat == "First Class")?(price * 0.7):(price * 0.65);
		}

		return price;
	}
}
