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


//Flatten Binary Tree to Linked List
//Find online
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* now = root;
        while(now)
        {
            if(now->left)
            {
                //Find current node's prenode that links to current node's right subtree
                TreeNode* pre = now -> left;
                while(pre->right)
                {
                    pre = pre->right;
                }
                pre->right = now->right;
                //Use current node's left subtree to replace its right subtree(original right 
                //subtree is already linked by current node's prenode
                now->right = now->left;
                now->left = NULL;
            }
            now = now->right;
        }
    }
};


//Find online, DFS, can't understand
class Solution {
     void flatten(TreeNode *root) {  
       // Start typing your C/C++ solution below  
       // DO NOT write int main() function  
       if(root == NULL) {
           return;
       }   
       ConvertToLink(root);  
  }  

  TreeNode* ConvertToLink(TreeNode* node) {  
       if(node -> left == NULL && node -> right == NULL) {
           return node;
       } 
             

       TreeNode* rHead = NULL;  

       if(node -> right != NULL) {
           rHead = ConvertToLink(node -> right);   
       } 
                                  
       TreeNode* p = node;  

       if(node -> left != NULL) {  
            TreeNode* lHead = ConvertToLink(node -> left);   
            node -> right = lHead;  
            lHead -> left = NULL;  
            node -> left = NULL;  
            while(p -> right != NULL) {
                p = p -> right; 
            }                  
       }       

       if(rHead != NULL) {  
            p -> right = rHead;  
            rHead -> left = NULL;  
       }

       return node;  
  }

};



//my code, similar to Find online
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) {
            return;
        }   
        TreeNode* cur = root;
        TreeNode* pre;
        while(cur) {
            if(cur -> left != NULL) {
                 pre = cur -> left;
                 while(pre -> right) {
                    pre = pre -> right;
                 }
                    pre -> right = cur -> right;
                    cur -> right = cur -> left;
                    cur -> left = NULL;
            }
           
            cur = cur -> right;
        }  
    }
};



//my code, 05/09/2016
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) {
            return;
        }
        while(root) {
            if(root -> left) {
                TreeNode* pre = root -> left;
                while(pre -> right) {
                    pre = pre -> right;
                }
                pre -> right = root -> right;
                root -> right = root -> left;
                root -> left = NULL;
            }
            root = root -> right;
        }
    }
};



int main(){
	return 0;
}