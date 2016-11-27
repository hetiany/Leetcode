#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

struct myClass {
	bool operator() (pair<int, int> p1, pair<int, int> p2) {
		if(p1.first < p2.first) {
			return true;		
		} else if(p1.first == p2.first) {
			if(p1.second <= p2.second) 
				return true;
			else
				return false;		
		} else 
			return false;
	}
} sortByFirst;

class Solution {
public:
	int get(vector< pair<int, int> > entities) {
		if(entities.size() == 0) {
			cout << 0 << endl;
			return 0;
		}
		std::sort(entities.begin(), entities.end(), sortByFirst);
		if(entities.size() == 0) {
			return 0;
		}
		int sum = 0;
		for(int i = 1; i < entities.size(); i++) {
			if(entities[i].first > entities[i - 1].first) {
				if(entities[i].second > entities[i - 1].second) {
					continue;
				}
				else 
					sum++;
			}
			else {
			// equals 
				sum++;		
			}
		}
		cout << "sum: " << sum << endl;
		return sum;
	}
};

int main() {
	/*pair<int, int> pair0 = make_pair(2,4);
	pair<int, int> pair1 = make_pair(4,1);
	pair<int, int> pair2 = make_pair(8,8);
	pair<int, int> pair3 = make_pair(3,5);*/

	pair<int, int> pair0 = make_pair(1,2);
	pair<int, int> pair1 = make_pair(2,1);
	


	/*pair<int, int> pair0 = make_pair(3,2);
	pair<int, int> pair1 = make_pair(8,7);
	pair<int, int> pair2 = make_pair(6,9);
	pair<int, int> pair3 = make_pair(3,4);
	pair<int, int> pair4 = make_pair(7,8);*/

	/*int N = 0;
	cin >> N;*/
	vector< pair<int, int> > input;
	/*for(int i = 0;i < N;i++) {
		int x = 0;
		int y = 0;
		cin >> x >> y;
		pair<int, int> entity = make_pair(x,y);
		input.push_back(entity);
	}	*/
	
	input.push_back(pair0);
	input.push_back(pair1);
	//input.push_back(pair2);
	//input.push_back(pair3);
	//input.push_back(pair4);
	
	Solution mySolution;
	mySolution.get(input);
	return 0;
}
