#include <iostream>
using namespace std;
 
/**
 * Definition for singly-linked list.
 */

// solution Liu
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Remove Duplicates from Sorted List
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;

        ListNode *fast, *slow;
        slow = head;
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


//my code, 06/24/2016
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next) {
            return head;
        }
        ListNode* fast = head -> next;
        ListNode* slow = head;
        while(fast) {
            if(fast -> val != slow -> val) {
                fast = fast -> next;
                slow = slow -> next;
            } else {
                slow -> next = fast -> next;
                fast = fast -> next;
            }
        }
        return head;
    }
};


int main(){

    ListNode *a = new ListNode(1);
    //ListNode mm(1);
    //cout << mm.val << endl;
    //ListNode *a = &mm;
    ListNode *b = new ListNode(2);
    //ListNode *c = new ListNode(1);
    a -> next = b;
    //b -> next = c;
    //cout << a  -> val << endl;
    //cout << b  -> val << endl;
    //cout << c  -> val << endl;
    //cout << a->next->val << endl;
    Solution sol;
    cout << sol.deleteDuplicates(a) -> val << endl;
    return 0;
}