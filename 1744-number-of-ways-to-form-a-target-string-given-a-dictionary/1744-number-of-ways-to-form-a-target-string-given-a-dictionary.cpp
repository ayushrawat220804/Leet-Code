class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        int m = target.size();
        int n = words[0].size();

        // Precompute the frequency of each character in each column
        vector<vector<int>> freq(26, vector<int>(n, 0));
        for (const string& word : words) {
            for (int j = 0; j < n; ++j) {
                freq[word[j] - 'a'][j]++;
            }
        }

        // Dynamic Programming table
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        
        // Base cases
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = 1; // 1 way to form an empty target
        }

        // Fill DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // Skip the current column
                dp[i][j] = dp[i][j-1];
                
                // Use the current column if it matches target[i-1]
                char targetChar = target[i-1];
                if (freq[targetChar - 'a'][j-1] > 0) {
                    dp[i][j] += dp[i-1][j-1] * freq[targetChar - 'a'][j-1];
                    dp[i][j] %= MOD;
                }
            }
        }

        return dp[m][n];
    }
};
