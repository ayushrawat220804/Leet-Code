//Approach-1 Brute Force
//T.C : O(n^m), where n = number of words, m = length of pref
//S.C : O(n^m)
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string& word : words) {
            if (word.find(pref) == 0) {
                count++;
            }
        }
        return count;
    }
};