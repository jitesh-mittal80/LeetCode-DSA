class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        for(int j = 0; j<m; j++){
            ans = min(ans, minsum(matrix,0,j,n,m,dp));
        }
        return ans;
    }

    int minsum(vector<vector<int>>& matrix, int i, int j, int n, int m, vector<vector<int>>& dp){
        if(i == n-1){
            return matrix[i][j];
        }

        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }

        int dig1 = INT_MAX;
        int dig2 = INT_MAX;
        if(j>0){
            dig1 = minsum(matrix, i+1, j-1, n, m,dp);
        }
        if(j<m-1){
            dig2 = minsum(matrix, i+1, j+1, n, m,dp);
        }
        int down = minsum(matrix, i+1, j, n, m,dp);

        return dp[i][j] = matrix[i][j] + min({dig1, dig2, down});
    }
};