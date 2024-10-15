class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        
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
        
        vector<string> result;
        string currentCombination;
        backtrack(digits, 0, currentCombination, result, digitToLetters);
        return result;
    }
    
    // Helper function is now public
private:
    void backtrack(const string& digits, int index, string& currentCombination, vector<string>& result, const vector<string>& digitToLetters) {
        if (index == digits.size()) {
            result.push_back(currentCombination);
            return;
        }
        
        string letters = digitToLetters[digits[index] - '0'];
        
        for (char letter : letters) {
            currentCombination.push_back(letter); 
            backtrack(digits, index + 1, currentCombination, result, digitToLetters);
            currentCombination.pop_back();         
        }
    }
};
