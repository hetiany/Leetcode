int minPath(TreeNode* root) {
	if (root == NULL) return 0;
	if (!root -> left && !root -> right)
		return root -> val;
	if (!root -> left) 
		return root -> val + minPath(root -> right);
	if (!root -> right)
		return root -> val + minPath(root -> left);
}