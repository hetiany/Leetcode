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

//dfs
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
  /*  	if(root == NULL){ return false;}
    	int calsum = root->val;
        //int sumleft = sumpath(root->left);
        //int sumrigh = sumpath(root->right);

    int sumpath(TreeNode* a){
    	int sum = 0;
    	int sumleft = sumpath(root->left);
        int sumrigh = sumpath(root->right);
    	if(a->left == NULL && a->right == NULL){
    		return sum = a -> val;
    	}
    }*/

        
    }
};



//dfs, Find online, similar to mine
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
    	return hasPathSum(root, 0, sum);      
       }  
       bool hasPathSum(TreeNode *root, int sum, int target) {  
            if(root == NULL) return false;  
            sum += root->val;  
            if(root->left == NULL && root->right == NULL) //leaf  
            {  
                 if(sum == target)  
                      return true;  
                 else  
                      return false;  
            }  
            return hasPathSum(root->left, sum, target)   
                   || hasPathSum(root->right, sum, target);           
    }
};


//Liu, Path Sum
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
       if (!root){
                return false;
            }
        if (!(root -> left) &&
            !(root -> right) &&
            root -> val == sum){
            return true;
        }
        if (root -> left &&
            hasPathSum(root -> left, sum - root -> val)){
            return true;
        }
        if (root -> right &&
            hasPathSum(root -> right, sum - root -> val)){
            return true;
        }
        return false;

        
    }
};


// My code
class Solution {
public:
    bool A = false, B = false;
    bool hasPathSum(TreeNode* root, int sum) {
       if (!root){
                return false;
            }
        if (!(root -> left) &&
            !(root -> right) &&
            root -> val == sum){
            return true;
        }
    
        if(root->left){
             A =  hasPathSum(root -> left, sum - root -> val);
        }
        if(root->right){
             B =  hasPathSum(root -> right, sum - root -> val);
        }
        
        if(A||B){
            return true;
        } else{
            return false;
        }
    }
};


//my code
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL){
            return false;
        }
        if(root -> val == sum && root -> left == NULL && root -> right == NULL){
            return true;
        }
       if( hasPathSum(root -> left, sum - (root->val)) ){
           return true;
       } 
       if( hasPathSum(root -> right, sum - (root->val)) ){
           return true;
       }
      
       return false;
        
    }
};


//My code, 04/27/2016
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) {
            return false;
        }       
        if (!(root -> left) &&
            !(root -> right) &&
            root -> val == sum){
            return true;
        }        
        int target = sum - root -> val;

        if(hasPathSum(root -> left, target) || hasPathSum(root -> right, target)) {
            return true;
        }
        return false;
    }
};

 int main(){

	return 0;
}