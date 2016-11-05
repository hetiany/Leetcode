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
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode * slow, * fast, * preslow;
        slow = fast = head;
        preslow = NULL;
        while(fast -> next && fast -> next -> next){
            fast = fast -> next -> next;
            preslow = slow;
            slow = slow -> next;
        }
        TreeNode * node = new TreeNode(slow -> val);
        fast = slow -> next;
        delete slow;
        if(preslow != NULL){
            preslow -> next = NULL;
            node -> left = sortedListToBST(head);
        }
        node -> right = sortedListToBST(fast);
        return node;
    }
};

 int main(){
    return 0;
 }