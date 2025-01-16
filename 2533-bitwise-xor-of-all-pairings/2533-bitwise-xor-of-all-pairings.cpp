//Approach-2 (Using Xor property)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int XOR = 0;

        if(m % 2 != 0) { //m is of odd length
            for(int &num : nums2) {
                XOR ^= num;
            }
        }

        if(n % 2 != 0) { //n is of odd length
            for(int &num : nums1) {
                XOR ^= num;
            }
        }

        return XOR;
    }
};