#include <iostream>
#include <queue>
using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };





//Liu, bfs, time exceed
/*class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(!root) return 0;
        int counter = 0;
        queue<TreeNode *> Q;
        Q.push(root);
        Q.push(NULL);
        while(Q.empty() == false) {
            TreeNode * tmp = Q.front();
            Q.pop();
            if(tmp != NULL) {
                if(!tmp -> left) Q.push(tmp -> left);
                if(!tmp -> right) Q.push(tmp -> right);
            } else {
                counter++;
                if(Q.empty() == false) Q.push(NULL);
            }
        }
        return counter;
    }
};*/

//Liu, dfs
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(!root) return 0;
        int maxLeft = maxDepth(root -> left);
        int maxRight = maxDepth(root -> right);
        if(maxLeft == 0) return ++maxRight;
        if(maxRight == 0) return ++maxLeft;
        return maxLeft > maxRight ? ++maxLeft : ++maxRight;
        //return max(maxLeft, maxRight) + 1;
    }
};


int main(){
     TreeNode *a = new TreeNode(0);
    //TreeNode *b = new TreeNode(0);
    a->left = new TreeNode(-5);
    //b->left = new TreeNode(-8);
    Solution sol;
    cout << sol.maxDepth(a) << endl;
	return 0;
}