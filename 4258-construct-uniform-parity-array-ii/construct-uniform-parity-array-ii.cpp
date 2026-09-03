class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int modd = INT_MAX;
        int n = nums1.size();

        for(int i = 0; i<n; i++){
            if(nums1[i]%2){
                modd = min(modd, nums1[i]);
            }
        }

        if(modd == INT_MAX) return true;

        for(int i = 0; i<n; i++){
            if(nums1[i]%2 == 0 && nums1[i] < modd){
                return false;
            }
        }

        return true;
    }
};