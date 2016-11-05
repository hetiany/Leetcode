//my code, 06/26/2016
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head -> next) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        int count = 0;
        while(fast) {
            ++count;
            fast = fast -> next;
        }
        fast = head;
        k = k % count;
        if(k == 0) {
            return head;
        }
        while(--k) {
            fast = fast -> next;
        }
        while(fast -> next) {
            fast = fast -> next;
            slow = slow -> next;
        }
        while(head != slow) {
            fast -> next = head;
            head = head -> next;
            fast = fast -> next;
        }
        fast -> next = NULL;
        return head;
    }
};

//Find online
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;

        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;

        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};