//Approach-2 (Dijkstra's Algorithm) - Accepted
//T.C : O((m*n) * log(m*n))
//S.C : O(m*n)
class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; //min-heap of int
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        pq.push({0, 0, 0});
        result[0][0] = 0;
        //T.C : O(m*n * log(m*n))
        //S.C : O(m*n)
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop(); //log(size of pq)

            int currCost = curr[0];
            int i = curr[1];
            int j = curr[2];

            if(result[i][j] < currCost) {
                continue;
            }

            for(int dir_i = 0; dir_i <= 3; dir_i++) {
                int i_ = i + dir[dir_i][0];
                int j_ = j + dir[dir_i][1];

                if(i_ >= 0 && j_ >= 0 && i_ < m && j_ < n) {
                    int gridDir = grid[i][j];
                    int dirCost = ((gridDir-1 != dir_i) ? 1 : 0);

                    int newCost = currCost + dirCost;

                    if(newCost < result[i_][j_]) {
                        result[i_][j_] = newCost;
                        pq.push({newCost, i_, j_});
                    }
                }
            }
        }
        return result[m-1][n-1]; //min cost to reach (m-1, n-1)
    }
};