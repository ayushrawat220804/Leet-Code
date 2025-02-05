#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.length() != s2.length()) return false;  // Step 1: Check Length
    
        int diffCount = 0, first = -1, second = -1;

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {  // Step 2: Check Differences
                diffCount++;
                if (first == -1) first = i;
                else if (second == -1) second = i;
                else return false;  // More than 1 swap needed
            }
        }

        return (diffCount == 0 || (diffCount == 2 && s1[first] == s2[second] && s1[second] == s2[first]));
    }
};

// int main() {
//     Solution sol;

//     vector<pair<string, string>> testCases = {
//         // {"hello", "holle"},  // ✅ True (Swap 'o' and 'l')
//         // {"hello", "oellh"},  // ❌ False (Multiple swaps needed)
//         // {"abc", "acb"},      // ✅ True (Swap 'b' and 'c')
//         // {"abc", "def"},      // ❌ False (Different letters)
//         // {"abcd", "abc"},     // ❌ False (Different lengths)
//         // {"a", "a"},          // ✅ True (Same string)
//         // {"ab", "ba"},        // ✅ True (Swap 'a' and 'b')
//         // {"ab", "cd"}         // ❌ False (Different letters)
//     };

//     for (auto& test : testCases) {
//         cout << "areAlmostEqual(\"" << test.first << "\", \"" << test.second << "\") -> "
//              << (sol.areAlmostEqual(test.first, test.second) ? "True" : "False") << endl;
//     }

//     return 0;
// }
