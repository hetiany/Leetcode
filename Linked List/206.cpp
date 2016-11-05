#include <iostream>
using namespace std;
 
  
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

//my code
//Reverse Linked List
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
        	return NULL;
        }

        if(head->next == NULL){
        	return head;
        }

        //Notice, when initialization, fast cannot point to head->next
        ListNode *fast = head, *slow = head, *tmp = NULL;

        while(fast){
        	fast = fast -> next;
        	slow -> next = tmp;
        	tmp = slow;
        	slow = fast;
        }
        return tmp;
    }
};



//my code another version
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }

        if(head->next == NULL){
            return head;
        }

        //Notice, when initialization, fast cannot point to head->next
        ListNode *fast = head -> next, *slow = head, *tmp = NULL;

        while(fast){
            slow -> next = tmp;
            tmp = slow;
            slow = fast;
            fast = fast -> next;
        }
        
        slow -> next = tmp;
        tmp = slow;
        return tmp;
    }
};



//Find online
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if(head == NULL){
        	return NULL;
        }

        if(head->next == NULL){
        	return head;
        }

        ListNode *cur = head;
    	ListNode *forward = NULL;
    	ListNode *previous = NULL;

    	while (cur) {
        	//There is no need to use head here, cur will suffice
        	//head = cur; //set the head to last node
        	forward = cur->next; //save the next pointer in forward

        	cur->next = previous; //change next to previous
        	previous = cur;
        	cur = forward;

        	//cout << "cur= " << cur->item << endl; //this is just to display the current value of cur

        	//don't return here you have only adjusted one node
        	//return head;
    	}

    	//at this point cur is NULL, but previous still holds the correct node
    	return previous;
    	}
};




//my code, 06/24/2016
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = NULL;
        while(head) {
            ListNode* temp = head -> next;
            head -> next = dummy;
            dummy = head;
            head = temp;
        }
        return dummy;
    }
};



//my code, 06/24/2016, insert in head, using dummy node
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        while(head) {
            ListNode* temp = head -> next;
            head -> next = dummy -> next;
            dummy -> next = head;
            head = temp;
        }
        return dummy -> next;
    }
};


//using recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return reverse_List(head, NULL);
    }
    ListNode *reverse_List(ListNode *head, ListNode *newHead){
        if(head == NULL) return newHead;
        ListNode *p = head -> next;
        head -> next = newHead;
        //newHead=head;
      return reverse_List(p, head);

    }
};


int main(){

	return 0;
}