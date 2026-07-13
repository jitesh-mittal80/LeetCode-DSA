class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int i = 0;
        int odd = 0;
        int ans = 0;

        for (int j = 0; j < nums.size(); j++) {

            if (nums[j] % 2)
                odd++;

            while (odd > k) {
                if (nums[i] % 2)
                    odd--;
                i++;
            }

            ans += (j - i + 1);
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};