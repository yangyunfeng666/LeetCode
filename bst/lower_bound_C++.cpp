

int lower_bound(vector<int> array,int target) {
 	int left = 0,right = array.size();
	while (left < right) {
		int mid = (left + right) >> 1;
		if (array[mid] >= target) {
			right = mid;	
		} else {
		        left = mid + 1;
		}
	}
	return right;
}




