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

//Binary Tree Inorder Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> result;
        if (root == NULL)
        return result;
	    TreeNode* p = root;	    
	    stack<TreeNode*> s;
	    while (!s.empty() || p)
	    {
	        //一直遍历到左子树最下边，边遍历边保存根节点到栈中
	        while (p)
	        {
	            s.push(p);
	            p = p->left;
	        }
	        //当p为空时，说明已经到达左子树最下边，这时需要出栈了
	        if (!s.empty())
	        {
	            p = s.top();
	            s.pop();
	            //cout << p->val << endl;
	            result.push_back(p->val);
	            //进入右子树，开始新的一轮左子树遍历(这是递归的自我实现)
	            p = p->right;
	        }
	    }
	    return result;
    }
};


//my code
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> store;
        TreeNode* temp;
        if(root == NULL){
            return result;
        }
        temp = root;
        while( store.size() != 0 || temp != NULL){
            while(temp != NULL){
                store.push(temp);
                temp = temp -> left;
            }
            if(store.size() != 0){
                temp = store.top();
                store.pop();
                result.push_back(temp -> val);
                temp = temp -> right;
            }
            
        }
        
        return result;
    }
};


//my code
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) {
            return result;
        }
        stack<TreeNode*> store;
        TreeNode* temp;
        store.push(root);
        temp = root -> left;
        while(store.size() != 0 || temp != NULL) {
            while(temp != NULL) {
                store.push(temp);
                temp = temp -> left;
            }
            if(store.size() != 0) {
                temp = store.top();
                store.pop();
                result.push_back(temp -> val);
                temp = temp -> right;
            }
        }
        return result;
    }
};


//my code, 05/13/2016
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) {
            return result;
        }
        stack<TreeNode*> store;
        TreeNode* temp = root;
        while(temp || !store.empty()) {
            while(temp) {
                store.push(temp);
                temp = temp -> left;
            }
            temp = store.top();
            store.pop();
            result.push_back(temp -> val);
            temp = temp -> right;
        }
        return result;
    }
};


//my code, 05/16/2016
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<int> temp_result;
        if(!root) {
            return result;
        }
        stack<TreeNode*> store;
        TreeNode* temp = root;
        TreeNode* cur = root;
        while(temp) {
            while(cur) {
                store.push(cur);
                cur = cur -> left;
            }
            if(!store.empty()) {
                temp = store.top();
                store.pop();
                result.push_back(temp -> val);
                if(temp -> right) {
                    temp = temp -> right;
                    cur = temp;
                } else {
                    cur = NULL;
                }
            }
            if(cur == NULL && store.empty()) {
                return result;
            }
        }
        return temp_result;
    }
};


int main(){

	return 0;
}