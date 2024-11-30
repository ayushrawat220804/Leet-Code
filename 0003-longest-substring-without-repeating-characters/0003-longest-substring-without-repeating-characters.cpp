class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), p1 = 0, p2 = 0, ans = 0;
        // Base case: if the string is empty or has one character, return its length
        if (n <= 1) {
            return n;
        }
        // Map to store the last index of each character
        unordered_map<char, int> mp;
        // Iterate through the string with p2
        while (p2 < n) {
            // If the character at p2 is already in the map, move p1 to the right of the last occurrence
            if (mp.find(s[p2]) != mp.end()) {
                p1 = max(p1, mp[s[p2]] + 1);
            }
            // Update the answer with the maximum length found
            ans = max(ans, p2 - p1 + 1);
            // Update the map with the current index of the character
            mp[s[p2]] = p2;   
            // Move p2 to the next character
            p2++;
        }
        return ans;
    }
};
