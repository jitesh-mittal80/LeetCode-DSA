class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;

        int count = 0;
        int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if(row == n-1 && col == n-1){
                    return count+1;
                }

                for(auto dir : dirs){
                    int i = dir[0] + row;
                    int j = dir[1] + col;

                    if(i>=0 && i<n && j>=0 && j<n && grid[i][j] == 0){
                        grid[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
            count++;
        }

        return -1;
    }
};