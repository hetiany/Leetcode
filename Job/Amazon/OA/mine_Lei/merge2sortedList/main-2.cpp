//(2N) * (K / 2) + 
// (4N) * (K / 4) + 
// (8N) * (K / 8) + 
// .............. + 
// (2^logK*N) * (K / (2 ^logK)) 

// = logK*KN
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
 {
 	if (!l1) return l2;
 	if (!l2) return l1;
 	if (l1 -> val <= l2 -> val) {
 		l1 -> next = mergeTwoLists(l1 -> next, l2);
 		return l1;
 	} else {
 		l2 -> next = mergeTwoLists(l2 -> next, l1);
 		return l2;
 	}
 }

 ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
 	ListNode dummy(0);
 	ListNode* tail = &dummy;
 	while (l1 && l2) {
 		if (l1 -> val <= l2 -> val) {
 			tail -> next = l1;
 			l1 = l1 -> next; 
 		} else {
 			tail -> next = l2;
 			l2 = l2 -> next;
 		}
 		tail = tail -> next;
 	}
 	tail -> next = l1 ? l1 : l2;
 	return dummy -> next;
 }

