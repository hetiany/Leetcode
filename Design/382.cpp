//Find online ???
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        curr = head;
        newhead = head;
        int i = 0;
        while(head){
            head = head -> next;
            i++;
        }
        length = i;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int n = rand() % length;
        while(n){
            // cannot understand from here ???
            if(!curr -> next){
                curr = newhead;
                n--;
            }
            //for here I can use while or if
            /*while(curr && curr -> next && n){
                curr = curr -> next;
                n--;
            }*/
            if(curr && curr -> next && n){
                curr = curr -> next;
                n--;
            }
        }
        return curr -> val;
    }
    
private:
    ListNode* curr;
    ListNode* newhead;
    int length;
};