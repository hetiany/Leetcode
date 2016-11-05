#include <iostream>
#include <vector>
#include <queue>
using namespace std;


 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
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
                if(!Q.empty) Q.push(NULL);
            }
        }
        return vec;
    }
};

int main(){
    return 0;
}