class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(5,-1)));
        return solve(prices, 0, 1, 0, dp);
    }

    int solve(vector<int>& prices, int i, int buy, int count, vector<vector<vector<int>>>& dp){
        if(i == prices.size()){
            return 0;
        }

        if(count > 4){
            return 0;
        }

        if(dp[i][buy][count] != -1){
            return dp[i][buy][count];
        }

        if(buy){
            int take = -prices[i] + solve(prices, i+1, 0, count+1, dp);
            int nottake = solve(prices, i+1, 1, count, dp);

            return dp[i][buy][count] = max(take, nottake);
        }else{
            int take = prices[i] + solve(prices, i+1, 1, count+1, dp);
            int nottake = solve(prices, i+1, 0, count, dp);

            return dp[i][buy][count] = max(take, nottake);
        }
    }
};