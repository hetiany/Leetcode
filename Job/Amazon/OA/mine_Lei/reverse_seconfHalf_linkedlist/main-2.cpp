ListNode * reverse_secondHalf(ListNode * head) {
	if (head == nullptr || head -> next == nullptr)
		return head;
	ListNode *slow = head, *fast = head;
	while (fast -> next = nullptr && fast -> next -> next != nullptr) {
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	ListNode * pre = slow -> next;
	pre = reverseList(pre);
	slow -> next = pre;
	return head;
}

ListNode* reverse(ListNode * pre) {
	ListNode * dummy = nullptr;
	while (pre) {
		ListNode * tmp = pre -> next;
		pre -> next = dummy;
		dummy = pre;
		pre = tmp; 
	}
	return dummy;
}