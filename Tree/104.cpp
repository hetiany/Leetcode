#include <iostream>
using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

/*class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){ return 0; }
        int maxdepth = 0;
        if( root->left || root -> right){
        	++maxdepth;
        }
    }
};*/

//Find online, dfs, better than Liu
class Solution {
public:
   int maxDepth(TreeNode* root) {
   if(root == NULL)  
        return 0;  
      int lmax = maxDepth(root->left);  
      int rmax = maxDepth(root->right);  
      return max(lmax, rmax)+1;
    }
};


int main(){
	/*int a = 0,b = 0;
    cout << max(a,b)+1 << endl;
    cout << a << b << endl;*/


    TreeNode *a = new TreeNode(0);
	//TreeNode *b = new TreeNode(0);
	a->left = new TreeNode(-5);
	//b->left = new TreeNode(-8);
	Solution sol;
	cout << sol.maxDepth(a) << endl;
	return 0;
}