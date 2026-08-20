class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;

        int ic = image[sr][sc];
        if(ic == color) return image;
        q.push({sr, sc});

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};
        image[sr][sc] = color;
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i = 0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == ic){
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};