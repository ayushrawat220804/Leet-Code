//Approach-2 (Binary Search on Answer "Minimize the Maximum Robbed Amount(capability)")
//T.C : O(n*log(maxC))
//S.C : O(1)
class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int k) {
        int house = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= mid) {
                house++;
                i++; //skipping adjacent house
            }
        }

        return house >= k; //we managed to rob atleast k houses
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();

        int l = *min_element(begin(nums), end(nums));
        int r = *max_element(begin(nums), end(nums));

        int result = r;

        while(l <= r) { //O(log(maxC) * n )
            int mid = l + (r-l)/2; //capability

            if(isPossible(nums, mid, k) == true) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }
};