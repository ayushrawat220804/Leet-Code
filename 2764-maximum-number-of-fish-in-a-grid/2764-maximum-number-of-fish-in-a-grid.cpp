/********************************************************************** C++ **********************************************************************/
// Approach-1 (Using DSU)
// T.C : O(m*n * alpha(m*n))
// S.C : O(m*n)
class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) { //size of parent and size array
        parent.resize(n);
        size.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 0; //fis count ios 0 initially for each
        }
    }

    //find the parent of x
    int find(int x) {
        if(parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]); //Path Compression
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) { //both already in same group
            return;
        }

        if(size[x_parent] > size[y_parent]) {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        } else {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
    }

    void setSize(int x, int fishCount) {
        size[x] = fishCount;
    }

    int getMaxFishCount() {
        return *max_element(begin(size), end(size));
    }
};

class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int totalCells = m*n;

        DSU dsu(totalCells);
        //DSU = alpha(totalCells)

        //Initialize size array with initial fish count of each cell
        //O(m*n)
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) {
                    int idx = i*n + j;
                    dsu.setSize(idx, grid[i][j]);
                }
            }
        }
        //O(m*n * alpha(m*n))
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) {
                    int idx = i * n + j; //parent ka index milgaya
                    for(auto &dir : directions) {
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];
                        if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0) {
                            int idx_ = i_ * n + j_; //parent ka index
                            dsu.Union(idx, idx_);
                        }
                    }
                }
            }
        }

        return dsu.getMaxFishCount();

    }
};