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


//Reverse Linked List II
//Find online
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if(head == NULL || m == n){
    		return head;
    	}
        n -= m;
        ListNode* pre = new ListNode(0);
        ListNode* prehead = pre;
        pre -> next = head;
        while(--m){
        	pre = pre -> next; 	
        }   

        ListNode* pstart = pre -> next;

        while(n--) {
            ListNode *p = pstart -> next;
            pstart -> next = p -> next;
            p -> next = pre -> next;
            pre -> next = p;
        }
        return prehead -> next;
    }
};


//my code, 06/25/2016
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head -> next || m == n) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        int reverse_times = n - m + 1;
        ListNode* fast = head;
        ListNode* slow = dummy;
        for(int i = 1; i < m; ++i) {
            slow = fast;
            fast = fast -> next;
        }
        slow -> next = reverselist(fast, reverse_times);
        return dummy -> next;
    }
    
    ListNode* reverselist(ListNode* head, int count) {
        ListNode* dummy = new ListNode(0);
        ListNode* last = head;
        ListNode* temp = NULL;
        while(count) {
            temp = head -> next;
            head -> next = dummy -> next;
            dummy -> next = head;
            head = temp;
            --count;
        }
        last -> next = temp;
        return dummy -> next;
    }
};


int main(){
	return 0;
}