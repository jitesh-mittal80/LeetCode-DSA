class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp(n ,vector<int>(m,INT_MAX));
        return minsum(triangle, 0, 0, dp);
    }

    int minsum(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp){
        if(i == triangle.size()-1){
            return triangle[i][j];
        }

        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }

        int down = minsum(triangle, i+1, j, dp);
        int dig = minsum(triangle, i+1, j+1, dp);

        return dp[i][j] = triangle[i][j]+min(down, dig);
    }
};