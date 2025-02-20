class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> numSet(nums.begin(), nums.end());// Store nums in set for quick lookup

        // Generate all possible binary strings of length n
        for (int i = 0; i < (1 << n); ++i) {
            string candidate = "";
            for (int j = n - 1; j >= 0; --j) {
                candidate += ((i >> j) & 1) ? '1' : '0';  // Convert integer to binary string
            }
            
            // If this string is not in nums, return it
            if (numSet.find(candidate) == numSet.end()) {
                return candidate;
            }
        }
        
        return ""; // This will never be reached since there must be an answer
        
    }
};