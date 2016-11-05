#include <queue>
#include <iostream>
using namespace std; 


// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//Binary Tree Level Order Traversal II
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > vec;
        if(root == NULL) return vec;
        vector<int> level;
        queue<TreeNode *> Q;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty()){
            TreeNode * tmp = Q.front();
            Q.pop();
            if(tmp != NULL){
                level.push_back(tmp -> val);
                if(tmp -> left) Q.push(tmp -> left);
                if(tmp -> right) Q.push(tmp -> right);
            } else {
                vec.push_back(level);
                level.clear();
                if(!Q.empty()) Q.push(NULL);
            }
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};

int main(){
    return 0;
}