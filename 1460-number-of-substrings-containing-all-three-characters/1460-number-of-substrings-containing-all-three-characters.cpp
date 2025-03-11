//Approach (Sliding Window Khandani Template)
//T.C : O(2*n) ~ O(n)
//S.C : O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        int result = 0;
        
        vector<int> mp(3, 0); //0 - a, 1 - b, 2 - c

        int i = 0;
        int j = 0;
        while(j < n) {
            char ch = s[j];
            mp[ch-'a']++;

            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0) {
                result += (n - j);

                mp[s[i] - 'a']--;
                i++;
            }

            j++;
        }

        return result;

        
    }
};
