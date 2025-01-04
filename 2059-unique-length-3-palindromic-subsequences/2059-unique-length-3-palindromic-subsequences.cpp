class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> firstOccurrence(26, -1);
        vector<int> lastOccurrence(26, -1);
        int n = s.size();

        // Populate first and last occurrence for each character
        for (int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';
            if (firstOccurrence[ch] == -1) {
                firstOccurrence[ch] = i;
            }
            lastOccurrence[ch] = i;
        }

        int count = 0;

        // Check for unique palindromic subsequences
        for (int ch = 0; ch < 26; ++ch) {
            if (firstOccurrence[ch] != -1 && lastOccurrence[ch] > firstOccurrence[ch]) {
                unordered_set<char> uniqueMiddle;

                // Collect unique middle characters
                for (int i = firstOccurrence[ch] + 1; i < lastOccurrence[ch]; ++i) {
                    uniqueMiddle.insert(s[i]);
                }

                // Add the size of the unique middle set to the count
                count += uniqueMiddle.size();
            }
        }

        return count;
    }
};
