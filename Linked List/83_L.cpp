/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode * fast, * slow;
        slow = head;
        if(head -> next == NULL) return head;
        fast = head -> next;
        while(fast){
            if(fast -> val == slow -> val){
                fast = fast -> next;
                slow -> next = fast;
            } else {
                fast = fast -> next;
                slow = slow -> next;
            }
        }
        return head;
    }
};