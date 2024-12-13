class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector <pair <int , int>> vect(n);
        for (int i = 0; i < n; i++){
            vect[i] = {nums[i], i};
        }
        sort(begin(vect), end(vect));

        long long score = 0;
        vector <bool> visited (n, false);

        for (int i = 0; i < n; i++){
            int element = vect[i].first;
            int idx = vect[i].second;
            if ( visited[idx] == false){
                visited[idx] = true;
                score = score + element;

                if(idx-1 >= 0 && visited[idx-1] == false){
                    visited[idx-1] = true;
                }
                if(idx+1 < n && visited[idx+1] == false){
                    visited[idx+1] = true;
                }
            }

        }
        return score;
    }
};