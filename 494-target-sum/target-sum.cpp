class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, 0);
    }

    int solve(vector<int>& nums, int target, int i, int sum){
        if(i == nums.size()){
            if(sum == target){
                return 1;
            }else{
                return 0;
            }
        }

        int plus = solve(nums,target, i+1, sum+nums[i]);
        int minus = solve(nums,target, i+1, sum-nums[i]);
        return minus + plus;
    }
};