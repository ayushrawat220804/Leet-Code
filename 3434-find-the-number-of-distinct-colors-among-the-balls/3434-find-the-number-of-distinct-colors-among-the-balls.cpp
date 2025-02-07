// potd 07,02,2025
// Approach-2 (Using hashmaps)
// T.C : O(n)
// S.C : O(n)

// cpp unorderedmap operation is o(n)
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);

        unordered_map<int, int> colormp; //color -> count
        unordered_map<int, int> ballmp; //ball -> color

        for(int i = 0; i < n; i++) {
            int ball  = queries[i][0];
            int color = queries[i][1];

            if(ballmp.count(ball)) { //already colored ball
                int prevColor = ballmp[ball];
                colormp[prevColor]--;

                if(colormp[prevColor] == 0) {
                    colormp.erase(prevColor);
                }
            }

            ballmp[ball] = color;
            colormp[color]++;

            result[i] = colormp.size();
        }

        return result;


    }
};