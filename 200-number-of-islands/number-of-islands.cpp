class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        int count = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1'){
                    if(!vis[i][j]){
                        count++;
                        q.push({i, j});
                        vis[i][j] = true;

                        vector<int> dr = {-1, 0, 1, 0};
                        vector<int> dc = {0, -1, 0, 1};

                        while(!q.empty()){
                            int r = q.front().first;
                            int c = q.front().second;
                            q.pop();
                            for(int k = 0; k<4; k++){
                                int nr = r + dr[k];
                                int nc = c + dc[k];

                                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == '1'){
                                    q.push({nr, nc});
                                    vis[nr][nc] = true;
                                }
                            }                      
                        }
                    }
                }
            }
        }
        return count;
    }
};