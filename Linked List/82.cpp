//my code, 06/25/2016
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next) {
            return head;
        } 
        ListNode* fast = head -> next;
        ListNode* slow = head;
        ListNode* pre_slow = NULL;
        while(fast) {
            if(fast -> val == slow -> val) {
                while(fast && fast -> val == slow -> val) {
                    fast = fast -> next;
                }
                if(slow == head) {
                    head = fast;
                    slow = fast;
                    if(fast && fast -> next) {
                        fast = fast -> next;
                    } else {
                        return head;
                    }
                } else {
                    pre_slow -> next = fast;
                    slow = fast;
                    if(fast && fast -> next) {
                        fast = fast -> next;
                    } else {
                        return head;
                    }
                }
            } else {
                pre_slow = slow;
                slow = fast;
                fast = fast -> next;
            }
        }
        return head;
    }
};


//Lei Zhang
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return head; 
        }
        ListNode * dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *pre = dummy, *tail = dummy, *cur = head;
        while (cur) {
            while (cur -> next && cur -> val == cur -> next -> val) {
               cur = cur -> next; 
            }
            if ( pre -> next == cur) {
                tail -> next = cur;
                tail = tail -> next;
            }
            pre = cur;
            cur = cur -> next;
        }
        tail -> next = NULL;
        return dummy -> next;
    }
};


//my code, changed based on Lei
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return head; 
        }
        ListNode * dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *pre = dummy, *cur = head;
        
        ListNode *tail = new ListNode(0);
        ListNode *store_tail = tail;
        
        while (cur) {
            while (cur -> next && cur -> val == cur -> next -> val) {
               cur = cur -> next; 
            }
            if ( pre -> next == cur) {
                tail -> next = cur;
                tail = tail -> next;
            }
            pre = cur;
            cur = cur -> next;
        }
        tail -> next = NULL;
        return store_tail -> next;
    }
};