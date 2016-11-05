//my code, time limit exceeded, not correct
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head -> next) {
            return head;
        }
        ListNode* odd = new ListNode(0);
        ListNode* odd_head = odd;
        
        ListNode* even = new ListNode(0);
        ListNode* even_head = even;
        
        
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while(fast && slow) {
            even -> next = fast;
            even = even -> next;
            
            odd -> next = slow;
            odd = odd -> next;
            
            if(fast -> next) {
                slow = fast -> next;
            }
            if(fast -> next && fast -> next -> next) {
                fast = fast -> next -> next;
            }
        }
        fast -> next = NULL;
        
        
        slow -> next = even_head -> next;
        return odd_head -> next;
    }
};


//Find online, this method is better
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) {
            return head;
        }
        ListNode *odd = head, *evenhead = head -> next, *even = evenhead;
        while(even && even -> next) {
            odd -> next = odd -> next -> next;
            even -> next = even -> next -> next;
            odd = odd -> next;
            even = even -> next;
        }
        odd -> next = evenhead;
        return head;
    }
};