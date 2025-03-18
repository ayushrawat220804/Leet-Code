//Approach-3 (Sliding Window Khandani Template)
//T.C : O(2*n) ~ O(n)
//S.C : O(1)
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 0;

        int result = 1;
        int mask = 0;

        while(j < n) {

            while((mask & nums[j]) != 0) { //keep shrinking
                mask = (mask ^ nums[i]);
                i++;
            }

            result = max(result, j-i+1);
            mask = (mask | nums[j]);
            j++;
        }

        return result;

    }
};