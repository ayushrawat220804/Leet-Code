class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int max_sum = 0;

        for(int i = 0; i < n; i++){
            int sum = nums[i];
            // int j = i + 1;
            for( int j = i + 1; j < n && nums[j] > nums[j-1]; j++){
                sum = sum + nums[j];
                // j++;
            }
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    
    }
};