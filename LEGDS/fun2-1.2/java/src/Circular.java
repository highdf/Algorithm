package src;

public class Circular {
	public static void leftShift(int[] arr,int count) {
		count = count % arr.length;

		if(count > 0) {
			int positionOf0 = arr.length - count;
			int remaining = ( arr.length - 1 ) - positionOf0;
			// System.out.printf("position_0 = %d,remaining = %d%n",position_0,remaining);

			int position = arr.length-1;
			for(int i = remaining;i >= 0;i -- ) {
				for(int j = i;j < position;j ++) {
					int temp = arr[j + 1];
					arr[j + 1] = arr[j];
					arr[j] = temp;
				}
				position --;
			}
		}
	}
}
