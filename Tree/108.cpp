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

//Convert Sorted Array to Binary Search Tree
//Liu
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return createABalancedBST(nums, 0, nums.size() - 1);
    }
    TreeNode * createABalancedBST(vector<int> &nums, int begin, int end){
        if(begin > end) return NULL;
        int mid = (begin + end)/2;
        TreeNode * node = new TreeNode(nums[mid]);
        node -> left = createABalancedBST(nums, begin, mid - 1);
        node -> right = createABalancedBST(nums, mid + 1, end);
        return node;
    }
};


//my code, change depend on Liu, error, why??
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) {
            return  NULL;
        }
        return get_result(nums, 0, nums.size()-1);
    }
    
    TreeNode* get_result(vector<int>& nums, int begin, int end) {
       // if(begin > end) {
        //    return NULL;
       // }
        int mid;
        if(begin <= end) {
            int mid = (begin + end)/2;
        }else{
            return NULL;
        }
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = get_result(nums, begin, mid-1);
        root -> right = get_result(nums, mid+1, end);
        return root;
    }
};

//my code, correct, change depend on Liu
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) {
            return  NULL;
        }
        return get_result(nums, 0, nums.size()-1);
    }
    
    TreeNode* get_result(vector<int>& nums, int begin, int end) {
       /* if(begin > end) {
            return NULL;
        }*/
        int mid;
        if(begin <= end) {
            int mid = (begin + end)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root -> left = get_result(nums, begin, mid-1);
            root -> right = get_result(nums, mid+1, end);
            return root;
        }else{
            return NULL;
        }
        /*TreeNode* root = new TreeNode(nums[mid]);
        root -> left = get_result(nums, begin, mid-1);
        root -> right = get_result(nums, mid+1, end);
        return root;*/
    }
};




//my code, 05/06/2016
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        return get_result(nums, begin, end);
    }
    TreeNode* get_result(vector<int>& nums, int begin, int end) {
        if(begin > end) {
            return NULL;
        }
        int mid = (begin + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = get_result(nums, begin, mid - 1);
        root -> right = get_result(nums, mid + 1, end);
        return root;
    }
};


int main(){
    Solution sol;
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    sol.sortedArrayToBST(num);
    return 0;
}