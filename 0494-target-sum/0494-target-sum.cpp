class Solution {
public:
    // Use a helper function outside of the main function
    int dfs(int index, int currentSum, vector<int>& nums, int target, unordered_map<string, int>& memo) {
        if (index == nums.size()) {
            return currentSum == target ? 1 : 0;
        }

        // Memoization key
        string key = to_string(index) + "," + to_string(currentSum);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // Calculate the number of ways by adding and subtracting the current number
        int add = dfs(index + 1, currentSum + nums[index], nums, target, memo);
        int subtract = dfs(index + 1, currentSum - nums[index], nums, target, memo);

        // Store result in memo
        memo[key] = add + subtract;
        return memo[key];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo;
        return dfs(0, 0, nums, target, memo);
    }
};
