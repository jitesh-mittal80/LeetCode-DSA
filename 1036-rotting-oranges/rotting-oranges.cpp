class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else if(grid[i][j] == 1){
                    visited[i][j] = 1;
                }
            }
        }

        int ans = 0;

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};

        while(!q.empty()){

            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            ans = max(ans, t);

            q.pop();

            for(int i = 0; i < 4; i++){

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   visited[nr][nc] == 1){

                    visited[nr][nc] = 2;

                    q.push({{nr, nc}, t + 1});
                }
            }
        }

        // Check if any fresh orange remains
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j] == 1)
                    return -1;
            }
        }

        return ans;
    }
};
