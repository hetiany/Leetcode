#include <iostream>
using namespace std;
 
  
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };



//Linked List Cycle II
//my code, error, 6 shape circle linked list
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL){
    		return NULL;
    	}
    	if(head -> next == head){
    		return head;
    	}
		
		ListNode *p = head->next;
		while(true){
			if(p->next == head){
				return p;
			}
			if(p->next == NULL){
				return NULL;
			}
			p = p -> next;
		}
    }
};


//Liu
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL) {
            return NULL;
        }
        ListNode * fast, * slow;
        fast = slow = head;
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow) {
               break; 
            }
        }
        if(fast == slow) {
            fast = head;
            while(fast != slow) {
                fast = fast -> next;
                slow = slow -> next;
            }
            return fast;
        } else {
            return NULL;
        }
    }
};


//my code, 06/25/2016
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head -> next) {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow) {
                break;
            }
        }
        if(fast == slow) {
            fast = head;
            while(true) {
                if(slow == fast) {
                    return fast;
                } else {
                    fast = fast -> next;
                    slow = slow -> next;
                }
            }
        } 
        return NULL;
    }
};


int main(){
	return 0;
}