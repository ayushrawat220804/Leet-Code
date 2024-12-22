#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> res(n, -1);

        // Using a map to simulate defaultdict
        unordered_map<int, vector<pair<int, int>>> groups;

        for (int i = 0; i < n; ++i) {
            int l = min(queries[i][0], queries[i][1]);
            int r = max(queries[i][0], queries[i][1]);

            if (l == r || heights[r] > heights[l]) {
                res[i] = r;
            } else {
                int h = max(heights[l], heights[r]);
                groups[r].emplace_back(h, i);
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;

        for (int i = 0; i < heights.size(); ++i) {
            for (auto& query : groups[i]) {
                min_heap.emplace(query.first, query.second);
            }

            while (!min_heap.empty() && heights[i] > min_heap.top().first) {
                auto [q_h, q_i] = min_heap.top();
                min_heap.pop();
                res[q_i] = i;
            }
        }

        return res;
    }
};
