package chapter1;

public class OuJiShu{

	public static void main(String[] args) {
		int[] array = {1,2,3,4,5,6,7,8,9,};

		for(int i = 0;i < array.length;i ++) {
			if(array[i] % 2 == 0) {
				array[i] /= 2;
			} else {
				array[i] *= 2;
			}
		}

		for(int i = 0;i < array.length;i ++) {
			System.out.printf("%d%c",array[i],(i == (array.length-1))?('\n'):(' '));
		}

	}
}
