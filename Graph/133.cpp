/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
//Lei
class Solution {
public:
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;

	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node) return NULL;
		UndirectedGraphNode * copy = new UndirectedGraphNode(node -> label);
		mp[node] = copy;
		queue<UndirectedGraphNode* > toVisit;
		toVisit.push(node);
		while(!toVisit.empty()){
			UndirectedGraphNode * cur = toVisit.front();
			toVisit.pop();
			for (auto nei : cur -> neighbors) {
			        if (mp.count(nei) == 0) {
			            UndirectedGraphNode* neigh = new UndirectedGraphNode (nei -> label);
			            mp[nei] = neigh;
			            toVisit.push(nei);
			            
			        }
			        mp[cur] -> neighbors.push_back(mp[nei]);
			    }

		}
		return copy;
	}
};