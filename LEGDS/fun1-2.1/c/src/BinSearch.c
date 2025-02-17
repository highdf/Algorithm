int BinSearch(int *arr,int length,int match) {
	int re = -1;
	int left = 0,right = length - 1;

	while(left <= right) {
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

	if(left > right) {
		re = left;
	}

	return re;
}
int BinSearch0(int *arr,int left,int right,int match) {
	int re = -1;

	if(left <= right) {
		int middle = (left + right) / 2;
		if(arr[middle] < match) {
			re = BinSearch0(arr, middle + 1, right, match);
		} else if(arr[middle] > match) {
			re = BinSearch0(arr, left, middle - 1, match);
		} else {
			re = middle;
		}
	} else {
		re = -1;
	}

	return re;
}
