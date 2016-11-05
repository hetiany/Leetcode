#include <vector>
#include <algorithm>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//Lowest Common Ancestor of a Binary Search Tree
//Find online
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (p -> val < root -> val && q -> val < root -> val)
            return lowestCommonAncestor(root -> left, p, q);
        if (p -> val > root -> val && q -> val > root -> val)
            return lowestCommonAncestor(root -> right, p, q);
        return root; 
    }
};

//Find online
class Solution { 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (true) {
            if (p -> val < cur -> val && q -> val < cur -> val)
                cur = cur -> left;
            else if (p -> val > cur -> val && q -> val > cur -> val)
                cur = cur -> right;
            else return cur; 
        }
    }
};


//my code
//time: O(logN)  space: O(1) 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == NULL || q == NULL){
            return NULL;
        }
        if( p->val <= root -> val && root -> val <= q -> val ){
            return root;
        }
         if( q->val <= root -> val && root -> val <= p -> val ){
            return root;
        }
        if( root -> val <= p -> val && root -> val < q -> val){
            return lowestCommonAncestor(root -> right, p, q);
        }
        
        if(root -> val >= q -> val && root -> val > p -> val){
            return lowestCommonAncestor(root -> left, p, q);
        }
        return root;
    }
};



//my code, 04/28/2016
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return NULL;
        }
        if(p -> val <= root -> val && root -> val <= q -> val) {
            return root;
        }
         if(q -> val <= root -> val && root -> val <= p -> val) {
            return root;
        }
        if(root -> val < p -> val && root -> val < q -> val) {
           return lowestCommonAncestor(root -> right, p, q);
        }
         if(root -> val > p -> val && root -> val > q -> val) {
           return lowestCommonAncestor(root -> left, p, q);
        }
        //this sentence don't run
        return root;
    }
};

//my code, 08/24/2016
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return NULL;
        }    
        if(root -> val < p -> val && root -> val < q -> val) {
            return lowestCommonAncestor(root -> right, p , q);
        }
        if(root -> val > p -> val && root -> val > q -> val) {
            return lowestCommonAncestor(root -> left, p, q);
        }
        return root;
    }
};


int main(){

	return 0;
}