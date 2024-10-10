class Solution {
public:
    string intToRoman(int num) {
        // Define the Roman numeral symbols and their corresponding values
        vector<pair<int, string>> valueSymbols = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };
        
        string result = "";
        
        // Iterate through the value-symbol pairs from largest to smallest
        for (const auto &valSymbol : valueSymbols) {
            // While num is greater than or equal to the current value
            while (num >= valSymbol.first) {
                result += valSymbol.second; // Add the Roman numeral symbol to result
                num -= valSymbol.first;     // Subtract the value from num
            }
        }
        
        return result;
    }
};
