package control;

public class BreakAndContinue{

	public static void main(String[] args) {
		int i;
		System.out.println("break behaviour");
		for(i = 0;i < 10;i++) {
			if(i == 6) {
				break;
			} 

			System.out.printf("i = %d%n",i);
		}
		System.out.println("out for");
		System.out.printf("i = %d%n",i);

		System.out.println("continue behaviour");
		for(i = 0;i < 10;i++) {
			if(i == 6) {
				continue;
			} 

			System.out.printf("i = %d%n",i);
		}
		System.out.println("out for");
		System.out.printf("i = %d%n",i);
	}
}
