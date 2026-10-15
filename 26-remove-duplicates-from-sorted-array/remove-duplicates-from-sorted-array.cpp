class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        int size = 0;
        for(int i : s){
            nums[size] = i;
            size++;
        }

        return size;
    }
};