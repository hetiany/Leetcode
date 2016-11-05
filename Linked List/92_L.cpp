#include <iostream>
using namespace std;
 
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head == NULL) return NULL;
        if(m == n) return head;
        ListNode * originalHead = new ListNode(0);
        originalHead -> next = head;
        ListNode * start, *prestart;
        start = head;
        prestart = originalHead;
        for(int i = 1; i < m; ++i) {
            prestart = start;
            start = start -> next;
        }
        ListNode * node, *prenode, *postnode;
        node = start;
        prenode = NULL;
        postnode = node -> next;
        for(int i = 1; i < n - m + 1; ++i){
            prenode = node;
            node = postnode;
            postnode = postnode -> next;
            node -> next = prenode;
        }
        prestart -> next = node;
        start -> next = postnode;
        head = originalHead -> next;
 
        delete originalHead;
        return head;
    }
};
 
void printLinkedList(ListNode * head){
    while(head){
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}
 
int main(int argc, char const *argv[])
{
    ListNode * a = new ListNode(3);
    ListNode * b = new ListNode(5);
    ListNode * c = new ListNode(7);
    a -> next = b;
    b -> next = c;
    printLinkedList(a);
    Solution sol;
    printLinkedList(sol.reverseBetween(a, 1, 3));
 
    return 0;
}