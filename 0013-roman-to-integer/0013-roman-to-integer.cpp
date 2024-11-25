class Solution {
public:
    int romanToInt(string s) {
        // Array to store the integer values of Roman numerals using ASCII offsets
        int romanValues[128] = {};
        romanValues['I'] = 1;
        romanValues['V'] = 5;
        romanValues['X'] = 10;
        romanValues['L'] = 50;
        romanValues['C'] = 100;
        romanValues['D'] = 500;
        romanValues['M'] = 1000;

        int result = 0;
        int n = s.size();

        // Loop through the string
        for (int i = 0; i < n; ++i) {
            int currentVal = romanValues[s[i]];

            // If the current value is less than the next value, subtract it
            if (i < n - 1 && currentVal < romanValues[s[i + 1]]) {
                result -= currentVal;
            } 
            // Otherwise, add the current value
            else {
                result += currentVal;
            }
        }

        return result;
    }
};
