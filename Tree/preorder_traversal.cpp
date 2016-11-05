#include <iostream>
#include <stack>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 //recursion
 void pre_traverse(TreeNode *pTree)  
{   
    if(pTree)  
    {  
        cout << pTree->val << endl;  
        if(pTree->left)  
            pre_traverse(pTree->left);  
        if(pTree->right)  
            pre_traverse(pTree->right);      
    }  
}


//non-recursion
void PreOrderWithoutRecursion1(TreeNode* root)
{
    if (root == NULL)
        return;
    TreeNode* p = root;
    stack<TreeNode*> s;
    while (!s.empty() || p)
    {
        //边遍历边打印，并存入栈中，以后需要借助这些根节点(不要怀疑这种说法哦)进入右子树
        while (p)
        {
            cout << p->val << endl;
            s.push(p);
            p = p->left;
        }
        //当p为空时，说明根和左子树都遍历完了，该进入右子树了
        if (!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
    //cout << endl;
}

int main(){

	return 0;
}