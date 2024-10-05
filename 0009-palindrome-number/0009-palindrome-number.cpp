class Solution {
public:
    bool isPalindrome(int x) {
        // Step 1: Handle negative numbers and numbers ending with 0 (but not zero itself)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        // Step 2: Reverse half of the number
        int reversed_half = 0;
        while (x > reversed_half) {
            reversed_half = reversed_half * 10 + x % 10;
            x /= 10;
        }

        // Step 3: Check if the first half equals the reversed second half
        // For odd-length numbers, discard the middle digit by reversed_half / 10
        return x == reversed_half || x == reversed_half / 10;
    }
};
