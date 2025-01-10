#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For max
using namespace std;

class Solution {
public:
    bool isSubset(vector<int>& freq2, vector<int>& temp) {
        for (int i = 0; i < 26; i++) { // O(1)
            if (temp[i] < freq2[i]) {
                return false; // Not a subset
            }
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;

        vector<int> freq2(26); // Frequency of maximum required characters
        for (string& word : words2) { // O(n * l1)
            vector<int> temp(26, 0);

            for (char& ch : word) { // Count frequency of each character in the word
                temp[ch - 'a']++;
                freq2[ch - 'a'] = max(freq2[ch - 'a'], temp[ch - 'a']);
            }
        }

        for (string& word : words1) { // O(m * l2)
            vector<int> temp(26, 0);

            for (char& ch : word) { // Count frequency of each character in the word
                temp[ch - 'a']++;
            }

            if (isSubset(freq2, temp)) { // Check if the word meets the conditions
                result.push_back(word);
            }
        }

        return result;
    }
};