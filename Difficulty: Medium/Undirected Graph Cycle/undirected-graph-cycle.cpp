//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(int node, vector<vector<int>>& adj, vector<int> &vis){
        queue<pair<int,int>> q;
        q.push({node, -1});
        vis[node] = 1;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int nn = x.first;
            int p = x.second;
            for(auto x : adj[nn]){
                if(!vis[x]){
                    vis[x] = 1;  
                    q.push({x,nn});
                }
                else if(x != p){
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector <int> vis(n + 1, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(check(i,adj,vis)) return true;
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends