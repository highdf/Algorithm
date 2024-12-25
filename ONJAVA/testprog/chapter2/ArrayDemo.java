package chapter2;

import java.util.Scanner;
import java.util.ArrayList;

public class ArrayDemo{

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		ArrayList<Student> al = new ArrayList<Student>();

		System.out.printf("Please enter number of student%n");
		int num = scan.nextInt();

		System.out.printf("Please enter info of student%n");
		for(int i = 0,end = num;i < num;i ++) {
			String number = scan.next();
			String name = scan.next();
			int age = scan.nextInt();
			Student sd = new Student(number,name,age);
			al.add(sd);
		}

		for(int i = 0,end = al.size();i < end;i ++) {
			al.get(i).getInfo();
		}
	}
}
