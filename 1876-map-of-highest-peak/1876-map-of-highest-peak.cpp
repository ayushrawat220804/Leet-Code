//Approach - Using Multi-Source BFS
//T.C : O(m * n) , We will visit all cells once
//S.C : O(m * n), in worst case queue will contain all the cells
class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();


        vector<vector<int>> height(m, vector<int>(n, -1));

        queue<P> que;
        //Height of water cells must be 0 only
        //T.C : O(m*n)
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j] == 1) { //this cell is water
                    height[i][j] = 0; //This is a source for hitting BFS
                    que.push({i, j});
                }
            }
        }

        //Apply khandani template - Multi source BFS ka
        //T.C : O(m*n)
        //S.C : O(m*n)
        while(!que.empty()) {
            int N = que.size();

            while(N--) {
                P curr = que.front();
                que.pop();

                int i = curr.first;
                int j = curr.second;

                for(auto &dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && height[i_][j_] == -1) {
                        height[i_][j_] = height[i][j] + 1;
                        que.push({i_, j_});
                    }
                }
            }
        }

        return height;


    }
};
