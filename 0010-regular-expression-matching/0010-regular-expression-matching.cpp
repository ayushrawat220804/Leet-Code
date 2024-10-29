class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.length(), len_p = p.length();
        vector<vector<bool>> dp(len_s + 1, vector<bool>(len_p + 1, false));
        dp[0][0] = true; // An empty pattern matches an empty string

        // Initialize dp for patterns like a*, a*b*, a*b*c* (to match empty string)
        for (int j = 1; j <= len_p; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2]; // '*' can match zero of the previous element
            }
        }

        // Fill the DP table
        for (int i = 1; i <= len_s; ++i) {
            for (int j = 1; j <= len_p; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1]; // Match single character or '.'
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || // '*' matches zero of the previous element
                               (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')); // '*' matches one or more
                }
            }
        }

        return dp[len_s][len_p]; // The result is in the bottom-right cell of the DP table
    }
};
