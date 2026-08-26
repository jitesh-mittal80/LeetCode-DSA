class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);

        for(int start = 0; start < n; start++) {
            if(vis[start] != -1){
                continue;
            }
            queue<int> q;
            vis[start] = 0;

            q.push(start);

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(int neighbor : graph[node]) {

                    if(vis[neighbor] == -1) {
                        vis[neighbor] = 1 - vis[node];
                        q.push(neighbor);
                    }else if(vis[neighbor] == vis[node]){
                        return false;
                    }
                }
            }
        }

        return true;    
    }
};