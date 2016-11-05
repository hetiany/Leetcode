//Find online
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(!head || !(head->next)) return head;

        //get the linked list's length
        ListNode* cur = head;
        int length = 0;
        while(cur){
            length++;
            cur = cur->next;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode *left, *right, *tail;
        for(int step = 1; step < length; step <<= 1){
            cur = dummy.next;
            tail = &dummy;
            while(cur){
                left = cur;
                right = split(left, step);
                cur = split(right,step);
                tail = merge(left, right, tail);
            }
        }
        return dummy.next;
    }
private:
    /**
     * Divide the linked list into two lists,
     * while the first list contains first n ndoes
     * return the second list's head
     */
    ListNode* split(ListNode *head, int n){
        //if(!head) return NULL;
        for(int i = 1; head && i < n; i++) head = head->next;

        if(!head) return NULL;
        ListNode *second = head->next;
        head->next = NULL;
        return second;
    }
    /**
      * merge the two sorted linked list l1 and l2,
      * then append the merged sorted linked list to the node head
      * return the tail of the merged sorted linked list
     */
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head){
        ListNode *cur = head;
        while(l1 && l2){
            if(l1->val > l2->val){
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
            else{
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
        }
        cur->next = (l1 ? l1 : l2);
        while(cur->next) cur = cur->next;
        return cur;
    }
};


//Lei
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head -> next == NULL) return head;
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * p1 = head;
        while (fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode * p2 = slow -> next;
        slow -> next = NULL;
        ListNode* h1 = sortList(p1);
        ListNode* h2 = sortList(p2);
        return mergeSort(h1, h2);
    }
    ListNode * mergeSort(ListNode * p, ListNode * q) {
        ListNode dummy(-1);
        ListNode * tail = &dummy;
        while (p && q) {
            if (p -> val < q-> val) {
                tail -> next = p;
                p = p -> next;
            }
            else {
                tail -> next = q;
                q = q -> next;
            }
            tail = tail -> next;
        }
        tail -> next = p ? p : q;
        return dummy.next;
    }
};