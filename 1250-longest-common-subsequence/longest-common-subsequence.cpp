class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1 = text1.size();
        int t2 = text2.size();
        vector<vector<int>> dp(t1, vector<int>(t2, -1));
        return lcs(text1, text2, 0, 0, dp);
    }

    int lcs(string& text1, string& text2, int i, int j, vector<vector<int>>& dp){
        if(i == text1.size() || j == text2.size()){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(text1[i] == text2[j]){
        return dp[i][j] = 1 + lcs(text1, text2, i+1, j+1, dp);
        }

        return dp[i][j] = max(lcs(text1, text2, i+1, j, dp), lcs(text1, text2, i, j+1, dp));
    }
};