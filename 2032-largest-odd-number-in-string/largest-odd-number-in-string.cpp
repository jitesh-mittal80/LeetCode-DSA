class Solution {
public:
    string largestOddNumber(string num) {
        string ans;
        int l = num.length();

        for (int i = l-1; i >= 0; i--){

            if ((num[i] - '0') % 2 == 1){
                ans = num.substr(0, i+1);
                return ans;
            }
        }

        return ans;
    }
};