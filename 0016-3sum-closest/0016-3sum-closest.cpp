class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    // Sort the array to apply the two-pointer technique
    sort(nums.begin(), nums.end());
    
    int closestSum = INT_MAX;  // Initialize with a large value
    int minDifference = INT_MAX;  // To track the minimum difference

    // Iterate through each number as the first element of the triplet
    for (int i = 0; i < nums.size() - 2; ++i) {
        int left = i + 1;  // Initialize the left pointer
        int right = nums.size() - 1;  // Initialize the right pointer
        
        // Use two pointers to find the other two numbers
        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];
            int currentDifference = abs(currentSum - target);

            // Update closest sum if a better one is found
            if (currentDifference < minDifference) {
                closestSum = currentSum;
                minDifference = currentDifference;
            }

            // Move pointers to adjust the sum closer to the target
            if (currentSum < target) {
                ++left;  // Move left pointer right to increase the sum
            } else if (currentSum > target) {
                --right;  // Move right pointer left to decrease the sum
            } else {
                // If currentSum == target, we've found the closest possible sum
                return currentSum;
            }
        }
    }
    
    return closestSum;
        
    }
};