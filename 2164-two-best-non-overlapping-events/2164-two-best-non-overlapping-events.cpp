// thank you CodeWithMIk
//Approach-2 (Recursion + Memoization and Sorting)
//T.C : O(n * logn, After memoizing, we will visit at max n states and for binarysearch it will take log(n))
//S.C : O(n*3) ~= O(n)
class Solution {
public:
    int n;
    int t[100001][3];
    
    //upper_bound of endTime
    int binarySearch(vector<vector<int>>& events, int endTime) {
        int l = 0;
        int r = n-1;
        int result = n;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(events[mid][0] > endTime) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;
    }

    int solve(vector<vector<int>>& events, int i, int count) {
        if(count == 2 || i >= n) {
            return 0;
        }

        if(t[i][count] != -1) {
            return t[i][count];
        }

        int nextValidEventIndex = binarySearch(events, events[i][1]);
        int take = events[i][2] + solve(events, nextValidEventIndex, count+1);

        int not_take = solve(events, i+1, count);

        return t[i][count] = max(take, not_take);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(begin(events), end(events));
        memset(t, -1, sizeof(t));

        int count = 0;
        return solve(events, 0, count);
    }
};