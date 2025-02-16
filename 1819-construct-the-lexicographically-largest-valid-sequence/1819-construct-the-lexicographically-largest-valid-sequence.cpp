//Approach (Using simple backtracking Khandani Template)
//T.C : O(n!)
//S.C : O(n)
class Solution {
public:

    bool solve(int i, int n, vector<int>& result, vector<bool>& used) {
        if(i >= result.size()) {
            return true; //gauranteed answer - we were filling largest numbers first
        }

        if(result[i] != -1) {
            return solve(i+1, n, result, used);
        }

        for(int num = n; num >= 1; num--) {
            if(used[num]) {
                continue;
            }

            //try
            used[num] = true;
            result[i] = num;

            //EXPLORE
            if(num == 1) {
                if(solve(i+1, n, result, used) == true) {
                    return true;
                }
            } else {
                int j = result[i] + i;

                if(j < result.size() && result[j] == -1) {
                    result[j] = num;
                    if(solve(i+1, n, result, used) == true) {
                        return true;
                    }
                    result[j] = -1;
                }
            }

            //UNDO
            used[num] = false;
            result[i] = -1;
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2*n-1, -1);

        vector<bool> used(n+1, false);

        solve(0, n, result, used);

        return result;
    }
};

