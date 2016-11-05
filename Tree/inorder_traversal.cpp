#include <iostream>
#include <stack>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 void pre_traverse(TreeNode *pTree)  
{   
    if(pTree)  
    {           
        if(pTree->left)  
            pre_traverse(pTree->left);  
        cout << pTree->val << endl; 
        if(pTree->right)  
            pre_traverse(pTree->right);      
    }  
}

//non-recursion
void InOrderWithoutRecursion1(TreeNode* root)
{
    if (root == NULL)
        return;
    TreeNode* p = root;
    stack<TreeNode*> s;
    while (!s.empty() || p)
    {
        //一直遍历到左子树最下边，边遍历边保存根节点到栈中
        while (p)
        {
            s.push(p);
            p = p->left;
        }
        //当p为空时，说明已经到达左子树最下边，这时需要出栈了
        if (!s.empty())
        {
            p = s.top();
            s.pop();
            cout << p->val << endl;
            //进入右子树，开始新的一轮左子树遍历(这是递归的自我实现)
            p = p->right;
        }
    }
 }

int main(){

	return 0;
}
