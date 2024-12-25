package chapter1;

import java.util.Random;

public class RandomMa{

	public static void main(String[] args) {
		String QR = random();

		System.out.println(QR);
	}

	public static String random() {
		Random rand = new Random();
		String re = "";
		char[] a = new char[52];
		int Index;

		for(char i = 0;i < a.length;i ++) {
			if(i >= 0 && i <= 26) {
				a[i] = (char)(i + 'a');
				//a[i] = i + 'a';
			} else {
				a[i] =(char)(i - 26 + 'A');
			}
		}

		for(int i = 0;i < 4;i ++) {
			Index = rand.nextInt(52);
			//System.out.printf("%d ",Index);
			re += a[Index];
		}

		re += rand.nextInt(10);

		return re;
	}
}
