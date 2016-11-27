#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class sortentity {
public:
	bool operator() (pair<int, int> p1, pair<int, int> p2) {
		if(p1.first < p2.first) {
			return true;
		} else if(p1.first == p2.first) {
			if(p1.second <= p2.second) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	}
};


class Solution {
public:
	int nondominate(vector<pair<int, int> >& entities) {
		if(entities.size() == 0 || entities.size() == 1) {
			return entities.size();
		}
		std::sort(entities.begin(), entities.end(), sortentity());
		int x_max = 0;
		int y_max = 0;
		vector<bool> record(entities.size(), true);

		for(int i = entities.size() - 1; i >= 0; --i) {
			x_max = entities[i].first;
			y_max = entities[i].second;

			for(int j = i; j >= 0; --j) {
				if(record[j] && x_max > entities[j].first && y_max > entities[j].second) {
					record[j] = false;
					//cout << entities[j].first << " " << entities[j].second << endl;
				} else {
					continue;
				}
			}

		}
		int num = 0;
		for(auto a : record) {
			//cout << a << endl;
			if(a) {
				++num;
			}
		}
		return num;
	}
};


int main() {
/*	vector< pair<int, int> > input;
	pair<int, int> pair0 = make_pair(3,2);
	pair<int, int> pair1 = make_pair(8,7);
	pair<int, int> pair2 = make_pair(6,9);
	pair<int, int> pair3 = make_pair(3,4);
	pair<int, int> pair4 = make_pair(7,8);
	pair<int, int> pair5 = make_pair(3,2);

	input.push_back(pair0);
	input.push_back(pair1);
	input.push_back(pair2);
	input.push_back(pair3);
	input.push_back(pair4);*/

	int N = 0;
	cin >> N;
	vector< pair<int, int> > input;
	for(int i = 0;i < N;i++) {
		int x = 0;
		int y = 0;
		cin >> x >> y;
		pair<int, int> entity = make_pair(x,y);
		input.push_back(entity);
	}

	
	Solution mySolution;
	cout << mySolution.nondominate(input) << endl; 
	//mySolution.nondominate(input);
	return 0;
}
