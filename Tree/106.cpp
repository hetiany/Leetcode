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

//Construct Binary Tree from Inorder and Postorder Traversal
//Find online, important
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      if(inorder.size() == 0 || postorder.size() == 0)return NULL;
        TreeNode *p;
        TreeNode *root;
        stack<TreeNode *> stn;

        root = new TreeNode(postorder.back()); 
        stn.push(root); 
        postorder.pop_back(); 

        while(true)
        {
            if(inorder.back() == stn.top()->val) 
            {
                p = stn.top();
                stn.pop(); 
                inorder.pop_back(); 
                if(inorder.size() == 0) {
                    break;
                }
                if(stn.size() != 0 && inorder.back() == stn.top()->val){
                    continue;
                }
                p->left = new TreeNode(postorder.back()); 
                postorder.pop_back();
                stn.push(p->left);
            }
            else 
            {
                p = new TreeNode(postorder.back());
                postorder.pop_back();
                stn.top()->right = p; 
                stn.push(p); 
            }
        }
        return root;
    }
};


//my code, similar to preorder and inorder
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) {
            return NULL;
        }
        stack<TreeNode*> store;
        int post_num = postorder.size();
        int in_num = inorder.size();
        post_num = post_num - 1;
        in_num = in_num - 1;
        TreeNode* root = new TreeNode(postorder[post_num]);
        TreeNode* temp = root;
        store.push(temp);
        bool flag = false;
        while(post_num > 0) {
            if(store.size() != 0 && store.top() -> val == inorder[in_num] ) {
                temp = store.top();
                store.pop();
                --in_num;
                flag = true;
                continue;
            }
            if(flag == false) {
                --post_num;
                temp -> right = new TreeNode(postorder[post_num]);
                temp = temp -> right;
                store.push(temp);
            }else {
                flag = false;
                --post_num;
                temp -> left = new TreeNode(postorder[post_num]);
                temp = temp -> left;
                store.push(temp);
            }
        }
        return root;
    }
};


 int main(){
	return 0;
}