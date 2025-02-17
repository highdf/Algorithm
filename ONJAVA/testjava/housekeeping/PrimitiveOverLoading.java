package housekeeping;

public class PrimitiveOverLoading{

	public static void main(String[] args) {
		Test test = new Test();
		byte b = 0;
		char c = ' ';
		short s = 0;
		int i = 0;
		long l = 0;
		float f = 0;
		double d = 0;

		System.out.println("f0");
		test.f0(b);
		test.f0(c);
		test.f0(s);
		test.f0(i);
		test.f0(l);
		test.f0(f);
		test.f0(d);

		System.out.println("f1");
		test.f1(b);
		test.f1(c);
		test.f1(s);
		test.f1(i);
		test.f1(l);
		test.f1(f);
		test.f1(d);

		System.out.println("f2");
		test.f2(b);
		test.f2(c);
		test.f2(s);
		test.f2(i);
		test.f2(l);
		test.f2(f);
		test.f2(d);

		System.out.println("f3");
		test.f3(b);
		test.f3(c);
		test.f3(s);
		test.f3(i);
		test.f3(l);
		test.f3(f);
		test.f3(d);

		System.out.println("f4");
		test.f4(b);
		test.f4(c);
		test.f4(s);
		test.f4(i);
		test.f4(l);
		test.f4(f);
		test.f4(d);

		System.out.println("f5");
		test.f5(b);
		test.f5(c);
		test.f5(s);
		test.f5(i);
		test.f5(l);
		test.f5(f);
		test.f4(d);
	}
}

class Test{

	void f0(byte i) {
		System.out.println("f0(byte)");
	}
	void f0(char i) {
		System.out.println("f0(char)");
	}
	void f0(short i) {
		System.out.println("f0(short)");
	}
	void f0(int i) {
		System.out.println("f0(int)");
	}
	void f0(long i) {
		System.out.println("f0(long)");
	}
	void f0(float i) {
		System.out.println("f0(float)");
	}
	void f0(double i) {
		System.out.println("f0(double)");
	}

	void f1(char i) {
		System.out.println("f1(char)");
	}
	void f1(short i) {
		System.out.println("f1(short)");
	}
	void f1(int i) {
		System.out.println("f1(int)");
	}
	void f1(long i) {
		System.out.println("f1(long)");
	}
	void f1(float i) {
		System.out.println("f1(float)");
	}
	void f1(double i) {
		System.out.println("f1(double)");
	}
	
	void f2(int i) {
		System.out.println("f2(int)");
	}
	void f2(long i) {
		System.out.println("f2(long)");
	}
	void f2(float i) {
		System.out.println("f2(float)");
	}
	void f2(double i) {
		System.out.println("f2(double)");
	}

	void f3(long i) {
		System.out.println("f3(long)");
	}
	void f3(float i) {
		System.out.println("f3(float)");
	}
	void f3(double i) {
		System.out.println("f3(double)");
	}

	void f4(float i) {
		System.out.println("f4(float)");
	}
	void f4(double i) {
		System.out.println("f4(double)");
	}

	void f5(double i) {
		System.out.println("f5(double)");
	}
}
