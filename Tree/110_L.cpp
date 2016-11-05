#include <queue>
#include <iostream>
using namespace std; 


// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


//bottom-up
 class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return height(root) != -1;
    }
    int height(TreeNode * root) {
        if(root == NULL) return 0;
        int leftHeight = height(root -> left);
        if(leftHeight == -1) return -1;
        int rightHeight = height(root -> right);
        if(rightHeight == -1) return -1;
        return abs(leftHeight - rightHeight) <= 1 ?
        max(leftHeight, rightHeight) + 1 : -1;
    }
};

//top-bottom
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(root == NULL) return true;
        return abs(height(root -> left) - height(root -> right)) <= 1
        && isBalanced(root -> left)
        && isBalanced(root -> right);
    }
    int height(TreeNode * root) {
        if(root == NULL) return 0;
        return max(height(root -> left), height(root -> right)) + 1;
    }
};


 int main(){
    return 0;
}