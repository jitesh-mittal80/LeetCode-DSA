class Solution {
public:
    bool search(vector<int>& nums, int target) {
        bool result = false;
        for (int i = 0; i<nums.size(); i++){
            if (nums[i] == target){
                result = true;
                break;
            }
        }
        return result;
    }
};