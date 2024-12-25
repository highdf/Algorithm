package chapter1;

public class FengQiGuo{

	public static void main(String[] args) {
		for(int i = 1;i < 101;i ++ ) {
			int a = i % 10;
			int b = (i/10) % 10;

			if(i % 7 == 0 || a == 7 || b == 7) {
				System.out.printf("%nPass%n");
			} else {
				System.out.printf("%d ",i);
			}
		}

		System.out.println();
	}
}

