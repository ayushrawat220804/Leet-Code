class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxLeft = values[0]; // Initialize maxLeft with the first element + index
        int maxScore = INT_MIN; // Initialize the maximum score to a very small value

        for (int j = 1; j < values.size(); ++j) {
            // Calculate the score for the current pair
            maxScore = max(maxScore, maxLeft + values[j] - j);

            // Update maxLeft for the next iteration
            maxLeft = max(maxLeft, values[j] + j);
        }

        return maxScore;
    }
};
