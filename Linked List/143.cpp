//my code. 06/26/2016
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head -> next) {
            return ;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        //Find middle
        while(fast -> next && fast -> next -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        //reverse the second half
        ListNode*  reverse_head = reverselist(slow -> next);
        slow -> next = NULL;
        
        //merge two list
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(reverse_head) {
            temp -> next = head;
            head = head -> next;
            temp = temp -> next;
            
            temp -> next = reverse_head;
            reverse_head = reverse_head -> next;
            temp = temp -> next;
        }
        if(head) {
            temp -> next = head;
            temp = temp -> next;
        }
        head = dummy -> next;
        return ;
    }
    ListNode* reverselist(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = NULL;
        while(head) {
            temp = head -> next;
            head -> next = dummy -> next;
            dummy -> next = head;
            head = temp;
        }
        return dummy -> next;
    }
    
};