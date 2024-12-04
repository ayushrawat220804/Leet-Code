//Approach (Simple traversal using two pointers)
//T.C : O(m+n)
//S.C : O(1)
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        if(n > m) {
            return false;
        }

        int i = 0;
        int j = 0;

        while(i < m && j < n) {
            if((str1[i] == str2[j])   ||
               (str1[i]+1 == str2[j]) ||
               (str1[i]-25 == str2[j])) {
                j++;
            }

            i++;
        }

        return j == n;
    }
};