//求tree的leaf跟root数值的最大差距
int amplitude(TreeNode* root) {
	if (!root) return 0;
	return helper(root, root -> val, root -> val);
}
int helper (TreeNode *root, int minVal, int maxVal)//current minVal or maxVal before root;
{
	if (!root)
		return maxVal - minVal;
	if (root -> val < minVal)
		minVal = root -> val;
	if (root -> val > maxVal)
		maxVal = root -> val;
	return max (helper(root -> left, minVal, maxVal), helper (root -> right, minVal, maxVal);
}