class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return money(nums, 0, dp);
    }

    int money(vector<int>& nums, int i, vector<int>& dp){
        int amount = 0;
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        dp[i] = max(money(nums,i+1, dp), nums[i] + money(nums,i+2,dp));
        return dp[i];
    }
};