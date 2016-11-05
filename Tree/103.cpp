#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


//Binary Tree Zigzag Level Order Traversal
//Find online
class Solution {
public:
	vector<vector<int> > result;
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        
	    if(root!=NULL)
	    {
	        traverse(root, 0);
	    }

	    for(int i=1;i<result.size();i+=2)
	    {
	        vector<int>* v = &result[i];
	        std:reverse(v->begin(), v->end());
	    }
	    return result;
	}

	void traverse(TreeNode* node, int level)
	{
	    if(node == NULL) return;

	    vector<int>* row = getRow(level);
	    row->push_back(node->val);

	    traverse(node->left, level+1);
	    traverse(node->right, level+1);
	}

	vector<int>* getRow(int level)
	{
	    if(result.size()<=level)
	    {
	        vector<int> newRow;
	        result.push_back(newRow);
	    }
	    return &result[level];
	}
};

//my code
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if(root == NULL) {
            return result;
        }
        bool flag = false;
        vector<int> temp;
        TreeNode* node;
        queue<TreeNode*> store;
        store.push(root);
        int cur_count = 1;
        int next_count = 0;
        while(store.size() > 0) {
               node = store.front();
               store.pop();
               --cur_count;
               temp.push_back(node -> val);
               if( node -> left ) {
                   store.push(node -> left);
                   ++next_count;
               }
               if( node -> right) {
                   store.push(node -> right);
                   ++next_count;
               }
          if( cur_count == 0) {
               if(flag == true) {
                   reverse(temp.begin(), temp.end());
                   result.push_back(temp);
                   cur_count = next_count;
                   next_count = 0;
                   temp.clear();
                   flag = false;
                   continue;
               }
               if(flag == false) {
                   result.push_back(temp);
                   cur_count = next_count;
                   next_count = 0;
                   temp.clear();
                   flag = true;
                   continue;
              }
          
           }
       }
       return result;
    }    
};



// Find online, no reverse operation
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > result;
    if (!root) {
        return result;
    }    
    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);    
    bool leftToRight = true;

    while ( !nodesQueue.empty()) {
        int size = nodesQueue.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++) {
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            // find position to fill node's value
            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node -> val;
            if (node->left) {
                nodesQueue.push(node->left);
            }
            if (node->right) {
                nodesQueue.push(node->right);
            }
        }

        // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
    }
};


//my code, version 5/6/2016
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if(!root) {
            return result;
        }
        queue<TreeNode*> store;
        store.push(root);
        int cur_size = 1;
        int next_size = 0;
        bool lefttoright = true;
        while(!store.empty()) {
            vector<int> level(cur_size);
            for(int i = 0; i < cur_size; ++i) {
                TreeNode* temp;
                temp = store.front();
                store.pop();
                if(lefttoright) {
                    level[i] = temp -> val;
                }
                if(!lefttoright) {
                    level[cur_size - 1 - i] = temp -> val;
                }
                if(temp -> left) {
                    store.push(temp -> left);
                    ++next_size;
                }
                if(temp -> right) {
                    store.push(temp -> right);
                    ++next_size;
                }
            }
            result.push_back(level);
            cur_size = next_size;
            next_size = 0;
            if(lefttoright) {
                lefttoright = false;
                continue;
            }
             if(!lefttoright) {
                lefttoright = true;
                continue;
            }
        }
        return result;
    }
};

int main(){
	return 0;
}