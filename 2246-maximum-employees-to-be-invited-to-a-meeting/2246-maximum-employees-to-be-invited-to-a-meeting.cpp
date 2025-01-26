//Approach - Using BFS and Cycle Checks
//T.C : ~O(n)
//S.C : ~O(n)
class Solution {
public:

    int BFS(int start, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int, int>> que; //{node, path length}
        que.push({start, 0});
        int maxDistance = 0;

        while(!que.empty()) {
            auto[currNode, dist] = que.front();
            que.pop();

            for(auto &ngbr : adj[currNode]) {
                if(!visited[ngbr]) {
                    visited[ngbr] = true;
                    que.push({ngbr, dist+1});
                    maxDistance = max(maxDistance, dist+1);
                }
            }
        }

        return maxDistance;
    }

    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int, vector<int>> adj;

        for(int i = 0; i < n; i++) {
            int u = i;
            int v = favorite[i];
            // u --> v
            adj[v].push_back(u); //reversed graph - so that we can find the path length after traversal
        }

        int longestCycleEmplCount = 0;
        int happyCoupleEmplCount  = 0; //cycle length = 2 waalo se kitna milpaega total

        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++) {

            if(!visited[i]) {
                //{node, abtak ka node count}
                unordered_map<int, int> mp;

                int currNode      = i;
                int currNodeCount = 0;

                while(!visited[currNode]) { //until cycle is not detected
                    visited[currNode] = true;
                    mp[currNode] = currNodeCount;

                    int nextNode = favorite[currNode]; //favorite node of curr node
                    currNodeCount += 1;

                    if(mp.count(nextNode)) { //already visited hai ye. Matlab cycle detect hogaya hai
                        int cycleLength = currNodeCount - mp[nextNode];
                        longestCycleEmplCount = max(longestCycleEmplCount, cycleLength);

                        if(cycleLength == 2) { //happy couple case
                            //currNode <-> nextNode = 2 nodes
                            vector<bool> visitedNodes(n, false);
                            visitedNodes[currNode] = true;
                            visitedNodes[nextNode] = true;
                            happyCoupleEmplCount += 2 + BFS(currNode, adj, visitedNodes) + BFS(nextNode, adj, visitedNodes);
                        }
                        break;
                    }
                    currNode = nextNode;
                }
            }
        }

        return max(happyCoupleEmplCount, longestCycleEmplCount);

    }
};