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

//Binary Tree Preorder Traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> result;
        if (root == NULL)
        return result;
	    TreeNode* p = root;
	    stack<TreeNode*> s;
	    while (!s.empty() || p)
	    {
	        //边遍历边打印，并存入栈中，以后需要借助这些根节点(不要怀疑这种说法哦)进入右子树
	        while (p)
	        {
	            //cout << p->val << endl;
	            result.push_back(p->val);
	            s.push(p);
	            p = p->left;
	        }
	        //当p为空时，说明根和左子树都遍历完了，该进入右子树了
	        if (!s.empty())
	        {
	            p = s.top();
	            s.pop();
	            p = p->right;
	        }
	    }
	    return result;
    }
};

//my code
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> store;
        TreeNode* temp;
        if(root == NULL){
            return result;
        }
        temp = root;
        while( store.size() != 0 || temp != NULL){
            while(temp != NULL){
                result.push_back(temp -> val);
                store.push(temp);
                temp = temp -> left;
            }
            if(store.size() != 0){
                temp = store.top();
                store.pop();
              
                temp = temp -> right;
            }
            
        }        
        return result;        
    }
};

//my code
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) {
            return result;
        }
        stack<TreeNode*> store;
        TreeNode* temp;
        store.push(root);
        result.push_back(root -> val);
        temp = root -> left;
        while(store.size() != 0 || temp != NULL) {
            while(temp != NULL) {
                store.push(temp);
                result.push_back(temp -> val);
                temp = temp -> left;
            }
            if(store.size() != 0) {
                temp = store.top();
                store.pop();
                //result.push_back(temp -> val);
                temp = temp -> right;
            }
        }
        return result;
    }
};


//my code, 05/13/2016
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root) {
            return result;
        }
        stack<TreeNode*> store;
        TreeNode* temp = root;
        while(temp || !store.empty()) {
            while(temp) {
                result.push_back(temp -> val);
                store.push(temp);
                temp = temp -> left;
            }
            temp = store.top();
            store.pop();
            temp = temp -> right;
        }
        return result;
    }
};


//my code, using recursive, 05/13/2016
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        get_result(root, result);
        return result;
    }
    void  get_result(TreeNode* root, vector<int>& result) {
        if(!root) {
            return ;
        }
        result.push_back(root -> val);
        get_result(root -> left, result);
        get_result(root -> right, result);
    }
};



 int main(){

	return 0;
}