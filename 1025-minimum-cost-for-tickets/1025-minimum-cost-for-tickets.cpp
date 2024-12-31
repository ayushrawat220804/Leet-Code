// Thanks To CodeStoryWithMIK
// Approach-1 (Recursion + Memoization)
// Time: O(max_day), Space: O(n), where n = size of days vector
class Solution {
public:
    int t[366]; // Memoization table
    
    int memoized(vector<int>& days, vector<int>& costs, int& n, int idx) {
        if (idx >= n)
            return 0; // No more travel days, no cost
        
        if (t[idx] != -1)
            return t[idx]; // Return memoized result
        
        // If 1-day pass is taken
        int cost_1 = costs[0] + memoized(days, costs, n, idx + 1);
        
        // If 7-day pass is taken
        int i = idx;
        while (i < n && days[i] < days[idx] + 7) {
            i++;
        }
        int cost_7 = costs[1] + memoized(days, costs, n, i);
        
        // If 30-day pass is taken
        int j = idx;
        while (j < n && days[j] < days[idx] + 30) {
            j++;
        }
        int cost_30 = costs[2] + memoized(days, costs, n, j);
        
        // Store and return the minimum cost
        return t[idx] = min({cost_1, cost_7, cost_30});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(t, -1, sizeof(t)); // Initialize memoization table
        int n = days.size();
        return memoized(days, costs, n, 0);
    }
};
