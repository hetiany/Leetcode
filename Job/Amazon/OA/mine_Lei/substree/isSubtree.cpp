bool isSubtree(TreeNode *root, TreeNode *subtree) {
        // write your code here
	if (subtree == NULL)
		return true;
	if (root == NULL) 
		return false;
	if (root -> val == subtree -> val)
	{
		if (isSameTree(root, subtree))
			return true;
	}
	return isSubtree(root -> left, subtree) || isSubtree(root -> right, subtree); 
    }
    
    bool isSameTree(TreeNode * root , TreeNode * subroot)
    {
        if (!root && !subroot) return true;
        if (!root || !subroot) return false;
        if (root -> val == subroot -> val)
        {
            return isSameTree(root -> left, subroot -> left) && isSameTree(root -> right, subroot -> right);
        }
        return false;
    }
};