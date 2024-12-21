class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adjList(n);
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int components = 0;
        dfs(0, -1, adjList, values, k, components);
        return components;
    }

private:
    long dfs(int node, int parent, const vector<vector<int>>& adjList, const vector<int>& values, int k, int& components) {
        long sum = values[node];
        for (int neighbor : adjList[node]) {
            if (neighbor != parent) {
                sum += dfs(neighbor, node, adjList, values, k, components);
            }
        }
        if (sum % k == 0) {
            ++components;
            return 0;
        }
        return sum;
    }
};