// Thankyou CodeWithMIK
//Approach-2 (Sorting and Using Binary Search)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int maxBeauty = 0;
        //Proof in the video for nums[i] + 2*k
        for (int i = 0; i < nums.size(); i++) {
            auto upperBound = upper_bound(nums.begin(), nums.end(), nums[i] + 2 * k);

            maxBeauty = max(maxBeauty, int(upperBound - nums.begin()) - i);
        }

        return maxBeauty;
    }
};
