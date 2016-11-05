#include <iostream>
using namespace std;
 
  
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

//Linked List Cycle
//my code, error, 6 shape circle linked list
class Solution {
public:
    bool hasCycle(ListNode *head) {
    	if(head == NULL || head -> next == NULL){
    		return false;
    	}
    	if(head -> next == head){
    		return true;
    	}
		
		ListNode *p = head->next;
		while(true){
			if(p->next == head){
				return true;
			}
			if(p->next == NULL){
				return false;
			}
			p = p -> next;
		}        
    }
};

//Liu
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL)    
            return false;

        ListNode *fast = head;
        ListNode *slow = head;

        while(fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};


//my code, 06/25/2016
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head -> next) {
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow) {
                return true;
            }
        }
        return false;
    }
};


//my code, 06/25/2016
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head -> next) {
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast -> next && fast -> next -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow) {
                return true;
            }
        }
        return false;
    }
};


 int main(){

	return 0;
}