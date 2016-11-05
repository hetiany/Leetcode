#include <iostream>
using namespace std;
 
  
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) {
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast){
            if(fast -> val == val) {
                if(fast == head) {
                    fast = head -> next;
                    slow = head -> next;
                    head = head -> next;
                } else {
                    slow -> next = fast -> next;
                    fast = fast -> next;
                }           
            } else {
                slow = fast;
                fast = fast -> next;
                //slow = slow->next;
            }
        }
        return head;
    }
};


//my code, 06/25/2016
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast) {
            if(fast -> val != val) {
                slow = fast;
                fast = fast -> next;
            } else {
                if(fast == head) {
                    fast = fast -> next;
                    slow = slow -> next;
                    head = head -> next;
                } else {
                    slow -> next = fast -> next;
                    fast = fast -> next;
                }
            }
        }
        return head;
    }
};


int main(){

	return 0;
}