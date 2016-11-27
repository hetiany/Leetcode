int amplitude (TreeNode * root) {
	if (!root) return 0;
	return helper(root, root -> val, root -> val);
}
int helper (TreeNode * root, int minVal, int maxVal) {
	if (root == NULL) return max - min;
	if (root -> val < minVal) 
		min = root -> val;
	if (root -> val > maxVal)
		max = root -> val;
	return max(helper (root -> left, minVal, maxVal), helper(root -> right, minVal, maxVal));  
}