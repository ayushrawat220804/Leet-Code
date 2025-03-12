class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto lambdaP =[](int num){
        return num > 0;
        };                
        auto lambdaN =[](int num){
            return num < 0;
        };

        int P = count_if(nums.begin(), nums.end(), lambdaP);
        int N = count_if(nums.begin(), nums.end(), lambdaN);


        int result  = max(P,N);
        return result;
    }
};