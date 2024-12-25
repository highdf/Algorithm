package chapter1;

import java.util.Scanner;

public class ZuiDaZhi{

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int[] arr;
		int n = scan.nextInt();
		int Max;
		arr = new int[n];

		System.out.println("Please enter element");
		for(int i = 0;i < arr.length;i ++) {
			arr[i] = scan.nextInt();
		}

		Max  = Array.ArrayMax(arr);
		System.out.println("MaxValue is " + (Max));
	}
}

class Array{

	static int ArrayMax(int[] arr) {
		int Max = 0;

		for(int i = 0;i < arr.length;i ++) {
			Max = (Max < arr[i])?(arr[i]):(Max);
		}

		return Max;
	}
}
