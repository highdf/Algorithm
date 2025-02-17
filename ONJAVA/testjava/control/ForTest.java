package control;

public class ForTest{

	public static void main(String[] args) {
		int i;

		for(i = 0;i < 10;i ++) {
			System.out.printf("i = %d : %b : Into for%n",i,i < 10);
		}

		System.out.printf("i = %d : %b : out for%n",i,i < 10);
	}
}
