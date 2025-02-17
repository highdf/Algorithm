
public class Precedence{

	public static void main(String[] args) {
		int a = 1,b = 2,c = 3;

		System.out.println("a + b*c + c = " +(a+b*c+c));
		System.out.println("(a + b)*(c + c) = " + ((a+b)*(c+c)));
	}
}
