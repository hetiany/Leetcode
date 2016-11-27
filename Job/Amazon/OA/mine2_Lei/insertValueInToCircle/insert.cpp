#include <iostream>
#include <vector>
using namespace std;

class CNode {
public:
	int val;
	CNode* next;
	CNode(int x){
		val = x;
	}
};
// CNode* insert(CNode* myList, int x) {
// 	CNode * Node = new CNode(x);
// 	if (myList == NULL) {
// 		myList = Node;
// 		Node -> next = Node;
// 		return Node;
// 	} 
// 	CNode* cur = myList;
// 	CNode* pre = NULL;
// 	while (pre == NULL || cur != myList) {
// 		if (pre != NULL) {
// 			if (pre -> val <= x && cur -> val >= x)
// 				break;
// 			if (cur -> val <= pre -> val && (x <= cur -> val || x >= pre -> val))
// 				break;
// 		}
// 		pre = cur;
// 		cur = cur -> next;
// 	}
// 	Node -> next = cur;
// 	pre -> next = Node;
// 	return Node;
// }
CNode* insert(CNode* myList, int x) {
	CNode * Node = new CNode(x);
	if (myList == NULL) {
		myList = Node;
		Node -> next = Node;
		return Node;
	} 
	CNode* cur = myList;
	CNode* pre = cur;
	cur = cur -> next;
	while (cur != myList) {
			if (pre -> val <= x && cur -> val >= x)
				break;
			if (cur -> val <= pre -> val && (x <= cur -> val || x >= pre -> val))
				break;
		pre = cur;
		cur = cur -> next;
	}
	Node -> next = cur;
	pre -> next = Node;
	return Node;
}
int main(int argc, char const *argv[])
{
	    CNode* min = new CNode(5);
		CNode* node4 = new CNode(7);
		CNode* node5 = new CNode(3);
		//CNode* max = new CNode(20);
		min -> next = node4;
		node4 -> next = node5;
		node5 -> next = min;
		//max -> next = min;
		CNode* res = insert (node4, 3);
		cout << (res -> val) << " ";
		CNode* temp = res -> next;
		while(temp != res) {
			cout << temp -> val << " ";
			temp=temp -> next;
		}
	return 0;
}