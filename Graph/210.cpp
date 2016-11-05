//Lei
class Solution {
public:
    vector<unordered_set<int> > make_graph(int numCourses, vector<pair<int, int> > & prerequisites ) {
        vector<unordered_set<int> > graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
     
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> res;
        vector<unordered_set<int> > graph;
        graph = make_graph(numCourses, prerequisites);
        vector<int> visited(numCourses, 0);   //0 unvisited, 1 being visited, 2 visited;
        for (int i = 0; i < numCourses; ++i) {
            //if (visited[i] == 2) continue;
            if (visited[i] == 0) {
                if (!dfs(graph, visited, res, i)) return {};
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(vector<unordered_set<int> >& graph, vector<int> & visited, vector<int> & res, int start) {
        visited[start] = 1;
        for (auto nei : graph[start]) {
            if(visited[nei] == 1) return false;
            if (visited[nei] == 2) continue;
            if(!dfs(graph, visited, res, nei)) return false;
        }
        res.push_back(start);
        visited[start] = 2;
        return true;
    }
};




//changed by online
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = compute_indegree(graph);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (!degrees[j]) break;
            }
            if (j == numCourses) {
                res.clear();
                return res;
            }
            res.push_back(j);
            degrees[j] = -1;
            for (int neigh : graph[j]) {
                degrees[neigh]--;
            }
        }
        return res;
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
