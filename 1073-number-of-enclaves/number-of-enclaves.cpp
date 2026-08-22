class Solution {
public:

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& v){
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m || v[i][j] || grid[i][j] == 0){
            return;
        }
        v[i][j] = true;
        dfs(i+1, j, grid, v);
        dfs(i-1, j, grid, v);
        dfs(i, j-1, grid, v);
        dfs(i, j+1, grid, v);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> v(n, vector<bool>(m, false));
        for(int i = 0; i<n; i++){
            if(grid[i][0] == 1 && !v[i][0]){
                dfs(i, 0, grid, v);
            }
            if(grid[i][m-1] == 1 && !v[i][m-1]){
                dfs(i, m-1, grid, v);
            }
        }

        for(int j = 0; j<m; j++){
            if(grid[0][j] == 1 && !v[0][j]){
                dfs(0, j, grid, v);
            }
            if(grid[n-1][j] == 1 && !v[n-1][j]){
                dfs(n-1, j, grid, v);
            }
        }
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && !v[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};