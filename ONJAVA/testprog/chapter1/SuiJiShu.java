package chapter1;

import java.util.Random;

public class SuiJiShu{

	public static void main(String[] args) {
		Random rand = new Random();
		int[] arr = {2,588,888,1000,10000};
		
		for(int i = 0;i < arr.length;) {
			int r = rand.nextInt(5);
			if(arr[r] > 0) {
				System.out.println(arr[r] + " ");
				arr[r] = -1;
				i ++;
			}
		}	
	}
}
