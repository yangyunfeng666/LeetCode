
int upper_bound(vector<int> arr,int target) {
	int left = -1,right = arr.size() - 1;
	while (left < right) {
		int mid = (left + right + 1) >> 1; //如果是left = mid 补一个+1
		if (arr[mid] <= target) { //条件
		 left = mid; //范围
		} else {
		 right = mid - 1;
		}
	}
	return left;
}
