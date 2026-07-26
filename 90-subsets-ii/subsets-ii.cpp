class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ms(nums, 0, temp ,ans);
        return ans;
    }

    void ms(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& ans){
        if(i >= nums.size()){
            if(find(ans.begin(), ans.end(), temp) == ans.end()){
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(nums[i]);
        ms(nums, i+1, temp ,ans);
        temp.pop_back();
        ms(nums, i+1, temp ,ans);
    }
};