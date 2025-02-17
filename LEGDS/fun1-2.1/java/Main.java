import java.util.ArrayList;
import java.util.Scanner;
import src.Insert;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		ArrayList<Integer> arr = new ArrayList<>();
		
		System.out.printf("Please enter number of element%n");
		int number = scan.nextInt();

		System.out.printf("Please enter element of array%n");
		for(int i = 0;i < number;i ++) {
			int element = scan.nextInt();
			arr.add(element);
		}

		System.out.printf("Pleade enter element of insertion%n");
		int insert = scan.nextInt();

		Insert.insert(arr, insert);

		System.out.printf("After Insert%n");
		for(int i = 0;i < arr.size();i ++) {
			char c = (i == (arr.size() - 1))?('\n'):(' ');
			System.out.printf("%d%c",arr.get(i),c);
		}

		scan.close();

	}
}
