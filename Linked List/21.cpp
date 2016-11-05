#include <iostream>
using namespace std;
 
/**
 * Definition for singly-linked list.
 */

// solution Liu
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
//Merge Two Sorted Lists
class Solution {
public:
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2){
        ListNode head(0), *l;
        l = &head;
        while(l1 && l2){
            if(l1 -> val < l2 -> val){
                l -> next = l1;
                l1 = l1 -> next;
            }
            else{
                l -> next = l2;
                l2 = l2 -> next;
            }            
            l = l -> next;
        }
        if(l1) l -> next = l1;
        if(l2) l -> next = l2;
        return head.next;
    }
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(l1 && l2) {
            if(l1 -> val <= l2 -> val) {
                cur -> next = l1;
                cur = cur -> next;
                l1 = l1 -> next;
            }
            if(l1 -> val > l2 -> val) {
                cur -> next = l2;
                cur = cur -> next;
                l2 = l2 -> next;
            }
            //cur = cur -> next;
        }
        if(l1) {
            cur -> next = l1;
        }
        if(l2) {
            cur -> next = l2;
        }
        return head -> next;
    }
};


//my code, 06/24/2016
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(l1 && l2) {
            if(l1 -> val <= l2 -> val) {
                cur -> next = l1;
                cur = cur -> next;
                l1 = l1 -> next;
            } else {
                cur -> next = l2;
                cur = cur -> next;
                l2 = l2 -> next;
            }
        }
        if(l1) {
            cur -> next = l1;
        }
        if(l2) {
            cur -> next = l2;
        }
        return head -> next;
    }
};


//Find online, using recursive
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};


//my code, 10/03/2016
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(l1 && l2) {
            if(l1 -> val < l2 -> val) {
                cur -> next = l1;
                cur = cur -> next;
                l1 = l1 -> next;
            } else {
                cur -> next = l2;
                cur = cur -> next;
                l2 = l2 -> next;
            }
        }
        if(l1) {
            cur -> next = l1;
        }
        if(l2) {
            cur -> next = l2;
        }
        return dummy -> next;
    }
};