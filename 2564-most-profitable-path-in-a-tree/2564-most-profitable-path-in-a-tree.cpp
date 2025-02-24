//Approach-1 (DFS for Bob and DFS for Alice)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> bobMap;
    int aliceIncome;
    bool DFSBob(int curr, int t, vector<bool>&  visited) {
        visited[curr] = true;
        bobMap[curr] = t;

        if(curr == 0) { //reached target
            return true;
        }

        for(auto &ngbr : adj[curr]) {
            if(!visited[ngbr]) {
                if(DFSBob(ngbr, t+1, visited) == true) {
                    return true;
                }
            }
        }

        bobMap.erase(curr);
        return false;
    }

    void DFSAlice(int curr, int t, int income, vector<bool>& visited, vector<int>& amount) {
        visited[curr] = true;

        if(bobMap.find(curr) == bobMap.end() || t < bobMap[curr]) {
            income += amount[curr];
        } else if(t == bobMap[curr]) {
            income += (amount[curr]/2);
        }


        if(adj[curr].size() == 1 && curr != 0) { //leaf node
            aliceIncome = max(aliceIncome, income);
        }

        /*
            {1} -> (2, 3)
            2 -> 1
            3 -> 1,....
            (1) ---- (2)
             |
             |
             (3)------.....
        */

        for(int &ngbr : adj[curr]) {
            if(!visited[ngbr]) {
                DFSAlice(ngbr, t+1, income, visited, amount);
            }
        }

    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size(); //n nodes (0 to n-1)

        aliceIncome = INT_MIN;
        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //DFS on Bob for finding time to reach each node till 0
        int time = 0;
        vector<bool> visited(n, false);
        DFSBob(bob, time, visited);
        
        int income = 0;
        visited.assign(n, false);
        DFSAlice(0, 0, income, visited, amount);

        return aliceIncome;
    }
};
