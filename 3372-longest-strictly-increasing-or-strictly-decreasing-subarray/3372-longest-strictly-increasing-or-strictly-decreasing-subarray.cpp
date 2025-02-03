class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.size() < 2){
            return nums.size();
        } 
        int longest = 1, increase = 1, decrease = 1;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
            // Strictly increasing
            increase++;
            decrease = 1;  // Reset decreasing subarray
            }else if (nums[i] < nums[i - 1]) {
                // Strictly decreasing
                decrease++;
                increase = 1;  // Reset increasing subarray
                }
                else {
                    // Reset both subarrays if equal
                    increase = 1;
                    decrease = 1;
                }
            

            // update longest subaray
            longest = max(longest, max(increase, decrease));
        }
        return longest;
    
    }
};