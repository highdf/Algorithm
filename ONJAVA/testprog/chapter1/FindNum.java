package chapter1;

import java.util.Scanner;

public class FindNum{
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N;
		int[] arr;
		int element;

		System.out.println("Please enter a intege");
		N = scan.nextInt();
		arr = new int[N];

		System.out.println("Please enter array of element");
		for(int i = 0;i < arr.length;i ++) {
			arr[i] = scan.nextInt();
		}

		System.out.println("Please enter find element");
		element = scan.nextInt();

		System.out.println(Find.findArr(arr,element));

	}
}

class Find{

	static boolean findArr(int[] arr,int element) {
		boolean re;
		int i;

		for(i = 0; i < arr.length && arr[i] != element;i ++)  {

		}

		if(i < arr.length) {
			re = true;
		} else {
			re = false;
		}

		return re;
	}
}
