#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        // dp[i][j] will be true if first i characters in s match the first j characters in p
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Base case: both empty strings match
        dp[0][0] = true;
        
        // Handle patterns like "a*", "a*b*", etc. at the start of the pattern string
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2]; // '*' can match zero of the preceding element
            }
        }
        
        // Fill the dp table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    // If characters match or pattern has '.', take result from dp[i-1][j-1]
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // '*' can either match zero occurrences of the preceding character
                    dp[i][j] = dp[i][j - 2];
                    
                    // Or '*' can match one or more of the preceding character (if it matches)
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        
        // The answer is whether the entire string matches the entire pattern
        return dp[m][n];
    }
};
