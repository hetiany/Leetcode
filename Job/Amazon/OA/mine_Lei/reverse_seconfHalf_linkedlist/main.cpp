// Example program
#include <iostream>
#include <string>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
//  ListNode * reverseList(ListNode * head)
// {
// 	ListNode * pre = NULL;
// 	while (head)
// 	{
// 		ListNode * next = head -> next;
// 		head -> next = pre;
// 		pre = head;
// 		head = next;
// 	}
// 	return pre;
// }
 
// ListNode * reverse_secondHalf(ListNode * head)
// {
// 	if (!head || !head -> next || !head -> next -> next)
// 		return head;
// 	ListNode * slow = head, *fast = head;
// 	while (fast -> next && fast -> next -> next)
// 	{
// 		slow = slow -> next;
// 		fast = fast -> next -> next;
// 	} 
// 	ListNode * pre = slow -> next;
// 	pre = reverseList(pre);
// 	slow -> next = pre;
// 	return head;
// }
 
 ListNode * reverseList(ListNode *);

ListNode * reverse_secondHalf(ListNode * head) {
	if (head == nullptr || head -> next == nullptr)
		return head;
	ListNode *slow = head, *fast = head -> next;
	while (fast -> next != nullptr && fast -> next -> next != nullptr) {
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	ListNode * pre = slow -> next;
	ListNode * dummy = NULL;
	while (pre) {
		ListNode * tmp = pre -> next;
		pre -> next = dummy;
		dummy = pre;
		pre = tmp; 
	}
	slow -> next = dummy;
	// pre = reverseList(pre);
	// slow -> next = pre;
	return head;
}

ListNode* reverseList(ListNode * pre) {
	ListNode * head = nullptr;
	while (pre) {
		ListNode * tmp = pre -> next;
		pre -> next = head;
		head = pre;
		pre = tmp; 
	}
	return head;
}
 // ListNode * reverseList(ListNode * head)
 // {
 // 	ListNode * pre = NULL;
 // 	while (head)
 // 	{
 // 		ListNode * next = head -> next;
 // 		head -> next = pre;
 // 		pre = head;
 // 		head = next;
 // 	}
 // 	return pre;
 // }



int main(int argc, char const *argv[])
{
	ListNode head(1), p1(2), p2(3), p3(4), p4(5);
	head.next = &p1;
	p1.next = &p2;
	//p2.next = &p3;
	//p3.next = &p4;
	ListNode * ptr = &head;
	ptr = reverse_secondHalf(&head);
	while (ptr)
	{
		cout<< ptr -> val;
		ptr = ptr -> next;
	}
	return 0;
}