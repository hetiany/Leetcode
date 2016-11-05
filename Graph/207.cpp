//Find online, topo sort
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = compute_indegree(graph);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (!degrees[j]) break;
            }
            if (j == numCourses) return false;
            degrees[j] = -1;
            for (int neigh : graph[j]) {
                degrees[neigh]--;
            }
        }
        return true;
    }

    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
    
    vector<int> compute_indegree(vector<unordered_set<int>>& graph) {
        vector<int> degrees(graph.size(), 0);
        for (auto neighbors : graph)
            for (int neigh : neighbors)
                degrees[neigh]++;
        return degrees;
    }
};


//Lei, topo sort, dfs
class Solution {
private:
	vector<unordered_set<int> > graph; 
	public:
	bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) 
	{
		vector<unordered_set<int> > graph = make_graph(numCourses, prerequisites);

		vector<int> visited(numCourses, false);
		for (int i = 0;i < numCourses; ++i) {
			if (visited[i] == 0)
				if ( !dfs(graph, visited, i) ) 
					return false;
		}
		return true;
	}
	//0 : univisited, 1 : visiting , 2 : visited
	bool dfs(vector<unordered_set<int> >& graph, vector<int> & visited, int i) {
		if (0 == visited[i]) {
			visited[i] = 1;
		}
		for (auto node : graph[i]) {
			if (visited[node] == 0) {
				if (!dfs(graph, visited, node)) return false;
			} else if (visited[node] == 1) {
				return false;
			} else continue;
		}
		visited[i] = 2;
		return true;
	}
	
	vector<unordered_set<int> > make_graph(int numCourses, vector<pair<int, int> >& prerequisites) {
		vector<unordered_set<int> > graph(numCourses);
		for (auto pre : prerequisites) {
			graph[pre.second].insert(pre.first);
		} 
		return graph;
	} 
};