#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


//my code, BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
    	if(root == NULL) {
    		return result;
    	}
    	queue<TreeNode*> store;
    	store.push(root);
    	TreeNode* temp;
    	int cur_count = 1;
    	int next_count = 0;
    	while(store.size() != 0) {
    	    while(cur_count != 0) {
    	        temp = store.front();
    	        store.pop();
    	        --cur_count;
    	        if(temp -> left) {
    	            store.push(temp -> left);
    	            ++next_count;
    	        }
    	        if(temp -> right) {
    	            store.push(temp -> right);
    	            ++next_count;
    	        }
    	        if(cur_count == 0) {
    	            result.push_back(temp -> val);
    	        }
    	    }
    	    cur_count = next_count;
    	    next_count = 0;
    	}
    }
};


//Find online, DFS, Better method
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
     void recursion(TreeNode *root, int level, vector<int> &res) {
        if(root == NULL) {
            return ;
        }
        if(res.size() < level) {
            res.push_back(root -> val);
        }
        recursion(root -> right, level + 1, res);
        recursion(root -> left, level + 1, res);
    }
};

int main() {
	return 0;
}