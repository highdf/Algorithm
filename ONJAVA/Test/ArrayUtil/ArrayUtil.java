package ArrayUtil;

public class ArrayUtil{
	private ArrayUtil() {
		;
	}

	public static String printArr(int[] arr) {
		StringBuilder sb = new StringBuilder();

		sb.append('[');
		for(int i = 0;i < arr.length;i ++) {
			if(i == (arr.length - 1)) {
				sb.append(arr[i]).append(']');
			} else {
				sb.append(arr[i]).append(',');
			}

		}

		return sb.toString();
	}

	public static double getSum(int[] arr) {
		int sum = 0;

		for(int i = 0;i < arr.length;i ++) {
			sum += arr[i];
		}

		return (sum * 1.0) / arr.length;
	}
}
