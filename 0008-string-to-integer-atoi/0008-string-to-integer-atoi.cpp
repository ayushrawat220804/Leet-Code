class Solution {
public:
    int myAtoi(string s) {
    int i = 0;
    int n = s.size();
    // Step 1: Skip leading whitespaces
    while (i < n && s[i] == ' ') {
        i++;
    }
    
    // Step 2: Handle sign if any
    int sign = 1;  // Positive by default
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    
    // Step 3: Convert characters to integer
    long long result = 0;
    while (i < n && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');
        
        // Step 4: Handle overflow and clamp the result
        if (result * sign >= INT_MAX) {
            return INT_MAX;
        } else if (result * sign <= INT_MIN) {
            return INT_MIN;
        }
        i++;
    }
    
    return result * sign;
        
    }
};