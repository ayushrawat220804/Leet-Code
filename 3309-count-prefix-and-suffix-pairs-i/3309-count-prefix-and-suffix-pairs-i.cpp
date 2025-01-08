//Approach-1 Brute Force
//T.C : O(n^2 * l)
//S.C : O(n^2 * l)
class Solution {
public:
    
    bool isPrefixAndSuffix(string &check, string &s) {
        int n = check.length();

        //You can use fine() function as well
        string s1 = s.substr(0, n);
        string s2 = s.substr(s.length() - n, n);
        
        return s1 == check && s2 == check;
        
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        auto lambda = [](string& s1, string& s2) {
            return s1.length() < s2.length();
        };
        
        //sort(begin(words), end(words), lambda);
        
        int count = 0;
        for(int i = 0; i < words.size()-1; i++) {
            for(int j = i+1; j < words.size(); j++) {
                if(words[i].length() <= words[j].length() && isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        
        return count;
    }
};