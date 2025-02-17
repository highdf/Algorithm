package housekeeping;

public class StaticInitialization{

	public static void main(String[] args) {
		Test1 test0;
		
		test0 = new Test1();
	}
}

class Test0{
	Test0(String s) {
		System.out.println(s);
	}
}

class Test1 {
	//static Test0 test0 = new Test0("one time init");
	static Test0 test0 = new Test0("three time init");

	Test0 test1 = new Test0("two times init");

	static {
		test0 = new Test0("four time init");
	}

	{
		test1 = new Test0("five time init");
	}

	Test1() {
		System.out.println("Th the Test1()");
	}
}

