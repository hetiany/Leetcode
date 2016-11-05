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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size() == 0) return NULL;
        return createABalancedBST(num, 0, num.size() - 1);
    }
    TreeNode * createABalancedBST(vector<int> &num, int begin, int end){
        if(begin > end) return NULL;
        int mid = (begin + end) >> 1;
        TreeNode * node = new TreeNode(num[mid]);
        node -> left = createABalancedBST(num, begin, mid - 1);
        node -> right = createABalancedBST(num, mid + 1, end);
        return node;
    }
};


int main(){

    return 0;
}