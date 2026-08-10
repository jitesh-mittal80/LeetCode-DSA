class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, 1, dp);
    }

    int solve(vector<int>& prices, int i, int buy, vector<vector<int>>& dp){
        if(i == prices.size()){
            return 0;
        }

        if(buy){
            if(dp[i][buy] != -1){
                return dp[i][buy];
            }
            int take = -prices[i] + solve(prices, i+1, 0, dp);
            int nottake = solve(prices, i+1, 1, dp);

            return dp[i][buy] = max(take, nottake);
        }else{
            if(dp[i][buy] != -1){
                return dp[i][buy];
            }
            int take = prices[i] + solve(prices, i+1, 1, dp);
            int nottake = solve(prices, i+1, 0, dp);

            return dp[i][buy] = max(take, nottake);
        }
    }
};