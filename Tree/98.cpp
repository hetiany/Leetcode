#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


//Validate Binary Search Tree
// my code, error 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
    	if(!root){
    		return true;
    	}

    	if(root->left){
    		return root->left->val < root->val && isValidBST(root->left);
    	}

    	if(root->right){
    		return root->right->val > root->val && isValidBST(root->right);
    	}

    	if(root->left == NULL && root->right == NULL){
    		return true;
    	}

        
    }
};
 

//Find online, better
class Solution {
public:
    bool isValidBST(TreeNode* root) {
         return isValidBST(root, NULL, NULL);
}

bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if(!root) return true;
    if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
        return false;
    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};


//Find online
class Solution {
public:
     bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};



//my code, changed depend on code above, error
class Solution {
public:
    bool isValidBST(TreeNode* root) {
         return isValidBST(root, NULL, NULL);
}

bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if(!root) return true;
    if(minNode && root->val > minNode->val && maxNode && root->val < maxNode->val)
      return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);

    if(minNode && root->val > minNode->val && maxNode == NULL)
      return isValidBST(root->left, minNode, root);

  	if(minNode == NULL && maxNode && root->val < maxNode->val)
      return isValidBST(root->right, root, maxNode);

	if(!minNode && !maxNode){
		return true;
	}
    return false;


    //return true;
    }
};

//my code, error
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        if(root -> left == NULL && root -> right == NULL) {
            return true;
        }
        if(root -> left != NULL && root -> right == NULL) {
            return isValidBST(root -> left) && (root -> left -> val < root -> val);
        }
        if(root -> left == NULL && root -> right != NULL) {
            return isValidBST(root -> right) && (root -> val < root -> right -> val);
        }
        return isValidBST(root -> left) && isValidBST(root -> right) && (root -> left -> val < root -> val < root -> right -> val);
    }
};


//Liu
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return validateBST(root, LONG_MIN, LONG_MAX);
    }
private:
    bool validateBST(TreeNode * root, long min, long max){
        if(root == NULL) return true;
        if(root -> val < max && root -> val > min)
            return validateBST(root -> left, min, root -> val)
                && validateBST(root -> right, root -> val, max);
        return false;
    }
};


//my code, changed depend on Liu
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return getValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool getValidBST(TreeNode* root, long min, long max) {
        if(root == NULL) {
            return true;
        }
        if(root -> val > min && root -> val < max) {
            return getValidBST(root -> left, min, root -> val) && getValidBST(root -> right, root -> val , max);
        }
        return false;
    }
};


 int main(){
 	return 0;
 }