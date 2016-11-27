#include <iostream>
#include <vector>
using namespace std;

class Container {
	public:
	 double first;
	 double second;
};

Container findOptimalWeights( double capacity, vector<double> weights) {
	Container res;//////////////
	int len = weights.size();
	sort(weights.begin(), weights.end());
	int left = 0, right = len - 1;
	double minDiff = capacity + 1;
	while (left < right) {
		double sum = weights[left] + weights[right];
		if (sum == capacity) {
			res.first = weights[left];
			res.second = weights[right];
			return res;
		} else if (sum < capacity) {
			if (minDiff > capacity - sum) {
				minDiff = capacity - sum;
				res.first = weights[left];
				res.second = weights[right];
			}
			++left;
		} else {
			--right;
		}
	}
	return res;
}
int main(int argc, char const *argv[])
{
	    double capacity = 27.3;
		vector<double> weights = {1.6, 2.9, 4.5, 6.5, 7.9, 8.3, 9.4, 10.1, 
				           15.2, 16.7, 18.9, 19.01, 19.7, 21.6, 15.4, 17.9};
		Container c = findOptimalWeights(capacity, weights);
		cout << "first is:" << c.first << " second is : " << c.second <<endl;
	return 0;
}