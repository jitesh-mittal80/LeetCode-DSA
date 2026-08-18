class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n+1, 0);
        int count = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                count++;
                bfs(isConnected, i, vis);
            }
        }
        return count;
    }

    void bfs(vector<vector<int>>& isConnected, int start, vector<int>& vis){
        int n = isConnected.size();

        queue<int> q;

        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i = 0; i<n; i++){
                if(isConnected[node][i] == 1 && !vis[i]){
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }
};