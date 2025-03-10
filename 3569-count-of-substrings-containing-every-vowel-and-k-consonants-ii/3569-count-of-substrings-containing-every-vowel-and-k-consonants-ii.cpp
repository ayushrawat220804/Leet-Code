//T.C : O(2*n) ~ O(n)
//S.C : O(n)
class Solution {
public:
    bool isVowel(char &ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        unordered_map<char, int> mp; //to keep count of vowels in a current window
        //S.C : O(5) constant
        //Preprocessing to be able to find index of just next consonant
        vector<int> nextCons(n); //S.C : O(n)
        int lastConsIdx = n;
        //T.C : O(n)
        for(int i = n-1; i >=0; i--) {
            nextCons[i] = lastConsIdx;
            if(!isVowel(word[i])) { //consonant
                lastConsIdx = i;
            }
        }

        int i = 0;
        int j = 0;
        long long count = 0;
        int cons = 0;
        while(j < n) {       //T.C : O(2*n) ~ O(n) 
            char ch = word[j];
            if(isVowel(ch)) {
                mp[ch]++;
            } else {
                cons++;
            }

            while(cons > k) {            //cons must be always == k
                char ch = word[i];
                if(isVowel(ch)) {
                    mp[ch]--;
                    if(mp[ch] == 0) {
                        mp.erase(ch);
                    }
                } else {
                    cons--;
                }
                i++;
            }

            while(i < n && mp.size() == 5 && cons == k) { //valid window
                int idx = nextCons[j]; //it will tell me the next consonant after jth index
                count += idx - j; //most important part
                char ch = word[i];
                if(isVowel(ch)) {
                    mp[ch]--;
                    if(mp[ch] == 0) {
                        mp.erase(ch);
                    }
                } else {
                    cons--;
                }
                i++;
            }
            j++;
        }
        return count;
    }
};