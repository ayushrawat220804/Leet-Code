class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // start end() -> destination, begin() -> source-start, end() -> source-end
        nums.insert(nums.end(), nums.begin(), nums.end());
        return nums;
    }
};