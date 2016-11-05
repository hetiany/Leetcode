#include <queue>
#include <iostream>
#include <algorithm>
using namespace std; 


// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//top-bottom
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){return true;}       
       return abs(calheight(root->left) - calheight(root->right)) <= 1 
         	  && isBalanced(root->left) 
         	  && isBalanced(root->right);
    }
    int calheight(TreeNode* a){
    	if(a == NULL)  
        return 0;  
      int lmax = calheight(a->left);  
      int rmax = calheight(a->right);  
      return max(lmax, rmax)+1;
    }
};


//my code
//time: O(n), space: O(1)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        int left = calculate(root -> left);
        int right = calculate(root -> right);
        
        if( isBalanced(root->left) && isBalanced(root->right) && abs(left - right) <= 1 ){
            return true;
        }
        return false;
    }
    
    int calculate(TreeNode* node){
        if(node == NULL){
            return 0;
        }        
       int left = calculate(node -> left);
       int right = calculate(node -> right);      
       return max(left,right) + 1;
        
        
    }
};


 int main(){
    return 0;
}