#include <iostream>
using namespace std;


 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//dfs
class Solution {
public:
    bool isSameTree(TreeNode * p, TreeNode * q) {
        if(p == NULL && q == NULL) return true;
        if(p && q) {
           if (p -> val == q -> val
               && isSameTree(p -> left, q -> left)
               && isSameTree(p -> right, q -> right))
               return true;
           else return false;
       } else return false;
   }
};


int main(){
	TreeNode *a = new TreeNode(0);
	TreeNode *b = new TreeNode(0);
	a->left = new TreeNode(-5);
	b->left = new TreeNode(-8);
	Solution sol;
	cout << sol.isSameTree(a,b) << endl;
	return 0;
}



