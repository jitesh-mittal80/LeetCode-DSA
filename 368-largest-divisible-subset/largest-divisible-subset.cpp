class Solution {
public:

    vector<int> dp;

    int solve(int i, vector<int>& nums) {

        if (dp[i] != -1)
            return dp[i];

        int ans = 1;

        for (int j = i + 1; j < nums.size(); j++) {

            if (nums[j]%nums[i] == 0) {
                ans = max(ans, 1 + solve(j, nums));
            }
        }

        return dp[i] = ans;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        dp.assign(n, -1);

        for (int i = 0; i < n; i++) {
            solve(i, nums);
        }

        int L = 0;

        for (int i = 0; i < n; i++) {
            L = max(L, dp[i]);
        }

        vector<int> ans;

        int prevIndex = -1;
        int remaining = L;

        while (remaining > 0) {

            for (int i = prevIndex + 1; i < n; i++) {

                if (prevIndex != -1 && nums[i] <= nums[prevIndex])
                    continue;

                if (prevIndex == -1 || nums[i] % nums[prevIndex] == 0) {
                    if (dp[i] >= remaining){
                        ans.push_back(nums[i]);
                        prevIndex = i;
                        remaining--;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};