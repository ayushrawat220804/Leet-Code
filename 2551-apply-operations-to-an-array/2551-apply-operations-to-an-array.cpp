class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n-1; i++){
            if (nums[i] == (nums[i+1])){
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
            }
        }

        int replacewithzero = 0; // or nums.size() -1; iterate backword
        for (int i = 0; i < n; i++){
            if(nums[i] !=0){
                swap(nums[i],nums[replacewithzero]);
                replacewithzero++;
            }
        }

        return nums;
        // vector<int> result = nums;
        // return result;
    }
};