package chapter1;

import java.util.Scanner;

public class ArrCopy{

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int[] arr;
		int[] arr0;
		int N,front,last;

		System.out.println("Please enter array of length");
		N = scan.nextInt();
		arr = new int[N];

		System.out.println("Please enter array of element");
		for(int i = 0;i < arr.length;i ++) {
			arr[i] = scan.nextInt();
		}

		System.out.println("Please enter front and last of value");
		front = scan.nextInt();
		last = scan.nextInt();

		arr0 = CopyArr.copyArr(arr,front,last);

		System.out.println("result is");
		for(int i = 0;i < arr0.length;i ++) {
			System.out.printf("%d%c",arr0[i],(i < (arr0.length-1))?(' '):('\n'));
		}
	}
}

class CopyArr{

	static int[] copyArr(int[] arr,int front,int last) {
		int[] re = new int[last-front];

		for(int i = 0,j = i + front;j < arr.length && i < re.length;j ++,i ++) {
			re[i] = arr[j];
		}

		return re;
	}
}
