 bool isSubtree(TreeNode * t1, TreeNode * t2) {
	if (t2 == NULL) return true;
	if (t1 == NULL) return false;
	if (t1 -> val == t2 -> val && isSameTree(t1, t2))
		return true;
	return isSubtree(t1 -> left, t2) || isSubtree(t1 -> right, t2);
}

bool isSameTree(TreeNode * t1, TreeNode * t2) {
	if (!t1 && !t2) return true;
	if (!t1 || !t2) return false;
	if (t1 -> val == t2 -> val)
		return (isSameTree(t1 -> left, t2 -> left) && isSameTree(t1 -> right, t2 -> right));
	return false;
}
};