package operators;

public class URShift{

	public static void main(String[] args) {
		short s = -1;

		System.out.printf("s:\t%s%n",Integer.toBinaryString(s));
		s >>>= 26;
		System.out.printf("s>>>10:\t%s%n",Integer.toBinaryString(s));
		System.out.printf("s>>>10:\t%s%n",Integer.toBinaryString(s>>>10));
		s = 0x7fff;
		System.out.printf("s:\t%s%n",Integer.toBinaryString(s));
		s >>>= 10;
		System.out.printf("s>>>10:\t%s%n",Integer.toBinaryString(s));
		s = 0x7fff;
		System.out.printf("s>>>10:\t%s%n",Integer.toBinaryString(s>>>10));

	}
}
