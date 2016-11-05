#include <vector>
#include <algorithm>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//Find online
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	    if (!root || !p || !q) {
	        return NULL;
	    }

	    if (root == p || root == q) {
	        return root;
	    }

	    TreeNode* l = lowestCommonAncestor(root->left, p, q);
	    TreeNode* r = lowestCommonAncestor(root->right, p, q);

	    if (l && r) {
	        return root;
	    }

	    return l? l : r;
    }
};

//My code, changed by online answer
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) {
            return NULL;
        }
        if (root == p || root == q) {
            return root;
        }
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if (l && r) {
            return root;
        }
        if(l) {
            return l;
        }
        if(r) {
            return r;
        }
        return NULL;
    }
}; 


 int main() {
 	return 0;
 }