package housekeeping;

public class InitalValues{

	public static void main(String[] args) {
		Test test = new Test();
		int i = 0;

		i ++;
		test.print();
	}
}
class Test{
	byte b = 0;
	char c = 'a';
	short s = 2;
	int i = 4;
	long l = 5;
	float f = 1.1f;
	double d = 3.2;
	Test test;

	Test() {
	}

	void print() {
		System.out.println("b = " + (b));
		System.out.println("c = " + (c));
		System.out.println("s = " + (s));
		System.out.println("i = " + (i));
		System.out.println("l = " + (l));
		System.out.println("f = " + (f));
		System.out.println("d = " + (d));
		System.out.println("test = " + (test));
	}
}
