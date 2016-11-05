#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 **/
 struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head -> next == NULL){
            return NULL;
        }
        ListNode *previous, *slow, *fast;
        previous = head;
        slow = head;
        fast = head;
        for (int i = 0; i < n; ++i)
            fast = fast -> next;
 
        while(fast) {
            previous = slow;
            fast = fast -> next;
            slow = slow -> next;
        }
 
        if (slow == head){
            head = head -> next;
        } else {
            previous -> next = slow -> next;
        }
        return head;
    }
};
 
int main(int argc, char const *argv[])
{
    ListNode *a = new ListNode(1);
    ListNode mm(1);
    cout << mm.val << endl;
    //ListNode *a = &mm;
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    a -> next = b;
    b -> next = c;
    cout << a  -> val << endl;
    cout << b  -> val << endl;
    cout << c  -> val << endl;
    Solution sol;
    cout << sol.removeNthFromEnd(a, 2)  -> val << endl;
    return 0;
}