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

//Insertion Sort List
//Time limit exceed???
// my code can be accpted through my own test
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL){
        	return NULL;
        }
        if(head -> next == NULL){
        	return head;
        }
        ListNode* sorthead = new ListNode(0);      
        sorthead -> next = head;
        ListNode* sortfast = sorthead -> next; 
        ListNode* sortslow = sorthead -> next; 
        ListNode* presortslow = NULL;
        //ListNode* sortfast = sorthead -> next; 
        head = head -> next;
        while(head){
        	if(head->val >= sortfast->val){
        		sortfast -> next = head;
        		sortfast = sortfast -> next;
        		head = head -> next;
        	}else{
        		if(sortslow->val > head->val){
        			sorthead -> next = head;
        			head = head -> next;
        			sorthead -> next -> next = sortslow;
        			sortslow = sorthead -> next;
        			presortslow = NULL;
        		}else{
        			while(sortslow->val <= head->val){
        				presortslow = sortslow;
		        		sortslow = sortslow -> next;
        			}
        			presortslow -> next = head;
		        	head = head -> next;
		        	presortslow -> next -> next = sortslow;
		        	sortslow = sorthead -> next;
		        	presortslow = NULL;
        		}
       		
        	}
        }
        return sorthead->next;

    }
};


//runtime error
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL){
        	return NULL;
        }
        if(head -> next == NULL){
        	return head;
        }
        ListNode* sorthead = new ListNode(0);      
        sorthead -> next = head;
        ListNode* sortfast = head; 
        ListNode* sortslow = sorthead; 
        while(sortfast){
        	// error here
        	if(sortfast -> next && sortfast -> val < sortfast -> next -> val){
        		//cout << "haha" << endl;
        		sortfast = sortfast -> next;
        	}else{
        			while(sortslow -> next && sortslow -> next -> val < sortfast -> next -> val){
        					sortslow = sortslow -> next;
        			}
        			ListNode* tempslow = sortslow -> next;

        			sortslow -> next = sortfast -> next;

        			sortfast -> next = sortfast -> next -> next;

        			sortslow -> next -> next = tempslow;

        			sortslow = sorthead;
        			}       		
        	}
        
        ListNode *res = sorthead -> next;
        delete sorthead;
        return res;
    } 
};


//Find online, correct
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        ListNode* cur = head;
        while (cur) {
            if (cur -> next && cur -> next -> val < cur -> val) {
                while (pre -> next && pre -> next -> val < cur -> next -> val) {
                    pre = pre -> next;
                }
                /* Insert cur -> next after pre.*/
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
                
                /* Move pre back to new_head. */
                pre = new_head;
            } else {
                cur = cur -> next;
            }
        }
        ListNode* res = new_head -> next;
        delete new_head;
        return res;
    }
};

//Lei, this method is better
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head -> next) {
            return head;
        }
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* forward, *tail = head;
        ListNode* p = head -> next;
        while (p) {
            if(p -> val >= tail -> val) {
                tail = tail -> next;
            } else {
                forward = &dummy;
                tail -> next = p -> next;
                while (forward != tail) {
                    if (forward -> next -> val >= p -> val) {
                        p -> next = forward -> next;
                        forward -> next = p;
                        break;
                    } else {
                       forward = forward -> next; 
                    }
                }
            }
            p = tail -> next;
        }
        return dummy.next;
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
 	ListNode *newhead = sol.insertionSortList(a);
 	cout << newhead->val << endl;
 	cout << newhead->next->val << endl;
 	cout << newhead->next->next->val << endl;
 	cout << newhead->next->next->next->val << endl;
	return 0;
}