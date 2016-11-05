#include <iostream>
using namespace std;



//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


//Remove Nth Node From End of List
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //ListNode dummy{-1, head};
        ListNode *p = head, *q = head, *previous = head;

        // first, let q move n steps
        for(int i = 1; i < n; ++i){
        	q = q -> next;
        }
        
        while(q -> next){
        	previous = p;
        	p = p -> next;
        	q = q -> next;
        }
        
        ListNode *tmp = NULL;
        if(p == head){
        	tmp = head;
        	head = head -> next;
        	delete tmp;
        }else{
        	previous -> next = p -> next;
            delete p;
        }
        
        return head;
    }
};



// Liu solution

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



//my code, 06/23/2016
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *quick = head, *slow = head;
        int count = 0;
        while(quick) {
            ++count;
            quick = quick -> next;
        }
        quick = head;
        int rest = count - 1 - n;
        if(rest == -1) return head -> next;
        while(rest > 0) {
            slow = slow -> next;
            --rest;
        }
        slow -> next = slow -> next -> next;
        return head;
    }
};


//my code, 10/03/2016
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head; 
        ListNode* fast = head;
        ListNode* pre = head;
        while(n) {
            fast = fast -> next;
            --n;
        }
        while(fast) {
            fast = fast -> next;
            pre = slow;
            slow = slow -> next;
            
        }
        if(slow == head) {
            return head -> next;
        }
        pre -> next = slow -> next;
        return head;
    }
};


int main(){

	return 0;
}