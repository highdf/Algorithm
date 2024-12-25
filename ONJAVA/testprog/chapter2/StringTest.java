package chapter2;

import java.util.Scanner;
public class StringTest{

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		System.out.printf("Please enter a number%n");
		int num = scan.nextInt();

		String re;
		re = F1(num);

		System.out.printf("result is %s%n",re);
	}

	public static String F0(String str) {
		String re = "";
		int j = str.length() - 1;

		for(;j >= 0;j --) {
			re += str.charAt(j);
		}

		return re;
	}
	public static String F1(int num) {
		String re = "";
		char[] c = new char[7];

		for(int i = c.length-1;i >= 0;i --) {
			switch(num % 10) {
				case 0:c[i] = '零';break;
				case 1:c[i] = '壹';break;
				case 2:c[i] = '贰';break;
				case 3:c[i] = '叁';break;
				case 4:c[i] = '肆';break;
				case 5:c[i] = '伍';break;
				case 6:c[i] = '陆';break;
				case 7:c[i] = '柒';break;
				case 8:c[i] = '捌';break;
				case 9:c[i] = '玖';break;
			}	
			num /= 10;
		}

		re += new String(c);
		
		return re;
	}
}
