struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}
bool subtree(TreeNode * root, TreeNode * subroot)
{
	if (subroot == NULL)
		return true;
	if (root == NULL) 
		return false;
	if (root -> val == subroot -> val)
	{
		if (subtree(root -> left, subtree -> left) && subtree(root -> right, subtree -> right))
			return true;
	}
	return subtree(root -> left, subtree) || subtree(root -> right, subtree); 
}

bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
    }