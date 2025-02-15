class Solution {
public:
    bool canPartition(string num, int index, int target) {
        if (index == num.size()) {
            return target == 0;
        }
        
        int sum = 0;
        for (int i = index; i < num.size(); ++i) {
            sum = sum * 10 + (num[i] - '0');  // Forming the substring as a number
            if (sum > target) break;          // Early exit if sum exceeds target
            if (canPartition(num, i + 1, target - sum)) return true;
        }
        
        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            string squareStr = to_string(square);

            if (canPartition(squareStr, 0, i)) {
                sum += square;
            }
        }
        return sum;
    }
};