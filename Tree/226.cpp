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

//Invert Binary Tree
 //Find online, dfs
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    	if(root == NULL){return NULL;}
    	if(root){
    	root -> left = invertTree(root->left);
        root -> right = invertTree(root->right);
        swap(root->left, root->right);
    	}

    	return root;
        
    }
};


//my code, dfs
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){return NULL;}
        root -> left = invertTree(root->left);
        root -> right = invertTree(root->right);
        if(root->left || root->right){
            swap(root->left, root->right); 
        }
        return root;
        
    }
};


//my code
//time: O(n),  space: o(1)
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }       
        TreeNode* left = invertTree(root -> left);
        TreeNode* right = invertTree(root -> right);        
        root -> right = left;
        root -> left  = right;
        return root;        
    }
};



//Find online, dfs
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    if(root == NULL){return NULL;}

    //stack<TreeNode*> stk;
    queue<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
        TreeNode* p = stk.front();
        stk.pop();
        if (p) {
            stk.push(p->left);
            stk.push(p->right);
            swap(p->left, p->right);
        }
    }
    return root;
        
    }
};


//my code, 04/28/2016
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) {
            return NULL;
        }
        swap(root -> left, root -> right);
        invertTree(root -> left);
        invertTree(root -> right);
        return root;
    }
};

int main(){

	return 0;
}