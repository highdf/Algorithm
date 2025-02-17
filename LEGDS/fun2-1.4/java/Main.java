import java.util.Scanner;
import src.ArraySum;

public class Main{

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		System.out.printf("Please enter a double value%n");
		double x = scan.nextDouble();
		System.out.printf("Please enter number of sum%n");
		int n = scan.nextInt();

		System.out.printf("Result of sum is %.2f %n",ArraySum.arraySum(x, n));
		System.out.printf("Recursion is %.2f %n",ArraySum.arraySum0(x,n));

		scan.close();
	}
}
