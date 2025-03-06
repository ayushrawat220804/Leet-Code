class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n*n; // total number of elements
        unordered_map<int, int> mp;
        int a = -1;
        int b = -1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                mp[grid[i][j]]++;

            }
        }
        // 1 to N;
        for(int num =1; num <= N; num++){
            if (!mp.count(num)){
                b = num;  
            } else if ( mp[num] == 2 ){
                a = num;
            }
            if (a != -1 && b != -1){
                break;
            }
        }

        return {a,b};

    }
};