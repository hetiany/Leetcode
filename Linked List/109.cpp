#include <iostream>
using namespace std;
 
  
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };



class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL){
        	return NULL;
        }


    }
};

//Convert Sorted List to Binary Search Tree
//Find online, recursion
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST( head, NULL );
    }
    
    TreeNode *sortedListToBST(ListNode *head, ListNode *tail)
    {
        if( head == tail )
            return NULL;
        
        if( head->next == tail )    // 
        {   
            TreeNode *root = new TreeNode( head->val );
            return root;
        }

        ListNode *mid = head, *temp = head;
        while( temp != tail && temp->next != tail )    // 寻找中间节点
        {
            mid = mid->next;
            temp = temp->next->next;
        }
        TreeNode *root = new TreeNode( mid->val );
        root->left = sortedListToBST( head, mid );
        root->right = sortedListToBST( mid->next, tail );
        return root;
    }
};

 int main(){
 	return 0;
 }