void insertSort(int nums[], int n) {
	if (n < 1) return;
	for (int i = 1; i < n; ++i) {
		int temp = nums[i];
		int j = i - 1;
		while (j >= 0 && temp < nums[j]) { /////j > 0 ;
			nums[j + 1] = nums[j];
			--j;  // -- j;
		}	
		nums[j + 1] = temp;
	} 
	return;
}