package housekeeping;

public class OrderInitialization{

	public static void main(String[] args) {
		Test test = new Test();
	}
}

class Test {
	int i0;

	Test() {
		System.out.println("in the Test()");
		System.out.printf("i0 = %d,i1 = %d%n",i0,i1);
		this.i0 = 3;
		this.i1 = 3;
		System.out.printf("i0 = %d,i1 = %d%n",i0,i1);
	}

	int i1;
}
