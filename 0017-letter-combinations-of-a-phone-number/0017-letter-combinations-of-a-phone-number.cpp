class Solution {
    // Helper function to generate combinations recursively
    void solve(string digit, string output, int index, vector<string>& ans, string mapping[]) {
        // Base case: if we've processed all the digits, store the output
        if (index >= digit.length()) {
            ans.push_back(output);
            return;
        }
        
        // Convert the current digit character to an integer (e.g., '2' -> 2)
        int number = digit[index] - '0';
        string value = mapping[number];   // Get the corresponding string of letters
        
        // Loop through all characters in the corresponding string
        for (int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);   // Choose a character
            solve(digit, output, index + 1, ans, mapping); // Recursively process the next digit
            output.pop_back();            // Backtrack to remove the last character
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0)  // Handle the case of an empty input string
            return ans;
        
        string output = "";  // Initialize the output string (without space)
        int index = 0;
        
        // Mapping of digits to their corresponding letters
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        // Start the recursive solving process
        solve(digits, output, index, ans, mapping);
        
        return ans;
    }
};
