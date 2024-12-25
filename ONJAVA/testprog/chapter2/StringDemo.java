package chapter2;

import java.util.Scanner;

public class StringDemo{

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String name = "luky";
		String passwork = "275365shen";


		for(int i = 0;i < 3;i ++) {
			System.out.println("Please enter your name");
			String sname = scan.next();
			System.out.println("Please enter your passwork");
			String spasswork = scan.next();
			
			if(name.equals(sname) == true && passwork.equals(spasswork)) {
				System.out.println("Enter is true");
				break;
			} else {
				System.out.printf("Eneter error:Enter again Please%n");
				System.out.printf("%d times%n",2-i);
			}
		}
	}
}
