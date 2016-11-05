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



//Find online
class Solution {
public:
	int countNodes(TreeNode* root) {
	if(!root) return 0;
	int left_height = getLeftHeight(root -> left);
	int right_height = getLeftHeight(root -> right);

	if(left_height == right_height) {
	     return pow(2, left_height) + countNodes(root -> right);
	}

	return pow(2, right_height) + countNodes(root -> left);
	}	
private:
    int getLeftHeight(TreeNode* node) {
	int height = 0;
	while(node) { 
        height++;
	    node = node -> left;	    
	}
	return height;
	}
};



//Find online
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) {
            return 0; 
        }
        int hl = 0;
        int hr = 0;
        TreeNode* l = root; 
        TreeNode* r = root;
        while(l) {
            hl++;
            l = l -> left;
        }
        while(r) {
            hr++;
            r = r -> right;
        }
        if(hl == hr) {
            return pow(2,hl) - 1;
        }
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};



//my code, not complete
class Solution {
public:
    int countNodes(TreeNode* root) {
        int total = 0;
        /*if(root == NULL) {
            return total;
        }*/
        total = get_result(root, total);
        return total;
    }
    
private:
    int get_result(TreeNode* root, int& total) {
        if(!root) {
            return 0;
        }
        
        int left_count = get_result(root -> left, total);
        
        int right_count = get_result(root -> right, total);
        
        total = max(left_count, right_count) + 1;
        
        
    }
};

//my code, 05/11/2016, changed by find online(2)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int left = 1;
        int right = 1;
        TreeNode* leftnode = root;
        TreeNode* rightnode = root;
        while(leftnode -> left) {
            leftnode = leftnode -> left;
            ++left;
        }
        while(rightnode -> right) {
            rightnode = rightnode -> right;
            ++right;
        }
        if(left == right) {
            return pow(2,left) - 1;
        }
        return countNodes(root -> left) + countNodes(root -> right) + 1;
    }
};


int main(){
	return 0;
}