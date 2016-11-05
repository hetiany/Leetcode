//my code, 06/25/2016
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head -> next) {
            return true;
        }
        ListNode* pointer = head;
        vector<int> store;
        while(pointer) {
            store.push_back(pointer -> val);
            pointer = pointer -> next;
        }
        int left = 0, right = store.size() - 1;
        while(left < right) {
            if(store[left] == store[right]) {
                ++left;
                --right;
            } else {
                return false;
            }
        }
        return true;
    }
};


//Find online
class Solution {
public:
    bool isPalindrome(ListNode* head) {
         if(head == NULL || head -> next == NULL) {
             return true;
         }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next != NULL && fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow -> next = reverseList(slow -> next);
        slow = slow -> next;
        while(slow != NULL){
            if(head -> val != slow -> val) {
                return false;
            }
            head = head -> next;
            slow = slow -> next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while(head != NULL){
            next = head -> next;
            head -> next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};


//my code, 06/25/2016
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head -> next) {
            return true;
        }
        ListNode* fast = head;
        ListNode* slow = slow;
        while(fast -> next && fast -> next -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        slow -> next = reverselist(slow -> next);
        slow = slow -> next;
        while(slow) {
            if(slow -> val == head -> val) {
                slow = slow -> next;
                head = head -> next;
            } else {
                return false;
            }
        }
        return true;
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