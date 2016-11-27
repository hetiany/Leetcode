class CNode {
public:
	int val;
	CNode next;
	CNode(int x){
		val = x;
	}
}

CNode* insert(CNode* myList, int n) {
	//corner case;
	if (myList == NULL) return CNode(n);
	if (myList -> next == myList) {
		myList -> next = new CNode(n);
		myList -> next -> next = myList;
		if (myList.val < n)
			return myList;
		return myList -> next;
	}
	else if (n < myList -> val) {
			CNode cur = myList;
			while (cur -> next != myList) {
				cur = cur -> next;
			}
			//add value after the tail
			cur ->next = new CNode(n);
			cur->next->next = myList;
			return cur->next;
		}
	else {   //find tail then appedn
		CNode * cur = myList;
		while (cur -> next != myList && cur -> next -> val <= n) {
			 cur = cur -> next;
		}
		CNode * temp = cur -> next ;
		cur -> next = new CNode(n);
		cur -> next -> next = temp;
		return myList;
	}
}


CNode * insert(CNode * head, int x)
{
	if (head == NULL) {
		head = new CNode(x);
		head -> next = head;
		return head;
	}
	CNode cur = head;
	CNode pre = NULL;
	do {
		pre = cur;
		cur = cur -> next;
		if (pre -> val <= x && x <= cur -> val)
			break;
		if (cur -> val < pre -> val && (x < cur -> val || x > pre -> val))
			break;
	} while (cur != head);
	CNode * tmp = new CNode(x);
	newNode -> next = cur;
	pre -> next = newNode;
	return newNode;
}


















