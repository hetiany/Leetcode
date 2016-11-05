#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };




//Minimum Depth of Binary Tree, dfs
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){return 0;}
        int leftmin = minDepth(root -> left);
        int rightmin = minDepth(root -> right);
        if(leftmin == 0){
        	return rightmin + 1;
        }
        if(rightmin == 0){
        	return leftmin + 1;
        }
        return min(leftmin,rightmin) + 1;
    }
};


//My code
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        int minleft = minDepth(root -> left);
        int minright = minDepth(root -> right);
        
        if(root -> left == NULL && root -> right != NULL) {
            return  ++minright;
        }
        
        if(root -> left != NULL && root -> right == NULL) {
            return  ++minleft;
        }
        
        return minleft < minright ?  ++minleft : ++minright;
        
    }
};


//my code, 08/22/2016
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int left = minDepth(root -> left);
        int right = minDepth(root -> right);
        if(root -> left && !root -> right) {
            return left + 1;
        }
        if(!root -> left && root -> right) {
            return right + 1;
        }
        return min(left, right) + 1;
    }
};


int main(){

	return 0;
}