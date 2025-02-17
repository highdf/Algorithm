package housekeeping;

public class ArrayOfPrimitives{

	public static void main(String[] args) {
		int[] arr = {1,2,3,4,};
		//int[] arr;
		//arr = {1,2,3,4,};
		//int[] arr; 
		//arr = new int[4];
		//arr[0] = arr[1] = arr[2] = arr[3] = 0;
		int[] a;

		a = arr;

		System.out.println("first time print");
		for(int t:arr) {
			System.out.printf("%d%c",t,' ');
		}
		System.out.println();

		for(int i = 0;i < a.length;i ++) {
			a[i] ++;
		}

		System.out.println("two time print");
		for(int t:arr) {
			System.out.printf("%d%c",t,' ');
		}
		System.out.println();
	}
}
