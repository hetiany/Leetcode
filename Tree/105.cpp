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

 
 //Construct Binary Tree from Preorder and Inorder Traversal
 //Find online 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         if(preorder.size() == 0 || inorder.size() == 0)
            return NULL;

        //stack<int> s;
        stack<TreeNode *> st;
        TreeNode *t, *root;
        int i,j,f;

        f = i = j = 0;
        //s.push(preorder[i]);

        root = new TreeNode(preorder[i]);
        st.push(root);
        t = root;
        i++;

        while(i < preorder.size())
        {
            if(!st.empty() && st.top()->val == inorder[j])
            {
                t = st.top();
                st.pop();
                //s.pop();
                f = 1;
                j++;
            }
            else
            {
                if(f == 0)
                {
                    //s.push(preorder[i]);
                    t -> left = new TreeNode(preorder[i]);
                    t = t -> left;
                    st.push(t);
                    i++;
                }
                else 
                {
                    f = 0;
                    //s.push(preorder[i]);
                    t -> right = new TreeNode(preorder[i]);
                    t = t -> right;
                    st.push(t);
                    i++;
                }
            }
        }

        return root;
    }
};


//Find online, recursive
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

TreeNode* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
    if(ps > pe){
        return nullptr;
    }
    TreeNode* node = new TreeNode(preorder[ps]);
    int pos;
    for(int i = is; i <= ie; i++){
        if(inorder[i] == node->val){
            pos = i;
            break;
        }
    }
    node->left = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
    node->right = create(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);
    return node;
 }
 
};

//my code
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0) {
            return NULL;
        }
        int pre = 0;
        int middle = 0;
        bool flag = false;
        stack<TreeNode*> store;
        TreeNode* root = new TreeNode(preorder[pre]);
        TreeNode* temp = root;
        store.push(temp);
        ++pre;
        while( pre < preorder.size() ) {
            if( store.size() != 0 && store.top() -> val == inorder[middle] ) {
                temp = store.top();
                store.pop();
                ++middle;
                flag = true;
                continue;
            } 
              if(flag == false) {
                    
                    temp -> left = new TreeNode(preorder[pre]);
                    temp = temp -> left;
                    store.push(temp);
                    ++pre;
              }else {
                    flag = false;
                    temp -> right = new TreeNode(preorder[pre]);
                    temp = temp -> right;
                    store.push(temp);
                    ++pre;
                }
        }
        return root;
    }
};


//my code
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0) {
            return NULL;
        }
        int pre = 0;
        int middle = 0;
        bool flag = false;
        stack<TreeNode*> store;
        TreeNode* root = new TreeNode(preorder[pre]);
        TreeNode* temp = root;
        store.push(temp);
        //++pre;
        while( pre < preorder.size() - 1 ) {
            if( store.size() != 0 && store.top() -> val == inorder[middle] ) {
                temp = store.top();
                store.pop();
                ++middle;
                flag = true;
                continue;
            } 
              if(flag == false) {
                    ++pre;
                    temp -> left = new TreeNode(preorder[pre]);
                    temp = temp -> left;
                    store.push(temp);
                    //++pre;
              }else {
                    flag = false;
                    ++pre;
                    temp -> right = new TreeNode(preorder[pre]);
                    temp = temp -> right;
                    store.push(temp);
                    //++pre;
                }
        }
        return root;
    }
};

 int main(){
 	return o;
 }