/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//my code
class Solution {
public:
       vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string temp;
        if(root == NULL){
            return result;
        }
        get_result(root, result, temp);
        return result;
    }
    
    void get_result(TreeNode* root, vector<string>& result, string temp){
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            string n = to_string(root -> val);
            temp = temp + n;
            result.push_back(temp);
            temp.pop_back();
            return;
        }
        
        string m = to_string(root -> val);
        //temp.push_back(m);
        temp = temp + m;
        get_result(root -> left, result, temp + "->");
        get_result(root -> right, result, temp + "->");
        temp.pop_back();

    }
};


//find online, better
class Solution {
public:

	vector<string> binaryTreePaths(TreeNode* root) {
	    vector<string> result;
	    if(!root) {
            return result;
        }

	    get_result(result, root, to_string(root->val));
	    return result;
	}

	void get_result(vector<string>& result, TreeNode* root, string t) {
	    if(!root->left && !root->right) {
	        result.push_back(t);
	        return;
	    }

	    if(root->left) {
            get_result(result, root->left, t + "->" + to_string(root->left->val));
        }
	    if(root->right) {
            get_result(result, root->right, t + "->" + to_string(root->right->val));
        }
	}

};


//my code, 4/30/2016
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string temp;
        get_result(root, result, temp);
        return result;
    }
    void get_result(TreeNode* root, vector<string>& result, string temp) {
        if(!root) {
            return;
        }
        if(!root -> left && !root -> right) {
            string m = to_string(root -> val);
            temp = temp + m;
            result.push_back(temp);
            //temp = temp - m;
            temp.pop_back();
            return;
        }
        string n = to_string(root -> val);
        temp = temp + n;
        get_result(root -> left, result, temp + "->");
        get_result(root -> right, result, temp + "->");
        //temp = temp - n;
        temp.pop_back();
    }
};