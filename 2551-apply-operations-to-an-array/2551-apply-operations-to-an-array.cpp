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

        int replacewithzero = 0; // iterate, if we get 0; swap it 
        for (int i = 0; i < n; i++){
            if(nums[i] !=0){
                swap(nums[i],nums[replacewithzero]);
                replacewithzero++;
            }
        }
        vector<int> result = nums;

        return result;
        // vector<int> result = nums;
        // return result;
    }
};

/*
int main (){
    Solution sol;
    vector<int> nums = {1,2,2,1,1,0};
    vector<int> result = sol.applyoperation(nums);
    cout << "output is : " ;
    for ( int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }

}
*/