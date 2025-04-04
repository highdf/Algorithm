package src;

public class BinSearch{
	public static final int NO_FIND = -1;

	public static int  binSearch(int[] arr,int match) {
		int re = NO_FIND;
		int left = 0;
		int right = arr.length-1;

		while(left <= right){
			int middle = (left + right) / 2;

			if(arr[middle] > match) {
				right = middle - 1;
			} else if(arr[middle] < match) {
				left = middle + 1;
			} else {
				re = middle;
				break;
			}
		}

		return re;
	}	

	public static int binSearch(int[] arr,int start,int end,int match) {
		int re = -1;

		if(start <= end) {
			int middle = (start + end) / 2;

			if(arr[middle] == match) {
				re = middle;
			} else if(arr[middle] > match) {
				re = binSearch(arr,start,middle - 1,match);
			} else if(arr[middle] < match) {
				re = binSearch(arr,middle + 1,end,match);
			}
		} else {
			re = -1;
		}

		return re;
	}
}
