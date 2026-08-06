class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for(int i = 0; i<n; i++){
            total += nums[i];
        }
        vector<vector<int>> dp(n, vector<int>(2*total + 1, -1));
        return solve(nums, target, 0, 0, dp, total);
    }

    int solve(vector<int>& nums, int target, int i, int sum, vector<vector<int>>& dp, int total){
        if(i == nums.size()){
            if(sum == target){
                return 1;
            }else{
                return 0;
            }
        }

        if(dp[i][sum + total]!= -1){
            return dp[i][sum + total];
        }

        int plus = solve(nums,target, i+1, sum+nums[i], dp, total);
        int minus = solve(nums,target, i+1, sum-nums[i], dp, total);
        return dp[i][sum + total] = minus + plus;
    }
};