//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    // Adjacency list representation
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

    // Priority queue for Dijkstra's algorithm
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Distance vector initialized to infinity
    vector<int> dist(V, 1e9);
    dist[0] = 0;

    // Push the source node with distance 0
    pq.push({0, 0}); // {distance, node}

    while (!pq.empty()) {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        // Iterate over neighbors
        for (auto it : adj[node]) {
            int n2 = it.first;  // Neighbor
            int wt = it.second; // Weight of the edge

            // Relax the edge
            if (dis + wt < dist[n2]) {
                dist[n2] = dis + wt;
                pq.push({dist[n2], n2});
            }
        }
    }

    // Replace unreachable distances with -1 (optional)
    for (int i = 0; i < V; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
    }

    return dist;
}

};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends