// thank you CodeWithMik
class Solution {
public:
    #define P pair<int, pair<int, int>>
    vector <vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector <vector<int>> results(m, vector<int>(n, INT_MAX));
        // results [i][j] = minimum distance/obestacle count between staring [0][0] to destinaion[i][j]
        results[0][0] = 0;
        priority_queue<P, vector<P>, greater <P>> pq;
        pq.push({0,{0,0}}); // {weight,{i,j}};
        // 0[Elog(V)] -> E(no of edges), V(no of vertices)
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int distance = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            for (auto &dir : directions ){
                int x = i + dir[0];
                int y = j + dir[1];

                if(x < 0 || x >= m || y<0 || y >= n){
                    continue;
                }
                int weight = (grid[x][y] == 1 ) ? 1 : 0;
                if (distance + weight < results[x][y]){
                    results[x][y] = distance + weight;
                    pq.push({distance + weight, {x,y}}); // pq.push({ ,{}});
                }

            }
        }
        return results [m-1][n-1];
    }
};