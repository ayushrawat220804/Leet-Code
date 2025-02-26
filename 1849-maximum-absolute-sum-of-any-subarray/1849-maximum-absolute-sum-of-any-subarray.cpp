class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

    int maxSum = 0, minSum = 0;
    int currMax = 0, currMin = 0;

    for (int num : nums) {
        currMax = max(0, currMax + num);  // Kadane’s for max sum
        currMin = min(0, currMin + num);  // Kadane’s for min sum
        maxSum = max(maxSum, currMax);
        minSum = min(minSum, currMin);
    }

    return max(abs(maxSum), abs(minSum));  // Take the max absolute sum
        
    }
};