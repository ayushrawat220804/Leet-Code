//Approach-3 (Better Brute Force)
//T.C : O(n^3)
//S.C : O(1)
//S.C : O(n)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int totalNumberOfTuples = 0;
        int n = nums.size();

        int result = 0;
        sort(begin(nums), end(nums));

        // Four nested loops to select a, b, c, d
        for (int i = 0; i < n; i++) {           // Choose a
            for (int j = n - 1; j > i; j--) {   // Choose b (distinct from a)

                int product = nums[i] * nums[j];
                unordered_set<int> st;

                for (int k = i+1; k < j; k++) {   // Choose c

                    if(product % nums[k] == 0) {
                        int lValue = product/nums[k];

                        if(st.count(lValue)) {
                            totalNumberOfTuples++;
                        }

                        st.insert(nums[k]);
                    }
                }
            }
        }

        // Each unique combination corresponds to 8 possible tuples
        return totalNumberOfTuples * 8;
    }
};