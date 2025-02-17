import java.util.Scanner;

import src.BinSearch;

public class Main{

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		System.out.printf("Please enter a length of array%n");
		int length = scan.nextInt();

		System.out.printf("Please enter a ordered array%n");
		int[] arr = new int[length];
		for(int i = 0;i < arr.length;i ++) {
			arr[i] = scan.nextInt();
		}

		System.out.printf("Please enter match%n");
		int match = scan.nextInt();
		scan.close();

		// int re = BinSearch.binSearch(arr, match);
		// if(re >=0) {
		// 	System.out.printf("ordered_array[%d] = match%n",re);
		// } else {
		// 	System.out.printf("Don't find in the ordered_array%n");
		// }
		int re = BinSearch.binSearch(arr,0,arr.length-1,match);
		if(re >=0) {
			System.out.printf("ordered_array[%d] = match%n",re);
		} else {
			System.out.printf("Don't find in the ordered_array%n");
		}
	}	
}
