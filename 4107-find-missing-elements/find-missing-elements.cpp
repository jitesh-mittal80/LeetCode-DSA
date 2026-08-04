class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mine = INT_MAX;
        int maxe = INT_MIN;

        unordered_set<int> s;

        for (int num : nums) {
            mine = min(mine, num);
            maxe = max(maxe, num);
            s.insert(num);
        }

        vector<int> ans;

        for (int num = mine; num <= maxe; num++) {
            if (s.find(num) == s.end()) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};