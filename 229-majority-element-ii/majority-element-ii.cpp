class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        unordered_map<int, int> majority;

        for (int i = 0; i<n ; i++){
            majority[nums[i]]++;
        }

        for (auto it : majority){
            if (it.second > n/3){
                result.push_back(it.first);
            }
        }

        return result;
    }
};