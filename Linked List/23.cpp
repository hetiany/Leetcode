//Lei
class Solution {
public:
    static bool compare (const ListNode* l1, const ListNode* l2) {
        return l1 -> val > l2 -> val;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
    // write your code here
    int length = lists.size();
    vector<ListNode*> temp;
    for (int i = 0; i < length; ++i) {
    if (lists[i]) 
        temp.push_back(lists[i]);
    }
    if (length == 0) return NULL;
    make_heap(temp.begin(), temp.end(), compare);
    ListNode * cur;
    ListNode dummy(0);
    cur = & dummy;
    while (temp.size() > 0) {
        cur -> next = temp.front();
        pop_heap (temp.begin(), temp.end(), compare);
        temp.pop_back();
        cur = cur -> next;
        if (cur -> next) {
            temp.push_back(cur -> next);
            push_heap(temp.begin(),temp.end(), compare);
        }
    }
    return dummy.next;
    }
};

//Find online
class Solution {
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        for (auto l : lists) {
            if (l) {
                q.push(l);
            }
        }
        
        if (q.empty()) {
            return NULL;
        }
        
        ListNode* result = q.top();
        q.pop();
        if (result->next) {
            q.push(result->next);
        }

        ListNode* tail = result;            
        while (!q.empty()) {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if (tail->next) {
                q.push(tail->next);
            }
        }
        
        return result;
    }
};