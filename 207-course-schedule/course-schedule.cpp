class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& path) {

        visited[node] = 1;
        path[node] = 1;

        for(int neighbour : adj[node]) {

            if(!visited[neighbour]) {
                if(dfs(neighbour, adj, visited, path))
                    return true;
            }

            else if(path[neighbour]) {
                return true;
            }
        }

        path[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites) {
            int course = it[0];
            int prerequisite = it[1];

            adj[prerequisite].push_back(course);
        }

        vector<int> visited(numCourses, 0);
        vector<int> path(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {

            if(!visited[i]) {
                if(dfs(i, adj, visited, path))
                    return false;
            }
        }

        return true;
    }
};