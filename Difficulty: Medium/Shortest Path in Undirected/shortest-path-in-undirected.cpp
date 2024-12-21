//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        queue<int> q;
        q.push(src);
        int n = adj.size();
        vector<int> dis(n,1e8);
        dis[src] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto x : adj[node]){
                int d2  = 1 + dis[node];
                if(d2 < dis[x]){
                    dis[x] = d2;
                    q.push(x);
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(dis[i] == 1e8) dis[i] = -1;
        }
        return dis;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends