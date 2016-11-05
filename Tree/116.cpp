#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

 struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };


//Populating Next Right Pointers in Each Node
//Find online
class Solution {
public:
    void connect(TreeLinkNode *root) {
	    if (root == NULL) return;
	    TreeLinkNode *pre = root;
	    TreeLinkNode *cur = NULL;
	    while(pre->left) {
	        cur = pre;
	        while(cur) {
	            cur->left->next = cur->right;
	            if(cur->next){
	            	cur->right->next = cur->next->left;
	            } 	            	
	            cur = cur->next;
	        }
	        pre = pre->left;
	    }        
    }
};


//my code
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) {
            return;
        }
        queue<TreeLinkNode*> store;
        TreeLinkNode* cur_temp = root;
        TreeLinkNode* pre_temp = root;
        store.push(cur_temp);
        int cur_count = 1;
        int next_count = 0;
        
        while(store.size() != 0) {
            
            while(cur_count != 0) {
                cur_temp = store.front();
                store.pop();
                --cur_count;
                
                if(cur_temp -> left) {
                    store.push(cur_temp -> left);
                    ++next_count;
                }
                if(cur_temp -> right) {
                    store.push(cur_temp -> right);
                    ++next_count;
                }
                
                if(cur_count == 0) {
                    pre_temp -> next = cur_temp;
                    cur_temp -> next = NULL;
                    pre_temp = NULL;
                }else{
                    if(pre_temp != NULL) {
                        pre_temp -> next = cur_temp;
                        pre_temp = cur_temp;
                    } 
                    if(pre_temp == NULL){
                         pre_temp = cur_temp;
                    }
                }

            }            
            cur_count = next_count;
            next_count = 0;
        }
    }
};


//my code, 05/11/2016, changed by find online
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) {
            return ;
        }
        TreeLinkNode* cur_node = root;
        while(root -> left) {
            while(cur_node) {
                if(cur_node -> right) {
                    cur_node -> left -> next = cur_node -> right;
                }
                if(cur_node -> next) {
                    cur_node -> right -> next = cur_node -> next -> left;
                }
                cur_node = cur_node -> next;
      
            }
            root = root -> left;
            cur_node = root;
        }
    }
};




int main(){

	return 0;
}