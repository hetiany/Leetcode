bool flag;
    bool check(TreeNode *T1, TreeNode *T2) {
        if (T1 == NULL && T2 != NULL)
            return false;
        if (T1 != NULL && T2 == NULL)
            return false;

        if (T1 == NULL && T2 == NULL)
            return true;
        if (T1->val != T2->val)
            return false;
        
        return check(T1->left, T2->left) && check(T1->right, T2->right);
    }

    void dfs(TreeNode *T1, TreeNode *T2) {
        //if (flag) return;
        if (check(T1, T2)) {
            flag = true;
            return;
        }
        if (T1 == NULL)            
            return;
    
        dfs(T1->left, T2);
        dfs(T1->right, T2);
        
    }
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        flag = false;
        dfs(T1, T2);
        return flag;
    }