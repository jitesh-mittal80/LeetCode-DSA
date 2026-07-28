class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }

        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);
        int end1 = nums.size() - 1;
        int end2 = nums.size() - 2;
        return max(money(nums, 0, dp1, end2), money(nums,1,dp2,end1));
    }

    int money(vector<int>& nums, int i, vector<int>& dp, int end){
        if(i > end){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        dp[i] = max(money(nums,i+2,dp,end) + nums[i], money(nums,i+1,dp,end));
        return dp[i];
    }
};