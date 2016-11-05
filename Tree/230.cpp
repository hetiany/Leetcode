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


//my code, 05/11/2016
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) {
            return 0;
        }
        vector<int> store;
        get_elements(store, root);
        if(k <= store.size()) {
        	return store[k-1];
        }
        return 0;
    }
    void get_elements(vector<int>& store, TreeNode* root) {
        if(!root) {
            return ;
        }
        get_elements(store, root -> left);
        store.push_back(root -> val);
        get_elements(store, root -> right);
    }
};


//Find online
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) {
            return 0;
        }
        stack<TreeNode *> st;
        TreeNode *p = root;
        while(p || !st.empty()) {
            while(p) {
                st.push(p);
                p = p -> left;
            }
            p = st.top();
            if(--k == 0) {
               return p -> val; 
            }
            st.pop();
            p = p -> right;
        }
        return 0;
    }
};


//my code, 05/13/2016, correct, but not better
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) {
            return 0;
        }
        stack<TreeNode*> store;
        TreeNode* temp = NULL;
        while(1) {
             while(root) {
                store.push(root);
                root = root -> left;
            }
            temp = store.top();
            store.pop();
            --k;
            if(k == 0) {
                return temp -> val;
            }
            if(temp -> right) {
                root = temp -> right;
            }
        }
        //the sentance return 0 can be deleted
        //return 0;
    }
};


//another method, binary search
//my code, 06/12/2016
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int left_count = 0, right_count = 0;
        if(root -> left) {
            left_count = count_node(root -> left);
        }
        if(k <= left_count) {
            return kthSmallest(root -> left, k);
        }
        if(k == left_count + 1) {
            return root -> val;
        }
        if(k > left_count + 1) {
           return kthSmallest(root -> right, k - left_count - 1);
        }
        return 0;
    }
    
    int count_node(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return 1 + count_node(root -> left) + count_node(root -> right);
    }    
};


//another binary search
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int left_count = 0, right_count = 0;
        if(root -> left) {
            left_count = count_node(root -> left);
        }
        if(k <= left_count) {
            return kthSmallest(root -> left, k);
        }
        if(k == left_count + 1) {
            return root -> val;
        }
        if(k > left_count + 1) {
           return kthSmallest(root -> right, k - left_count - 1);
        }
        return 0;
    }
    
    int count_node(TreeNode* root) {
        int num = 0;
        get_count(root, num);
        return num;
    }
    
    void get_count(TreeNode* root, int& num) {
        if(!root) {
            return ;
        }
        if(root) {
            ++num;
        }
        if(root -> left) {
            get_count(root -> left, num);
        }
        if(root -> right) {
            get_count(root -> right, num);
        }
    }
};