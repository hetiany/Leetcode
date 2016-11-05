#include <iostream>
using namespace std;
 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 


// Find online  
//Intersection of Two Linked Lists
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	int n1 = 0; //length of headA
        int n2 = 0; //length of headB
        ListNode * a1 = headA;
        ListNode * a2 = headB;
         
        while (a1){
            n1++;
            a1 = a1->next;
        }
        while (a2){
            n2++;
            a2 = a2->next;
        }
         
        a1 = headA;
        a2 = headB;
         
        while (n1>0 && n2>0){
            if (n1>n2){
                n1--;
                a1 = a1->next;
            }
            if (n2>n1){
                n2--;
                a2 = a2->next;
            }
            if (n2 == n1){
                if (a1 == a2) {
                    return a1;
                } else { 
                    a1 = a1->next;
                    a2 = a2->next;
                    n1--;
                    n2--;
                }
            }
        }
        return NULL;
        
    }
};


//my code, 06/24/2016
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count_A = 0;
        int count_B = 0;
        ListNode* point_A = headA;
        ListNode* point_B = headB;
        while(point_A) {
            ++count_A;
            point_A = point_A -> next;
        }
        while(point_B) {
            ++count_B;
            point_B = point_B -> next;
        }
        point_A = headA, point_B = headB;
        while(count_A > count_B) {
            point_A = point_A -> next;
            --count_A;
        }
        while(count_A < count_B) {
            point_B = point_B -> next;
            --count_B;
        }
        while(count_A) {
            if(point_A != point_B) {
                point_A = point_A -> next;
                point_B = point_B -> next;
                --count_A;
                --count_B;
            } else {
                return point_A;
            }
        }
        return NULL;
    }
};


int main(){

	return 0;
}