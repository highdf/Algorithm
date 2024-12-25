package housekeeping;

public class OverLoadOrder{

	public static void main(String[] args) {
		Test test = new Test();

		test.info(1,"Test first");
		test.info("Test secoud",2);
	}
}

class Test{

	void info(int i,String str) {
		System.out.println(i + str);
	}

	void info(String str,int i) {
		System.out.println(str + i);
	}
}
