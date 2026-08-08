class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int lcsLength = lcs(word1, word2, 0, 0, dp);

        return n + m - 2 * lcsLength;
    }

    int lcs(string& s1, string& s2, int i, int j,
            vector<vector<int>>& dp) {

        if (i == s1.size() || j == s2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + lcs(s1, s2, i + 1, j + 1, dp);
        }

        return dp[i][j] = max(
            lcs(s1, s2, i + 1, j, dp),
            lcs(s1, s2, i, j + 1, dp)
        );
    }
};