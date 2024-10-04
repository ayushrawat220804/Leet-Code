#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
float x = 234.324;
    int reverse(int x) {
        int reversedNum = 0;

        while (x != 0) {
            int digit = x % 10;   // Get the last digit
            x = x /  10;              // Remove the last digit

            // Check for overflow before actually adding the digit
            if (reversedNum > (INT_MAX / 10) || (reversedNum == (INT_MAX / 10) && digit > 7)) {
                return 0;  // Overflow
            }
            if (reversedNum < (INT_MIN / 10) || (reversedNum == (INT_MIN / 10) && digit < -8)) {
                return 0;  // Underflow
            }

            reversedNum = reversedNum * 10 + digit;  // Add the digit to the reversed number
        }

        return static_cast<int>(reversedNum);  // Cast the result back to int
    }
};
