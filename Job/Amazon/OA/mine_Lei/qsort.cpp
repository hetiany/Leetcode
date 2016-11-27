void Qsort(int * arr, int low, int high) {
	int mid, pivot, i, j;
	if (low < high) {
		// mid = low + ( high - low ) / 2;
		// swap (arr[mid], arr[low]); 
		// pivot = arr[low];
		i = low + 1;
		j = right;
		while (i <= j) {
			while (i <= j && arr[i] <= key) ++i;
			while (i <= j && arr[i] >= key) --j;
			if (i < j) {
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[j], pivot);
		Qsort(arr, low, j - 1);
		Qsort(arr, j + 1, high);
	}
}
