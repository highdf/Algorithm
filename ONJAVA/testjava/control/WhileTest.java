package control;

public class WhileTest{

	public static void main(String[] args) {
		int i = 0;

		while(i < 10) {
			System.out.printf("i = %d %b\tInside 'while'%n",i,i < 10);
			i ++;
		}

		System.out.printf("i = %d %b\tout 'while'%n",i,i < 10);
	}
}
