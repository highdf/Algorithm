import java.util.Scanner;

import src.ArraySum;

public class Main{

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		System.out.printf("Please enter the first element%n");
		int a = scan.nextInt();
		System.out.printf("Please enter number of sum%n");
		int n = scan.nextInt();

		int sum = ArraySum.araySum(a, n);
		System.out.printf("Result of sum = %d%n",sum);
		
		int[] arr = ArraySum.arraySum0(a, n);

		if(arr[arr.length - 1] == 1) {
			System.out.printf("1");
		}
		for(int i = arr.length-2;i >= 0;i --) {
			char c = (i == 0)?('\n'):('\0');
			System.out.printf("%d%c",arr[i],c);
		}
		
		int[] arr0 = ArraySum.arraySum1(a, n);

		if(arr0[arr0.length - 1] == 1) {
			System.out.printf("1");
		}

		for(int i = arr0.length-2;i >= 0;i --) {
			char c = (i == 0)?('\n'):('\0');
			System.out.printf("%d%c",arr0[i],c);
		}

		scan.close();
	}
}
