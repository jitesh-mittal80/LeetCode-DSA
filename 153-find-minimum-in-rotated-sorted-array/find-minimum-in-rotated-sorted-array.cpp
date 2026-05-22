class Solution {
public:
    int findMin(vector<int>& nums) {
        int gmin = nums[0];

        for (int i = 1; i< nums.size(); i++){
            int localmin = nums[i];
            gmin = min(localmin, gmin);
        }

        return gmin;
    }
};