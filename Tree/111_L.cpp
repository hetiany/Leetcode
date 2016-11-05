#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


//dfs
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root){
            return 0;
        }
        int minLeft = minDepth(root -> left);
        int minRight = minDepth(root -> right);
        if (minLeft == 0){
            return minRight + 1;
        }
        if (minRight == 0){
            return minLeft + 1;
        }
        return minLeft > minRight ? minRight + 1 : minLeft + 1;
    }
};


//bfs
class Solution
{
public:
    int minDepth(TreeNode * root) {
        if(root == NULL) return 0;
        int counter = 0;
        queue<TreeNode *> Q;
        Q.push(root);
        Q.push(NULL);
        while(Q.empty() == false){
            TreeNode * tmp = Q.front();
            Q.pop();
            if(tmp != NULL){
                if(tmp -> left) Q.push(tmp -> left);
                if(tmp -> right) Q.push(tmp -> right);
                if(tmp -> left == NULL && tmp -> right == NULL) {
                    counter++;
                    break;
                }
            } else {
                counter ++;
                if(Q.empty() == false) Q.push(NULL);
            }
        }
        return counter;
    }
};



 int main(){

	return 0;
}