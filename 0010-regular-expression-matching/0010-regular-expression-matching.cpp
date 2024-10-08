#include <vector>
#include <string>
using namespace std;

// Function for string matching with dynamic programming
int stringMatch(vector<vector<int>> &dp, string &s, string &p, int len_s, int len_p) {
    if (len_s == 0 && len_p == 0) {
        return 1; // We have completely matched the string `s` and pattern `p`.
    }
    if (len_p == 0) {
        return 0; // If pattern is exhausted but string is not, it's a mismatch.
    }
    
    // If already computed, return the cached result.
    if (dp[len_s][len_p] != -1) {
        return dp[len_s][len_p];
    }
    
    // Handle '*' case
    if (p[len_p - 1] == '*') {
        int res = stringMatch(dp, s, p, len_s, len_p - 2); // Consider zero occurrence of the char before '*'
        int len_rep = 0;
        while (len_s - len_rep > 0 && (s[len_s - len_rep - 1] == p[len_p - 2] || p[len_p - 2] == '.')) {
            len_rep++;
            res = res | stringMatch(dp, s, p, len_s - len_rep, len_p - 2); // Consider repeated occurrences
        }
        return dp[len_s][len_p] = res; // Store and return the result
    }
    
    // Handle when len_s is 0 but len_p is not exhausted
    if (len_s == 0) {
        return dp[len_s][len_p] = 0;
    }
    
    // Handle direct character match or '.'
    if (p[len_p - 1] == '.' || s[len_s - 1] == p[len_p - 1]) {
        return dp[len_s][len_p] = stringMatch(dp, s, p, len_s - 1, len_p - 1);
    }

    // If no match
    return dp[len_s][len_p] = 0;
}

class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.length(), len_p = p.length();
        
        // dp table initialized with -1 for memoization
        vector<vector<int>> dp(len_s + 1, vector<int>(len_p + 1, -1));
        
        // Call the recursive matching function
        return stringMatch(dp, s, p, len_s, len_p);
    }
};
