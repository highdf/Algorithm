package chapter2;

import java.util.Scanner;

public class XuanZhuan{

	public static void main(String[] arge) {
		Scanner scan = new Scanner(System.in);
		
		System.out.printf("Please enter a String and number%n");
		String str = scan.next();
		String str0 = scan.next();
		int count = scan.nextInt();

		str = XuanZhuan(str,count);

		//System.out.printf("str0 = %s%n",str0);
		System.out.printf("%b%n",str0.equals(str));
	}

	public static String XuanZhuan(String str,int count) {
		StringBuilder sb = new StringBuilder("");
		count %= str.length();
		sb.append(str.substring(count,str.length()));
		sb.append(str.substring(0,count));

		return sb.toString();
	}
}
