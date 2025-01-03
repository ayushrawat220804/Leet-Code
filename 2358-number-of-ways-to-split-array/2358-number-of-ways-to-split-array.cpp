class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0, leftSum = 0;
        int count = 0;

        // Compute the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        // Iterate through the array to calculate leftSum and rightSum
        for (int i = 0; i < nums.size() - 1; ++i) {
            leftSum += nums[i];
            long long rightSum = totalSum - leftSum;

            // Check if the split is valid
            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }
};
