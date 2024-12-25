package chapter2;

import java.util.Scanner;

public class Test0{

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		System.out.printf("Please neter a String%n");
		String str = scan.next();

		if(F1(str) == true) {
			str = F0(str);
			System.out.printf("%s%n",str);
		} else {
			System.out.printf("The String is error%n");
		}

	}

	public static String F0(String str) {
		StringBuilder re = new StringBuilder("");
		String[] string = {"","I","II","III","IV","V","VI","VII","VIII","VX"};

		for(int i = 0;i < str.length();i ++) {
			re.append(string[str.charAt(i) - '0']);
		}
		return re.toString();
	}

	public static boolean F1(String str) {
		boolean re = true;

		if(str.length() <= 9) {
			for(int i = 0;i < str.length();i ++) {
				if(str.charAt(i) < '0' || str.charAt(i) > '9') {
					re = false;
					break;
				}
			}
		} else {
			re = false;
		}

		return re;
	}
}
