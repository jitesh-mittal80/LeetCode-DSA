class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int final_index = 1;
        vector<int> v(s.begin(), s.end());
        int n = v.size();

        int current = 1;

        for (int i = 1; i<n; i++){
            if (v[i] - v[i-1] == 1){
                current++;
            }

            else{
                current = 1;
            }

            final_index = max(final_index, current);

        }
        if (v.empty()){
            return 0;
        }
        else{
            return final_index;
        }

        return -1;
    }
};