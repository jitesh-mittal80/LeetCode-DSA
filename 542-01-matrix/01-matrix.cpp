class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> v(n, vector<bool>(m, false));

        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    v[i][j] = true;
                    q.push({{i,j}, 0});
                }
            }
        }
        vector<vector<int>> bfs(n, vector<int>(m, 0));
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};

        while(!q.empty()){
            int sr = q.front().first.first;
            int sc = q.front().first.second;
            int ds = q.front().second;
            q.pop();
            bfs[sr][sc] = ds;

            for(int i = 0; i<4; i++){
                int nr = sr + dr[i];
                int nc = sc + dc[i];

                if(nc >= 0 && nc < m && nr >= 0 && nr < n && !v[nr][nc]){
                    v[nr][nc] = true;
                    q.push({{nr, nc}, ds+1});
                }
            }
        }
        return bfs;
    }
};