class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(begin(banned), end(banned));
        int count = 0;
        int sum = 0;

        for(int num = 1; num <= n; num++) {
            if(st.count(num)) {
                continue;
            }

            if(sum + num <= maxSum) {
                count++;
                sum += num;
            } else {
                break;
            }
        }

        return count;
    }
};