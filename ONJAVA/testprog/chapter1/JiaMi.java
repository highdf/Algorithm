package chapter1;

import java.util.Scanner;

public class JiaMi{

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int num  = scan.nextInt();
		int i;
		int[] arr = new int[10];

		for(i = 0; i < arr.length && num > 0;i ++) {
			arr[i] = num % 10;
			arr[i] = (arr[i] + 5) % 10;
			num /= 10;
		}

		if(num == 0) {
			for(int j = 0;j < i;j ++) {
				num = num * 10 + arr[j];
			}	
			System.out.println("result is " + (num));
		} else {
			System.out.println("The array is small");
		}
	}
}
