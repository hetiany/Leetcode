//my code, 06/26/2016
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) {
            return l1;
        }
        if(l1 && !l2) {
            return l1;
        }
        if(!l1 && l2) {
            return l2;
        } 
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* result = new ListNode(0);
        ListNode* head_result = result;
        int total = 0;
        int carry = 0;
        while(p1 && p2) {
            total = p1 -> val + p2 -> val + carry;
            carry = 0;
            if(total >= 10) {
                carry = 1;
                total = total % 10;
            }
            p1 = p1 -> next;
            p2 = p2 -> next;
            result -> next = new ListNode(total);
            result = result -> next;
        }
        if(!p1 && !p2) {
            if(carry == 1) {
                result -> next = new ListNode(1);
                carry = 0;
            }
        }
        if(p1 && !p2) {
            while(p1) {
                total = p1 -> val + carry;
                carry = 0;
                if(total >= 10) {
                    carry = 1;
                    total = total % 10;
                }
                p1 = p1 -> next;
                result -> next = new ListNode(total);
                result = result -> next;
            }
            if(carry == 1) {
                result -> next = new ListNode(1);
                carry = 0;
            }
        }
        if(!p1 && p2) {
            while(p2) {
                total = p2 -> val + carry;
                carry = 0;
                if(total >= 10) {
                    carry = 1;
                    total = total % 10;
                }
                p2 = p2 -> next;
                result -> next = new ListNode(total);
                result = result -> next;
            }
            if(carry == 1) {
                result -> next = new ListNode(1);
                carry = 0;
            }
        }
        return head_result -> next;
    }
};


//Find online, Java
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode c1 = l1;
        ListNode c2 = l2;
        ListNode sentinel = new ListNode(0);
        ListNode d = sentinel;
        int sum = 0;
        while (c1 != null || c2 != null) {
            sum /= 10;
            if (c1 != null) {
                sum += c1.val;
                c1 = c1.next;
            }
            if (c2 != null) {
                sum += c2.val;
                c2 = c2.next;
            }
            d.next = new ListNode(sum % 10);
            d = d.next;
        }
        if (sum / 10 == 1)
            d.next = new ListNode(1);
        return sentinel.next;
    }
};


//my code, changed based on Java version, this method is better
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* result = new ListNode(0);
        ListNode* head_result = result;
        int sum = 0;
        while(l1 || l2) {
            if(l1) {
                sum = sum + l1 -> val;
                l1 = l1 -> next;
            }
            if(l2) {
                sum = sum + l2 -> val;
                l2 = l2 -> next;
            }
            result -> next = new ListNode(sum % 10);
            result = result -> next;
            sum = sum / 10;
        }
        if(sum == 1) {
            result -> next = new ListNode(1);
        }
        return head_result -> next;
    }
};