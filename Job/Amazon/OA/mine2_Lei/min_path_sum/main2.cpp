#include <iostream>
#include <stack>

using namespace std;
//Binary search tree minimum sum from root to leaf
class TreeNode {
public :
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minPath(TreeNode* root) {
	if (root == NULL) return 0;
	if (!root -> left && !root -> right)
		return root -> val;
	if (!root -> left)
		return root -> val + minPath(root -> right);
	if (!root -> right)
		return root -> val + minPath(root -> left);
	return root -> val + min (minPath(root->left), minPath (root -> right));

}
int minPath1(TreeNode * root)
{
		if (root == NULL){
			return 0;
		}
		if (root -> left == NULL && root -> right == NULL) {
			return root -> val;
		}
		int minSum = INT_MAX;
		TreeNode * cur = root;
		int curSum = 0;
		stack < pair<TreeNode *, int> > stk;
		while (!stk.empty() || cur) {
			while (cur) {
				curSum += cur -> val;
				stk.push(make_pair(cur, curSum));
				cur = cur -> left;
			}
			pair<TreeNode*, int> p = stk.top();
			cur = p.first;
			curSum = p.second;
			if (!cur -> right && !cur -> left ) {
				minSum = min(minSum, curSum);
			}
			stk.pop();
			cur = cur -> right;
		}
	return minSum;
}

int main() {
		// TODO Auto-generated method stub
		TreeNode* root = new TreeNode(10);
		TreeNode* node1=new TreeNode(5);
		TreeNode* node2=new TreeNode(15);
		TreeNode* node3=new TreeNode(9);
		TreeNode* node4=new TreeNode(8);
		TreeNode* node5=new TreeNode(1);
		root -> left=node1;
		root -> right=node2;
		node1 -> right=node3;
		node3 -> left=node4;
		node2 -> left = node5;
		//cout<<"over"<<endl;
		cout << minPath(root)<<endl;
		cout << minPath1(root)<<endl;
		return 0;
}
