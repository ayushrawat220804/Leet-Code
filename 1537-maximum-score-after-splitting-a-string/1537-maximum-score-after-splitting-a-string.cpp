class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int countLeftZeros = 0; // Count of zeros on the left
        int countRightOnes = 0; // Count of ones on the right
        // Count all the '1's in the string for the initial right part
        for (char c : s) {
            if (c == '1') countRightOnes++;
        }
        int maxScore = 0;
        // Iterate through valid split points (1 to n-1)
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '0') {
                countLeftZeros++;
            } else {
                countRightOnes--;
            }
            // Calculate the score for the current split
            maxScore = max(maxScore, countLeftZeros + countRightOnes);
        }
        return maxScore;
    }
};