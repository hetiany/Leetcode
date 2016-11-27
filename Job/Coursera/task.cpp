// This is the text editor interface. 
// Anything you type or change here will be seen by the other person in real time.
#include <iostream>
#include <vector>
//#include <queue>
#include <unordered_set>
using namespace std;

//1 2 3     a
//2 1 2     b

//1 2 3     a
//2 1 1     b

//1 3   a
//2 1   b

class Solution {
public:
    int taskMaster(int n, vector<int>& a, vector<int>& b) {
    	if(!a.size() || !b.size()) {
    		return n;
    	}
        unordered_set<int> complete;
        unordered_set<int> uncomplete;
        //int res = 0;
        for (int i = 0; i < n; i++) {
            if (uncomplete.find(b[i]) != uncomplete.end()) {
                uncomplete.insert(a[i]);
                continue;
            }
            if (complete.find(b[i]) != complete.end()) {
                continue;
            }
            if (complete.find(a[i]) != complete.end()) {
                uncomplete.insert(b[i]);
            } else {
                complete.insert(b[i]);
            }
        }
        return n - uncomplete.size();
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...https:
    //codepair.hackerrank.com/paper/hfqqapxbouopkservyxrsnesktiarqdq?b=eyJpbnRlcnZpZXdfaWQiOjI0MDM2Nywicm9sZSI6ImludGVydmlld2VyIiwic2hvcnRfdXJsIjoiaHR0cDovL2hyLmdzL2Y0ZjdmYSJ9#
    //std::cout << "Hello, World!\n";
    //vector<int> a = {1,2,3};
    //vector<int> b = {2,1,2};
    vector<int> a;
    vector<int> b;
    int task_num = 0;
    cin >> task_num;
    int dependents = 0;
    cin >> dependents;

    for(int i = 0; i < dependents; ++i) {
    	int x = 0;
    	cin >> x;
    	a.push_back(x);
    }

    for(int i = 0; i < dependents; ++i) {
    	int x = 0;
    	cin >> x;
    	b.push_back(x);
    }

    Solution s;
    cout<< s.taskMaster(task_num, a, b)<<endl;
    return 0;
}


//Topological sorting
/*#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> taskMaster(int n, vector<int>& a, vector<int>& b) {
        vector<int> res;
        vector<vector<int>> dict(n);
        vector<int> prev(n, 0);
        for (int i = 0; i < a.size(); i++) {
            dict[b[i]].push_back(a[i]);
            prev[a[i]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (prev[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int task = q.front();
            q.pop();
            res.push_back(task);
            for (int t : dict[task]) {
                if (--prev[t] == 0) {
                    q.push(t);
                }
            }
        }
        
        
        return res;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> a = {0,1};
    vector<int> b = {1,2};
    Solution s;
    vector<int> res = s.taskMaster(3, a, b);
    for (int i : res) {
        cout<<i<<endl;
    }
    return 0;
}*/