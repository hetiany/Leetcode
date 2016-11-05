//Find online, binary search, not understand ??
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
		int l = matrix[0][0], r = matrix[n - 1][n - 1];
		int mid = 0;
		while (l < r) {
			mid = (l + r) / 2;
			int num = 0;
			for (int i = 0; i < n; i++) {
				int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				num += pos;
			}
			if (num < k) {
				l = mid + 1;
			}
			else {
				r = mid;
			}
		}
		return l;
    }
};

//my code, using heap, 08/07/2016
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(!matrix.size()) {
            return 0;
        }
        int row = matrix.size();
        int total = row * row;
        priority_queue<int> store;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < row; ++j) {
                store.push(matrix[i][j]);
            }
        }
        for(int i = 0; i < total - k; ++i) {
            store.pop();
        }
        return store.top();
    }
};
