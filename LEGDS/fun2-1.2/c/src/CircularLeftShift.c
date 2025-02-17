#include "CircularLeftShift_in.h"
#include "CircularLeftShift_out.h"

void CircularLeftShift(int *arr,int length,int count) {
	count = count % length;

	if(count > 0) {
		int positionOf0 = length - count;
		int remaining = (length - 1) - positionOf0;
		// printf("positionOf0 = %d,remaining = %d\n",positionOf0,remaining);

		int position = (length - 1);
		for(int i = remaining;i >= 0; i --) {
			for(int j = i;j < position;j ++) {
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
			position --;
		}
	}
}
