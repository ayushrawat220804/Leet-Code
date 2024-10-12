class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    // Loop over each character of the first string
    for (int i = 0; i < strs[0].length(); i++) {
        char c = strs[0][i];  // Take the i-th character of the first string
        
        // Compare this character with the i-th character of each string
        for (int j = 1; j < strs.size(); j++) {
            // If the i-th character doesn't match or we run out of characters in strs[j]
            if (i >= strs[j].length() || strs[j][i] != c) {
                return strs[0].substr(0, i);  // Return the common prefix so far
            }
        }
    }
    
    // If all characters of the first string are matched, return the full string
    return strs[0];
    }

};