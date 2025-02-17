package housekeeping;

public class Flower{

	public static void main(String[] args) {
		Test test0 = new Test((char)'a');
		Test test1 = new Test((short)122);
		Test test2 = new Test((int)'e');

		test0.print();
		test1.print();
		test2.print();

	}
}

class Test{
	private char a;
	private short b;
	private int c;

	Test(char a) {
		this.a = a;
	}

	Test(short b) {
		this((char)(b-1));
		this.b = b;
	}

	Test(int c) {
		this((short)(c-2));
		this.c = c;
	}

	void print() {
		System.out.println("a = " + (this.a));
		System.out.println("b = " + (this.b));
		System.out.println("c = " + (this.c));
	}
}
