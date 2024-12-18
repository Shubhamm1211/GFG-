//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    // bool dfs(int node,int par, vector<int>&vis, vector<vector<int>> &adj){
    //     vis[node] = 1;
    //     for(auto x : adj[node]){
    //         if(!vis[x]){
    //             if(dfs(x,node,vis,adj)){
    //                 return true;
    //             }
    //             else if(x != par) return true;
    //         }
    //     }
    //     return false;
        
    // }
    // bool isCycle(vector<vector<int>>& adj) {
    //     // Code here
    //     int n = adj.size();
    //     vector <int> vis(n + 1,0);
    //     for(int i = 0; i < n; i++){
    //         if(!vis[i]){
    //             if(dfs(i,-1,vis,adj)) return true;  
    //         }
    //     }
    //     return false;
        
    // }
    bool dfs(int node, int par, vector<int>& vis, vector<vector<int>>& adj) {
    vis[node] = 1; // Mark the current node as visited
    for (auto x : adj[node]) {
        if (!vis[x]) { 
            // If the node is unvisited, continue DFS
            if (dfs(x, node, vis, adj)) {
                return true; // Cycle found
            }
        } else if (x != par) {
            // If the node is visited and is not the parent, cycle exists
            return true;
        }
    }
    return false;
}

bool isCycle(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> vis(n, 0); // Adjust size to 'n'
    for (int i = 0; i < n; i++) {
        if (!vis[i]) { // Check unvisited nodes
            if (dfs(i, -1, vis, adj)) {
                return true; // Cycle found
            }
        }
    }
    return false; // No cycle found
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