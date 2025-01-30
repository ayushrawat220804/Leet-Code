//Approach - Using Bipartite, DFS and BFS
//T.C : O(V * (V+E))
//S.C : O(V+E)
class Solution {
public:
    //1 : Red
    //0 : Green
    bool isBipartite(unordered_map<int, vector<int>> &adj, int curr, vector<int>& colors, int currColor) {
        colors[curr] = currColor;

        for(int &ngbr : adj[curr]) {
            if(colors[ngbr] == colors[curr]) {
                return false;
            }

            if(colors[ngbr] == -1) {
                if(isBipartite(adj, ngbr, colors, 1 - currColor) == false) {
                    return false;
                }
            }
        }

        return true;
    }

    int bfs(unordered_map<int, vector<int>> &adj, int currNode, int n) {
        queue<int> que;
        vector<bool> visited(n, false);
        que.push(currNode);
        visited[currNode] = true;

        int level = 1; //max groups in that components
        while(!que.empty()) {

            int size = que.size();
            while(size--) {
                int curr = que.front();
                que.pop();

                for(int &ngbr : adj[curr]) {
                    if(visited[ngbr])
                        continue;
                    
                    que.push(ngbr);
                    visited[ngbr] = true;
                }
            }
            level++; //1 extra will be incremeented in the last loop
        }

        return level-1;
    }

    int getMaxFromEachComp(unordered_map<int, vector<int>> &adj, int curr, vector<bool>& visited, vector<int>& levels) {
        int maxGrp = levels[curr];
        visited[curr] = true;

        for(int &ngbr : adj[curr]) {
            if(!visited[ngbr]) {
                maxGrp = max(maxGrp, getMaxFromEachComp(adj, ngbr, visited, levels));
            }
        }

        return maxGrp;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj; //O(V+E) space

        for(auto& edge : edges) {
            int u = edge[0] - 1; //converting to 0-based idnex
            int v = edge[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //Bipartite check
        vector<int> colors(n, -1); //O(V)
        //O(V*(V+E))
        for(int node = 0; node < n; node++) { //O(n)
            if(colors[node] == -1) {
                if(isBipartite(adj, node, colors, 1) == false) { //O(V+E)
                    return -1;
                }
            }
        }

        //BFS karke max levels nikalo for each node
        vector<int> levels(n, 0);
        //T.C :O(V * (V+E))
        for(int node = 0; node < n; node++) { //O(V)
            levels[node] = bfs(adj, node, n); //O(V+E)
        }


        int maxGroupEachComp = 0;
        vector<bool> visited(n, false);
        for(int node = 0; node < n; node++) { //O(V * (V+E))
            if(!visited[node]) {
                maxGroupEachComp += getMaxFromEachComp(adj, node, visited, levels);
            }
        }

        return maxGroupEachComp;
    }
};