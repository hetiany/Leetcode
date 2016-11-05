#include <iostream>
using namespace std;
 
  
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


//Swap Nodes in Pairs
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	if(head == NULL){
    		return NULL;
    	}
    	if(head->next == NULL){
    		return head;
    	}
    	int nodenum = 0;
    	ListNode *slow = head, *fast = head->next, *prefast = NULL;
    	while(slow){
    		++nodenum;
    		slow = slow -> next;
    	}
    	//cout << nodenum << endl;
    	slow = head;
    	head = head -> next;
    	for(int i = 0; i < nodenum/2; ++i){
    		if(i >= 1){
    			prefast -> next = fast;
    		}
    		prefast = slow;
    		fast = fast -> next;
    		slow -> next -> next = slow;
    		slow -> next = fast;
    		slow = fast;
    		if(fast != NULL){
    			fast = fast -> next;
    		}    		
    	}
    	return head;        
    }
};


//my code, 06/24/2016
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head -> next) {
            return head;
        }
        ListNode* fast = head -> next;
        ListNode* f_pervious = fast;
        ListNode* slow = head;
        head = fast;
        while(true) {
            slow -> next = fast -> next;
            fast = fast -> next; 
            f_pervious -> next = slow;
            if(fast && fast -> next) {
                slow -> next = fast -> next;
                slow = fast;
                fast = fast -> next;
                f_pervious = fast;             
            } else {
                break;
            }
        }
        return head;
    }
};


//my code, using dummy node, insert in the front of the list
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head -> next ) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* temp = NULL;
        while(cur && cur -> next) {
            temp = cur -> next -> next;
            cur -> next -> next = cur;
            pre -> next = cur -> next;
            cur -> next = temp;
            pre = cur;
            cur = temp;
        }
        return dummy -> next;
    }
};


//my code. 10/03/2016
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* slow = head, *fast = head, *pre = NULL;
        if(!head || !head -> next) {
            return head;
        }
        head = head -> next;
        fast = fast -> next;
        while(fast) {
            slow -> next = fast -> next;
            pre = fast;
            fast = fast -> next;
            pre -> next = slow;
            if(fast && fast -> next) {
                slow -> next = fast -> next;
                slow = fast;
                fast = fast -> next;
            } else {
                break;
            }
        }
        return head;
    }
};

 int main(){
 	ListNode *a = new ListNode(1);
 	ListNode *b = new ListNode(2);
 	ListNode *c = new ListNode(3);
 	ListNode *d = new ListNode(4);
 	a->next = b;
 	b->next = c;
 	c->next = d;
 	Solution sol;
 	ListNode *newhead = sol.swapPairs(a);
 	cout << newhead->val << endl;
 	cout << newhead->next->val << endl;
 	cout << newhead->next->next->val << endl;
 	cout << newhead->next->next->next->val << endl;
	return 0;
}