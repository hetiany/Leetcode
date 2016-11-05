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

//Path Sum II
//Find online, better than my code
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        vector<int> cur_path;
        pathSumRec(root, sum, result, cur_path);
        return result;
    }

    void pathSumRec(TreeNode* root, int sum, vector<vector<int> >& result, vector<int>& cur_path) {
        if (root == NULL) {
            return;
        }

        if (root -> val == sum && root -> left == NULL && root -> right == NULL) {
            cur_path.push_back(root -> val);
            result.push_back(cur_path);
            cur_path.pop_back();
            return;
        }

        int sum_left = sum - root -> val;
        cur_path.push_back(root -> val);
        pathSumRec(root -> left, sum_left, result, cur_path);
        //cur_path.pop_back();
        pathSumRec(root -> right, sum_left, result, cur_path);
        cur_path.pop_back();
    }
};


//my code
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        vector<int> temp;
         if(root == NULL){
            return result;   
        }
        temp.push_back(root -> val);
        get_result(root, sum, result, temp );
        return result;
    }
    
    void get_result(TreeNode* root, int sum, vector<vector<int> >& result, vector<int> temp){
         if(root == NULL){
            return;   
        }
        if(root->val == sum && root->left == NULL && root->right == NULL){
            result.push_back(temp);
            return ;
        }
        
        if(root -> left){
            temp.push_back((root->left) ->val);
             get_result(root->left, sum - (root->val), result, temp);
             temp.pop_back();
        }
       
        if(root -> right){
            temp.push_back((root->right)->val);
             get_result(root->right, sum - (root->val), result, temp);
             temp.pop_back();
        }
        
    }
};
  int main(){
	return 0;
}