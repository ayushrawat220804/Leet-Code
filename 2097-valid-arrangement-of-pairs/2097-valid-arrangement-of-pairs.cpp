class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // step -1 build adjacency list - graph
        unordered_map<int, vector<int>> adj;
        // build indegree and outdegree
        unordered_map<int, int> indegree, outdegree;
        // key - node
        // value - indegree / outdegree
        for (auto &edge: pairs) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v); // v--> v
            outdegree[u]++;
            indegree[v]++;
        }
        
        // find the startnode of eulerpath
        int startnode = pairs[0][0];
        for ( auto &it : adj ){
            int node = it.first;
            if(outdegree[node] - indegree[node] == 1){
                startnode = node;
                break;
            }
        }
        // simply do the khandani DFS
        vector <int> eulerpath; // to store my eularpath
        stack<int> st; // to perform DFS
        st.push(startnode);
        
        while(!st.empty()){
            int curr = st.top();
            if(!adj[curr].empty()){
                int neighbour = adj[curr].back();
                adj[curr].pop_back();
                st.push(neighbour);
            }
            else {
                eulerpath.push_back(curr);
                st.pop();
            }
        }
        // build your result 
        reverse(begin(eulerpath), end(eulerpath));
        vector<vector<int>> result;
        for(int i = 0; i< eulerpath.size()-1; i++){
            result.push_back({eulerpath[i], eulerpath[i+1]});
        }
        
        return result;
    }
};