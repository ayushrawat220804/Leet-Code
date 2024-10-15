class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Edge case: return an empty result if the input is empty
        if (digits.empty()) {
            return {};
        }
        
        // Mapping of digits to their corresponding letters
        const vector<string> digitToLetters = {
            "",    // 0 (no letters)
            "",    // 1 (no letters)
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs",// 7
            "tuv", // 8
            "wxyz" // 9
        };
        
        vector<string> result;    // To store the result of all combinations
        string currentCombination; // To build individual combinations
        
        // Call the helper function to perform backtracking
        backtrack(digits, 0, currentCombination, result, digitToLetters);
        
        return result;
    }
    
public:
    // Helper function to perform backtracking
    void backtrack(const string& digits, int index, string& currentCombination, vector<string>& result, const vector<string>& digitToLetters) {
        // Base case: if the current combination's length is equal to the input digits
        if (index == digits.size()) {
            result.push_back(currentCombination); // Add the combination to the result
            return;
        }
        
        // Get the letters corresponding to the current digit
        string letters = digitToLetters[digits[index] - '0'];
        
        // Iterate over the letters and append each to the current combination
        for (char letter : letters) {
            currentCombination.push_back(letter);      // Choose the letter
            backtrack(digits, index + 1, currentCombination, result, digitToLetters); // Explore the next digit
            currentCombination.pop_back();             // Unchoose the letter (backtrack)
        }
    }
};
