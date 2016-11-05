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

//Sum Root to Leaf Numbers
 //Liu
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
        
        if(root -> left) dfs(root -> left, carry);
        if(root -> right) dfs(root -> right, carry);

        if(root -> left == NULL
        && root -> right == NULL) pathSum += carry;
    }
};

//my code
class Solution {
public:
    int sum = 0;
    int sumNumbers(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int num = 0;
        get_num(root, num);
        return sum;
    }
    
    void get_num(TreeNode* root, int num) {
        num = num * 10 + root -> val;
        if(root -> left == NULL && root -> right == NULL) {
            sum += num;
            return;
        }
               
        if(root -> left) {
           get_num(root -> left, num);
        }
       
        if(root -> right) {
           get_num(root -> right, num);
        }
    }
};



//my code
class Solution {
public:
    int sumNumbers(TreeNode* root) {
         if(root == NULL) {
             return 0;
         }
        int num = 0;
        int sum = 0;
        get_num(root, num, sum);
        return sum;
    }
    
    void get_num(TreeNode* root, int num, int& sum) {
        num = num * 10 + root -> val;
        if(root -> left == NULL && root -> right == NULL) {
            sum += num;
            return;
        }
        
        if(root -> left) {
           get_num(root -> left, num, sum);
        }
       
        if(root -> right) {
           get_num(root -> right, num, sum);
        }
    }
};



//my code, 05/08/2016
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int sub_sum = 0;
    /*    if(!root) {
            return 0;
        }*/
        return get_result(root, sum, sub_sum);
    }
    int get_result(TreeNode* root, int& sum, int sub_sum) {
        if(!root) {
            return 0;
        }
        if(!root -> left && !root -> right) {
            sub_sum = sub_sum * 10 + root -> val;
            return sum = sum + sub_sum; 
        }
        if(root -> left || root -> right) {
            sub_sum = sub_sum * 10 + root -> val;
        }
        get_result(root -> left, sum, sub_sum);
        get_result(root -> right, sum, sub_sum);
        return sum;
    }
};
int main(){
	return 0;
}