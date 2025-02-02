class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] > nums[(i + 1) % n])  // Compare with next (circular check)
                count++;
        return count <= 1;  // At most one descending pair
    }
};