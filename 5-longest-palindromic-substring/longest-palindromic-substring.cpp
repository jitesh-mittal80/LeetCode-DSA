class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        int start = 0;
        int mlen = 1;
        for(int i = 0; i<n; i++){
            for(int j = n-1; j >=0; j--){
                if(ispal(s, i, j, dp)){
                    if(j-i+1 > mlen){
                        mlen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, mlen);
    }

    bool ispal(string& s, int i, int j, vector<vector<int>>& dp){
        if(i >= j){
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] != s[j]){
            return dp[i][j] = false;
        }
        return dp[i][j] = ispal(s, i+1, j-1, dp);
    }
};