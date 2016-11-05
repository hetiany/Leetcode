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


class Solution {
public:
    int pathSum;
    int sumNumbers(TreeNode *root) {
        if(root == NULL) return 0;
        pathSum = 0;
        dfs(root, 0);
        return pathSum;
    }
    void dfs(TreeNode * root, int carry){
        carry = carry * 10 + root -> val;
        if(root -> left == NULL
        && root -> right == NULL) pathSum += carry;
        if(root -> left) dfs(root -> left, carry);
        if(root -> right) dfs(root -> right, carry);
    }
};

int main(){
    return 0;
}