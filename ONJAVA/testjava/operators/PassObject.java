package operators;

public class PassObject{

	public static void main(String[] args) {
		Tank c = new Tank();

		c.c = 23;
		System.out.println("c.c = " + (c.c));
		f(c);
		System.out.println("Before c.c = " + (c.c));

	}
	static void f(Tank b) {
		b.c = 21;
	}
}
class Tank{
	int c;
}
