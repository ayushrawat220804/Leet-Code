#include <iostream>
#include <vector>
#include <algorithm> // Include this header for the find function

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        // Iterate through the vector using an iterator
        for (auto it1 = nums.begin(); it1 != nums.end(); ++it1) {
            // Use the find function to locate the target value
            auto it2 = find(it1 + 1, nums.end(), target - *it1);
            if (it2 != nums.end()) { // If the target value is found
                // Calculate the indices and add them to the result vector
                result.push_back(it1 - nums.begin());
                result.push_back(it2 - nums.begin());
                break; // Exit the loop once the pair is found
            }
        }
        return result; // Return the result vector
    }
};

