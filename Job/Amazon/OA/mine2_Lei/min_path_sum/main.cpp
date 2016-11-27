	int minPath(TreeNode* root) {
			if (root == NULL)
				return 0;
			if (root -> left == NULL && root -> right == NULL)
				return root -> val;
			if (root -> left == NULL)
				return root -> val + minPath(root -> right);
			if (root -> right == NULL)
				return root -> val + minPath(root -> left);
			return root -> val + min(minPath(root -> left), minPath(root -> right));
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
			if (cur -> right == NULL) {
				minSum = min(minSum, curSum);
			}
			stk.pop();
			cur = cur -> right;
			
			
		}
	return minSum;
}






