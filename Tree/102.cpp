#include <iostream>
#include <stack>
#include <queue>
using namespace std;


 //Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


//Find online, bfs
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
      vector<vector<int> > result;  
      vector<TreeNode*> sta;  
      if(root == NULL) return result;  
      sta.push_back(root);  
      int nextLevCou=1;  
      int index=0;  
      while(index < sta.size())  
      {  
        int curLevCou = nextLevCou;  
        nextLevCou =0;  
        vector<int> level;  
        for(int i =index; i< index+curLevCou; i++)  
        {  
          root = sta[i];          
          level.push_back(root->val);  
          if(root->left!=NULL)  
          {  
            sta.push_back(root->left);  
            nextLevCou++;  
          }  
          if(root->right!=NULL)  
          {  
            sta.push_back(root->right);  
            nextLevCou++;  
          }  
        }  
        result.push_back(level);  
        index = index +curLevCou;  
      }  
      return result;  
    }
};



//Find online, another version, using queue, better than first version
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
      vector<vector<int> > result;  
      if(root == NULL) return result;  
      queue<TreeNode*> nodeQ;  
      nodeQ.push(root);  

      int nextLevelCnt=0, currentLevelCnt=1;  
      vector<int> layer;  
      int visitedCnt=0;  
      while(nodeQ.size() != 0)  
      {  
        TreeNode* node = nodeQ.front();  
        nodeQ.pop();  
        visitedCnt++;  
        layer.push_back(node->val);  
        if(node->left != NULL)  
        {  
          nodeQ.push(node->left);  
          nextLevelCnt++;  
        }  
        if(node->right != NULL)  
        {  
          nodeQ.push(node->right);  
          nextLevelCnt++;  
        }  
        if(visitedCnt == currentLevelCnt)  
        {  
          visitedCnt =0;  
          currentLevelCnt = nextLevelCnt;  
          nextLevelCnt=0;  
          result.push_back(layer);  
          layer.clear();  
        }  
      }  
      return result;  
    }
};


//my code
//time: O(n), space: O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        vector<int> layer;
        queue<TreeNode*> que;
        if(root == NULL){
            return result;
        }
        que.push(root);
        int count_current = 1;
        int count_next = 0;
        while(que.size() != 0){
            TreeNode* temp = que.front();
            que.pop();
            layer.push_back(temp -> val);
            --count_current;
            if(temp -> left != NULL){
                que.push(temp -> left);
                ++count_next;
            }
            if(temp -> right != NULL){
                que.push(temp -> right);
                ++count_next;
            }
            if(count_current == 0){
                result.push_back(layer);
                layer.clear();
                count_current = count_next;
                count_next = 0;
            }
        }
        return result;
    }
};


//my code, 04/26/2016
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if(!root) {
            return result;
        }
        int cur_level_count = 0;
        int next_level_count = 0;
        vector<int> level_container;
        queue<TreeNode*> store;
        store.push(root);
        ++cur_level_count;
        
        while(store.size()) {
            while(cur_level_count) {
                //level_container.push_back(store.front());
                TreeNode* temp = store.front();
                if(temp -> left) {
                    store.push(temp -> left);
                    ++next_level_count;
                }
                if(temp -> right) {
                    store.push(temp -> right);
                    ++next_level_count;
                }
                level_container.push_back(temp -> val);
                store.pop();
                --cur_level_count;
            }
            result.push_back(level_container);
            level_container.clear();
            cur_level_count = next_level_count;
            next_level_count = 0;
        }
        return result;
    }
};


//Find online, DFS
class Solution {
public:
    vector<vector<int>> ret;  
    vector<vector<int> > levelOrder(TreeNode *root) {
        buildVector(root, 0);
        return ret;
    }

    void buildVector(TreeNode *root, int depth)
    {
        if(root == NULL) return;
        if(ret.size() == depth)
            ret.push_back(vector<int>());
    
        ret[depth].push_back(root->val);
        buildVector(root->left, depth + 1);
        buildVector(root->right, depth + 1);
    }
};

int main(){
	return 0;
}