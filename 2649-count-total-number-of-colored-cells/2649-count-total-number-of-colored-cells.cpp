class Solution {
public:
    long long coloredCells(int n) {
        int time = 1;// 1 
        long long cells = 1; // 1 cell means 1 square, after 1 min, at 2 it will have 5 cells in total, how ? like it have 4 faces , 4 faces + 1 = 5 cells, draw on paper for clarity
        while (time <= n ){
            cells = cells + 4*(time - 1); 
            // why 4? because after each min, 1 cell have 4 faces so we multiply each cell block by 4
            time++;
        }
        return cells;
        
    }
};