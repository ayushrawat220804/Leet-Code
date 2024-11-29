class Solution {
public:
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    #define P pair<int, pair<int, int>>

    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({grid[0][0], {0, 0}}); // Start at top-left corner
        result[0][0] = 0;
        while (!pq.empty()) {
            // Get the current time, row, and column
            int time = pq.top().first;
            int row  = pq.top().second.first;
            int col  = pq.top().second.second;
            pq.pop();
            
            // Reached destination
            if (row == m - 1 && col == n - 1)
                return result[m-1][n-1];
            
            // Mark the current cell as visited
            if (visited[row][col]) continue;
            visited[row][col] = true;
            
            // Explore the neighboring cells
            for (auto dir: direction) {
                int r = row + dir[0];
                int c = col + dir[1];
                if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c])
                    continue;
                
                if (grid[r][c] <= time+1) {
                    pq.push({time+1, {r, c}});
                    result[r][c] = time+1;
                } else if ((grid[r][c]-time)%2==0) {
                    pq.push({grid[r][c]+1, {r, c}});
                    result[r][c] = grid[r][c]+1;
                } else {
                    pq.push({grid[r][c], {r, c}});
                    result[r][c] = grid[r][c];
                }
            }
        }
        return -1;
    }
};