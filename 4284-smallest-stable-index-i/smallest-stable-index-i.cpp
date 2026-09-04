class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int mi = *max_element(nums.begin(), nums.begin() + i + 1);
            int mn = *min_element(nums.begin() + i, nums.end());

            int s = mi - mn;

            if(s <= k){
                return i;
            }
        }

        return -1;
    }
};