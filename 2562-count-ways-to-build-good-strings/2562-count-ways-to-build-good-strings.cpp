class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // dp[i] will store the number of ways to build a string of length i
        vector<int> dp(high + 1, 0);
        dp[0] = 1; // base case: 1 way to make an empty string

        for (int i = 1; i <= high; ++i) {
            if (i >= zero) {
                dp[i] = (dp[i] + dp[i - zero]) % 1000000007; // adding '0' length string
            }
            if (i >= one) {
                dp[i] = (dp[i] + dp[i - one]) % 1000000007; // adding '1' length string
            }
        }

        int result = 0;
        // sum the number of ways to make strings between length low and high
        for (int i = low; i <= high; ++i) {
            result = (result + dp[i]) % 1000000007;
        }

        return result;
    }
};
