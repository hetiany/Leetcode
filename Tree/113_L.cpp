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


class Solution{
public:
    vector<vector<int> > pathSum(TreeNode * root, int sum){
        (this -> vec).clear();
        if(root == NULL) return vec;
        this -> targetSum = sum;
        dfs(root, 0);
        return this -> vec;
    }
private:
    vector<vector<int> > vec;
    vector<int> tmp;
    int targetSum;
    void dfs(TreeNode * root, int total){
        total += root -> val;
        (this -> tmp).push_back(root -> val);
        if(root -> left == NULL
        && root -> right == NULL
        && total == this -> targetSum){
            (this -> vec).push_back(this -> tmp);
            (this -> tmp).pop_back();
            return;
        }
        if(root -> left) dfs(root -> left, total);
        if(root -> right) dfs(root -> right, total);
        (this -> tmp).pop_back();
    }
};


  int main(){
    return 0;
}