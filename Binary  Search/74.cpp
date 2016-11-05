#include <iostream>
#include <vector>
using namespace std;
//Search a 2D Matrix
//last position <= target

//my code, 06/07/2016
//twice binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if(matrix.empty()) {
            return false;
        }    
        int row = matrix.size(), col = matrix[0].size();

        cout << row << endl;

        int begin = 0, end = row - 1, mid;
        while(begin + 1 < end) {
            mid = begin + (end - begin) / 2;
            if(matrix[mid][0] == target) {
                return true;
            } else if(matrix[mid][0] < target) {
                begin = mid;
            } else {
                end = mid;
            }
        } 

        if(matrix[end][0] <= target) {
            row = end;
        } else if(matrix[begin][0] <= target) {
            row = begin;
        } else {
            return false;
        }
        
        cout << row << endl;
        begin = 0, end = col - 1;
        while(begin + 1 < end) {
            mid = begin + (end - begin) / 2;
            if(matrix[row][mid] == target) {
                return true;
            } else if(matrix[row][mid] < target) {
                begin = mid;
            } else {
                end = mid;
            }
        } 
        
        if(matrix[row][begin] == target) {
            return true;    
        } else if(matrix[row][end] == target) {
            return true;
        } else {
            return false;
        }
        
    }
};

//my code, one time binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) {
            return false;
        }
        int row = matrix.size(), col = matrix[0].size();
        int begin = 0, end = row * col - 1, mid;
        while(begin + 1 < end) {
            mid = begin + (end - begin) / 2;
            if(matrix[mid / col][mid % col] == target) {
                return true;
            } else if(matrix[mid / col][mid % col] < target) {
                begin = mid;
            } else {
                end = mid;
            }
        }
        
        if(matrix[begin / col][begin % col] == target) {
            return true;
        } else if(matrix[end / col][end % col] == target) {
            return true;
        } else {
            return false;
        }
    }
};



int main() {
	Solution sol;
	vector<vector<int> > outer;

	vector<int> inner1;
	vector<int> inner2;

	inner1.push_back(1);
	inner2.push_back(3);

	outer.push_back(inner1);
	outer.push_back(inner2);
	cout << sol.searchMatrix(outer, 3) << endl;

	return 0;
}