//Approach - (Using cumulative sum + game strategy)
//T.C : O(col), col = total columns in the grid
//S.C : O(1)
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowRemainSum = accumulate(begin(grid[0]), end(grid[0]), 0LL); //O(col)

        long long secondRowRemainSum = 0;

        long long minimizedRobot2Sum = LONG_LONG_MAX;

        for(int Robot1Col = 0; Robot1Col < grid[0].size(); Robot1Col++) { //O(col);
            //Robot1 took this strategy
            firstRowRemainSum -= grid[0][Robot1Col];

            //Robot2 will try to do best after Robot1 has taken the above strategy
            long long bestOfRobot2 = max(firstRowRemainSum, secondRowRemainSum);

            minimizedRobot2Sum     = min(minimizedRobot2Sum, bestOfRobot2);

            secondRowRemainSum    += grid[1][Robot1Col];
        }

        return minimizedRobot2Sum;
    }
};