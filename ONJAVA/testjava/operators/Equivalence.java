package operators;

public class Equivalence{

	public static void main(String[] args) {
		Tank t0 = new Tank();
		Tank t1 = new Tank();

		t0.a = t1.a = 3;

		System.out.println("t0.a = " + (t0.a));
		System.out.println("t1.a = " + (t1.a));

		System.out.println("(t0 == t1) = " + (t0==t1));
	}
}
class Tank{
	int a;
}
