#include <iostream>
using namespace std;


 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

//Liu, dfs
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isLeftMirrorToRight(root -> left, root -> right);
    }
    bool isLeftMirrorToRight(TreeNode * left, TreeNode * right){
        if(left == NULL && right == NULL) return true;
        if(left && right){
            return left -> val == right -> val
            && isLeftMirrorToRight(left -> left, right -> right)
            && isLeftMirrorToRight(left -> right, right -> left);
        } 
        if (left || right) return false;
    }
};


//My code
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isLeftMirrorToRight(root -> left, root -> right);
    }
    
    bool isLeftMirrorToRight(TreeNode * left, TreeNode * right){
        if(left == NULL && right == NULL) return true;
        if(left && right){
            if(left -> val == right -> val
            && isLeftMirrorToRight(left -> left, right -> right)
            && isLeftMirrorToRight(left -> right, right -> left)){
                return true;
            } else{
                return false;
            }           
        } else{
            return false;
        }        
    }
};


int main(){
	return 0;
}