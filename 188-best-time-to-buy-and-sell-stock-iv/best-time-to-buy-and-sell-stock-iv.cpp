class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(k, prices, 0, 1, dp);
    }

    int solve(int k, vector<int>& prices, int i, int buy, vector<vector<vector<int>>>& dp){
        if(i == prices.size() || k == 0){
            return 0;
        }

        if(dp[i][buy][k] != -1){
            return dp[i][buy][k];
        }

        if(buy){
            int take = -prices[i] + solve(k, prices, i+1, 0, dp);
            int nottake = solve(k, prices, i+1, 1, dp);

            return dp[i][buy][k] = max(take, nottake);
        }else{
            int take = prices[i] + solve(k - 1, prices, i+1, 1, dp);
            int nottake = solve(k, prices, i+1, 0, dp);

            return dp[i][buy][k] = max(take, nottake);
        }
    }
};