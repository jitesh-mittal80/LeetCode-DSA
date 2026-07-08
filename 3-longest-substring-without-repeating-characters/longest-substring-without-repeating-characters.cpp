class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int temp = 0;
        int ans = 0;
        string result = "";

        for (char c : s){
            if (result.empty()){
                result.push_back(c);
                ans = 1;
            }

            else if (result.find(c) != string::npos){
                int duplicate_index = result.find(c);
                result.erase(0,duplicate_index+1);
                result.push_back(c);
                temp = result.length();
                ans = max(ans, temp);
            }else {
                result.push_back(c);
                temp = result.length();
                ans = max(ans, temp);
            }
        }

        return ans;
    }
};