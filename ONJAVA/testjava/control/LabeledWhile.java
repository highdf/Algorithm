package control;

public class LabeledWhile{

	public static void main(String[] args ) {
		System.out.println("break outer");	
outer:
		for(int i = 0;i < 2;i ++) {
			System.out.println("In for of number 0");
			for(int j = 0;j < 2;j ++) {
				System.out.printf("i = %d,j = %d%n",i,j);
				System.out.println("In for of number 1");
				if(j == 1) {
					break outer;
				}
			}
		}

		System.out.println("continue outer");	
oute:
		for(int i = 0;i < 2;i ++) {
			System.out.println("In for of number 0");
			for(int j = 0;j < 3;j ++) {
				System.out.printf("i = %d,j = %d%n",i,j);
				System.out.println("In for of number 1");
				if(j == 1) {
					continue oute;
				}
			}
		}

	}
}
