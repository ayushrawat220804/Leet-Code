//Approach (Using cummulativeSum array/Prefix Sum Array)
//T.C : O(N+Q)
//S.C : O(N)
class Solution {
public:
    bool isVowel(char &ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int Q = queries.size();
        int N = words.size();
        //"a,e,i,o,u"
        vector<int> result(Q);

        vector<int> cumSum(N);
        int sum = 0;
        for(int i = 0; i < N; i++) { //O(N)
            if(isVowel(words[i][0]) && isVowel(words[i].back())) {
                sum++;
            }

            cumSum[i] = sum;
        }

        for(int i = 0; i < Q; i++) { //O(Q)
            int l = queries[i][0];
            int r = queries[i][1];

            result[i] = cumSum[r] - ((l > 0) ? cumSum[l-1] : 0);
        }

        return result;
    }
};