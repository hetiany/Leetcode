#include <iostream>
using namespace std;


 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
//Liu 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
    	if(p == NULL && q == NULL) return true;
        if(p && q) {
           if ( p -> val == q -> val 
           	    && isSameTree(p -> left, q -> left) 
           	    && isSameTree(p -> right, q -> right)){
           		//cout << "haha" << endl;
           		return true;
           }
              //return true;
           else return false;
       } 
       else return false; // if(p || q){return false;}
        
    }
};

//Find online, dfs
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if(!p && !q) return true;  // if(p == NULL && q == NULL){return true;}
      if(!p || !q) return false;  
      return (p->val == q->val) &&  
           isSameTree(p->left, q->left) &&   
           isSameTree(p->right, q->right);      
        
    }
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
   	  if(p == NULL && q == NULL) return true;  
      if(p && q) { 
      return (p->val == q->val) &&  
           isSameTree(p->left, q->left) &&   
           isSameTree(p->right, q->right); 
      }
      if(p || q){return false;}
    }
};

//my code, 4/26/2016
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) {
            return true;
        }
        if(p && q) {
            if(p -> val == q -> val && isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right)) {
                return true;
            }  else {
                return false;
            }
        }
        return false;
    }
};


int main(){
	/*int aa = 2;
	int bb = 0;
	if(bb && (aa = 3)){

	}
	cout << aa << endl;*/

	TreeNode *a = new TreeNode(0);
	TreeNode *b = new TreeNode(0);
	a->left = new TreeNode(-5);
	b->left = new TreeNode(-8);
	Solution sol;
	cout << sol.isSameTree(a,b) << endl;

	return 0;
}