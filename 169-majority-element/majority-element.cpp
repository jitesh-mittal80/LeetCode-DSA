class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count;
        int target;
        int n = nums.size();

        for (int i = 0; i<n; i++){
            target = nums[i];
            count = 0;
            for (int j = 0; j<n; j++){
                if (nums[j] == target){
                    count++;
                }
            }
            if (count > (n/2)){
                return nums[i];
            }
        }

        return -1;
    }
};