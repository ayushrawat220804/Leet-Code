class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            vector<int> rotated(nums.begin() + i, nums.end());  // Rotate right part
            rotated.insert(rotated.end(), nums.begin(), nums.begin() + i);  // Append left part
            if (is_sorted(rotated.begin(), rotated.end()))  // Check if sorted
            return true;
        }
        return false;
    }
};