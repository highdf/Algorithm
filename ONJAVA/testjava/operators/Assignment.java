package operators;

public class Assignment{

	public static void main(String[] args) {
		Tank t0 = new Tank();
		Tank t1 = new Tank();

		t0.value = 1;
		t1.value = 0;

		System.out.println("t0.value = " + (t0.value));
		System.out.println("t1.value = " + (t1.value));

		t0 = t1;
		System.out.println("t0 = t1 before");
		System.out.println("t0.value = " + (t0.value));
		System.out.println("t1.value = " + (t1.value));

	}
}
class Tank{
	int value;
}
