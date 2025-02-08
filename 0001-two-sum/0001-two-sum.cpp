class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
            std::unordered_map<int, int> num_map; // Map to store the number and its index
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // Find the complement
        
        // Check if the complement exists in the map
        if (num_map.find(complement) != num_map.end()) {
            // If found, return the indices of the two numbers
            return {num_map[complement], i};
        }
        
        // Otherwise, add the number to the map with its index
        num_map[nums[i]] = i;
    }
    
    // If no solution is found, return an empty vector (though the problem guarantees one solution)
    return {};
        
    }
int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = twoSum(nums, target);
    
    // Print the result
    std::cout << "Indices: [" << result[0] << ", " << result[1] << "]\n";
    return 0;
}

};