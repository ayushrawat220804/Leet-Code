#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i = 0, j = 0;
        int n = (nums1.size() + nums2.size()) / 2;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size()) {
            ans.push_back(nums1[i]);
            i++;
        }

        while (j < nums2.size()) {
            ans.push_back(nums2[j]);
            j++;
        }

        if ((nums1.size() + nums2.size()) % 2 == 0) {
            return (double)(ans[n - 1] + ans[n]) / 2;
        } else {
            return ans[n];
        }
    }
};
