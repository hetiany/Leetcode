#include <iostream>
#include <vector>
using namespace std;

class Container {
	public:
	 double first;
	 double second;
};
void Qsort(double * arr, int low, int high) {
	int mid, i, j;
	double pivot;
	if (low < high) {
		// mid = low + ( high - low ) / 2;
		// swap (arr[mid], arr[low]); 
		pivot = arr[low];
		i = low + 1;
		j = high;
		while (i <= j) {
			while (i <= j && arr[i] <= pivot) ++i;
			while (i <= j && arr[j] >= pivot) --j;
			if (i <= j) {
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[j], arr[low]);
		Qsort(arr, low, j - 1);
		Qsort(arr, j + 1, high);
	}
}
bool compare(const double a, const  double b){
	return a < b;
}

Container findOptimalWeights( double capacity, double* weights, int n) {
		Container res;
		if (capacity == 0 || n <= 0) 
			return res;
		//Qsort(weights, 0, n - 1);
		sort(weights, weights + n, compare);
		// for (int i = 0; i < n ; ++i)
			// cout<<weights[i]<< " ";
		double minDiff = capacity + 1;
		int left = 0, right = n - 1;
		while (left < right) {
			double sum = weights[left] + weights[right];
			if (sum == capacity) {
				res.first = weights[left];
				res.second = weights[right];
				return res;
			} else if (sum < capacity) {
				if (capacity - sum < minDiff) {
					minDiff = capacity - sum;
					res.first = weights[left];
					res.second = weights[right];
				}
				++left;
			} else {
				-- right;
			}
		}
		return res;
	}

	int main(int argc, char const *argv[])
{
	    double capacity = 27.3;
		// vector<double> weights = {1.6, 2.9, 4.5, 6.5, 7.9, 8.3, 9.4, 10.1, 
		// 		           15.2, 16.7, 18.9, 19.01, 19.7, 21.6, 15.4, 17.9};
		double weights[16] = {1.6, 2.9, 4.5, 6.5, 7.9, 8.3, 9.4, 10.1, 15.2, 16.7, 18.9, 19.01, 19.7, 21.6, 15.4, 17.9};
		Container c = findOptimalWeights(capacity, weights, 16);
		cout << "first is:" << c.first << " second is : " << c.second <<endl;
	return 0;
}













