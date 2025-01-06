//Approach-1 (Brute Force Using unordered_set extra space)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        unordered_set<int> st;

        for(int i = 0; i < n; i++) {
            if(boxes[i] == '1') {
                st.insert(i);
            }
        }

        vector<int> answer(n, 0);

        for(int i = 0; i < n; i++) {
            for(auto &idx : st) {
                answer[i] += abs(i - idx);
            }
        }

        return answer;

    }
};
