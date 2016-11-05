#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return validateBST(root, LONG_MIN, LONG_MAX);
    }
private:
    bool validateBST(TreeNode * root, long min, long max){
        if(root == NULL) return true;
        if(root -> val < max && root -> val > min)
            return validateBST(root -> left, min, root -> val)
                && validateBST(root -> right, root -> val, max);
        return false;
    }
};


int main(){
    return 0;
 }