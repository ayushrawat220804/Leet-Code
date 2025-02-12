// approach brute force 
// time complexity = o(n^2) first loop for digit some, second loop for indexing
// space complexity = o(n) checking pair sum using digit sum
// Function to calculate sum of digits
int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

class Solution {
public:
    int maximumSum(vector<int>& nums) {

    unordered_map<int, int> digitSumMap;
    int maxSum = -1;

    for (int num : nums) {
        int sumDigits = digitSum(num);
        
        // If the sum already exists, calculate max sum
        if (digitSumMap.count(sumDigits)) {
            maxSum = max(maxSum, digitSumMap[sumDigits] + num);
        }
        
        // Store the maximum number for this digit sum
        digitSumMap[sumDigits] = max(digitSumMap[sumDigits], num);
    }
    
    return maxSum;
        
    }
};