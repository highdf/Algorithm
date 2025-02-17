package control;

public class ReturnTest{

	public static void main(String[] args){
		int i;
		i = test();

		System.out.printf("return before i = %d%n",i);
	}

	static int test() {
		System.out.printf("In front of return%n");
		return 1;
	}
}
