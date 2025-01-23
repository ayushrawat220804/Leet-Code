//Approach - 1 (Brute Force)
//T.C : O((m*n) * (m+n))
//S.C : O(1)
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int resultServers = 0;

        // Traverse through the grid
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) {
                    bool canCommunicate = false;

                    // Check for communication in the same row
                    for (int otherCol = 0; otherCol < n; ++otherCol) {
                        if (otherCol != col && grid[row][otherCol] == 1) {
                            canCommunicate = true;
                            break;
                        }
                    }

                    // If a server was found in the same row, increment resultServers
                    if (canCommunicate) {
                        resultServers++;
                    } else {
                        // Check for communication in the same column
                        for (int otherRow = 0; otherRow < m; ++otherRow) {
                            if (otherRow != row && grid[otherRow][col] == 1) {
                                canCommunicate = true;
                                break;
                            }
                        }

                        // If a server was found in the same column, increment resultServers
                        if (canCommunicate) {
                            resultServers++;
                        }
                    }
                }
            }
        }

        return resultServers;
    }
};