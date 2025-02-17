import java.util.Scanner;
import src.Circular;

public class Main {
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int length;

		System.out.printf("Please enter length of array%n");
		length = scan.nextInt();

		int[] arr = new int[length];
		System.out.printf("Please enter element of array%n");
		for(int i = 0;i < arr.length;i ++) {
			arr[i] = scan.nextInt();
		}

		System.out.printf("Please enter number of circular left shift%n");
		int count = scan.nextInt();

		System.out.printf("Circular left shift %d after%n",count);
		Circular.leftShift(arr,count);
		for(int i = 0;i < arr.length;i ++) {
			char separator = (i == (arr.length-1))?('\n'):(' ');
			System.out.printf("%d%c",arr[i],separator);
		}

		scan.close();
	}

}
