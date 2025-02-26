class Solution {
public:
    int m = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int oddCount = 0;   // Count of subarrays with an odd sum
        int evenCount = 1;  // Consider sum of zero as even
        int prefixSum = 0;  
        int result = 0;     
        for (int num : arr) {
            prefixSum += num;
            if (prefixSum % 2 == 0) {
                // If the prefix sum is even, it can form odd subarrays with previous odd prefix sums
                result = (result + oddCount) % m;
                evenCount++;  
            } else {
                // If the prefix sum is odd, it can form odd subarrays with previous even prefix sums
                result = (result + evenCount) % m;
                oddCount++;  
            }
        }
        return result;
    }
};