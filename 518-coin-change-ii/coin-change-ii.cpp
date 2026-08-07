class Solution {
public:
    int change(int amount, vector<int>& coins){
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans =  solve(coins, amount, 0, dp);
        return ans;
    }

    int solve(vector<int>& coins, int amount, int i, vector<vector<int>>& dp){
        if(amount == 0){
            return 1;
        }

        if(i == coins.size()){
            return 0;
        }

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        int take = 0;
        if(coins[i] <= amount){
            take = solve(coins, amount - coins[i], i, dp);
        }
        int nottake = solve(coins, amount, i+1, dp);
        return dp[i][amount] = take + nottake;
    }
};