#include <iostream>
#include <stack>
#include <vector>
using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//Find online, Binary Tree Postorder Traversal
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    	vector<int> result;
        if (root == NULL) {
        	return result;	
        }  
	    TreeNode* p = root;
	    stack<TreeNode*> s;
	    //pCur:当前访问节点，pLastVisit:上次访问节点
	    TreeNode* pCur, *pLastVisit;
	    //pCur = root;
	    pCur = root;
	    pLastVisit = NULL;
	    //先把pCur移动到左子树最下边
	    while (pCur) {
	        s.push(pCur);
	        pCur = pCur -> left;
	    }
	    while (!s.empty()) {
	        //走到这里，pCur都是空，并已经遍历到左子树底端(看成扩充二叉树，则空，亦是某棵树的左孩子)
	        pCur = s.top();
	        s.pop();
	        //一个根节点被访问的前提是：无右子树或右子树已被访问过
	        if (pCur -> right == NULL || pCur -> right == pLastVisit) {
	            //cout << pCur->val << endl;
	            result.push_back(pCur -> val);
	            //修改最近被访问的节点
	            pLastVisit = pCur;
	        }
	        /*这里的else语句可换成带条件的else if:
	        else if (pCur->lchild == pLastVisit)//若左子树刚被访问过，则需先进入右子树(根节点需再次入栈)
	        因为：上面的条件没通过就一定是下面的条件满足。仔细想想！*/
	        
	        else {
	            //根节点再次入栈
	            s.push(pCur);
	            //进入右子树，且可肯定右子树一定不为空
	            pCur = pCur -> right;
	            while (pCur) {
	                s.push(pCur);
	                pCur = pCur -> left;
	            }
	        }
	    }
	    return result;
    }
};



//Find online, better
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        vector<int> result;
        //base case
        if(root == NULL) {
        	return result;
        }        
        nodeStack.push(root);
	    while(!nodeStack.empty())  {
	        TreeNode* node= nodeStack.top();  
	        result.push_back(node->val);
	        nodeStack.pop();
	        if(node->left) {
	        	nodeStack.push(node->left);
	        }
	        
	        if(node->right) {
	        	nodeStack.push(node->right);
	        }	        
	    }
	     reverse(result.begin(),result.end());
	     return result;
    }
};


//Find online
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    	vector<int> v;
	    if (!root) {
	    	return v;
	    }
	    stack<TreeNode *> s;
	    s.push(root);
	    TreeNode *p = NULL;
	    while(!s.empty()) {
	        p = s.top();
	        s.pop();
	        v.insert(v.begin(), p -> val);
	        if (p -> left) {
	        	s.push(p -> left);
	        }
	        if (p -> right) {
	        	s.push(p -> right);
	        }
	    }
	    return v;
    }
};




//my code, 05/21/2016
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) {
            return result;
        }
        stack<TreeNode*> store;
        TreeNode* temp = root;
        while(temp || !store.empty()) {
            while(temp) {
                store.push(temp);
                result.push_back(temp -> val);
                temp = temp -> right;
            }
            temp = store.top();
            store.pop();
            temp = temp -> left;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

 int main(){

	return 0;
}
