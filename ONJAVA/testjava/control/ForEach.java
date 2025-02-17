package control;

public class ForEach{

	public static void main(String[] args) {
		int[] arr = new int[10];
		int i = 0;

		for(;i < (arr.length);i ++) {
			arr[i] = i;
		}
		for(int d : arr) {
			System.out.printf("%d ",d);
		}
		System.out.println();
	}
}
